function retanguloX(x, y) {
    this.x = x;
    this.y = y;


    this.calcArea = function () {
        return x * y;
    }

}

var retangulo1 = new retanguloX(2, 2);

//exemplo
alert("Area de um retangulo 2x2 = " + retangulo1.calcArea())