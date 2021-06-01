import React, { useState } from 'react'
import FoodForm from './FoodForm';
import FoodList from './FoodList';
import useLocalStorage from './uselocaleStorage'


function Food({dark}) {
   const [items, setTodos] = useLocalStorage(' ', [])

    return (
        <div>
            <FoodForm dark={dark} onAdd={(text) => {
                if (items.length < 10 && text.length !== 0) {
                    setTodos(
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
                setTodos(items.filter((t) =>
                    t.id !== todo.id
                ))
            }} />
        </div>
    )
}
export default Food;