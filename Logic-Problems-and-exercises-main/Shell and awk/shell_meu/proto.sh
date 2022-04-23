opcao=0
x=0
y=0
resultado=0
resultadoTotal=0

while test "$opcao" != "Z" 
do
	#clear

	echo "Aluno: Oani da Silva da Costa"
	echo " "
	echo "Selecione a opção"
	echo "  1 = Listar o conteudo de um arquivo texto."
	echo "  2 = Criar um diretorio."
	echo "  3 = Listar um diretorio."
	echo "  4 = Calcular a area de um quadrado."
	echo "  "
	echo "99 = ENCERRAR"
	echo "  "
	# echo "Resultado acumulado = $resultadoTotal"

	read opcao

	case $opcao in
		"A" ) 
			echo "x ="
			read x
			echo "y ="
			read y

			resultado=`expr $x + $y`
			resultadoTotal=`expr $resultado + $resultadoTotal`

			echo "RESULTADO = $resultado"

			if test `expr $resultado % 2` = 0
			then
				echo "RESULTADO $resultado EH UM NUMERO PAR"
			else
				echo "RESULTADO $resultado EH UM NUMERO IMPAR"
			fi
		;;

		"S" ) 
			echo "x ="
			read x
			echo "y ="
			read y

			resultado=`expr $x - $y`
			resultadoTotal=`expr $resultado + $resultadoTotal`

			echo "RESULTADO = $resultado"

			if test `expr $resultado % 2` = 0
			then
				echo "RESULTADO $resultado EH UM NUMERO PAR"
			else
				echo "RESULTADO $resultado EH UM NUMERO IMPAR"
			fi
		;;

		"M" ) 
			echo "x ="
			read x
			echo "y ="
			read y

			resultado=`expr $x \* $y`
			resultadoTotal=`expr $resultado + $resultadoTotal`

			echo "RESULTADO = $resultado"

			if test `expr $resultado % 2` = 0
			then
				echo "RESULTADO $resultado EH UM NUMERO PAR"
			else
				echo "RESULTADO $resultado EH UM NUMERO IMPAR"
			fi
		;;

		"D" ) 
			echo "x ="
			read x
			echo "y ="
			read y

			resultado=`expr $x / $y`
			resultadoTotal=`expr $resultado + $resultadoTotal`

			echo "RESULTADO = $resultado"

			if test `expr $resultado % 2` = 0
			then
				echo "RESULTADO $resultado EH UM NUMERO PAR"
			else
				echo "RESULTADO $resultado EH UM NUMERO IMPAR"
			fi
		;;
	esac
	
done