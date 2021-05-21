import React from 'react';
import Book from './Book';
import { useState } from 'react';

export default function Content(props) {
    const [val, setVal] = useState('test VAlue');
    const [bookVal, setbookVal] = useState([{title: 'My book'}, {title: 'My second book'}]);
    // let valu = "HIIIIII";
    return  <div>
        {bookVal.map((el) => <Book t={el.title} />)}
        <input 
        type="text" 
        value = {val} 
        onChange={(e) => {
            console.log(e.target.value);
            setVal(e.target.value);
        }
        }
        />
    {props.con}
    </div>
}