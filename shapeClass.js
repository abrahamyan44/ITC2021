class Shape {
    constructor(yourShape) {
        this.name = yourShape;
    }
    print() {
        console.log(this.name + this.getArea());
    }
}

class Rectangle extends Shape {
    constructor(height, width) {
        super("Rectangle: ");
        this.height = height;
        this.width = width;
    }
    getArea() {
        return this.height * this.width;
    }
}

class Triangle extends Shape {
    constructor(a, b, c) {
        super("Triangle: ");
        this.edge1 = a; // es obyektis edge1 memberin veragri a
        this.edge2 = b;
        this.edge3 = c;
    }
    getArea() {
        let perimeter = (this.edge1 + this.edge2 + this.edge3) / 2;
        let S = perimeter * (perimeter - this.edge1) * (perimeter - this.edge2) * (perimeter - this.edge3);
        return Math.sqrt(S);
    }
}

// Erb getArea() funkcian verasahmanum enq tarber classeri hamar tarber kerp da kochvum e polymorphism

class Circle extends Shape {
    constructor(radius) {
        super("Circle: ");
        this.radius = radius;
    }
    getArea() {
        return 3.14 * this.radius * this.radius;
    }
}

let myRectangle = new Rectangle(3, 4);
let myTriangle = new Triangle(10, 20, 15);
let myCircle = new Circle(5); // Circle tipi obyekti hamar new-ov tex enq vercnum

myRectangle.print();
myTriangle.print();
myCircle.print();
