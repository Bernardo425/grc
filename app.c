#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "membroLista.h"



/////////////////// 1- Funções para o gerenciamento de membros /////////////
void membroResgistrar(MembroListaT ** membros){

    MembroT membro;

    //recebendo os dados do membro
    printf("Insira o nome__: ");
    scanf("%s", membro.nome);
    printf("Insira o email__: ");
    scanf("%s", membro.email);
    printf("Insira a senha__: ");
    scanf("%s", membro.senha);

    if((* membros = inserirMembroLista(*membros, membro)) != NULL) 
        printf("Membro registrado com sucesso\n\n");
}

void membroApagar(MembroListaT ** membros){
    if(*membros == NULL){
        printf("A lista de membros encontra-se vazia!\n");
        return;
    }else{
        int id;
        printf("Digite o id do membro_: ");
        scanf("%d", &id);
        MembroListaT * m = procurarMEmbroLista(*membros, id);
        if(m == NULL){
            printf("membro não encontrado, tente novamente\n");
        }else{
            printf("Removendo o membro <%s>\n ...", m->membro.nome);
            if(removerMembroLista(membros, id) == TRUE) printf("Membro removido com sucesso\n");
            else  printf("Erro ocorrido ao remover membro, tente novamente\n");
        }
    }
}

void procurarMembro(MembroListaT * membros){
    int id;
    printf("Digite o id do membro_: ");
    scanf("%d", &id);
    MembroListaT * m = NULL;
    if((m = procurarMEmbroLista(membros, id)) == NULL){
        printf("membro não encontrado, tente novamente\n");
    }else{
        printf("Nome: %s\n", m->membro.nome);
        printf("Email: %s\n", m->membro.email);
    }
}

int iniciar() {
    MembroListaT * membros = NULL;


    char op = '0';

    do{
        fflush(stdin);
        system("cls");
        printf("\t==================Sistema de rede de computadores==================\n\n\n");
        printf("Menu Principal\n");
        printf("1- Gerenciar Membros\n");
        printf("2- Gerenciar ligacoes entre membros\n");
        printf("3- Gerenciar Span\n");
        printf("4- Fazer login\n");
        printf("0- Terminar simulação\n");
        printf("Escolha uma opção acima\n");
        printf(">> ");
        scanf("%c", &op);
        fflush(stdin);
        switch(op){
            case '1':
                do{
                    fflush(stdin);
                    system("cls");

                    printf("====Gerenciar Membros====\n");
                    printf("1- Imprimir membros registrados\n");
                    printf("2- Registrar membro\n");
                    printf("3- Remover membro\n");
                    printf("4- Procurar membro\n");
                    printf("5- voltar\n");
                    printf("Escolha uma opção acima\n");

                    printf(">> ");
                    scanf("%c", &op);
                    
                    system("cls");
                    switch(op){
                    case '1':
                        printf("==Listando membros registrados==\n");
                        if(membros == NULL) printf("a lista de membros encontra-se vazia!\n");
                        apresentaMembrosLista(membros);
                        break;
                    case '2':
                        printf("==Registrando membro==\n");
                        membroResgistrar(&membros);
                        break;
                    case '3':
                        printf("==Removendo membro==\n");
                        membroApagar(&membros);
                        break;
                    case '4':
                        printf("==Procurando membro==\n");
                        procurarMembro(membros);
                        break;
                    case '5':
                        break;
                    default:
                        printf("\nentrada invalida, tente novamente\n");
                        break;
                    }

                    system("pause");
                }while(op != '5');
                op = '1';
                break;
            case '0':
                printf("Terminando simulação..\n");
                printf("Apagando lista de membros... ");
                deletarListaMembros(membros);
                printf("feito\n\n");
                break;
            default: 
                printf("\nentrada invalida, tente novamente\n");
                break;
        }
        system("pause");
    }while(op != '0');
    printf("Saindo...");
}
