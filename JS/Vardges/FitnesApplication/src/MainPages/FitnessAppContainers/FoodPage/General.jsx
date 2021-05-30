import React, { useState } from 'react'
import FoodForm from './FoodForm';
import FoodList from './FoodList';


function Food({dark}) {
    const [items, SetItems] = useState([
    ]);

    return (
        <div>
            <FoodForm dark={dark} onAdd={(text) => {
                if (items.length < 10 && text.length !== 0) {
                    SetItems(
                        [
                            ...items,
                            {
                                id: Math.random(),
                                text: text
                            }
                        ],
                    );
                }
            }} />
            <FoodList  dark={dark} items={items} onDelete={(todo) => {
                SetItems(items.filter((t) =>
                    t.id !== todo.id
                ))
            }} />
        </div>
    )
}
export default Food;