opcao=0
x=0
y=0
resultado=0
resultadoTotal=0

while test "$opcao" != "Z" 
do
	#clear

	echo "CALCULADORA"
	echo " "
	echo "Selecione a operacao aritmetica:"
	echo "  A = ADICAO"
	echo "  S = SUBTRAÇÃO"
	echo "  M = MULTIPLICAÇAO"
	echo "  D = DIVIDAO"
	echo "  "
	echo "Z = ENCERRAR"
	echo "  "
	echo "Resultado acumulado = $resultadoTotal"

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