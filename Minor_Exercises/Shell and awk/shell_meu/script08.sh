
# cd ~/Dropbox/#BOITUVA/ADS/6SO2 && bash script08.sh

opcao="B"
x=0
y=0

while test $opcao != "Z"
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

	read opcao

	if test $opcao = "Z"
	then
		echo "Fim do programa"
		read seila
		exit
	fi

	case $opcao in
		"A")
			resp1="S"
			
			while test $resp1 != "N"
			do
				echo "Informe o nome do arquivo de texto com caminho para eu ler:"
				read arquivo
				
				if test -f $arquivo
				then
					more $arquivo
				else
					echo "Arquivo informado não existe."
				fi
			
				echo "Deseja listar outro arquivo? (S ou N)"
				read resp1
			done
		;;
		
		"S")
			resp2="S"
			until test $resp2 = "N"
			do
				echo "Informe um diretorio com caminho:"
				read diretorio
				
				if test -d $diretorio
				then
					ls -l $diretorio | more
				else
					echo "Diretorio informado não existe."
				fi
				
				echo "Deseja listar outro diretorio? (S ou N)"
				read resp2
			done
		;;
		
		"M")
			echo "Informe a base do retangulo"
			read base
			echo "Informe a altura do retangulo"
			read altura
			perimetro=`expr $base + $altura`
			perimetro=`expr $perimetro \* 2`
			echo "PERIMETRO = $perimetro"
			if test $perimetro -le 50
			then
				echo "PERIMETRO NORMAL"
				echo " "
				echo "Pressione ENTER"
				read seila    
			else
				echo "PETIMETRO ACIMA DO NORMAL"
				echo " "
				echo "Pressione ENTER"
				read seila
			fi
		;;

		*) 
			echo "Opção invalida"
			echo " "
			echo "Pressione ENTER"
			read seila
		;;
	esac
done