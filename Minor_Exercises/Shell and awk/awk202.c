BEGIN {
   
   lidos = 0
   aceito = 0
   tamTotal = 0
}

{lidos = lidos + 1
        
	if (NF >= 8 && $5 > 0) {
		tipo = substr($1,1,1)
		if (tipo == "-") {
				print ""
				print "DONO: ", $3, " - ARQUIVO: ", $9, " - TAMANHO: ", $5
				tamTotal = tamTotal + $5
				aceito = aceito + 1

				if (aceito == 1){
				nomeMaior = $9
				tamMaior  = $5
				}

				if ($5 > tamMaior) {
				nomeMaior = $9
				tamMaior  = $5
			}
		}
	}	
}

END {
    
	print "--------------------------------------------------------"
	print ""
	print "ALUNO: OANI DA SILVA DA COSTA"
	print "Quantidadede todos arquivos lidos, aceitos ou não= NNN ", lidos 
	print "Quantidadedos arquivos aceitos= ", aceito
	print "Tamanho total em bytes dos arquivos aceitos= ", tamTotal 
	MEDIA = tamTotal/ aceito
	print "Tamanho medio em bytes dos arquivos aceitos= ", MEDIA
	print "NOME= ", $9, " / TAMANHO: ", $5
	print "MAIOR ARQUIVO = ", nomeMaior, " - TAMANHO = ", tamMaior
  
}