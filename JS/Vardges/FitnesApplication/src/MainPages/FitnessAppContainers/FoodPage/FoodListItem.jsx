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
            {/* <input   type="checkbox"  onClick={()=>{
                item.completed = !item.completed;
            }
            }/> */}
            <h4 >{item.text} </h4>
            <button  onClick={() =>
                onDelete(item)}>X</button>
        </Card>

    )
}

export default FoodListItem;