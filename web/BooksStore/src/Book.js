import _ from 'lodash';

import data from '../books.json'

const count_form = document.querySelector('#count-form');

count_form.addEventListener('submit', function (event) {
    event.preventDefault();
    const input_tag = document.querySelector('#input-tag').value;
    const parent = document.querySelector(".parent");
    parent.innerHTML = " ";
    for (let i = 0; i < input_tag; i++) {
        const card = document.createElement('div');
        const image = document.createElement('img');
        const author = document.createElement('p');
        const title = document.createElement('p');

        card.className = 'book-item';
        image.className = 'img-item';
        author.className = 'author-tag';
        title.className = 'title-tag';

        author.textContent = data[i].author;
        title.textContent = data[i].title;
        image.src = data[i].path;

        parent.appendChild(card);
        card.appendChild(author);
        card.appendChild(title);
        card.appendChild(image);

        document.querySelector('#input-tag').value = '';

        image.onmouseover = 'bigImg(this)';
        image.onmouseout = 'normalImg(this)';

        function bigImg(x) {
            x.style.height = "300px";
            x.style.width = "200px";
        }
          
        function normalImg(x) {
            x.style.height = "270px";
            x.style.width = "170px";
        }
    }
})

// image.onmouseover = function(event) {