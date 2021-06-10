import './App.css';
import React, { useEffect, useState } from 'react';




function Fetch() {
  return fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
    .then(function (response) {
      // returns promise
      return response.json();
    }).then(function (output) {
      return output.data;
    });
}

function App() {

  const [result, setResult] = useState("Success!");
  useEffect(() => {
    Fetch().then(function (outputData) {    // ays artahaytutyuny veradardznum e output.data u et qcum outputDatai mej (output.data = outputData)
      setResult(outputData)                 // resultin veragrum enq gago
    })
  }, [])

  return (
    <table>
      <tbody>
        <tr>
          {Object.keys(result[0]).map(i => {  // ajic dzax enq kardum, aysinqn result[0]-i keyn enq vercnum
            return (
              <th>
                {i}
              </th>
            )
          })}
        </tr>
        {Object.values(result).map(j => {
          return (
          <tr> 
            {Object.values(j).map(k => {
              return (
                <td key={Math.random()}>
                  {k}
                </td>
              )
            })}
          </tr>
          )
        })}
      </tbody>
    </table>

  );
}

export default App;
