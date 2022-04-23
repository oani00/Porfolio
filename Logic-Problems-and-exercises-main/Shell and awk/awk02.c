BEGIN{
	print "Estatistica de diretorio"
	numreg = 0
	tamanho = 0
	ignorados = 0
	comum = 0
	diretorio = 0
    outros = 0;
}

NF => 8 && $5 > 0{
	
	print "Nome - ", $1
	print "Tamanho - ", $5
	
	numreg = numreg +1
	tamanho = tamanho + $5
}else{
	ignorados = ignorados + 1
	tamanho = tamanho + $5
}

if match($NOME, comum){
	comum = comum + 1;
}
if match($NOME, comum){

}
if match($NOME, comum){

}

END{
	print "ARQUIVOS LIDOS = ", numreg
	print "ESPACO OCUPADO = ", tamanho
	print "TAMANHO MEDIO = ", media
	"Número total de registros aceitos de arquivos tipo comum = ", comum
	"Número total de registros aceitos de arquivos tipo diretório = ", diretorio
	"Número total de registros aceitos de arquivos de outros tipos = ", outros
}