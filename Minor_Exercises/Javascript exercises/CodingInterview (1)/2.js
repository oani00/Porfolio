//Oaní da Silva da Costa
//Questão 2

//regra 1:
//https://www.quora.com/What-is-the-next-number-8-4-12-6-18-27

//Regra 2: 
// https: //www.wolframalpha.com/widgets/view.jsp?id=739465804a0e17d2a47c9bc9c805d60a
//https://oeis.org/A050196

// Escolhi esta regra:
//https://testbook.com/question-answer/find-the-missing-number-in-the-sequence8--609528dd7b5fc903f25ff577

const fs = require('fs'); // importa o modulo filesystem do Node

var a = 8;
var b = 4;
var c = 0;

var soma1 = 2; //https://testbook.com/question-answer/find-the-missing-number-in-the-sequence8--609528dd7b5fc903f25ff577
var soma2 = 4;
var soma22 = 2;
var vez = 0;


console.log(a); //valores iniciais
console.log(b); //valores iniciais



while (true) {

    if (vez == 0) {
        // console.log("a= " + a); //valores iniciais
        // console.log("soma2= " + soma2); //valores iniciais

        c = a + soma2 //atualiza o ultimo
        // console.log("c= " + c); //valores iniciais
        soma2 += soma22;
        soma22++;
        vez = 1;
    } else if (vez == 1) {
        c = a + soma1;
        soma1++;
        vez = 0;
    }

    if (c > 100) {
        break
    }
    console.log(c); //vai printando a sequencia



    a = b //vai andando a sequencia
    b = c //vai andando a sequencia


}