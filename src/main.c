#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 1000 //numero maximo de contatos

typedef enum {
    TELA_SAIR=-1,
    TELA_PRINCIPAL,//0
    TELA_CADASTRAR,//1
    TELA_DESCADASTRAR,//2
    TELA_LISTAR_TODOS,//3
} Telas;

typedef struct
{
    char nome[128]; //nome completo
    char telefone[64];//não é um número
} Contato;

typedef struct
{
    Telas menu;
    int totalContatos;
    Contato contatos[MAX_CONTATOS];
} AgendaTelefonica;

int main(void)
{
    AgendaTelefonica agenda;
    //zera todos os bytes de agenda
    memset(&agenda, 0x0, sizeof(agenda));

    //menu da agenda
    agenda.menu = TELA_PRINCIPAL;

    while (agenda.menu != TELA_SAIR)
    {
        switch (agenda.menu)
        {
            case TELA_PRINCIPAL:
            {
                    printf("---------------------------------------\n");
                    printf("\tAGENDA TELEFONICA:\n");
                    printf("---------------------------------------\n");
                    int opcao =-1;
                    do
                    {
                        printf("Escolha uma opcao:\n");
                        printf("\tdigite 1 para cadastrar contato\n");
                        printf("\tdigite 2 para remover contato\n");
                        printf("\tdigite 3 para listar todos os contatos\n");
                        printf("\tdigite 0 para sair do programa\n");
                        scanf("%d", &opcao);
                        //int c = 0; //Solução empírica para esvaziamento de buffer
                        //while ((c = getchar()) != '\n' && c != EOF) {}
                    } while (opcao < 0 || opcao > 3);

                    if (opcao == 0)
                        agenda.menu = TELA_SAIR;

                    if (opcao == 1)
                    {
                        agenda.menu = TELA_CADASTRAR;
                        if (agenda.totalContatos >= MAX_CONTATOS)
                        {
                            printf("\tAgenda estah lotada, nao eh possivel adicionar novos contatos\n");
                            agenda.menu = TELA_PRINCIPAL;
                        }
                    }

                    if (opcao == 2)
                    {
                        agenda.menu = TELA_DESCADASTRAR;
                        if (agenda.totalContatos == 0)
                        {
                            printf("\tNao hah nenhum contato cadastrado para remover\n");
                            agenda.menu = TELA_PRINCIPAL;
                        }
                    }

                    if (opcao == 3)
                    {
                        agenda.menu = TELA_LISTAR_TODOS;
                        if (agenda.totalContatos == 0)
                        {
                            printf("\tAgenda nao tem nenhum contato para listar\n");
                            agenda.menu = TELA_PRINCIPAL;
                        }
                    }
            }
            break;

            case TELA_CADASTRAR:
                {
                    //volta para tela principal
                    agenda.menu = TELA_PRINCIPAL;
                }
                break;
            case TELA_DESCADASTRAR:
                {
                    //volta para tela principal
                    agenda.menu = TELA_PRINCIPAL;
                }
                break;
            case TELA_LISTAR_TODOS:
                {
                    //volta para tela principal
                    agenda.menu = TELA_PRINCIPAL;
                }
                break;
            default:
                agenda.menu = TELA_PRINCIPAL;
                break;
        }
    }
    return 0;
}