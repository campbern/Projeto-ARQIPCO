#ifndef JOGOS_H
#define JOGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTANTES */
#define MAX_JOGOS 100
#define MAX_AVALIACOES 10

/* ESTRUTURAS DE DADOS (Requisito 3.1) */
typedef struct {
    char nome[100];
    char genero[50];
    float preco;
    int classificacao;
    int downloads;
} Jogo;

/* PROTÓTIPOS DAS FUNÇÕES */

/* Arquivos (Requisito 3.8) */
void carregarJogos(Jogo jogos[], int *total);
void salvarJogos(Jogo jogos[], int total);

/* Cadastro (Requisito 3.2) */
void cadastrarJogo(Jogo jogos[], int *total);
void listarJogos(Jogo jogos[], int total);

/* Compras (Requisito 3.4) */
void registrarCompra(Jogo jogos[], int total, float *faturamentoBruto, float *faturamentoLiquido);

/* Relatórios (Requisito 3.5) */
void relatorios(Jogo jogos[], int total, float faturamentoBruto, float faturamentoLiquido);

/* Avaliações (Requisito 3.7) */
void registrarAvaliacoes(int avaliacoes[][MAX_AVALIACOES], int qtdAvaliacoes[], int total, Jogo jogos[]);
void mostrarAvaliacoes(Jogo jogos[], int avaliacoes[][MAX_AVALIACOES], int qtdAvaliacoes[], int total);

#endif
