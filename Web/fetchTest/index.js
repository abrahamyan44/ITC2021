
//let a = fetch('./some.json')
fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
  .then(
    function(response) {
      if (response.status !== 200) {
        console.log('Looks like there was a problem. Status Code: ' +
          response.status);
        return;
      }

      // Examine the text in the response
      response.json().then(function(data) {
        console.log(data);
        console.log("ok");
      });
    }
  )
  .catch(function(err) {
    console.log('Fetch Error :-S', err);
  });
  