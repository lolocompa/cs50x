import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session["user_id"]
    display = db.execute("SELECT symbol FROM purchases WHERE user_id = ? GROUP BY symbol", user_id)

    name_l = []
    market_price_l = []
    sym_l = []
    shares_l = []
    price_total_l = []

    user_total = db.execute("SELECT cash FROM users WHERE id = ?", user_id)


    for record in display:

        sym = record["symbol"]
        sym_l.append(sym)

        look = lookup(sym)

        name = look["name"]
        name_l.append(name)

        market_price = look["price"]
        market_price_l.append(market_price)


        shares_list = db.execute("SELECT SUM(shares) AS total_shares FROM purchases WHERE symbol = ? AND user_id = ?", sym, user_id)
        shares = shares_list[0]["total_shares"]
        shares_l.append(shares)

        price_total = market_price * float(shares)
        price_total_l.append(price_total)

    times = len(sym_l)
    total = 10000
    return render_template("index.html", name_l=name_l, market_price_l=market_price_l, sym_l=sym_l, shares_l=shares_l, user_total=user_total[0]["cash"], price_total_l=price_total_l, times=times, total=total)














@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        sym = request.form.get("symbol")
        sym = sym.upper()
        shares = request.form.get("shares")

        try:
            shares = int(shares)
        except ValueError:
            return apology("Invalid number of shares")

        shares = int(shares)
        user_id = session["user_id"]

        bought = lookup(sym)

        if not bought:
            return apology("bought wasnt succesfull")

        price = bought["price"] * shares

        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        if current_cash[0]["cash"] < price:
            return apology("not enough cash")

        market_price = bought["price"]

        db.execute("INSERT INTO purchases (symbol, shares, price, user_id, market_price) VALUES (?, ?, ?, ?, ?)", sym, shares, price, user_id, market_price)

        new_cash = current_cash[0]["cash"] - price

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        return redirect("/")
















@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    user_id = session["user_id"]

    data = db.execute("SELECT symbol, shares, market_price, timestamp FROM purchases WHERE user_id = ? ORDER BY timestamp", user_id)

    return render_template("history.html", data=data)












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






@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")

        symbol_data = lookup(symbol)

        if not symbol_data:
            return apology("invalid symbol")

        return render_template("quoted.html", symbol_data=symbol_data)











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










@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session["user_id"]
    user_sym = db.execute("SELECT symbol FROM purchases WHERE user_id = ? GROUP BY symbol", user_id)

    if request.method == "GET":
        return render_template("sell.html", user_sym=user_sym)
    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not shares or symbol:
            return apology("error")

        shares_list = db.execute("SELECT SUM(shares) AS total_shares FROM purchases WHERE symbol = ? AND user_id = ?", symbol, user_id)
        shares_total = shares_list[0]["total_shares"]

        if shares_total < shares:
            return apology("too much shares")


        data = lookup(symbol)
        market_price = data["price"]
        shares_sold = -1 * shares

        total_price = market_price * shares
        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        new_cash =current_cash[0]["cash"] + total_price

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        db.execute("INSERT INTO purchases (symbol, shares, market_price, user_id, price) VALUES (?, ?, ?, ?, ?)", symbol, shares_sold, market_price, user_id, total_price)

        return redirect("/")
