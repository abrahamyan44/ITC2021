class Products {
    constructor() {
        this.classNameActive = 'products-element__btn_active';
        this.labelAdd    = 'Add to Cart';
        this.labelRemove = 'Remove from Cart';
        this.itemsLimit  = 15;
    }

    handleSetLocationStorage(element, id) {
        const { pushProduct, products } = localStorageUtil.putProducts(id);
        
        if (pushProduct) {
            element.classList.add(this.classNameActive);
            element.innerHTML = this.labelRemove;
        } else {
            element.classList.remove(this.classNameActive);
            element.innerHTML = this.labelAdd;
        }

        headerPage.render(products.length)
    }

    handleRemoveItem(remove_btn) {  // terrible code here!!!
        remove_btn.parentNode.parentNode.removeChild(remove_btn.parentNode);
    }

    render() {
        const productsStore = localStorageUtil.getProducts();
        let htmlCatalog = '';

        for(let i = 0; i < Math.min(this.itemsLimit, CATALOG.length); ++i) {
            let removeText = "remove";
            let id     = CATALOG[i].id;
            let title  = CATALOG[i].title;
            let author = CATALOG[i].author;
            let image  = CATALOG[i].image;
        
            let activeClass = '';
            let activeText = '';

            if (productsStore.indexOf(id) === -1) {
                activeText = this.labelAdd;
            } else {
                activeClass = ' ' + this.classNameActive;
                activeText = this.labelRemove;
            }

            htmlCatalog += `
                <li class="products-element">   
                    <span class="products-element__remove-btn"
                        onclick="productsPage.handleRemoveItem(this)">${removeText}</span>
                    <span class="products-element__title">${title}</span>
                    <span class="products-element__author">${author}</span>
                    <img  class="products-element__image" 
                        src="${image}" 
                        alt="${title}"
                    />
                    <div class="products-element__btn${activeClass}" 
                        onclick="productsPage.handleSetLocationStorage(this, '${id}');">
                        ${activeText}
                    </div>
                </li>
            `;
        };

        const html = `
            <ul class="products-container"> 
                ${htmlCatalog} 
            </ul>
        `;

        ROOT_PRODUCTS.innerHTML = html;
    }
}

const productsPage = new Products();
