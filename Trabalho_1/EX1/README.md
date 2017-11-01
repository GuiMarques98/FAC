#Exercicio 1

##Versões
Distri: Ubuntu 16.05.3 LTS
GCC : (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609


##Makefile
Comandos make|Explicação do comando
-|-
make|Compila os arquivos .c contidos na pasta src, e guarda os objetos na pasta obj, depois são linkados os .o gerando o executavel na pasta bin
make run|Roda o executavel
make clean|Deleta todos os arquivos da pasta bin e obj
make test1|Roda o teste contido no arquivo in1 na pasta doc
make test2|Roda o teste contido no arquivo in2 na pasta doc

##Arquivos

Arquivos *headers* e/ou fontes|O que fazem
-|-
types|Contém as structs Line e Point e algumas constantes simbólicas
geoarith|Contem as funções matemáticas necessárias para calculos de raio e centro do circulo
exer1|Contem as funções que capituram os inputs e desenham os outputs na tela

##Comentários
Todas as funções foram explicadas dentro dos arquivos fontes com comentários sobre as funções e como elas fazem isso. Só existem comentário no arquivo types.h para explicação das constantes e estruturas.

Os limites dos pontos indicados são da ordem de 0 <= |Pontos| <= 10⁸. E também pontos abaixo de 3 casas decimais como 0.0001.
