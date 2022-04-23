//alert("Olá! Agora que você tem mais de 18 anos e viu o filme poderia responder a nosso questionário?");

//------------------- SEXO -------------------

var sexom = 0
var sexof = 0
for (let i = 0; i < 45; i++) {

    if ((Math.floor((Math.random() * 10) + 1) % 2) > 0) { //retorna 1 ou 0
        sexom++;

    } else {
        sexof++;
    }

}

//------------------- IDADE -------------------
var resultado = 0;
var idade = 0;
var maioridade = 0;
var menoridade = 19;
for (let i = 0; i < 45; i++) {
    resultado = ((Math.floor((Math.random() * 100) + 1) % 50) + 18);
    idade += resultado;
    (resultado > maioridade) ? maioridade = resultado: maioridade + 0;
    (resultado < menoridade) ? menoridade = resultado: menoridade + 0;
}

//------------------- Avaliacao -------------------

var aval = 0
var aval1 = 0
var aval2 = 0
var aval3 = 0
var aval4 = 0
for (let i = 0; i < 45; i++) {
    resultado = (Math.floor((Math.random() * 10) + 1) % 4); //retorna 1,2,3,4
    aval += resultado;

    if (resultado == 1) {
        aval1++
    }
    if (resultado == 2) {
        aval2++
    }
    if (resultado == 3) {
        aval3++
    }
    if (resultado == 4) {
        aval4++
    }

}


//------------------- Parte do usuario -------------------



var idadeX = prompt("Qual a sua idade?");
idadeX = parseInt(idadeX);
while (idadeX < 18) {
    idadeX = prompt("Hije acho que você digitou algo errado. Informe novamente por favor:");
    idadeX = parseInt(idade);

}
alert("Ok, sua idade é " + idadeX);

var sexoX = prompt("Qual seu sexo? \n 0 - masculino | 1 - feminino");



while (sexoX != 0 && sexoX != 1) {
    sexoX = prompt("Apenas 0 - masculino ou 1 - feminino por favor");
    sexoX = parseInt(sexoX);

}

(sexoX == 1) ? sexof++ : sexom++

alert("Ok, sobre seu sexo voce informou " + sexoX);

var avalX = prompt("E o que você achou do filme? \n 1- péssimo | 2- regular | 3- bom | 4- ótimo");
avalX = parseInt(avalX);

while ((avalX != 1) && (avalX != 2) && (avalX != 3) && (avalX != 4)) {
    avalX = prompt("Poderia escolher entre 1 a 4 por favor? Obrigado! \n 1- péssimo | 2- regular | 3- bom | 4- ótimo");
    avalX = parseInt(avalX);

}

if (avalX == 1) {
    aval1++;
}
if (avalX == 2) {
    aval2++;
}
if (avalX == 3) {
    aval3++;
}
if (avalX == 4) {
    aval4++;
}

alert("Ok, sua nota então é " + avalX);
alert("Ufa, pesquisamos com mais 45 espectadores(as) que viram o filme. Eis, então, os resultados!");


aval = (aval + avalX) / 46;
idade = (idade + idadeX) / 46;
// aval = (aval) / 46;
// idade = (idade) / 46;

alert("Média das idades: " + idade.toFixed(0));
alert("A maior idade: " + maioridade);
alert("A menor idade: " + menoridade);
alert("Quantos responderam pessimo: " + aval1 + "Que pena...");
alert("A porcentagem que respondeu ótimo ou bom: " + ((aval2 + aval3) / 46).toFixed(2));
alert("Quantas mulheres responderam: " + sexom);
alert("Quantos homens responderam: " + sexof);

alert("É isso. \n caso queira fazer sua própria pesquisa contate a nossa agencia.\n Aqui não tem fake news! Somos isentos e não teve NENHUMA PSICOLOGIA ESCONDIDA para te influenciar!!! OU será que não... ; )");

// alert("Aliás sabia que o filme do Pelé tem média 8.1 no IMDB???");