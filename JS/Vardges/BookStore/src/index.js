import _ from 'lodash';
import data from '../resources/books.json'

const formBlock = document.querySelector('#form-block');
const book = document.querySelector('#bookdiv');
const globalDiv = document.getElementsByClassName('a');

function createElements(type, newClassName) {
    const variableName = document.createElement(type);
    variableName.className = newClassName;
    return variableName;
}

function initializedBookElements(index, bookElements){
    bookElements.titleH.textContent = data[index].title;
    bookElements.authorH.textContent = data[index].author;
    bookElements.elem.src = data[index].imageLink;
    bookElements.button.innerHTML = "Delete";
}

function appendBook(book, index) {
    const bookElements = createBookElements();
    const column = createElements('div', 'column');
    initializedBookElements(index,bookElements);
    let key;
    for (key in bookElements) {
        column.appendChild(bookElements[key])
        console.log(key);
    }
    book.appendChild(column);
}

function createBookElements() {
    return {
        titleH: createElements('h1', 'title'),
        authorH: createElements('h2', 'author'),
        elem: createElements('img', 'img'),
        button: createElements('button', 'delete')
    }
}


formBlock.addEventListener('submit', function (event) {
    event.preventDefault();
    book.innerHTML = "";
    const inputValue = document.querySelector('#input-block').value;
    if (inputValue > 0 && inputValue < 20) {
        document.querySelector("#input-block").value = "";
        for (let i = 0; i < inputValue; ++i) {
            appendBook(book, i);
            // book.appendChild();
        }
        globalDiv.appendChild = book;

    };
    document.querySelector("#input-block").value = "";
});


book.addEventListener('click', function (event) {
    if (event.target.className === 'delete') {
        const parentElement = event.target.parentElement;
        book.removeChild(parentElement);
    }
})
