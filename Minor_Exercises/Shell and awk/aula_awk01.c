BEGIN{
	print "INICIO DO PROGRAMA AWK01"
}

$3 > 5{
	print "NOME:", $1, " - FALTAS:", $3, " - TURMA:",$2
}

END{
	print "FIM DE PROCESSAMENTO"
}