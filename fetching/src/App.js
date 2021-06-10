import './App.css';
import { useEffect, useState } from "react";


const fetchData = (setVal) => {
  return fetch("https://datausa.io/api/data?drilldowns=Nation&measures=Population")
    .then((response) => response.json())
    .then((data) =>
      setVal(data.data)
    );
}



function DrawHeader({ fetch_data_header }) {
  return <thead class="styled-table">
    <tr>
      {fetch_data_header && Object.keys(fetch_data_header[0]).map(key => {
        return <td> {key} </td>
      })}
    </tr>

  </thead>

}

function Draw({ fetch_data }) {
  return <tbody class="styled-table">
    {fetch_data && fetch_data.length && fetch_data.map(data => {
      return <tr>
        {Object.keys(data).map(key => {
          console.log('====: ', data[key])
          return <td> {data[key]} </td>
        })}
      </tr>
    })}
  </tbody>
}



function App() {
  const [val, setVal] = useState();
  useEffect(() => {
    fetchData(setVal);
  }, []);
  console.log(val)

  return (
    <div className="App">
      <table class="styled-table">
        <DrawHeader fetch_data_header={val} />
        <Draw fetch_data={val} />
      </table>
    </div>
  );
}

export default App;
