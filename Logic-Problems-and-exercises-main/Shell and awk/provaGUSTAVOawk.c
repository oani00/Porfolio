BEGIN {
   
   qtderegAceito = 0
   qtdeAceitoDir = 0
   tamTotal = 0
   totalaceito = 0
}


NF >= 9 {

	tipo = substr($1,1,1)
	
	if (tipo == "-") {
	
      	qtderegAceito = qtderegAceito + 1
      	tamTotal = tamTotal + $5
	  
      	print "ARQUIVO: ", $9, " - TAMANHO: ", $5
     
     	total++
      
   	}
   	if(tipo == "d"){
   
	print "ARQUIVO: ", $9, " - TAMANHO: ", $5
	qtdeAceitoDir = qtdeAceitoDir + 1
	
	total++
	
   	}
   
   
}
END {
		
		if(total == 0){
		    
		    total = 1
		    
		}
		
		percentualComum = (qtderegAceito/total)*100
		percentualDiretorio = (qtdeAceitoDir/total)*100
		
		print "AUTOR: Gustavo Cecato"
        	print "TOTAL bits Comum = ", tamTotal = tamTotal + $5
		print "TOTAL arquvos lidos Comum = ", qtderegAceito
		print "TOTAL arquvos lidos Diretorio = ", qtdeAceitoDir
        	print "Porcentagem comum = " percentualComum
		print "Porcentagem diretorio = " percentualDiretorio
        
}
