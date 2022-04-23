var res   = 1;
var nota1 = 1;
var nota2 = 1;
var nota3 = 1;

var nota1 = prompt("Insira a nota 1");
var nota1 = parseFloat(nota1);
var nota2 = prompt("Insira a nota 2");
var nota2 = parseFloat(nota2);
var nota3 = prompt("Insira a nota 3");
var nota3 = parseFloat(nota3);

res = nota1 + nota2 + nota3;
res = (nota1 + nota2 + nota3) / 3;

alert("A media das tres notas é: " + res);