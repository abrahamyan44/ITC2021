import React, { useState } from 'react'

import {
    Button,
} from 'ui-neumorphism'


function FoodForm({ onAdd }) {
    const [text, setText] = useState("");
    const [value, setValue] = useState()
    return (
        <div>
            <form style={{ marginBlock: '30px' }} onSubmit={(ev) => {
                ev.preventDefault();
                setValue(text);
                onAdd(text);
                setText("")
            }}>
                <input type="text" value={text} maxLength={20} onChange={(ev) => {
                    if (ev.target.value !== ' ')
                        setText(ev.target.value)
                }} />
                <Button>Add</Button>
            </form>
        </div>
    )
}

export default FoodForm;
