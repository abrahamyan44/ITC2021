import './style.css'
import { useState } from 'react'
import Books from './Books';


export default function InputBox() {
    const [count, setCount] = useState(0);
    const [inputValue, setValue] = useState(0);
    console.log('Count = ', count);
    return <>
        <div className="search-box">
            <form id="form-block">
                <input id="input-block" type="text" placeholder="Set books count..."
                    onChange={(event) => {
                        setValue(event.target.value);
                    }}
                />
                <button type="submit" id="input-button"
                    onClick={(event) => {
                        event.preventDefault();
                        setCount(inputValue);
                    }}
                ><i className="fa fa-search"></i></button>
            </form>
        </div>
        <Books count={count} />
    </>
}