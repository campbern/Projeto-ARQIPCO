#include <stdio.h>
#include "jogos.h"

int main()
{

    // Jogos cadastrados
    Jogo jogos[MAX_JOGOS];
    int quantidadeJogos = 0;

    // Menu
    int opcao;

    // Faturamento
    float faturamentoBruto = 0.0;
    float faturamentoLiquido = 0.0;

    // Avaliações
    int avaliacoes[MAX_JOGOS][MAX_AVALIACOES] = {0};
    int qtdAvaliacoes[MAX_JOGOS] = {0};

    // Carregar jogos
    carregarJogos(jogos, &quantidadeJogos);

    // Menu principal
    do
    {

        printf("\n=================================\n");
        printf("        LOJA DE GAMES\n");
        printf("=================================\n");
        printf("1 - Cadastrar jogo\n");
        printf("2 - Listar jogos\n");
        printf("3 - Comprar jogo\n");
        printf("4 - Registrar avaliacao\n");
        printf("5 - Relatorios\n");
        printf("6 - Mostrar avaliacoes\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        // Validar entrada do menu
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida!\n");

            while (getchar() != '\n')
                ;

            opcao = -1;

            continue;
        }

        switch (opcao)
        {

        case 1:
            cadastrarJogo(jogos, &quantidadeJogos);
            break;

        case 2:
            listarJogos(jogos, quantidadeJogos);
            break;

        case 3:
            registrarCompra(
                jogos,
                quantidadeJogos,
                &faturamentoBruto,
                &faturamentoLiquido);
            break;

        case 4:
            registrarAvaliacoes(
                avaliacoes,
                qtdAvaliacoes,
                quantidadeJogos,
                jogos);
            break;

        case 5:
            relatorios(
                jogos,
                quantidadeJogos,
                faturamentoBruto,
                faturamentoLiquido);
            break;

        case 6:
            mostrarAvaliacoes(
                jogos,
                avaliacoes,
                qtdAvaliacoes,
                quantidadeJogos);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    // Salvar antes de sair
    salvarJogos(jogos, quantidadeJogos);

    return 0;
}