import React from 'react'
import {
    H4,
    H5,
    H6,
    Card,
    Body2,
    Caption,
    Subtitle2,
    IconButton,
    withResize,
    ToggleButton,
    ProgressCircular,
} from 'ui-neumorphism'

import {
    Button,
} from 'ui-neumorphism'


function FoodListItem({ item, onDelete, dark }) {
    return (
        <Card dark={dark} style={{
            display: 'flex',
            width: '252px',
           justifyContent: 'space-between',
            
        }} >
            <h4 >{item.text} </h4>
            <Button  onClick={() =>
                onDelete(item)}>X</Button>
        </Card>

    )
}

export default FoodListItem;