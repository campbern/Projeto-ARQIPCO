#include <stdio.h>
#include "jogos.h"

int main()
{

    // Declarações
    Jogo jogos[MAX_JOGOS];
    int quantidadeJogos = 0;
    int opcao;

    // Carregar jogos
    carregarJogos(jogos, &quantidadeJogos);

    // Menu principal
    do
    {

        printf("\n=== LOJA DE GAMES ===\n");
        printf("1 - Cadastrar jogo\n");
        printf("2 - Listar jogos\n");
        printf("3 - Comprar jogo\n");
        printf("4 - Registrar avaliacao\n");
        printf("5 - Relatorios\n");
        printf("6 - Mostrar avaliacoes\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            cadastrarJogo(jogos, quantidadeJogos); // cadastrar
            break;

        case 2:
            listarJogos(jogos, quantidadeJogos); // listar
            break;

        case 3:
            // registrarCompra(); // comprar
            break;

        case 4:
            // avaliar
            break;

        case 5:
            // relatorios
            break;

        case 6:
            // mostrar avaliacoes
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