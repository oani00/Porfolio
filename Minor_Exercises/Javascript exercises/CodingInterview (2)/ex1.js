/**
 * Oaní da Silva da Costa
 *
 * Teste de Lógica
 *
 * Escrito em Javascript usando Node
 * Foi pensado para ser aberto
 * e executado em um arquivo só prontamente
 * 
 * Aqui é a versão em pdf, para o arquivo .js acesse:
 * -------------------
 * 
 * -------------------
 */

const fs = require('fs'); // importa o modulo filesystem
// const prompt = require('prompt-sync')();; //importa o modulo prompt-sync


//o modulo prompt-sync deve ser instalado. Para isto: $ npm install prompt-sync
//No meu VScode não rodou, mas direto do terminal não teve problemas.

/* Primo
Um número primo é aquele que é divisível apenas por um e por ele mesmo. 
Obs: O número 1 não é primo.

Escreva uma função otimizada que, dado um número inteiro positivo, 
retorne true se o número for primo ou false caso contrário, 
com o menor número de iterações possível.
Imprima o resultado em tela da seguinte forma: 
“O número num é primo. Número de iterações necessárias: count”
ou
“O número num não é primo. Número de iterações necessárias: count” 

Eu faria uma força bruta, simplesmente ir tentando para cada número se há resto para todos os divisores menores que ele.
Mas procurando vi que dá para otimizar isso, o jeito mais óbvio é eliminar o número direto se ele for par, entre outras coisas.

Material consultado:
https://www.knowprogram.com/c-programming/c-prime-number-using-function/
https://www.tutorialspoint.com/different-methods-to-find-prime-number-in-python-program
https://en.wikipedia.org/wiki/Sieve_of_Atkin

https://www.quora.com/Whats-the-best-algorithm-to-check-if-a-number-is-prime
Nesse link tem uma resposta fantastica sobre as otimizações: https: //www.quora.com/Whats-the-best-algorithm-to-check-if-a-number-is-prime/answer/Lavesh-Kaushik
Mas simplesmente copiar dai sem entender não seria legal. Fiz por mim mesmo otimizando só um pouco.

*/

console.log("----------EX1----------");

//# checking for prime
function ehprimo(n) {
    //não pode ser menor que 1
    if (n <= 1) {
        console.log("Não é primo");
        return false;
    }
    //caso de ser 2
    else if (n === 2) {
        console.log("É primo");
        return true;
    } else if (n > 2 && n % 2 === 0) { //maior que 2 e não for par
        return false;
    } else {
        // Só precisamos testar até a raiz de n. Explicação: http://mathandmultimedia.com/2012/06/02/determining-primes-through-square-root/
        for (let i = 3; i < Math.sqrt(n) + 1; i++) {
            console.log(i);
            if (n % i == 0) {
                console.log("Não é primo");
                return false;
            }
            i++; //não precisa testar cada um, pode ir de 2 em 2
        }
        console.log("É primo");
        return true;
    }
}

console.log(n);
ehprimo(n);