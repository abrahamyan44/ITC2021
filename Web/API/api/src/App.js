import { useState, useEffect } from "react";
import { Table } from "react-bootstrap";
// import "./App.css";
import 'bootstrap/dist/css/bootstrap.min.css';


function App() {
  const [data, setData] = useState([]);
  useEffect(() => {
    fetch("https://datausa.io/api/data?drilldowns=Nation&measures=Population")
      .then(function (response) {
        return response.json();
      })
      .then(function (response) {
        setData(response.data);
      });
  }, []);

  return (
    // <div className="App">
      <Table striped bordered hover>
        <tbody>
          <td>
            Nation
          </td>
          <td>
            Year
          </td>
          <td>
            Population
          </td>
          <td>
            Slug Natiuon
          </td>
          {data.map(function (el) {
            return (
              <tr>
                <td>
                  {el.Nation}
                </td>
                <td>
                  {el.Year}
                </td>
                <td>
                  {el.Population}
                </td>
                <td>
                  {el["Slug Nation"]}
                </td>
              </tr>
              // <div id="row">
              //   <span className="element1">
              // {el.Nation} {el.Year} {el.Population} {el["Slug Nation"]}
              //   </span>
              // </div>
            );
          })}
        </tbody>
      </Table>
    // </div>
  );
}

export default App;
