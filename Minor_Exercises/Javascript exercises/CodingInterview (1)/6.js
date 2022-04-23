//Oaní da Silva da Costa
//Questão 6

const fs = require('fs'); // importa o modulo filesystem

var preco = 12
var capital = 20
let maxtamagochi = -1;

//adaptado de
//https://www.geeksforgeeks.org/find-deepest-node-binary-tree/
//https://www.youtube.com/watch?v=CbHObufjHWc


/* A idéia é ir navegando em uma arvore de preços atuais.*Se no node atual
for possivel fazer a compra ela será computada.*Recursivamente a função vai 
navegando na arvore n - aria e para *
    quando não puder ser feita a compra sempre atualizando o número *
    maximo de tamagochis.*O problema é analogo a 
    achar o maior número ne niveis em uma árvore.
    
Ela vai andando assim:

    12
├── 11 - fim
├── 10 - fim
├── ...
└── 3
    ├── 2
    │   └── 1 - fim
    ├── 2
    └── ...

*/

function find(preco, tamagochi, capital) {

    if ((capital - preco) > 0 && preco >= 1) {
        //a parada é se não puder ser feita a compra
        console.log("capital = " + capital)

        capital -= preco;
        tamagochi++;


        for (let fator = 1; fator < 12; fator++) {
            preco -= fator;

            find((preco), tamagochi, capital);

        }

        // Update level and rescue
        if (tamagochi > maxtamagochi) {
            maxtamagochi = tamagochi;
        }

    }
}

//aqui é chamada a função que não retorna nada, mas vai alterando a variavel maxtamagochi
find(preco, 0, capital);

console.log("posso comprar " + maxtamagochi + " tamagochis");