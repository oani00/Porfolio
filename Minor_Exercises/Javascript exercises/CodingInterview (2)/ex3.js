const fs = require('fs'); // importa o modulo filesystem
const { DefaultDeserializer } = require('v8');
// const prompt = require('prompt-sync')();; //importa o modulo prompt-sync
//o modulo prompt-sync deve ser instalado. Para isto: $ npm install prompt-sync
//No meu VScode não rodou, mas direto do terminal não teve problemas.

/* Movimento do bot
Existe um bot localizado em um par de coordenadas inteiras, (x, y). Ele pode ser movido para um outro par de coordenadas. 
Embora o bot possa se mover quantas vezes quiser, ele só pode fazer os dois tipos de movimentos a seguir:
1. Da posição (x, y) para a posição (x + y, y).
2. Da posição (x, y) para a posição (x, x + y).
Por exemplo, se o bot começa em (1, 1), ele pode fazer a seguinte sequência de movimentos: (1, 1) → (1, 2) → (3, 2) → (5, 2). 
Observe que o movimento sempre será para cima ou para a direita. 

Escreva uma função que, dadas as coordenadas iniciais e finais, determine se o bot pode alcançar as coordenadas finais
de acordo com as regras de movimento.
Descrição da função:
A função deve retornar true se o bot puder atingir seu objetivo, caso contrário, retorne false.
A função tem o(s) seguinte(s) parâmetro(s):

x1: valor inteiro, coordenada x inicial
y1: valor inteiro, coordenada y inicial
x2: valor inteiro, coordenada x final
y2: valor inteiro, coordenada y final */




console.log("----------EX3----------");

/* 
após quebrar a cabeça (meu racicinio antigo está abaixo) vi que ha uma solução muito muito mais elegante que a minha
https://www.geeksforgeeks.org/check-possible-move-given-coordinate-desired-coordinate/

Tentanto entender a solução vi que esse problema está relacionado com o algoritmo de euclides(para uma explicação visual: https: //www.youtube.com/watch?v=jb1VMGrxPWg )

Então no final das contas, dadas as regras do robozinho, se os maximos divisores comuns das coordenadas iniciais e finais
não forem iguais, não tem jeito dele chegar lá.

*/

    // Algoritmo de euclides não otimizado (para uma explicação visual: https://www.youtube.com/watch?v=h86RzlyHfUE )
    function gcd(i, j) {
        if (i == j)
            return i; //se os numeros forem iguais, o MDC é um deles mesmo.

        if (i > j)
            return gcd(i - j, j); //o maximo divisor comum entre quaisquer dois naturais é no minimo 1, a função sempre tem retorno.
        return gcd(i, j - i);
    }

function ispossible(x, y, a, b) {

    // Find absolute values of all as
    // sign doesn't matter.
    x = Math.abs(x);
    y = Math.abs(y);
    a = Math.abs(a);
    b = Math.abs(b);

    // If gcd is equal then it is possible to reach.
    // Else not possible.
    return (gcd(x, y) == gcd(a, b));
}

// Driver code

// Converting coordinate into positive integer
var x = 1,
    y = 1;
var a = 2,
    b = 2;
if (ispossible(x, y, a, b))
    console.log("Consigo chegar la");
else
    console.log("Não consigo chegar lá...");



/////////////////////////////////Raciocinio Antigo/////////////////////////////////



/*      "Escreva uma função que, dadas as coordenadas iniciais e finais,
determine se o bot pode alcançar as coordenadas finais
de acordo com as regras de movimento.""
No exercicio fala em ir para a direita ou ir para cima. Porém teoricamente esse exercício é analogo a caminhar em uma
arvore binária. Por tanto ao invés dos movimentos direita e subir eu nomeei os métodos como descer e subir esquerda 
e descer e subir direita para pensar numa arvore. 

A idéia é ir formando uma arvore e parar assim que conseguir chegar em x2, y2 ou quando tudo for tentado
(isso acontece quando ele tenta "subir acima do nó raiz", ou seja, ele "volta" o nó inicial, o que não pode e ai indica
que é impossivel chegar em x2, y2).

Algo tipo assim

1,1 <- digamos que serja a posicao inicial.
| \ 
|  \ 
|   \
|    \
1,2   2,1 <- digamos que queira vir para cá. Ela começa de 1,2, ai 1,3, ai volta para 1,2, ai vai para 3,2, volta para 1,1, depois para em 2,1
| \
|  \
|   \ 
1,3   3,2 <- por exemplo aqui ele chegaria por dDir, checaria que não tem filhos, e faria sDir.

*/

/* 

var x1 = 1;
var y1 = 1;
var x2 = 1;
var y2 = 2;

function posicao(x1, y1) {

    this.x = x1;
    this.y = y1;
    this.tentativa = 0;
    this.descipela = 0;

    this.dDir = function () {
        // console.log("antes "+ this.x);
        this.x += this.y;
        // this.x = this.x + y;
        // console.log("depois "+ this.x);
    };

    this.dEsq = function () {
        this.y += this.x;
    };

    this.sEsq = function () {
        this.x -= this.y;
    };

    this.sDir = function () {
        this.y -= this.x;
    };
    
    //para ele lembrar se ja passou pelo nodo
    this.setTentativa = function (t) {
        this.tentativa = t;
    };
    
    //para ele lembrar de onde veio
    this.setDescipela = function (d) {
        this.tentativa = d;
    };
};

let pos = new posicao(x1, y1);

 */

/**
 * a cada nivel que desce na arvore marcara se ja foi para a esquerda
 * a cada volta muda o valor
 * chega está false (vai para a esquerda)
 * se voltar marca true e vai para a direita
 * no filho está false, vai para a esquerda
 * e assim até chegar numa folha onde ou termina a execução ou vai subindo trocando tudo de novo de true para false até chegar na raiz
 * onde recomeça o processo agora na parte direita da arvore
 */


/*
// let movimento = [1]; //1- desça esquerda 2- desça direita 3- suba direita
//A cada nivel ele registra o movimento que deve tomar.
let nivel = 0; //começa no nivel 0
// let descipela = [0]; //1- esquerda 2- direita

if ((x1 === 0 && x2 !== 0) && (y1 === 0 && y2 !== 0)) {
    return false; //caso especial. se o inicio for 0,0 e o destino não for o próprio 0,0, nem precisa começar.
}


let count = 0;

console.log("Tentei:");

while (true) {

    count++;
    if (count > 15) {
        break;
    }
    console.log("Passo" + count + " x= " + pos.x + " y= " + pos.y);

    if ((pos.x < x1) || (pos.y < y1)) {
        console.log("NAO da para chegar...")
        break;
        // return false; //Não da para chegar de jeito nenhum (arvore totalmente percorrida)
    }
    if ((pos.x === x2) && (pos.y === y2)) {
        console.log("Cheguei!")
        break;
        // return true; //chegou no destino
    }
    // movimento[nivel + 1] = 1; //cria a marcação de um novo nivel para descer. A direção padrao do novo nivel é sempre 1

    //como nao está no destino, checa se não pode descer mais. Se não puder, sobe
    //Esse "não poder descer" é estar em um local proibido, ele passou das coordenadas e, ja que não pode voltar, tenta outra vez.
    if ((pos.x > x2) || (pos.y > y2) || (pos.tentativa == 2)) {
        if (pos.descipela === 1) { // ou seja, ele desceu pela esquerda, 1 é o padrão para um novo "nó"
            console.log("Subi pela direita")
            pos.sDir(); //e sobe pela direita
            // nivel--;
            pos.setTentativa(1); //para na proxima iteração ele descer pela direita
            console.log("ccccccc nivel= " + nivel)

        } else if (descipela[nivel - 1] === 2) {
            console.log("Subi pela esquerda")
            pos.sEsq();
            // nivel--;
            pos.setTentativa(2); //Todas as tentativas para o nodo
        }
    } else if (pos.tentativa === 0) { //se puder, desce para a esquerda.
        console.log("desci esquerda");
        pos.descipela = 1; //para ele lembrar de onde desceu naquele nivel
        // nivel++;
        movimento = false; //para ele lembrar que desceu pela esquerda
        pos.dEsq(); //ou seja, se a "plaquinha" estiver false, vá para a esquerda. Se não, direita.
        console.log("eeeeeee nivel= " + nivel)
    } else if (pos.tentativa === 1) {
        console.log("desci direita")
        pos.descipela = 2; //para ele lembrar de onde desceu naquele nivel
        // nivel++;
        pos.dDir();
        console.log("fffffff nivel= " + nivel)
    }


}

 */