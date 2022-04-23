clear

echo "Digite o nome de um diretorio (caminho completo)"

read dir

echo "vou checar se o dir existe"

if test -d $dir
then
	ls -l dir | more
else
	echo "o diretorio informado nao existe"
fi

exit