function conta() {


    var nome;
  
    var correntista;
    var banco;
    var numero;
    var saldo;
    
    this.getNome = function () {
        return nome;
    }
    this.setNome = function (nome) {
        nome = nome;
    }
    this.getCorrentista = function () {
        return correntista;
    }
    this.setCorrentista = function (correntista) {
        correntista = correntista;
    }
    this.getBanco = function () {
        return banco;
    }
    this.setBanco = function (banco) {
        banco = banco;
    }
    this.getNumero = function () {
        return numero;
    }
    this.setNumero = function (numero) {
        numero = numero;
    }
    this.getSaldo = function () {
        return saldo;
    }
    this.setSaldo = function (saldo) {
        saldo = saldo;
    }

};

function contacorrente() {

    var saldoEspecial;

    this.getSaldoEspecial = function () {
        return saldoEspecial;
    }
    this.setSaldoEspecial = function (saldoEspecial) {
        saldoEspecial = saldoEspecial;
    }
}


function poupanca(juros, dataVencimento) {

    var juros;
    var dataVencimento;

    this.getJuros = function () {
        return juros;
    }
    this.setJuros = function (juros) {
        juros = juros;
    }
    this.getDataVencimento = function () {
        return dataVencimento;
    }
    this.setDataVencimento = function (dataVencimento) {
        dataVencimento = dataVencimento;
    }

}

//herança
contacorrente.prototype = new conta();
poupanca.prototype = new conta();

//instanciacao

var conta1 = new conta();
var contacorr1 = new contacorrente();
var poup1 = new poupanca();


alert("------CONTA CORRENTE------- ");


contacorr1.setBanco("bradesco");
contacorr1.setCorrentista("sim");
contacorr1.setNome("joao");
contacorr1.setNumero(1000);
contacorr1.setSaldo(5555);

alert("banco = " + contacorr1.getBanco());
alert("Correntista? " + contacorr1.getCorrentista());
alert("Nome = " + contacorr1.getNome());
alert("Numero = " + contacorr1.getNumero());
alert("Saldo = " + contacorr1.getSaldo + " reais");

contacorr1.setSaldoEspecial(1);
alert("Saldo especial = " + contacorr1.getSaldoEspecial() + " reais")



contacorr1.setBanco("santander");
contacorr1.setCorrentista("sim");
contacorr1.setNome("maria");
contacorr1.setNumero(2222);
contacorr1.setSaldo(111);

alert("banco = " + contacorr1.getBanco());
alert("Correntista? = " + contacorr1.getCorrentista());
alert("Nome = " + contacorr1.getNome());
alert("Numero = " + contacorr1.getNumero());
alert("Saldo = " + contacorr1.getSaldo() + " reais");

alert("------POUPANCA------- ");
poup1.setDataVencimento("maio 2022");
poup1.setJuros(0.3);

alert("data de vencimento = " + poup1.getDataVencimento());
alert("Juros = " + contacorr1.getJuros());
