import _ from 'lodash';
import books from './books.json';

var list = document.createElement('div');
list.className = 'list-books';

function main() {
  const formBlock = document.querySelector('#form-block')
  
  formBlock.addEventListener('submit', function (event) {
    event.preventDefault(); 
    let inputValue = document.querySelector('#input-block').value;  
    if (0 < inputValue && inputValue <= books.length) {
      removeBook();
      setBooks(inputValue);
    } else {
      alert("Wrong input value.");
    }
  });
}

function setBooks(count) {  
  for (let index = 0; index < count; index++) {
     
    const element = books[index];
    
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
    
    book.appendChild(image);
    book.appendChild(title);
    book.appendChild(author);
    list.appendChild(book);
  }
  document.querySelector('body').appendChild(list);
}

function removeBook() {
  if (list.childElementCount > 0) {
    while (list.firstChild) {
      list.removeChild(list.firstChild);
    }
  }
}

main();