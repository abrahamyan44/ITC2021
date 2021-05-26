const data = require('./books.json')
let count_form = document.querySelector('.block_container');
console.log(count_form);
count_form.addEventListener('submit', function(event) {
    event.preventDefault();
    document.querySelector(".container").innerHTML = '';
    let input_tag = document.querySelector('#count').value;
    let parent = document.querySelector(".container");
    for(let i = 0; i < input_tag; i++) {
        let card = document.createElement('div');
        card.className = 'col-md';
        let author = document.createElement('p');
        author.textContent = data[i].author;
        card.appendChild(author);
        let title = document.createElement('p');
        title.textContent = data[i].title;
        card.appendChild(title);
        let image = document.createElement('img');
        image.src = data[i].img;
        card.appendChild(image);
        parent.appendChild(card);
    }

    document.querySelector('#count').value = '';
})