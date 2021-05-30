import React, { useState } from 'react'
import FoodListItem from './FoodListItem'



function FoodList({items, onDelete, dark}) {
    return (
        <div>
            {
                items.map(item => {
                    return (
                        <FoodListItem key={item.id} item={item} dark={dark} onDelete={onDelete}/>
                    )
                }
                )
            }
        </div>
    )
}

export default FoodList;


