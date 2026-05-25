# Projeto-ARQIPCO
Projeto de Introdução à Programação de Computadores (1ºSem/2026)

------------------------------

## DOCUMENTAÇÃO DO ARQUIVO JOGOS.H
Especificação técnica do cabeçalho do projeto da Loja de Games. Define:
* Estrutura de dados principal (struct)
* Constantes globais do sistema
* Protótipos das funções modularizadas

## REQUISITOS CONTEMPLADOS NO JOGOS.H
* Utilização de struct
* Definição do vetor de structs
* Definição de limites para matrizes de avaliações
* Modularização através de protótipos e diretivas de compilação

## ESTRUTURA DA STRUCT (Requisito 3.1)

typedef struct {
  char nome[100];
  char genero[50];
  float preco;
  int classificacao;
  int downloads;
} Jogo;

## CONSTANTES GLOBAIS DEFINIDAS
* MAX_JOGOS (100): Define o limite máximo de armazenamento de elementos no vetor de structs alocado na memória RAM.
* MAX_AVALIACOES (10): Define o limite máximo de colunas na matriz de notas, limitando a quantidade de avaliações permitidas por jogo.

## PROTÓTIPOS DAS FUNÇÕES DEFINDAS
Arquivos (Requisito 3.8)
* void carregarJogos(Jogo jogos[], int *total);
* void salvarJogos(Jogo jogos[], int total);

Cadastro (Requisito 3.2)
* void cadastrarJogo(Jogo jogos[], int *total);
* void listarJogos(Jogo jogos[], int total);

Compras (Requisito 3.4)
* void registrarCompra(Jogo jogos[], int total, float *faturamentoBruto, float *faturamentoLiquido);

Relatórios (Requisito 3.5)
* void relatorios(Jogo jogos[], int total, float faturamentoBruto, float faturamentoLiquido);

Avaliações (Requisito 3.7)
* void registrarAvaliacoes(int avaliacoes[][MAX_AVALIACOES], int qtdAvaliacoes[], int total, Jogo jogos[]);
* void mostrarAvaliacoes(Jogo jogos[], int avaliacoes[][MAX_AVALIACOES], int qtdAvaliacoes[], int total);

## DIRETIVAS DE COMPILAÇÃO E SEGURANÇA
Sinalizadores de macro para impedir que o compilador realize a dupla inclusão do cabeçalho durante o processo de linkagem dos módulos:
* #ifndef JOGOS_H
* #define JOGOS_H
* #endif

## BIBLIOTECAS VINCULADAS
* <stdio.h>
* <stdlib.h>
* <string.h>

------------------------------

## DOCUMENTAÇÃO DO ARQUIVO JOGOS.C
Arquivo responsável pela implementação das funcionalidades da Loja de Games. Contém a lógica de manipulação dos dados, interação com o usuário e persistência em arquivos.

## REQUISITOS CONTEMPLADOS NO JOGOS.C
Manipulação de vetores de struct em memória RAM
Entrada e saída de dados via terminal
Validação de dados de entrada
Controle de fluxo (if, while, for)
Manipulação de arquivos (leitura e escrita)
Uso de ponteiros para alteração de variáveis externas
Implementação de matriz para avaliações

## ARQUIVOS — (Requisito 3.8)
Função: carregarJogos
Responsável por ler os dados do arquivo jogos.txt e armazená-los em memória.

Funcionamento:
Abre o arquivo no modo leitura (r)
Lê linha por linha usando fscanf
Preenche o vetor de structs
Atualiza o total de jogos carregados
Realiza validação para evitar overflow do vetor

Função: salvarJogos
Responsável por gravar os dados atuais no arquivo jogos.txt.

Funcionamento:
Abre o arquivo no modo escrita (w)
Sobrescreve os dados antigos
Percorre o vetor e grava cada jogo no formato:
nome;genero;preco;classificacao;downloads

## CADASTRO — (Requisito 3.2)
Função: cadastrarJogo
Permite inserir novos jogos no sistema.

Funcionamento:
Verifica limite máximo (MAX_JOGOS)
Recebe dados via teclado
Valida preço (não permite valores negativos)
Inicializa downloads com 0
Armazena no vetor
Salva automaticamente no arquivo

Função: listarJogos
Exibe todos os jogos cadastrados.

Funcionamento:
Percorre o vetor
Mostra informações completas de cada jogo:
Nome
Gênero
Preço
Classificação
Downloads

## COMPRAS — (Requisito 3.4)
Função: registrarCompra
Registra uma compra/download de jogo.

Funcionamento:
Lista jogos disponíveis
Permite seleção pelo usuário
Valida entrada
Atualiza número de downloads
Calcula valores financeiros:
Faturamento bruto (100%)
Faturamento líquido (80%) → desconto de 20% de imposto
Armazena compra no arquivo compras.txt
Atualiza arquivo de jogos

## RELATÓRIOS — (Requisito 3.5)
Função: relatorios
Gera estatísticas gerais do sistema.

Relatórios gerados:
Jogo mais vendido
Total de downloads
Faturamento bruto
Faturamento líquido
Média de preços dos jogos
Média de preços dos jogos vendidos
Jogo mais caro
Jogo mais barato

Funcionamento:
Percorre o vetor
Realiza cálculos acumulativos
Determina valores máximos e mínimos


## AVALIAÇÕES — (Requisito 3.7)
Estrutura lógica:
Matriz avaliacoes[linhas][colunas]
Linhas = jogos
Colunas = notas
Vetor auxiliar qtdAvaliacoes[]
Controla quantas avaliações cada jogo possui

Função: registrarAvaliacoes
Permite adicionar avaliações aos jogos.

Funcionamento:
Exibe lista de jogos
Permite escolha do usuário
Verifica limite máximo de avaliações
Valida nota (0 a 10)
Armazena a nota na matriz

Função: mostrarAvaliacoes
Exibe relatório das avaliações.

Informações exibidas:
Média de cada jogo
Total de avaliações registradas
Jogo mais bem avaliado
Funcionamento:
Percorre a matriz
Calcula média das notas por jogo
Identifica maior média

-----------------------------
