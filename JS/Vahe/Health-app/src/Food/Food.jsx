import React from 'react';
import {useState} from 'react';
import './Food.css';
import { H4, Card, TextArea } from 'ui-neumorphism';

function Food (props) {
    const dark = props.dark;
    const [text, setText] = useState('');
    function handleKeyPress (event) {
        if (event.key === 'Enter') {
            event.preventDefault();
            setText(event.target.value);
        }
    }
    return (
        <div>
            <H4 className='food-title' dark={dark}>Food</H4>
            <Card className='output-text' dark={dark}>
                {text}
            </Card>
            <TextArea label={'Type text...'} className='text' dark={dark} onKeyDown={handleKeyPress}/>
        </div>
    )
}

export default Food;