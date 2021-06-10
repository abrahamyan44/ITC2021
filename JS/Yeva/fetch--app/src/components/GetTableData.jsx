function GetTableData(props) {
  return (
    <>
      {props.data.map((el) => {
        return (
          <tr>
            <td>{el["ID Nation"]}</td>
            <td>{el.Nation}</td>
            <td>{el.Year}</td>
            <td>{el.Population}</td>
            <td>{el["Slug Nation"]}</td>
          </tr>
        );
      })}
    </>
  );
}

export default GetTableData;