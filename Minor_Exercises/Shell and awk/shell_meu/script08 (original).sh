
# cd ~/Dropbox/#BOITUVA/ADS/6SO2 && bash script08.sh
# cd ~/Downloads && bash script08.sh

oper="B"
x=0
y=0
oper2="bar"

while test $oper != "Z"
do
	clear
	echo "------------------------------------------------"
	echo "|Aluno: Oani da Silva da Costa                 |"
	echo "|                                              |"
	echo "|Selecione a opção:                            |"
	echo "|                                              |"
	echo "|A = Listar o conteudo de um arquivo texto     |"  
	echo "|S = Listar um diretorio                       |"
	echo "|M = Calcular o perimetro de um retangulo      |"
	echo "|                                              |"
	echo "|Z = ENCERRAR                                  |"
	echo "------------------------------------------------"

	read oper
	echo " "
	echo "escolha = $oper "
	echo " "
   
	case $oper in
		"A")
			while test $oper == "A"; do
				echo "Me diga o nome de um arquivo (caminho)"
				read arquivo

				if test -f $arquivo; then
					more $arquivo
				else
					echo "O arquivo nao existe"
				fi

				echo "Se quiser ler um novo arquivo, digite <sim>, se <não>, voltarei ao menu inicial."
				read oper2

				while test $oper2 != "sim" || test $oper2 != "nao"; do
					echo "Digite "sim" ou "nao" "
					read oper2
				done
				
				if test oper2 == "sim"; then
					oper="A"
				fi

				if test oper2 == "nao"; then
					oper="B"
				fi

			done
		;;

		"S")
			while test $oper == "D"; do
				echo "Me diga o nome de um diretorio para ser criado"
				read diretorio
				
				if test -d $diretorio; then
					ls -l $diretorio | more
				else
					echo "O diretorio nao exite"
				fi

				echo "Se quiser listar um novo diretorio, digite <sim>, se <não>, voltarei ao menu inicial."
				read oper2

				while test $oper2 != "sim" || test $oper2 != "nao"; do
					echo "Digite "sim" ou "nao" "
					read oper2
				done
				
				if test oper2 == "sim"; then
					oper="A"
				fi

				if test oper2 == "nao"; then
					oper="B"
				fi
				
			done
		;;

		"M")
			echo "Me diga os lado x e y para eu calcular o perimetro de um retangulo"
			echo "x = "
			read x
			echo "y = "
			read y
			
			x=`expr 2*$x + 2*$y`
			echo "PERIMETRO = $x"

			if test $x -lt 50; then
				echo "PERIMETRO NORMAL"
			else
				echo "PERIMETRO ACIMA DO NORMAL"
			fi
		;;
	esac
		
	if test $oper = "Z"
	then
		echo "Programa encerrado."
		echo " "    
		exit
	fi

	if test $oper != "A" || test $oper != "S" || test $oper != "M" || test $oper != "Z"; then
		echo "Opcao eh invalida. Digite A, S, M ou Z"
	fi

done