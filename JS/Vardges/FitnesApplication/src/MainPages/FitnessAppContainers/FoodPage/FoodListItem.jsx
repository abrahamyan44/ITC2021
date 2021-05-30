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

function FoodListItem({ item, onDelete, dark }) {
    return (
        <Card dark={dark} style={{
            // fill:'currentcolor',
            display: 'flex',
            width: '252px',
            justifyContent: 'space-between',
            
        }} >
            <input  dark={dark} type="checkbox" />
            <h4 dark={dark}>{item.text} </h4>
            <button flet dark={dark} onClick={() =>
                onDelete(item)}>X</button>
        </Card>

    )
}

export default FoodListItem;