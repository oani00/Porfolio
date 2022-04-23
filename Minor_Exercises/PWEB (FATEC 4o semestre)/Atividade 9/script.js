var x = prompt("Insira o primeiro número");
var y = prompt("Insira o segundo número");
var z = prompt("Insira o terceiro número");

retornamaior(x, y, z); //https://www.w3schools.com/jsref/jsref_sort.asp
ordena(x, y, z);

function retornamaior(x, y, z) {

    let numeros = [x, y, z]
    numeros = numeros.sort();
    

    let m = numeros[2];

    alert("O maior número informado é:" + m);

    return m;

}


function ordena(a, b, c) {

    let numeros = [a, b, c]
    numeros = numeros.sort();
    alert("Agora os numeros em ordem crescente")

    let u = numeros[0];
    let i = numeros[1];
    let o = numeros[2];


    alert(" " + u + "<" + i + "<" + o);


}