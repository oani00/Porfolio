opcao=0
arquivo=0
area=0
diretorio=0
x=0

# cd ~/Dropbox/#BOITUVA/ADS/6SO2

while test "$opcao" != "99" 
do
	clear

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

	read opcao

	if test opcao != ; then
		echo "Opcao eh invalida. Digite 1, 2, 3, 4 ou 99"
	fi

	case $opcao in
		"1" )
			echo "Me diga o nome de um arquivo (caminho)"
			read arquivo

			if test -f arquivo; then
				echo "O arquivo ja exite"
			else
				more $arquivo
			fi
		;;

		"2" )
			echo "Me diga o nome de um diretorio para ser criado"
			read diretorio

			if test -d diretorio; then
				echo "O diretorio ja exite"
			else
				mkdir $diretorio
			fi
		;;

		"3" )
			echo "Me diga o nome de um diretorio para ser criado"
			read diretorio
			
			if test -d diretorio; then
				echo "O diretorio ja exite"
			else
				ls -l $diretorio
			fi
		;;

		"4" )
			echo "Me diga o lado de um quadrado para eu calcular a área (max 120 u2 (unidades quadradas))"
			read x
			x=`expr $x * $x`
			echo "A area eh $x u2"
		;;
	esac
done