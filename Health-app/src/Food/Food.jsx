import React from 'react';
import {useState} from 'react';
import './Food.css';
import NavigatonBar from '../NavigationBar/NavigationBar';
import { H4, Card, TextArea } from 'ui-neumorphism';
import { withRouter } from 'react-router';

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
        <>
        {/* <Card rounded width={300} height={600} dark = {dark} className='food-card'> */}
            <H4 className='food-title'>Food</H4>
            <Card className='output-text'>
                {text}
            </Card>
            <TextArea label={'Type text...'} className='text' onKeyDown={handleKeyPress}/>
            {/* <NavigatonBar selected = {'Food'} dark = {dark}/> */}
        {/* </Card> */}
        </>
    )
}

export default withRouter(Food);