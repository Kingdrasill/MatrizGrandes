# Trabalhando com matrizes muito grandes em arquivos

<div style="display: inline-block;">
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20in-VSCode-red"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/Language-C-blue"/> 
</div>

<p></p>

<p align="justify">
  Quando se está trabalhando com matrizes muito grands, com matrizes 10000x10000, um computador nomalmente não consiguira alaocar memória suficiente para poder trabalhar com está matriz, uma das formas de contornar este problema é colocar a matriz em um arquivo e pegar partes dela. Este código tem como objetivo fazer isto, além de quando a matriz for pega será feita a transposta dela e multiplicara as duas e mostra o resultado. A multiplicação de matrizes é algo que custa muito tempo, para contornar este problema será utilizada uma tabela hash que guardara os resultados da multiplições para caso precisa dela novamete será necessário apenas pegar ela da hash.
</p>

# A matriz

<p aling="justify">
  A estrutura Matriz foi criada para representar uma matriz, nela há variáveis que guarda as dimensões da matriz, uma para guardar o tipo da matriz e duas outras que guardam as matrizes do determinado tipo da variável, logo se o tipo for true será armazenada em uma matriz de inteiros e se for false a matriz será uma matriz d pontos flutuantes, abaixo está uma foto da estrutura:   
</p>

<p align=˜center>
  <img src=˜images/matriz.jpg˜>
</p>

# A hash

<p align=˜justify˜>
  A estrutura da hash foi baseada na seguinte: <a href="https://github.com/mpiress/HashTable">https://github.com/mpiress/HashTable</a> a sua diferença é que em de guardar um valor será guardado a estrutura Matriz, o tipo de matriz que foi inserida e as coordenadas que deram origem ao resultado da matriz. a imagem abaixo mostra a nova estrutura. Sobre as coordenadas para se criar a chave com elas, foi criado a aeguinte l[ogica (maiorColuna - menorColuna) MOD (maiorLinha - maiorColuna). 
</p>

<p align="center">
  <img src=images/matriz.jpgs;
</p>

#Execução do progama

<p align="justify">
  A primeira coisa que aparece quanto o código é iniciado mstra-se um menu, imagem abaixo), nele há 5 opções: 0 - Par dar/muar o nome do arquivo da matriz, 1 - Gerar a matriz no arquivo, 2 - Pegar as matrizes do arquivo, 3 - Para criar o arquivo de coordenadas e 4 - Para sair do progama. É obrigatório informar o nome do arquivo antes de criar o ler o arquivo. Quando for pedido as dimensões da matriz deve se informar a quantidade de linhas e a quantidade de colunas separados por espaço.  
</p>

<p align-˜center">
  <img src=˜images/menu.jpg˜>
<p> 

<p align=˜justify˜>
  Na opção 0, o nome do arquivo é pdeido para ser setado/mudado. A imagem abaixo mostra como o nome é setado. A opção 4 apenas serve para sair do códig.
</p>

<p align="center">
  <img href=˜images/opcao-0.jpg>
  <img href=˜images/opcao-4s.jpg>
</p>

<p align=˜justify˜>
  Na opção 1, o nome do arquivo setado na opção agora será utilizado para criar o arquivo da matriz. Primeiro é perguntado qual tipo de matriz deve ser criada a duas op. A imagem abaixo mostra como o nome é setado. A opção 4 apenas serve para sair do códig.
</p>

<p align="center">
  <img href=˜images/opcao-0.jpg>
  <img href=˜images/opcao-4s.jpg>
</p>

# Compilação e Execução

O progama disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
