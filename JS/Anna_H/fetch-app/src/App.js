import { useEffect, useState } from 'react';
import './App.css';

function App() {
  const [data, setData] = useState([]);

  useEffect (() => {
    fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
    .then(response => response.json())
    .then(response => setData(response.data))
  })

  return (
    <div className="App">
      {data.map((el, i) => {
        return (
          <div className='container'>
            <div key={el['ID Nation']}>{el.Nation}</div>
            <div key={el['ID Year']}>{el.Year}</div>
            <div key={i}>{el.Population}</div>
            <div key={i}>{el['Slug Nation']}</div>
          </div>
        )
      })}
    </div>
  );
}

export default App;
