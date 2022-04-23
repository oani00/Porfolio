BEGIN{
	print "Processando Diretorios"
	numreg = 0
	tamanho = 0
}

if (NF > 5){
	numreg = numreg +1
	tamanho = tamanho + $5
}

END{
	media = tamanho / numreg
	print "ARQUIVOS LIDOS = ", numreg
	print "ESPACO OCUPADO = ", tamanho
	print "TAMANHO MEDIO = ", media
	
}