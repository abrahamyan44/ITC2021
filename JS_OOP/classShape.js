class Shape {
    
    print() {
        console.log( "area is " + this.getArea());
    }

}


class Rectangle extends Shape {
    constructor(length, width) {
        super();
        this.length = length;
        this.width = width;
    }
    getArea() {
        return this.length * this.width;
    }
}

class Triangle extends Shape {
    constructor(a, b, c) {
        super();
        this.a = a;
        this.b = b;
        this.c = c;
    }
     getArea() {
        p = (a + b + c) / 2;
        return Math.sqrt(p * (p - this.a) * (p - this.b) * (p - this.c));
    }

}

class Circle extends Shape {
    constructor(radius) {
        super();
        this.radius = radius;
    }
    getArea() {
        return Math.PI * this.radius * this.radius;
    }

}

let r = new Rectangle(2, 3);
r.print();

