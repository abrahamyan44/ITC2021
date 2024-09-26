import _ from 'lodash';
import data from './bookList.json'
const blocdiv = document.querySelector('.book-block');
const formBlock = document.querySelector('#form-block');

const BOOK_COUNT = 20;

blocdiv.addEventListener('click', function (event) {
    event.preventDefault();
    if (event.target.className === "delete") {
        event.target.parentElement.remove(event.target.parentElement);
    }

})

function getImage(url) {
    const image = document.createElement("img");
    image.style.width = '270px';
    image.style.height = '300px';
    image.src =url;
    return image;
}

function getAuthor(author) {
    const pauthor = document.createElement('p');
    pauthor.className = 'author';
    pauthor.textContent = author;
    return author;
}

function getTitle(title) {
    const ptitle = document.createElement('p');
    ptitle.className = 'title';
    ptitle.textContent = title;
    return title;
}

function createDeleteButton() {
    const delete_button = document.createElement('button');
    delete_button.type = 'submit';
    delete_button.className = 'delete';
    delete_button.textContent = 'Delete';
    return delete_button;
}

function createSection(pauthor, ptitle, image, delete_button) {
    const imagediv = document.createElement('blocdiv');
    const bookdiv = document.createElement('blocdiv');
    bookdiv.className = 'book-section';
    const infodiv = document.createElement('blocdiv');
    infodiv.className = 'book-info';
    imagediv.appendChild(image);
    infodiv.appendChild(pauthor);
    infodiv.appendChild(ptitle);
    bookdiv.appendChild(infodiv);
    bookdiv.appendChild(imagediv);
    bookdiv.appendChild(delete_button);
    blocdiv.appendChild(bookdiv);
}

document.querySelector('.searchInput').value = '';
formBlock.addEventListener('submit', function (event) {
    event.preventDefault();
    blocdiv.innerHTML = "";
    let inputValue = document.querySelector('.searchInput').value;
    
    if (inputValue > BOOK_COUNT){
        document.querySelector('.searchInput').value = BOOK_COUNT;
        inputValue = BOOK_COUNT;
    }
    
    console.log(inputValue);
    for (let i = 0; i < inputValue; ++i) {
        const pauthor = getAuthor(data[i].author);
        const ptitle = getTitle(data[i].title);
        const image = getImage(".." + data[i].image_URL);
        const delete_button = createDeleteButton();
        createSection(pauthor, ptitle, image, delete_button);
    }
   
});
