<h1 align="center">Trabalho: Sistema Multitarefa</h1>

<p align="center">Deenvolvedor Julia Mello Lopes</p>
<p align="center">
  <a href="#introdução">Introdução</a> -
  <a href="#requisitos">R.I.C.E</a> -
  <a href="#etapa 1">Etapa 1</a> -
  <a href="#etapa 2">Etapa 2</a>
</p>

## Introdução

<p>Neste trabalho vamos construir um sistema de classificação cujas características nos permitirão observar conceitos importantes como: escalonamento e gestão de memória primária, na linguagem C++. 

Neste sistema, vamos considerar duas bases de dados D e T. A base D será utilizada para simular a inicialização, fornecendo assim o conceito de bootstrapping, tal como no sistema operacional. Já a base T representará os processos a serem executados, cada um produzindo uma série de computações pesadas e necessárias, as quais vamos coordenar utilizando um sistema de escalonamento em dois níveis: mecanismo e política. Além disso, abordaremos o conceito de memória tratando de chavear os processos entre memória primária e processador, claro, tudo de forma simulada para que possamos extrair resultados mensuráveis para avaliação.<p/>

## Requiritos, instalação, compilação, execução

* ### Requisitos
<p>Para que a execução funcione é necesessáario que você possua uma conta no GitHub, Windows e terminal WSL.<p\>

* ### Instalação
<p>Para instalar o repositório use o comando abaixo no terminal:<p\>
    
    git@github.com:juliamellolopes/Processos-e-Threads-DatasetArquivo.git

* ### Compilação:
<p>Primeiro abra o repositório e execute o seguinte comando:</p>

    make
    
* ### Execução
<p>Após copilar o arquivo execute o seguinte comando:</p>

    make run 

## Etapa 1

<p>Nesssa etapa foi elaborada uma tabela hash para itens e classes, onde os dados serão armazenados, caso esse dado se repita sera armazenado o local de repetição.

Toda a implementação dessa etapa esta na pasta src, dentro dos arquivos read.cpp e read.hpp. Nesses arquivos e feita leitura do arquivo D, que se encontra na pasta Arquivos, após a leitura, o arquivo é tokenizado coluna por coluna para atraves da biblioteca map armazenar dos dados. Dessa maneira, como ele ignora as repetições, caso o dado se repita ele ia armazenar tambem onde se encontra essa repetição.

## Etapa 2

Nessa segunda etapa será feita uma leitura do arquivo T, tokenizando linha por linha para em seguida comparar os arquivos com a tabela hash de itens e selecionando os elementos em comum, depois é feito o amazenamento dessa permutação em um vector.

Toda a implementação esta dentro da pasta src. No main será feita a criação dos vetores para armazenar os dados de comparados na hash e arquivo T e o chamado das funções que realizão a leitura, processamento dos arquivos, dentro do read.hpp. No arquivo read.cpp é implementado os metodos de tokenização, processamento e combinação para resolver essa etapa.
