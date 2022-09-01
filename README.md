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
  As matrizes
</p>

# Compilação e Execução

O progama disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
