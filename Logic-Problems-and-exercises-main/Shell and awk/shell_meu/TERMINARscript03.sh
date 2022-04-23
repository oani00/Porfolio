clear
echo "me fale o nome do dir plz"
read $1
mkdir $1
cp /etc/passwd $1

echo "copiei coisas para o seu dir. Este eh ele agora"
ls -l $1

echo "blz, agora vou remove-lo. Ateh!"
rmv $1
exit
