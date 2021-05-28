function render() {

    const productsStore = localStorageUtil.getProducts();

    headerPage.render(productsStore.length);
    productsPage.render();

}

let CATALOG=[];

// Remote server request imitation
fetch('server/catalog.json')
    .then(res => res.json())
    .then(body => {
        CATALOG = body;
        console.log(CATALOG);
        console.log('xuy');
        render();
    })
    .catch(error => {
        console.log(error);
    });