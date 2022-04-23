const fs = require('fs'); // importa o modulo filesystem
const prompt = require('prompt-sync')();; //importa o modulo prompt-sync
//o modulo prompt-sync deve ser instalado. Para isto: $ npm install prompt-sync
//No meu VScode não rodou, mas direto do terminal não teve problemas.

/* Palíndromo
Palíndromo, do grego palin (novo) e dromo (percurso), é toda palavra ou frase que quando lida ao contrário, 
desconsiderando espaços e pontuações, possui o mesmo sentido. Ex.: “asa”, “ovo”, “A base do teto desaba”. 
Escreva uma função que receba uma string como parâmetro e retorne true caso o valor dessa string seja um palíndromo ou false, 
caso contrário. */

/* 

A lógica é 
    ou copiar -> inverter -> comparar com o original
    ou comparar cada letra com a posição (final-ela)
        asasa
        12345

        1 com 5, 2 com 4, 3 com 3

Como é JS, sabia que tinha algum metodo que invertia a string, e tem, porém eu encontrei em

https: //www.freecodecamp.org/news/two-ways-to-check-for-palindromes-in-javascript-64fea8191fd7/

que se a string passada
for uma frase com espaços e letras maiusculas e minusculas como "A man, a plan, a canal. Panama"
é preciso tratar esses casos.

*/

console.log("----------EX2----------");

let str = prompt("Digite uma string para checar se é um palindromo: ");

function checapalindromo(str) {
    // Step 1. Lowercase the string and use the RegExp to remove unwanted characters from it
    var re = /[\W_]/g; // para tirar tudo o que não for alfanumérico
    
    var lowRegStr = str.toLowerCase().replace(re, '');
    // tira o que não for alfanumerico e coloca em minusculo
    
    var reverseStr = lowRegStr.split('').reverse().join('');
    // cria um array com os caracteres separados em cada espaço, inverte esse array, e depois junta em uma string denovo.
    
    return reverseStr === lowRegStr; // retorna true se forem iguais
}



if (checapalindromo(str)) {
    console.log("------------");
    console.log("é palindromo")
    console.log("------------");
} else {
    console.log("----------------");
    console.log("NAO é palindromo")
    console.log("----------------");
}