opcao=0
x=0
y=0
resultado=0

while test "$opcao" != "99" 
do
	#clear

	echo "CALCULADORA"
	echo "Selecione a operacao aritmetica:"
	echo "A = ADICAO"
	echo "S = SUBTRAÇÃO"
	echo "M = MULTIPLICAÇAO"
	echo "D = DIVIDAO"
	echo "ou digite 99 para sair"

	read opcao

	case $opcao in
		"A" ) 
			echo "x ="
			read x
			echo "y ="
			read y

			resultado=`expr $x + $y`

			echo "RESULTADO = $resultado"

			if test resultado%2 == 0
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

			echo "RESULTADO = $resultado"

			if test resultado%2 == 0
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

			echo "RESULTADO = $resultado"

			if test resultado%2 == 0
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

			echo "RESULTADO = $resultado"

			if test resultado%2 == 0
			then
				echo "RESULTADO $resultado EH UM NUMERO PAR"
			else
				echo "RESULTADO $resultado EH UM NUMERO IMPAR"
			fi
		;;

	esac
done