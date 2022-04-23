// +----+-----------+-----------+----------+----------+
// | -  |           |  jogador  |          |          |
// +----+-----------+-----------+----------+----------+
// | -  | -         | 0 tesoura | 1 papel  | 2 pedra  |
// | pc | 0 tesoura | 00 x      | 10perdeu | 20perdeu |
// | -  | 1 papel   | 01 venc   | 11x      | 21venceu |
// | -  | 2 pedra   | 02 venceu | 12perdeu | 22x      |
// +----+-----------+-----------+----------+----------+


while (true) {

    var computador = Math.floor((Math.random() * 10) + 1) % 3; //retorna ou 0, 1, 2 //https://www.w3schools.com/jsref/jsref_random.asp

    alert("computador = " + computador);
    alert("Jan Ken poh! Desculpe a interface simples, contribua com uma issue no github do jogo!");
    var jogador = prompt(" Escolah por favor: 0 - Tesoura | 1 - papel | 2 - pedra");
    var jogador = parseInt(jogador);
    
    alert("Você escolheu " + jogador + "\n e o computador " + computador);
    
    var verificacao = 3;
    
    if (jogador === 0 && computador === 0) {
        verificacao = 0;
    } else if (jogador === 0 && computador === 1) {
        verificacao = 1;
    } else if (jogador === 0 && computador === 2) {
        verificacao = 1;
    } else if (jogador === 1 && computador === 0) {
        verificacao = 2;
    } else if (jogador === 1 && computador === 1) {
        verificacao = 0;
    } else if (jogador === 1 && computador === 2) {
        verificacao = 2;
    } else if (jogador === 2 && computador === 0) {
        verificacao = 2;
    } else if (jogador === 2 && computador === 1) {
        verificacao = 1;
    } else if (jogador === 2 && computador === 2) {
        verificacao = 0;
    } else {
        alert("Opa algo errado aconteceu!");
    }
    
    alert("verif = " + verificacao);
    
    if (verificacao === 1) {
        alert("Você ganhou! Esse era apenas um demo, para jogar mais responda o questionario WebSai para ajudar a FATEC e continuar jogando!");
    } else if (verificacao === 2) {
        alert("Você perdeu... mais sorte na proxima ja que esse jogo é totalmente aleatorio e não tem nenhuma influencia dos resultados passados apesar da nossa cognição achar que tem.")
    } else {
        alert("Vocês empataram! Oloco ai não da poh! Tenta mais uma vez que agora o empate é mais dificil de acontecer (brincadeira, são independentes XD )")
    }

}