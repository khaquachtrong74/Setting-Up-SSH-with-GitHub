// JavaScript file: homePage.js

// Toggle the display of personal information
document.querySelector("header button").addEventListener("click", function() {
    const infoDiv = document.querySelector(".information");
    if (infoDiv.style.display === "none" || !infoDiv.style.display) {
        infoDiv.style.display = "block";
    } else {
        infoDiv.style.display = "none";
    }
});

// Smooth scrolling to sections when clicking on nav links
document.querySelectorAll("nav ul li a").forEach(link => {
    link.addEventListener("click", function(event) {
        event.preventDefault();
        const targetId = this.getAttribute("href").substring(1);
        const targetSection = document.getElementById(targetId);
        
        if (targetSection) {
            window.scrollTo({
                top: targetSection.offsetTop - 20,  // Adjust the offset if needed
                behavior: "smooth"
            });
        }
    });
});
