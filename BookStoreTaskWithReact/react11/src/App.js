import React from 'react'
import { DrawSearchButton, Draw } from './Search-Button.jsx'
import './App.css';
import ReactDOM from 'react-dom'
import background from './wood.jpg'

function App() {
  return (
    <div>
      <div className="header">Book Store</div>
      <DrawSearchButton />
    </div>

  );
}


export default App;
