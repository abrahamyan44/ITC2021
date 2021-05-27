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

formBlock.addEventListener("submit", function (event) {
    event.preventDefault();
    blockDiv.innerHTML = "";
    const inputValue = document.querySelector("#input-block").value;

    for (let i = 0; i < inputValue; ++i) {
        const bookData = data[i];
        const bookDiv = createBookSection();
        const infoDiv = createInfoSection();
        const deleteSection = createDeleteSection();
        const authorSection = createAuthorSection(bookData);
        const titleSection = createTitleSection(bookData);
        const imageSection = createImageSection(bookData);
        const addToCardSection = createAddToCardSection();
        infoDiv.appendChild(authorSection);
        infoDiv.appendChild(titleSection);
        bookDiv.appendChild(deleteSection);
        bookDiv.appendChild(infoDiv);
        bookDiv.appendChild(imageSection);
        bookDiv.appendChild(addToCardSection);
        blockDiv.appendChild(bookDiv);
        document.querySelector("#input-block").value = "";
    }
});

blockDiv.addEventListener("click", function (event) {
    if (event.target.className === "delete") {
        const parentElement = event.target.parentElement;
        blockDiv.removeChild(parentElement);
    } else {
        console.log("clicked");
    }
});