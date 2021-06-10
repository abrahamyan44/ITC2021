function GetFetch() {
  return fetch(
    "https://datausa.io/api/data?drilldowns=Nation&measures=Population"
  ).then((response) => {
    return response.json();
  });
}

export default GetFetch;