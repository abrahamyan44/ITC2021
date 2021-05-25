// import {useSteat} from 'react'
import listBooks from './books.json'
import Book from './Book'
import './style.css'


export default function Books(props) {
    // const count = props.value;
    // console.log(listBooks);
    const selectedBooks = listBooks.slice(0, props.count)
    console.log('Count =', props.count);
    return <>
        <div className='list-books'>
            {selectedBooks.map(book => {
                return (
                    <Book   image = {book.image}
                            title = {book.title}
                            author = {book.author}
                    />
                )
            })}
        </div>
    </>
}
