/*
 * ATTENTION: The "eval" devtool has been used (maybe by default in mode: "development").
 * This devtool is neither made for production nor for readable output files.
 * It uses "eval()" calls to create a separate source file in the browser devtools.
 * If you are trying to read the output file, select a different devtool (https://webpack.js.org/configuration/devtool/)
 * or disable the default devtool with "devtool: false".
 * If you are looking for production-ready output files, see mode: "production" (https://webpack.js.org/configuration/mode/).
 */
/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./src/index.ts":
/*!**********************!*\
  !*** ./src/index.ts ***!
  \**********************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

eval("__webpack_require__.r(__webpack_exports__);\n/* harmony import */ var _books_json__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./books.json */ \"./src/books.json\");\n\n// console.log(books.length);\nvar list = document.createElement('div');\nlist.className = 'list-books';\nfor (var index = 0; index < _books_json__WEBPACK_IMPORTED_MODULE_0__.length; index++) {\n    console.log(index);\n    var element = _books_json__WEBPACK_IMPORTED_MODULE_0__[index];\n    var title = document.createElement('div');\n    title.textContent = element.title;\n    title.className = 'title';\n    var author = document.createElement('div');\n    author.textContent = element.author;\n    author.className = 'author';\n    var image = document.createElement('img');\n    image.src = element.image;\n    image.className = 'image';\n    var book = document.createElement('div');\n    book.className = 'book';\n    book.appendChild(title);\n    book.appendChild(author);\n    book.appendChild(image);\n    list.appendChild(book);\n}\ndocument.querySelector('.list-books').appendChild(list);\n// function component() {\n//     const element = document.createElement('div');\n//     // Lodash, currently included via a script, is required for this line to work\n//     element.innerHTML = _.join(['Hello', 'webpack'], ' ');\n//     return element;\n//   }\n// document.body.appendChild(component());\n\n\n//# sourceURL=webpack://dictionary/./src/index.ts?");

/***/ }),

/***/ "./src/books.json":
/*!************************!*\
  !*** ./src/books.json ***!
  \************************/
/***/ ((module) => {

eval("module.exports = JSON.parse('[{\"author\":\"Arthur Conan Doyle\",\"title\":\"A Study in Scarlet\",\"image\":\"images/A_Study_In_Scarlet.jpg\"},{\"author\":\"Arthur Conan Doyle\",\"title\":\"The Valley of Fear\",\"image\":\"images/The_Valley_of_Fear.jpg\"},{\"author\":\"J.R.R. Tolkien\",\"title\":\"The Lord of the Rings\",\"image\":\"images/The_Lord_of_the_Rings.jpg\"},{\"author\":\"F. Scott Fitzgerald\",\"title\":\"The Great Gatsby\",\"image\":\"images/The_Great_Gatsby.jpg\"},{\"author\":\"Markus Zusak\",\"title\":\"The book Thief\",\"image\":\"images/The_Book_Thief.jpg\"},{\"author\":\"J.R.R. Tolkien\",\"title\":\"The Hobbit\",\"image\":\"images/The_Hobbit.jpg\"},{\"author\":\"Louisa May Alcott\",\"title\":\"Little Women\",\"image\":\"images/Little_Women.jpg\"},{\"author\":\"Ray Bradbury\",\"title\":\"Fahrenheit 451\",\"image\":\"images/Fahrenheit_451.jpg\"},{\"author\":\"Charlotte Bronte\",\"title\":\"Jane Eyre\",\"image\":\"images/Jane_Eyre.jpg\"},{\"author\":\"George Orwell\",\"title\":\"Animal Farm\",\"image\":\"images/Animal_Farm.jpg\"},{\"author\":\"Margaret Mitchell\",\"title\":\"Gone with the Wind\",\"image\":\"images/Gone_with_the_Wind.jpg\"},{\"author\":\"E.B. White\",\"title\":\"Charlotte’s Web\",\"image\":\"images/Charlottes_Web.jpg\"},{\"author\":\"William Golding\",\"title\":\"Lord of the Flies\",\"image\":\"images/Lord_of_the_Flies.jpg\"},{\"author\":\"Khaled Hosseini\",\"title\":\"The Kite Runner\",\"image\":\"images/The_Kite_Runner.jpg\"}]');\n\n//# sourceURL=webpack://dictionary/./src/books.json?");

/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	/* webpack/runtime/make namespace object */
/******/ 	(() => {
/******/ 		// define __esModule on exports
/******/ 		__webpack_require__.r = (exports) => {
/******/ 			if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 				Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 			}
/******/ 			Object.defineProperty(exports, '__esModule', { value: true });
/******/ 		};
/******/ 	})();
/******/ 	
/************************************************************************/
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module can't be inlined because the eval devtool is used.
/******/ 	var __webpack_exports__ = __webpack_require__("./src/index.ts");
/******/ 	
/******/ })()
;