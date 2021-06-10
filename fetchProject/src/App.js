import './App.css';
import React, { useState, useEffect } from "react"


function getFetchValue() {
  return fetch("https://datausa.io/api/data?drilldowns=Nation&measures=Population").then(function (response) {
    return response.json();
  }).then(function (response) {
    return response.data
  })
}

function DrawHeader(props) {
  return (
    <tr>
      {Object.keys(props.data[0]).map((elem) => {
        return (
          <th key={Math.random()}>{elem}</th>
        )
      })}
    </tr>
  )
}

function DrawBody(props) {
  return (
    Object.keys(props.data).map((key, i) => {
      return <tr>{Object.keys(props.data[key]).map(
        (key1, value) => {
          return (
            <td>
              {props.data[key][key1]}
            </td>
          )
        }
      )}</tr>
    })
  )
}

function App() {
  const [elements, setElements] = useState("1");
  useEffect(() => {
    getFetchValue().then(function (result) { setElements(result) })
  }, [])
  return (
    <table id="customers">
      <tbody>
        <DrawHeader data={elements} />
        <DrawBody data={elements} />
      </tbody>
    </table>
  );
}

export default App;
