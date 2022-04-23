function conta() {


    this.nome = "0";
    this.correntista = "0";
    this.banco = "0";
    this.numero = 0;
    this.saldo = 0;
    
    this.getNome = function () {
        return this.nome;
    }
    this.setNome = function (nome) {
        this.nome = nome;
    }
    this.getCorrentista = function () {
        return this.correntista;
    }
    this.setCorrentista = function (correntista) {
        this.correntista = correntista;
    }
    this.getBanco = function () {
        return this.banco;
    }
    this.setBanco = function (banco) {
        this.banco = banco;
    }
    this.getNumero = function () {
        return this.numero;
    }
    this.setNumero = function (numero) {
        this.numero = numero;
    }
    this.getSaldo = function () {
        return this.saldo;
    }
    this.setSaldo = function (saldo) {
        this.saldo = saldo;
    }

};

function contacorrente() {

    this.saldoEspecial = 0;

    this.getSaldoEspecial = function () {
        return this.saldoEspecial;
    }
    this.setSaldoEspecial = function (saldoEspecial) {
        this.saldoEspecial = saldoEspecial;
    }
}


function poupanca(juros, dataVencimento) {

    this.juros = 0;
    this.dataVencimento = "0";

    this.getJuros = function () {
        return this.juros;
    }
    this.setJuros = function (juros) {
        this.juros = juros;
    }
    this.getDataVencimento = function () {
        return this.dataVencimento;
    }
    this.setDataVencimento = function (dataVencimento) {
        this.dataVencimento = dataVencimento;
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
alert("Saldo = " + contacorr1.getSaldo() + " reais");

contacorr1.setSaldoEspecial(1);
alert("Saldo especial = " + contacorr1.getSaldoEspecial() + " reais")


alert("------POUPANCA------- ");

poup1.setBanco("santander");
poup1.setCorrentista("sim");
poup1.setNome("maria");
poup1.setNumero(2222);
poup1.setSaldo(111);

alert("banco = " + poup1.getBanco());
alert("Correntista? = " + poup1.getCorrentista());
alert("Nome = " + poup1.getNome());
alert("Numero = " + poup1.getNumero());
alert("Saldo = " + poup1.getSaldo() + " reais");

poup1.setDataVencimento("maio 2022");
poup1.setJuros(0.3);

alert("data de vencimento = " + poup1.getDataVencimento());
alert("Juros = " + poup1.getJuros());
