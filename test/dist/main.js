/*
 * ATTENTION: The "eval" devtool has been used (maybe by default in mode: "development").
 * This devtool is neither made for production nor for readable output files.
 * It uses "eval()" calls to create a separate source file in the browser devtools.
 * If you are trying to read the output file, select a different devtool (https://webpack.js.org/configuration/devtool/)
 * or disable the default devtool with "devtool: false".
 * If you are looking for production-ready output files, see mode: "production" (https://webpack.js.org/configuration/mode/).
 */
/******/ (() => { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ "./src/book.js":
/*!*********************!*\
  !*** ./src/book.js ***!
  \*********************/
/***/ ((__unused_webpack_module, __unused_webpack_exports, __webpack_require__) => {

eval("const data = __webpack_require__(/*! ./books.json */ \"./src/books.json\")\nlet count_form = document.querySelector('.block_container');\nconsole.log(count_form);\ncount_form.addEventListener('submit', function(event) {\n    event.preventDefault();\n    document.querySelector(\".container\").innerHTML = '';\n    let input_tag = document.querySelector('#count').value;\n    let parent = document.querySelector(\".container\");\n    for(let i = 0; i < input_tag; i++) {\n        let card = document.createElement('div');\n        card.className = 'col-md';\n        let author = document.createElement('p');\n        author.textContent = data[i].author;\n        card.appendChild(author);\n        let title = document.createElement('p');\n        title.textContent = data[i].title;\n        card.appendChild(title);\n        let image = document.createElement('img');\n        image.src = data[i].img;\n        card.appendChild(image);\n        parent.appendChild(card);\n    }\n\n    document.querySelector('#count').value = '';\n})\n\n//# sourceURL=webpack://test/./src/book.js?");

/***/ }),

/***/ "./src/books.json":
/*!************************!*\
  !*** ./src/books.json ***!
  \************************/
/***/ ((module) => {

"use strict";
eval("module.exports = JSON.parse('[{\"author\":\"Վարդգես Պետրոսյան\",\"title\":\"Ապրած և չապրած տարիներ\",\"img\":\"https://upload.wikimedia.org/wikipedia/hy/b/b1/%C2%AB%D4%B1%D5%BA%D6%80%D5%A1%D5%AE_%D6%87_%D5%B9%D5%A1%D5%BA%D6%80%D5%A1%D5%AE_%D5%BF%D5%A1%D6%80%D5%AB%D5%B6%D5%A5%D6%80%C2%BB_%D5%A3%D6%80%D6%84%D5%AB_%D5%B7%D5%A1%D5%BA%D5%AB%D5%AF.png\"},{\"author\":\"Ирвин Ялом\",\"title\":\"Когда ницше плакал\",\"img\":\"https://s1.livelib.ru/boocover/1000120239/o/1e12/Irvin_Yalom__Kogda_Nitsshe_plakal.jpeg\"},{\"author\":\"J. R. R. Tolkien\",\"title\":\"The Hobbit\",\"img\":\"https://chilternbookshops.co.uk/wp-content/uploads/2020/05/The-Hobbit.jpg\"},{\"author\":\"Հովհաննես Թումանյան\",\"title\":\"Անբան Հուռի\",\"img\":\"http://www.abrilbooks.com/media/catalog/product/b/2/b204528c-0255-40e4-b546-c7be000ad23c-7.gif\"},{\"author\":\"Immanuel Kant\",\"title\":\"Critique of Practical Reason\",\"img\":\"http://assets.cambridge.org/97805218/96856/cover/9780521896856.jpg\"},{\"author\":\"Paulo Coelho\",\"title\":\"Alquimista\",\"img\":\"https://img.wook.pt/images/o-alquimista-paulo-coelho/MXwxNTIzNzEzOXwxMDcyNTQ3NXwxMzgzNTIzMjAwMDAw/500x\"},{\"author\":\"Վիլյամ Սարոայան\",\"title\":\"Հայրիկ, դու խենթ ես\",\"img\":\"https://i.gr-assets.com/images/S/compressed.photo.goodreads.com/books/1537951793l/42073799._SY475_.jpg\"},{\"author\":\"Ռեյ Բրեդբըրի\",\"title\":\"Ֆարենհայթ 451\",\"img\":\"https://www.armenpress.am/static/tyyy/ghh/1111/txerq/789/jam/tg/qqqqq/ek/turk/halep/tarvankar/l/123/785/hhggg/rrr/cuyc/oscar/sargis_stepanyan/ddd/despanutyun/armenuhi/qax/451.jpg\"},{\"author\":\"Ральфом Лейтон\",\"title\":\"Вы, конечно, шутите, мистер Фейнман! \",\"img\":\"https://images-na.ssl-images-amazon.com/images/I/81R9u2QC30L.jpg\"},{\"author\":\" Стивена Кови \",\"title\":\"Семь навыков высокоэффективных людей \",\"img\":\"https://s1.livelib.ru/boocover/1000712798/200/be77/boocover.jpg\"}]');\n\n//# sourceURL=webpack://test/./src/books.json?");

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
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module can't be inlined because the eval devtool is used.
/******/ 	var __webpack_exports__ = __webpack_require__("./src/book.js");
/******/ 	
/******/ })()
;