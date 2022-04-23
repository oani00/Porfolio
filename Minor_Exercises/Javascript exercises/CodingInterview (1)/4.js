//Oaní da Silva da Costa
//Questão 4


const fs = require('fs'); // importa o modulo filesystem



var a = 0;
var b = 0;
var c = 0;
var d = 0;
var e = 0;
var f = 0;


for (var i = 0; i < 10; i++) {

    a = (i % 2);
    b = ((i + 1) % 2);
    c = (i % 2);
    d = ((i + 1) % 2);
    e = (i % 2);
    f = ((i + 1) % 2);
    // x = i % 2;
    console.log(a + "" + b + "" + c + "" + d + "" + e + "" + f); //procurei mas não achei um jeito de tirar o newline do console.log

    // if (i % 5 == 0) {
    //     console.log("\n")
    // }

}