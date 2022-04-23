clear
opcao="0"
until test $opcao = "Z"
do
	echo "Aluno: Carlos Wagner Rodrigues da Silva"
	echo " "
	echo "Selecione a opcao:"
	echo " "
	echo "A = Listar o conteudo um arquivo texto"
	echo "D = Listar um diretorio"
	echo "Q = Calcular o perimetro de um retangulo"
	echo " "
	echo "Z = Encerrar o script"
	echo " "
	read opcao
	echo " "
	if test $opcao = "Z"
	then
		echo "Programa encerrado."
		echo " "
		exit
	else
		if test $opcao != "Z" 
		then

			case $opcao in
   				"A")resp1="S"
              until test $resp1 = "N"
              do
                echo "Informe o caminho e o nome do arquivo de texto desejado:"
        				read arquivo
   	     				if test -f $arquivo
   			   		  then
   				     	   more $arquivo
   					    else
   					       echo "Arquivo informado não existe."
   					       echo " "   					    
                fi
                echo " "
                echo Pressione Enter para Continuar
                read resposta
                clear
                echo "Deseja listar outro arquivo? (S ou N)"
                read resp1
              done;;
   				
   				"D")resp2="S"
              until test $resp2 = "N"
              do
                echo "Informe o caminho e o nome do diretorio desejado:"
   				      read diretorio
   					    if test -d $diretorio
   					    then
   					 	    ls -l $diretorio | more
   					    else
   					 	    echo "Diretorio informado não existe."
   					 	    echo " "
   					    fi
                echo " "
                echo Pressione Enter para Continuar
                read resposta
                clear
                echo "Deseja listar outro diretorio? (S ou N)"
                  read resp2
              done;;
   				"Q")echo "Informe a base do retangulo"
   					  read base
              echo "Informe a altura do retangulo"
              read altura
   					  perimetro=`expr $base + $altura`
              perimetro=`expr $perimetro \* 2`
   					  echo "PERIMETRO = $perimetro"
              if test $perimetro -le 50
   					  then
   					 	  echo "PERIMETRO NORMAL"                
   					  else
   					    echo "PETIMETRO ACIMA DO NORMAL"   					 	  
   					  fi;;
   				*) echo "Opcao invalida";;
			esac

      echo " "	
			echo Pressione Enter para Continuar
			read resposta
			clear

		fi

	fi
done

