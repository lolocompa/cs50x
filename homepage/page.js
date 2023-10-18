let button1 = document.querySelector("#button1");
let pic1 = document.querySelector("#pic1");

button1.addEventListener("click", function(event) {

    if (pic1.style.display === "none")
    {
        pic1.style.display = "block";
        button1.textContent = "hide pic 1";
    }
    else
    {
        pic1.style.display = "none";
        button1.textContent = "show pic 1"
    }
});