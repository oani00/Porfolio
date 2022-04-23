"""
heuashuidash
"""


lista = [] # create empty list
 
first_num = input('O que você tem que fazer? ')

lista.append(first_num)

print("Você tem que fazer")
print(lista)
print("Quer adicionar mais algo (s/n)?")
pergunta = input()
if pergunta == "s":
	second_num = input('O que você tem que fazer? ')
	lista.append(second_num)
else:
	print("Você tem que fazer")
print("Você tem que fazer")
print(lista)
