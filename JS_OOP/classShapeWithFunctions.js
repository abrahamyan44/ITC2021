function Shape() {
}

Shape.prototype.print = function () {
    console.log(this.getArea());
}

function Triangle(a, b, c) {
    this.a = a;
    this.b = b;
    this.c = c;
}

Triangle.prototype.getArea = function () {
    p = (this.a + this.b + this.c) / 2;
    return Math.sqrt(p * (p - this.a) * (p - this.b) * (p - this.c));
}
Triangle.prototype.__proto__ = Shape.prototype;
///////////////////////////////////////////////

function Rectangle(length, width) {
    
    this.length = length;
    this.width = width;
}

Rectangle.prototype.getArea = function () {
    return this.length * this.width;
}

Rectangle.prototype.__proto__ = Shape.prototype;
//////////////////////////////////////////////
function Circle(radius) {
    this.radius = radius;
}

Circle.prototype.getArea = function () {
    return Math.PI * this.radius * this.radius;
}
Circle.prototype.__proto__ = Shape.prototype;


let triangle = new Triangle(2, 3, 4);
let rect = new Rectangle(2, 3);
let circle = new Circle(8);
triangle.print();
rect.print();
circle.print();

