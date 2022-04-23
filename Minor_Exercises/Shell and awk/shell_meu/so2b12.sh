# PROVA LAB TURMA B SO2

opcao="B"

while test $opcao != "Z"
do
	clear
	echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	echo "|Aluno: Oani da Silva da Costa      |"
	echo "|                                   |"
	echo "|Selecione a opção:                 |"
	echo "|                                   |"
	echo "|D = Listar um diretorio            |"  
	echo "|C = Copiar um arquivo              |"
	echo "|A = Listar um arquivo              |"
	echo "|Q = Calcular a área de um quadrado |"
	echo "|                                   |"
	echo "|Z = Finalizar                      |"
	echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

	read opcao

	if test $opcao = "Z"
	then
		echo "Fim do programa"
		read qqrcoisa
		exit
	fi

	case $opcao in

		"D")
			qualquer2="S"
			until test $qualquer2 = "N"
			do
				echo "Informe um diretorio:"
				read diretorio
				
				if test -d $diretorio
				then
					ls -l $diretorio | more
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				else
					echo "Diretorio informado não existe."
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				fi
				
				echo "Deseja listar outro diretorio? (N para sair)"
				read qualquer2
			done
		;;
		
		"C")
			qualquer3="S"
			while test $qualquer3 != "N"
			do
				echo "Informe o nome do arquivo para eu copiar (junto com o caminho)"
				read arquivo1
				
				if test -f $arquivo1
				then
					echo "Informe o nome do diretorio para onde copiar"
					read dirparacopia

					if test -d $dirparacopia
					then
						cp $arquivo1 $dirparacopia
						echo " "
						echo "Pressione <ENTER>"
						read qqrcoisa
					else
						echo "Diretorio informado não existe."
						echo " "
						echo "Pressione <ENTER>"
						read qqrcoisa
					fi

				else
					echo "Arquivo informado não existe."
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				fi
			
				echo "Deseja copiar outro arquivo? (N para sair)"
				read qualquer3
			done
		;;

		"A")
			qualquer1="S"
			
			while test $qualquer1 != "N"
			do
				echo "Informe o nome do arquivo de texto com caminho para eu ler:"
				read arquivo
				
				if test -f $arquivo
				then
					more $arquivo
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				else
					echo "Arquivo informado não existe."
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				fi
			
				echo "Deseja listar outro arquivo? (N para sair)"
				read qualquer1
			done
		;;

		"Q")
			
			qualquer4="S"
			
			while test $qualquer4 != "N"
			do
				echo "Me diga o lado de um quadrado para eu calcular a area"
				read lado
				lado=`expr $lado \* $lado`
				
				if test $lado -le 100
				then
					echo "AREA NORMAL = $lado"
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa    
				else
					echo "“AREA ACIMA DO PERMITIDO = $lado"
					echo " "
					echo "Pressione <ENTER>"
					read qqrcoisa
				fi
			
				echo "Deseja calcular outra area? (N para sair)"
				read qualquer4
			done
		;;

		*) 
			echo "Opção invalida"
			echo " "
			echo "Pressione <ENTER>"
			read qqrcoisa
		;;
	esac
done