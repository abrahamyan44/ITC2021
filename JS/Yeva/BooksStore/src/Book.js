import _ from 'lodash';
import data from './books.json'

const count_form = document.querySelector('#count-form');

count_form.addEventListener('submit', function (event) {
    event.preventDefault();
    const input_tag = document.querySelector('#input-tag').value;
    const parent = document.querySelector(".parent");
    parent.innerHTML = "";

    for (let i = 0; i < input_tag; i++) {
        const card = document.createElement('div');
        const image = document.createElement('img');
        const author = document.createElement('p');
        const title = document.createElement('p');
        const deleteButton = document.createElement('button');

        card.className = 'book-item';
        image.className = 'img-item';
        author.className = 'author-tag';
        title.className = 'title-tag';
        deleteButton.className = 'delete-button';

        author.textContent = data[i].author;
        title.textContent = data[i].title;
        image.src = data[i].path;
        deleteButton.innerHTML = 'X';

        parent.appendChild(card);
        card.appendChild(deleteButton);
        card.appendChild(author);
        card.appendChild(title);
        card.appendChild(image);

        document.querySelector('#input-tag').value = '';
    }
})