import logo from './logo.svg';
import './App.css';
import { useState, useEffect } from 'react'

const data = (setData) => {
  fetch("https://datausa.io/api/data?drilldowns=Nation&measures=Population").then(function (response) {
    return response.json();
  }).then(function (response) {
    setData(response.data);
  })
}

function DrawHead({ fetch_data }) {
  return <thead> <tr>
    {fetch_data && fetch_data.length && Object.keys(fetch_data[0]).map(key => {
      return <td>{key}</td> 
    })}
  </tr> </thead>
}

function DrawBody({ fetch_data }) {
  return <tbody>
    {fetch_data && fetch_data.length && fetch_data.map(data => {
      return <tr>
        {Object.keys(data).map(key => {
          return <td> {data[key]} </td>
        })}
      </tr>
    })}
  </tbody>
}

function App() {
  const [fetch_data, setData] = useState([]);
  useEffect(() => {
    data(setData);
  }, []);
  return (
    <div className="App">
      <table className="styled-table">
        <DrawHead fetch_data={fetch_data} />
        <DrawBody fetch_data={fetch_data} />
      </table>
    </div>
  );
}

export default App;