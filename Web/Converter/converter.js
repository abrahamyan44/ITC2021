const selectId = document.querySelector("#select-id");
const tables = document.querySelector(".tables")
const objOfMass = {a1: "b1", a2: "b2", a3: "b3"};
const objOfArea = {c1: 1, c2: 2, c3: 3};

selectId.addEventListener('change', function(evt){
   const value = evt.target.value;
   if (value === '1') {
      CreateTables(objOfMass)
   } else if (value === '2') {
      CreateTables(objOfArea)
  }
})

function CreateTables(obj){
    tables.innerHTML=("");
    const div1 = document.createElement("div");
    const div2 = document.createElement("div");
    //const icon = document.createElement("i");

    div1.className = "div-1";
    div2.className = "div-2";
   // icon.className = "icon";

    const select1 = document.createElement("select")
    const select2 = document.createElement("select")

    const input1 = document.createElement("input")
    const input2 = document.createElement("input")


    for (let key in obj) {
        const option = document.createElement("option");
        option.value = key;
        option.text = key;
        select1.appendChild(option);
    }

    Object.values(obj).forEach(function(val){
        const option = document.createElement("option");
        option.value = val;
        option.text = val;
        select2.appendChild(option);
    })

    //var e = document.createElement("h5");
    //e.append('<i class="fa fa-trash-o" aria-hidden="true"></i>');
    //e.innerHTML = '<li>This<i class="fa fa-cross"></i></li>'

    div1.appendChild(input1)
    div2.appendChild(input2)
    div1.appendChild(select1)
    div2.appendChild(select2)
    tables.appendChild(div1)
    //tables.appendChild(e)
    tables.appendChild(div2)
}