import {useState} from 'react'
import Book from './Book'

export default function Body(props) {
    const [title, setTitle] = useState();
    const [books, setBooks] = useState(
        [{title: 'first book'}]
    
    );

    return <div>
        {books.map(b => {
            return <Book title = {b.title}/>
        })}
        <input 
            type="text" 
            value = {title}
            onChange={(e) => {
                console.log(e.target.value);
                setTitle(e.target.value);
            }}    
        />
        {props.context}
    </div>
}