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