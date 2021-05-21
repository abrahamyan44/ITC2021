import * as _ from 'lodash';

//import books from './books.json';
const books = require("./books.json");

console.log('---books', books);

function component() {
    const element = document.createElement('div');
  
    element.innerHTML = _.join(['Hello', 'webpack'], ' ');
  
    return element;
  }
  
  document.body.appendChild(component());