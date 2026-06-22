#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"

// ======================================================
// REQUISITO 3.8 — CARREGAR JOGOS
// ======================================================
void carregarJogos(Jogo jogos[], int *total)
{

    FILE *arquivo = fopen("dados/jogos.txt", "r");

    if (arquivo == NULL)
    {
        printf("[Sistema] Arquivo jogos.txt nao encontrado.\n");
        *total = 0;
        return;
    }

    *total = 0;

    while (fscanf(arquivo,
                  " %99[^;];%49[^;];%f;%d;%d\n",
                  jogos[*total].nome,
                  jogos[*total].genero,
                  &jogos[*total].preco,
                  &jogos[*total].classificacao,
                  &jogos[*total].downloads) == 5)
    {

        (*total)++;

        if (*total >= MAX_JOGOS)
            break;
    }

    fclose(arquivo);

    printf("[Sistema] %d jogos carregados.\n", *total);
}

// ======================================================
// REQUISITO 3.8 — SALVAR JOGOS
// ======================================================
void salvarJogos(Jogo jogos[], int total)
{

    FILE *arquivo = fopen("dados/jogos.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo,
                "%s;%s;%.2f;%d;%d\n",
                jogos[i].nome,
                jogos[i].genero,
                jogos[i].preco,
                jogos[i].classificacao,
                jogos[i].downloads);
    }

    fclose(arquivo);
}

// ======================================================
// REQUISITO 3.2 — CADASTRAR JOGO
// ======================================================
void cadastrarJogo(Jogo jogos[], int *total)
{

    if (*total >= MAX_JOGOS)
    {
        printf("Limite de jogos atingido.\n");
        return;
    }

    Jogo novo;

    printf("\n===== CADASTRO DE JOGO =====\n");

    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);

    printf("Genero: ");
    scanf(" %[^\n]", novo.genero);

    do
    {
        printf("Preco: ");
        scanf("%f", &novo.preco);

        while (getchar() != '\n')
            ;

        if (novo.preco < 0)
        {
            printf("Preco invalido.\n");
        }

    } while (novo.preco < 0);

    printf("Classificacao: ");
    scanf("%d", &novo.classificacao);

    while (getchar() != '\n')
        ;

    novo.downloads = 0;

    jogos[*total] = novo;
    (*total)++;

    salvarJogos(jogos, *total);

    printf("Jogo cadastrado com sucesso.\n");
}

// ======================================================
// LISTAR JOGOS
// ======================================================
void listarJogos(Jogo jogos[], int total)
{

    if (total == 0)
    {
        printf("Nenhum jogo cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE JOGOS =====\n");

    for (int i = 0; i < total; i++)
    {

        printf("\n%d - %s\n", i + 1, jogos[i].nome);
        printf("Genero: %s\n", jogos[i].genero);
        printf("Preco: R$ %.2f\n", jogos[i].preco);
        printf("Classificacao: %d\n", jogos[i].classificacao);
        printf("Downloads: %d\n", jogos[i].downloads);
    }
}

// ======================================================
// REQUISITO 3.4 — REGISTRAR COMPRA
// ======================================================
void registrarCompra(Jogo jogos[], int total,
                     float *fatBruto, float *fatLiquido)
{

    if (total == 0)
    {
        printf("Nenhum jogo cadastrado.\n");
        return;
    }

    int opcao, quantidade;

    printf("\n===== JOGOS DISPONIVEIS =====\n");

    for (int i = 0; i < total; i++)
    {
        printf("%d - %s | R$ %.2f\n",
               i + 1,
               jogos[i].nome,
               jogos[i].preco);
    }

    printf("Escolha: ");
    scanf("%d", &opcao);
    opcao--;

    if (opcao < 0 || opcao >= total)
    {
        printf("Opcao invalida.\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    jogos[opcao].downloads += quantidade;

    float valor = jogos[opcao].preco * quantidade;

    *fatBruto += valor;
    *fatLiquido += valor * 0.8;

    FILE *arquivo = fopen("dados/compras.txt", "a");

    if (arquivo != NULL)
    {
        fprintf(arquivo,
                "%s;%.2f;%d\n",
                jogos[opcao].nome,
                jogos[opcao].preco,
                quantidade);
        fclose(arquivo);
    }

    salvarJogos(jogos, total);

    printf("Compra registrada com sucesso.\n");
}

// ======================================================
// REQUISITO 3.5 — RELATORIOS
// ======================================================
void relatorios(Jogo jogos[], int total,
                float fatBruto, float fatLiquido)
{

    if (total == 0)
    {
        printf("Nenhum jogo cadastrado.\n");
        return;
    }

    int maisVendido = 0;
    int maisCaro = 0;
    int maisBarato = 0;

    int totalDownloads = 0;
    float somaPrecos = 0;
    float somaVendidos = 0;
    int qtdVendidos = 0;

    for (int i = 0; i < total; i++)
    {

        totalDownloads += jogos[i].downloads;
        somaPrecos += jogos[i].preco;

        if (jogos[i].downloads > jogos[maisVendido].downloads)
            maisVendido = i;

        if (jogos[i].preco > jogos[maisCaro].preco)
            maisCaro = i;

        if (jogos[i].preco < jogos[maisBarato].preco)
            maisBarato = i;

        if (jogos[i].downloads > 0)
        {
            somaVendidos += jogos[i].preco;
            qtdVendidos++;
        }
    }

    printf("\n===== RELATORIOS =====\n");
    printf("Mais vendido: %s\n", jogos[maisVendido].nome);
    printf("Total downloads: %d\n", totalDownloads);
    printf("Faturamento bruto: R$ %.2f\n", fatBruto);
    printf("Faturamento liquido: R$ %.2f\n", fatLiquido);
    printf("Media geral: R$ %.2f\n", somaPrecos / total);

    if (qtdVendidos > 0)
    {
        printf("Media vendidos: R$ %.2f\n",
               somaVendidos / qtdVendidos);
    }

    printf("Mais caro: %s\n", jogos[maisCaro].nome);
    printf("Mais barato: %s\n", jogos[maisBarato].nome);
}

// ======================================================
// REQUISITO 3.7 — REGISTRAR AVALIACOES
// ======================================================
void registrarAvaliacoes(int avaliacoes[][MAX_AVALIACOES],
                         int qtdAvaliacoes[],
                         int total,
                         Jogo jogos[])
{

    int jogo, nota;

    printf("\n===== AVALIACOES =====\n");

    for (int i = 0; i < total; i++)
    {
        printf("%d - %s\n", i + 1, jogos[i].nome);
    }

    printf("Escolha: ");
    scanf("%d", &jogo);
    jogo--;

    if (jogo < 0 || jogo >= total)
    {
        printf("Jogo invalido.\n");
        return;
    }

    if (qtdAvaliacoes[jogo] >= MAX_AVALIACOES)
    {
        printf("Limite atingido.\n");
        return;
    }

    printf("Nota (0-10): ");
    scanf("%d", &nota);

    if (nota < 0 || nota > 10)
    {
        printf("Nota invalida.\n");
        return;
    }

    avaliacoes[jogo][qtdAvaliacoes[jogo]] = nota;
    qtdAvaliacoes[jogo]++;

    printf("Avaliacao registrada.\n");
}

// ======================================================
// REQUISITO 3.7 — MOSTRAR AVALIACOES
// ======================================================
void mostrarAvaliacoes(Jogo jogos[],
                       int avaliacoes[][MAX_AVALIACOES],
                       int qtdAvaliacoes[],
                       int total)
{

    int melhor = -1;
    float melhorMedia = 0;
    int totalAvaliacoes = 0;

    printf("\n===== RELATORIO DE AVALIACOES =====\n");

    for (int i = 0; i < total; i++)
    {

        int soma = 0;

        for (int j = 0; j < qtdAvaliacoes[i]; j++)
        {
            soma += avaliacoes[i][j];
            totalAvaliacoes++;
        }

        if (qtdAvaliacoes[i] > 0)
        {

            float media = (float)soma / qtdAvaliacoes[i];

            printf("%s -> %.2f\n",
                   jogos[i].nome,
                   media);

            if (media > melhorMedia)
            {
                melhorMedia = media;
                melhor = i;
            }
        }
    }

    printf("Total avaliacoes: %d\n", totalAvaliacoes);

    if (melhor != -1)
    {
        printf("Melhor avaliado: %s\n", jogos[melhor].nome);
    }
}
