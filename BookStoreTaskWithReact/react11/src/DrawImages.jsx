import  {valueAfterSubmit} from './Search-Button.jsx'


const array = [
    {
        "author": "Jorge Luis Borges",
        "imageLink": "images/ficciones.jpg",
        "title": "Ficciones"
    },
    {
        "author": "Jane Austen",
        "imageLink": "images/pride-and-prejudice.jpg",
        "title": "Pride and Prejudice"
    },
    {
        "author": "Honor\u00e9 de Balzac",
        "imageLink": "images/le-pere-goriot.jpg",
        "title": "Le P\u00e8re Goriot"
    },
    {
        "author": "Unknown",
        "imageLink": "images/the-book-of-job.jpg",
        "title": "The Book Of Job"
    },
    {
        "author": "Albert Camus",
        "imageLink": "images/l-etranger.jpg",
        "title": "The Stranger"
    },
    {
        "author": "Paul Celan",
        "imageLink": "images/poems-paul-celan.jpg",
        "title": "Poems"
    },
    
    {
        "author": "Unknown",
        "imageLink": "images/one-thousand-and-one-nights.jpg",
        "title": "One Thousand and One Nights"
    },
    {
        "author": "Unknown",
        "imageLink": "images/njals-saga.jpg",
        "title": "Nj\u00e1l's Saga"
    },
    {
        "author": "Giovanni Boccaccio",
        "imageLink": "images/the-decameron.jpg",
        "title": "The Decameron"
    },
    {
        "author": "Louis-Ferdinand C\u00e9line",
        "imageLink": "images/voyage-au-bout-de-la-nuit.jpg",
        "title": "Journey to the End of the Night"
    },
    {
        "author": "Miguel de Cervantes",
        "imageLink": "images/don-quijote-de-la-mancha.jpg",
        "title": "Don Quijote De La Mancha"
    },
    {
        "author": "Geoffrey Chaucer",
        "imageLink": "images/the-canterbury-tales.jpg",
        "title": "The Canterbury Tales"
    },
    {
        "author": "Anton Chekhov",
        "imageLink": "images/stories-of-anton-chekhov.jpg",
        "title": "Stories"
    },
    {
        "author": "Joseph Conrad",
        "imageLink": "images/nostromo.jpg",
        "title": "Nostromo"
    },
    {
        "author": "Charles Dickens",
        "imageLink": "images/great-expectations.jpg",
        "title": "Great Expectations"
    },
    {
        "author": "Chinua Achebe",
        "imageLink": "images/things-fall-apart.jpg",
        "title": "Things Fall Apart"
    },
    {
        "author": "Hans Christian Andersen",
        "imageLink": "images/fairy-tales.jpg",
        "title": "Fairy tales"
    },
    {
        "author": "Unknown",
        "imageLink": "images/the-epic-of-gilgamesh.jpg",
        "title": "The Epic Of Gilgamesh"
    },
    {
        "author": "Emily Bront\u00eb",
        "imageLink": "images/wuthering-heights.jpg",
        "title": "Wuthering Heights"
    }
]; 

function iterate(item) {
    return (
        <div>item.title</div>
    )
}

function Draw() {

    console.log("Anna: ",valueAfterSubmit)
    const arr = array.slice(0,valueAfterSubmit)
    console.log(arr)
    return (
        arr.foreach(iterate)
    )
}

