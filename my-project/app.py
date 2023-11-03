import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required



app = Flask(__name__)


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)



db = SQL("sqlite:///movies.db")



@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response




@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")








@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hashed_password = generate_password_hash(password)

        check_name = db.execute("SELECT username FROM users WHERE username = ?", username)

        if not username or not password or not confirmation:
            return apology("dont leave a blank space")
        elif password != confirmation:
            return apology("password soesnt match confirmation")
        elif check_name:
            return apology("username already exists")

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed_password)

        return redirect("/login")








@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    if request.method == "GET":
        return render_template("index.html")
    else:
        year = request.form.get("year")
        rating = request.form.get("rating")
        actor1 = request.form.get("actor1")
        actor2 = request.form.get("actor2")
        director = request.form.get("director")




        query = "SELECT DISTINCT movies.id, movies.title FROM movies "

        joins = []
        conditions = []
        params = []

        if year:
            joins.append("LEFT JOIN ratings AS r1 ON movies.id = r1.movie_id")
            conditions.append("movies.year >= ?")
            params.append(year)
        if rating:
            if "r1" not in [join[18:20] for join in joins]:
                joins.append("LEFT JOIN ratings AS r2 ON movies.id = r2.movie_id")
            conditions.append("r2.rating >= ?")
            params.append(rating)
        if actor1:
            joins.append("LEFT JOIN stars AS s1 ON movies.id = s1.movie_id")
            joins.append("LEFT JOIN people AS p1 ON s1.person_id = p1.id")
            conditions.append("p1.name LIKE ?")
            params.append(f'%{actor1}%')
        if actor2:
            joins.append("LEFT JOIN stars AS s2 ON movies.id = s2.movie_id")
            joins.append("LEFT JOIN people AS p2 ON s2.person_id = p2.id")
            conditions.append("p2.name LIKE ?")
            params.append(f'%{actor2}%')
        if director:
            joins.append("LEFT JOIN directors AS d ON movies.id = d.movie_id")
            joins.append("LEFT JOIN people AS pd ON d.person_id = pd.id ")
            conditions.append("pd.name LIKE ?")
            params.append(f'%{director}%')

        if joins:
            query += " " + " ".join(joins)
        if conditions:
            query += " WHERE " + " AND ".join(conditions)

        query += "LIMIT 150"
        # Execute the SQL query using your database connection
        results = db.execute(query, *params)

        # Process and return the results as needed
        # You may want to render a template with the results or return JSON, for example

        # Example: return a list of movie titles
        movie_titles = [result['title'] for result in results]
        return render_template("result.html", movie_titles=movie_titles)





@app.route("/list", methods=["GET", "POST"])
@login_required
def movie_list():
    if request.method == "GET":
        movie_list = db.execute("SELECT * FROM list")
        return render_template("list.html", movie_list=movie_list)
    else:
        user_id = session["user_id"]
        title = request.form.get("title")
        released = db.execute("SELECT year FROM movies WHERE title = ?", title)
        rating = db.execute("SELECT rating FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE title = ?)", title)
        db.execute("INSERT INTO list (title, year, rating, user_id) VALUES (?, ?, ?, ?)", title, released[0]["year"], rating[0]["rating"], user_id)
        return redirect("/")





@app.route("/remove", methods=["POST"])
@login_required
def remove():
    if request.method == "POST":
        user_id = session["user_id"]
        title = request.form.get("name")
        db.execute("DELETE FROM list WHERE user_Id = ? AND title = ?", user_id, title)
        return redirect("/list")
