import React, { useState } from 'react';
import { Card, CardContent, H4, Button } from 'ui-neumorphism';
import NotificationItem from '../componenets/NotificationItem/NotificationItem';
import Navigation from '../componenets/Navigation/Navigation.jsx';
import './Food.css';

function Food(props) {

    const [inputVal, setInputVal] = useState('');
    const [listArr, setListArr] = useState([]);

    function handleChange(e) {
        setInputVal(e.target.value);
    }

    function handleClick() {
        inputVal !== '' && setListArr([...listArr, inputVal]);
    }

    return (
        <Card rounded width={340} height={610} className='card'>
            <CardContent>
                <H4 className='food-card-title'>Food</H4>
                <input value={inputVal} className='foodName' placeholder="food name" onChange={handleChange} />
                <Button rounded onClick={handleClick}>Add</Button>
                <div className='food-card-content'>
                    {listArr.map((el, i) => (
                        <NotificationItem
                            title={el}
                            subtitle={`${i + 1}th food`}
                        />
                    ))}
                </div>
            </CardContent>
            <Navigation />
        </Card>
    )
}

export default Food;