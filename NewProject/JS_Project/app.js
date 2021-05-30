const menu = document.querySelector('#mobile-menu');
const menuLinks = document.querySelector('.navbar_menu');

const mobileMenu = () => {
    menu.classList.toggle('is-active');
    menuLinks.classList.toggle('active');
};

menu.addEventListener('click', mobileMenu);


var data = {
    "images": [{
        "name": "Edison",
        "bannerImg1": "http://i.stack.imgur.com/HXS1E.png?s=32&g=1"
    },
    {
        "bannerImg1": "http://i.stack.imgur.com/8ywqe.png?s=32&g=1"
    }]
};


data.images.forEach(function (obj) {
    var img = new Image();
    img.src = obj.bannerImg1;
    img.setAttribute("class", "banner-img");
    // img.setAttribute("alt", "effy");
    for (var i = 0; i < data.length; i++) {
        document.getElementById("image-container").appendChild(img);
    }
});


data.images.forEach.call(obj, function (obj) {
    var img = new Image();
    img.src = obj.bannerImg1;
    img.setAttribute("class", "banner-img");
    img.setAttribute("alt", "effy");
    for (var i = 0; i < obj.length; i++) {
        localTime = updateLocalTime(obj[i].innerHTML);
        obj[i].innerHTML = localTime
    }
    document.getElementById("img-container").appendChild(img);
});


//   Array.prototype.forEach.call(timestamps, function (timestamp) {
//     localTime = updateLocalTime(timestamp.innerHTML);
//     timestamp.innerHTML = localTime;
//   });

//   for (var i = 0; i < timestamps.length; i++) {
//     localTime = updateLocalTime(timestamps[i].innerHTML);
//     timestamps[i].innerHTML = localTime
//   }


data.images.forEach(function (obj) {
    var img = new Image();
    img.src = obj.bannerImg1;
    img.setAttribute("class", "banner-img");
    img.setAttribute("alt", "effy");
    document.getElementById("img-container").appendChild(img);
});


var myJSON = '{"name":"John", "age":31, "city":"New York"}';
var myObj = JSON.parse(myJSON);
document.getElementById("demo").innerHTML = myObj.name;