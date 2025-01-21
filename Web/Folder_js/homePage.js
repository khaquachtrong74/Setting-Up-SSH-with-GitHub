window.onload = function () {
    let p = document.querySelectorAll("section p");
    let h2 = document.querySelectorAll("main h2");
    // let articleH2 = document.querySelectorAll("main h2+article");
    // articleH2.forEach(el => {
    //     el.setAttribute("style", "display:none");
    // })
    p.forEach(element => {
        element.addEventListener("mousemove", function () {
            element.setAttribute("style",
                "background-color: grey; color:white; transition: color .5s"
            );
        });
        element.addEventListener("mouseleave", function () {
            element.setAttribute("style", "background-color: none");
        });
    });
    // h2.forEach(element => {
    //     let flag = false;
    //     element.addEventListener("click", function () {
    //         if (!flag) {
    //             element.setAttribute("style",
    //                 "transform: skew(0deg, 1deg) translateX(500px); transition: transform 3.3s"
    //             );
    //             flag = true;
                

    //         }
    //         else {
    //             element.setAttribute("style", "transform: skew(none); transition: 1.3s ease");
    //             flag = false;
    //         }

    //     })

    // });

};
