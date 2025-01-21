window.onload = function () {
    const headers = document.querySelectorAll('h2');
    const headers3 = document.querySelectorAll('h3');
    headers.forEach(header => {
        const list = header.nextElementSibling;
        header.addEventListener('click', () => {
            if (list && list.tagName === 'UL') {     
                list.style.display = list.style.display === 'none' ? 'block' : 'none';
            }
        })
    })
    headers3.forEach(header3 => {
        const list1 = header3.nextElementSibling;
        header3.addEventListener('click', () => {
            if (list1 && list1.tagName === 'UL') {     
                list1.style.display = list1.style.display === 'none' ? 'block' : 'none';
            }
        })
    })
}
