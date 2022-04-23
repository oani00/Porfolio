BEGIN {
   print "Exercicio awk03 - SO2 Laboratorio"
   qtderegAceito = 0
   tamTotal = 0
}

NF >= 9 {
   tipo = substr($1,1,1)
   if (tipo == "-") {
      qtderegAceito = qtderegAceito + 1
      tamTotal = tamTotal + $5
      print "ARQUIVO: ", $9, " - TAMANHO: ", $5
      if (qtderegAceito == 1) {
         nomeMenor = $9
         tamMenor  = $5
         nomeMaior = $9
         tamMaior  = $5
      }
      if ($5 < tamMenor) {
         nomeMenor = $9
         tamMenor  = $5
      }
      if ($5 > tamMaior) {
         nomeMaior = $9
         tamMaior  = $5
      }
   }
}
END {
        print "TOTAL ACEITOS = ", qtderegAceito 
	print "TOTAL TAMANHO = ", tamTotal 
        print "MENOR ARQUIVO = ", nomeMenor, " - TAMANHO = ", tamMenor
        print "MAIOR ARQUIVO = ", nomeMaior, " - TAMANHO = ", tamMaior
}
