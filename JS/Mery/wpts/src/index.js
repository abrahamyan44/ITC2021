import _ from "lodash";
import data from "../resources/bookInfo.json";

const blockDiv = document.querySelector(".book-block");
const formBlock = document.querySelector("#form-block");

function createBookSection() {
    const bookDiv = document.createElement("div");
    bookDiv.className = "book-section";
    return bookDiv;
}

function createInfoSection() {
    const infoDiv = document.createElement("div");
    infoDiv.className = "book-info";
    return infoDiv;
}

function createDeleteSection() {
    const spanDelete = document.createElement("span");
    spanDelete.className = "delete";
    spanDelete.textContent = "X";

    return spanDelete;
}

function createAuthorSection(data) {
    const pAuthor = document.createElement("p");
    pAuthor.className = "author";
    pAuthor.textContent = data.author;

    return pAuthor;
}

function createTitleSection(data) {
    const pTitle = document.createElement("p");
    pTitle.className = "title";
    pTitle.textContent = data.title;

    return pTitle;
}

function createImageSection(data) {
    const imageDiv = document.createElement("div");
    const image = document.createElement("img");
    image.className = "image";
    image.src = data.src;

    imageDiv.appendChild(image);

    return imageDiv;
}

function createAddToCardSection() {
    const spanValue = document.createElement("span");
    spanValue.className = "value";
    spanValue.textContent = "Add to card";

    return spanValue;
}
function createAllSections(index) {
    const bookData = data[index];

    return {
        infoDiv: createInfoSection(),
        bookDiv: createBookSection(),
        deleteSection: createDeleteSection(),
        authorSection: createAuthorSection(bookData),
        titleSection: createTitleSection(bookData),
        imageSection: createImageSection(bookData),
        addToCardSection: createAddToCardSection(),
    }
}
function appendAllSections(book) {
    book.infoDiv.appendChild(book.authorSection);
    book.infoDiv.appendChild(book.titleSection);
    book.bookDiv.appendChild(book.deleteSection);
    book.bookDiv.appendChild(book.infoDiv);
    book.bookDiv.appendChild(book.imageSection);
    book.bookDiv.appendChild(book.addToCardSection);
    blockDiv.appendChild(book.bookDiv);
}

formBlock.addEventListener("submit", function (event) {
    event.preventDefault();
    blockDiv.innerHTML = "";
    const inputValue = document.querySelector("#input-block").value;

    for (let i = 0; i < inputValue; ++i) {
        const book = createAllSections(i);
        appendAllSections(book);
    }
    document.querySelector("#input-block").value = "";
});

blockDiv.addEventListener("click", function (event) {
    if (event.target.className === "delete") {
        const parentElement = event.target.parentElement;
        blockDiv.removeChild(parentElement);
    } else {
        console.log("clicked");
    }
});
