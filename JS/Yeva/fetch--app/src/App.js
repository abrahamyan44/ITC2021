import { useEffect, useState } from "react";
import GetFetch from "../src/components/GetFetch";
import GetHeaders from "../src/components/GetHeaders";
import GetTableData from "../src/components/GetTableData";
import "./App.css";


function App() {
  const [data, setData] = useState([]);

  useEffect(() => {
    GetFetch().then((response) => {
      setData(response.data);
    });
  }, []);
  return (
    <table>
      <GetHeaders />
      <GetTableData data={data} />
    </table>
  );
}

export default App;
