class Shape {
    constructer() {

    }
	// GetArea = function() {};
	print() {
		console.log( this.GetArea() ); 
	}
}


class Rectangle extends Shape {
    constructer (width, lenght) {
        super();
		this.width = width;
		this.lenght = lenght;
    }
	
	GetArea() {
			let area =  this.width * this.lenght;
			return area;
	}
}


class Triangle  extends Shape {
    constructer (base, height) {
		this.base = base;
		this.height = height;
    }

	GetArea() {
		let area = this.base * this.heigt / 2;
		return area;
	}
}


class Circle  extends Shape {
    constructer (radius) {
		this.radius = radius;
    }
		
	GetArea() {
		let area = math.pi * this.radius * this.radius;
		return area;
	}
}

let r = new Rectangle(4, 6);
r.print();