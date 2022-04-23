//forma 1

var aluno1 = {

    // function aluno1(ra, nome),

    ra: 11111111,
    nome: "Oani"
};





//forma 2

function alunoX(ra, nome) {
    this.ra = ra;
    this.nome = nome;
    
}

var aluno2 = new alunoX(32089834, "Joao")



//forma 3

var aluno3 = {}

aluno3.ra = 33333333;
aluno3.nome = "Oaniii";