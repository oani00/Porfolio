const fs = require('fs'); // importa o modulo filesystem

var x = 8;
var y = 0;
var a = 5;

while (x > 1) {
    y = x + a;
    x = x / 2;
    a = a + x + y;
}

console.log(a); //103