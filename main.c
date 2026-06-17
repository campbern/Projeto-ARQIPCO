#include <stdio.h>
#include "jogos.h"

int main()
{

    // Declarações
    Jogo jogos[MAX_JOGOS];

    int quantidadeJogos = 0;
    int opcao;

    float faturamentoBruto = 0.0;
    float faturamentoLiquido = 0.0;

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
        // Verificando a opção do usuário
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
            cadastrarJogo(jogos, &quantidadeJogos); // cadastrar
            salvarJogos(jogos, quantidadeJogos);    // salvar jogos após cadastro
            break;

        case 2:
            if (quantidadeJogos == 0)
            {
                printf("Nenhum jogo cadastrado.\n");
            }
            else
            {
                listarJogos(jogos, quantidadeJogos); // listar
            }
            break;

        case 3:
            // Verifica se tem jogos para dps comprar
            if (quantidadeJogos == 0)
            {
                printf("Nenhum jogo cadastrado.\n");
            }
            else
            {
                registrarCompra(
                    jogos,
                    quantidadeJogos,
                    &faturamentoBruto,
                    &faturamentoLiquido); // comprar

                salvarJogos(jogos, quantidadeJogos); // atualizando jogos disponiveis
            }
            break;

        case 4:
            // verifica se tem jogos para avaliar
            if (quantidadeJogos == 0)
            {
                printf("Nenhum jogo cadastrado.\n");
            }
            else
            {
                registrarAvaliacoes(
                    avaliacoes,
                    qtdAvaliacoes,
                    quantidadeJogos,
                    jogos); // avaliar
            }
            break;

        case 5:
            // Verifica antes de gerar um relatório
            if (quantidadeJogos == 0)
            {
                printf("Nenhum jogo cadastrado.\n");
            }
            else
            {
                relatorios(
                    jogos,
                    quantidadeJogos,
                    faturamentoBruto,
                    faturamentoLiquido); // relatorios
            }
            break;

        case 6:
            // Verifica antes de mostrar as avaliações
            if (quantidadeJogos == 0)
            {
                printf("Nenhum jogo cadastrado.\n");
            }
            else
            {
                mostrarAvaliacoes(
                    jogos,
                    avaliacoes,
                    qtdAvaliacoes,
                    quantidadeJogos); // mostrar avaliacoes
            }
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