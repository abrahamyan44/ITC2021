// data = [
//     {"author": "Yuval Noah" , "title": "A History of Tomorrow", "path": "https://newmag.am/public/home/assets/img/books/thumbs/2cc9ad900e3e0df25f20cc9b652a5889.jpg"},
//     {"author": "Yuval Noah" , "title": "A History of Tomorrow", "path": "https://newmag.am/public/home/assets/img/books/thumbs/2cc9ad900e3e0df25f20cc9b652a5889.jpg"}
// ]
const data = require('../src/books.json')
// import data from '../src/books.json';
window.onload = function() {
console.log('aaa')
let count_form = document.querySelector('.block_container');
console.log(count_form);
count_form.addEventListener('submit', function(event) {
    event.preventDefault();
    let input_tag = document.querySelector('#count').value;
    console.log(input_tag);
    let parent = document.querySelector(".container");
    console.log(parent);
    for(let i = 0; i < input_tag; i++) {
        let card = document.createElement('div');
        card.textContent = data[i].author;
        parent.appendChild(card);
    }
})}