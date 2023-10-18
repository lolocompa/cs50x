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



let button2 = document.querySelector("#button2");
let pic2 = document.querySelector("#pic2");

button2.addEventListener("click", function(event) {

    if (pic2.style.display === "none")
    {
        pic2.style.display = "block";
        button2.textContent = "hide pic 2";
    }
    else
    {
        pic2.style.display = "none";
        button2.textContent = "show pic 2"
    }
});



let button3 = document.querySelector("#button3");
let pic3 = document.querySelector("#pic3");

button3.addEventListener("click", function(event) {

    if (pic3.style.display === "none")
    {
        pic3.style.display = "block";
        button3.textContent = "hide pic 3";
    }
    else
    {
        pic3.style.display = "none";
        button3.textContent = "show pic 3"
    }
});