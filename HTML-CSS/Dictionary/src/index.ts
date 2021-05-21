import * as _ from 'lodash';
import books from './books.json';

// console.log(books.length);

const list = document.createElement('div');
list.className = 'list-books';

for (let index = 0; index < books.length; index++) {
  console.log(index);

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
  book.appendChild(title);
  book.appendChild(author);
  book.appendChild(image);

  list.appendChild(book);
}

document.querySelector('.list-books').appendChild(list)






// function component() {
//     const element = document.createElement('div');
  
//     // Lodash, currently included via a script, is required for this line to work
//     element.innerHTML = _.join(['Hello', 'webpack'], ' ');
  
//     return element;
//   }
  
  // document.body.appendChild(component());