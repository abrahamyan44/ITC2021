import logo from './logo.svg';
import './App.css';
import { useState } from 'react';

var selector1 = "g";
var selector2 = "g";

function handleFirstSelectChange (e) {
  selector1 = e.target.value;
  console.log(selector2)
}

function handleSecondSelectChange (e) {
  selector2 = e.target.value;
  console.log(selector2)
}

function getValue(value) {
  console.log(100)
  if ((selector2 === "g" && selector1 === "mg") || (selector2 === "kg" && selector1 === "g") || (selector2 === "Mg" && selector1 === "kg")) {
    return value / 1000;
  }
  if ((selector2 === "kg" && selector1 === "mg") || (selector2 === "Mg" && selector1 === "g")) {
    return value / 1000000;
  }
  if (selector2 === "Mg" && selector1 === "mg") {
    return value / 1000000000;
  }
  if ((selector1 === "g" && selector2 === "mg") || (selector1 === "kg" && selector2 === "g") || (selector1 === "Mg" && selector2 === "kg")) {
    return value * 1000;
  }
  if ((selector1 === "kg" && selector2 === "mg") || (selector1 === "Mg" && selector2 === "g")) {
    return value * 1000000;
  }
  if (selector1 === "Mg" && selector2 === "mg") {
    return value * 1000000000;
  }
  if (selector2 === selector1) {
    return value;
  }
}

function App() {
  const [value, setValue] = useState("0")
  // const number = useState('0')
  return (
    <div className="App">
      <div className="App">
        <form className="form_class">
          <div>
            <input type="number" className="input_num" onChange={e => setValue(e.target.value)} maxLength={11}/><br/>
            <select onChange={handleFirstSelectChange}>
              <option value="mg">Miligram</option>
              <option value="g">Gram</option>
              <option value="kg">Kilogram</option>
              <option value="Mg">Megagram</option>
            </select>
          </div>
          <button className="swap_button"></button>
        </form>
        <div>
          <div className="convert_block">
            <div>
              { getValue(value) }
            </div>
          </div>
          <select onChange={handleSecondSelectChange}>
            <option value="mg">Miligram</option>
            <option value="g">Gram</option>
            <option value="kg">Kilogram</option>
            <option value="Mg">Megagram</option>
          </select>
        </div>
      </div>
    </div>
  );
}

export default App;
