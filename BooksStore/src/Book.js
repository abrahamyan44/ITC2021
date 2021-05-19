import _ from 'lodash';

import data from '../books.json'

let count_form = document.querySelector('#count-form');
count_form.addEventListener('submit', function (event) {
    event.preventDefault();
    let input_tag = document.querySelector('#input-tag').value;
    let parent = document.querySelector(".parent");
    for (let i = 0; i < input_tag; i++) {
        let card = document.createElement('div');
        card.className = 'book-item';
        card.textContent = data[i].author;
        parent.appendChild(card);

    }
})