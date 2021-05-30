import React,{useState} from 'react'

function FoodForm({onAdd}) {
    const [text, setText] = useState("");
    const [value, setValue] = useState()
    return (
        <div>
            <form  style={{marginBlock: '30px'}} onSubmit={(ev) => {
                ev.preventDefault();
                if(ev.target.value !== ' ')
                setValue(text);
                onAdd(text);
                setText("")
            }}>
                <input type="text" value={text}  maxLength={20} onChange={(ev) => {
                    setText(ev.target.value)
                }} />
                <button>Add</button>
            </form>
        </div>
    )
}

export default FoodForm;
