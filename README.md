# Projeto-IPCO
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
