import _ from 'lodash';
import './style.css';
import books from './books.json';

var list = document.createElement('div');
list.className = 'list-books';


function main() {
  const formBlock = document.querySelector('#form-block')
  
  formBlock.addEventListener('submit', function (event) {
    event.preventDefault(); 
    let inputValue = document.querySelector('#input-block').value;  
    if (0 < inputValue && inputValue <= books.length) {
      list.innerHTML = '';
      setBooks(inputValue);
    } else {
      alert("Wrong input value.");
    }
  });
  list.addEventListener("click", removeBook);
}

function setBooks(count) {  
  for (let index = 0; index < count; index++) {
    const element = books[index];
    const button = document.createElement('button');
    button.className = 'delete-button';
    const close_icon = document.createElement('i');
    close_icon.className = 'icon fa fa-close';
    button.appendChild(close_icon);

    const title = document.createElement('div');
    title.textContent = element.title;
    title.className = 'title';
    
    const author = document.createElement('div');
    author.textContent = element.author;
    author.className = 'author';
    

    const image = document.createElement('img');
    image.src = element.image;
    image.className = 'image';
    
    const book = document.createElement('div');
    book.className = 'book';
    book.setAttribute('id', index);

    book.appendChild(button);
    book.appendChild(image);
    book.appendChild(title);
    book.appendChild(author);
    list.appendChild(book);
  }
  document.querySelector('body').appendChild(list);
}

function removeBook(event) {
  if (list.childElementCount > 0) {
    while (list.firstChild) {
      list.removeChild(list.firstChild);
    }
  }

  if (evt.target.className === "delete-button") {
    list.removeChild(evt.target.parentElement);
  }
}

main();