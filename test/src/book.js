const data = require('./books.json')
console.log('aaa')
let count_form = document.querySelector('.block_container');
console.log(count_form);
count_form.addEventListener('submit', function(event) {
    event.preventDefault();
    document.querySelector(".container").innerHTML = '';
    let input_tag = document.querySelector('#count').value;
    let parent = document.querySelector(".container");
    console.log(parent);
    for(let i = 0; i < input_tag; i++) {
        let card = document.createElement('div');
        let author = document.createElement('p');
        author.textContent = data[i].author;
        card.appendChild(author);
        let title = document.createElement('p');
        title.textContent = data[i].title;
        card.appendChild(title);
        let image = document.createElement('img');
        image.src = data[i].img;
        card.appendChild(image);
        let bookButton = document.createElement('span');
        bookButton.className = 'book_button';
        let buy = document.createElement('button');
        buy.textContent = "Buy";
        bookButton.appendChild(buy);
        let Delete = document.createElement('button');
        Delete.textContent = "Delete";
        bookButton.appendChild(Delete);
        container.addEventListener('click', function(event) {
            card.appendChild(bookButton);
            card.className = 'col-md';
            parent.appendChild(card);
        }
    document.querySelector('#count').value = '';
}})