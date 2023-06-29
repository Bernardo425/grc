#define TRUE 1
#define FALSE 0

typedef int bool;
// registro que define um usuario
typedef struct membroType{
    int id; // identificador unico de quem envia a membro
    char nome[100];
    char email[100];
    char senha[100];
} MembroT;

// registro que define uma lista de membros
typedef struct membroLista{
    MembroT membro; // o valor no da lista, neste caso a membro
    struct membroLista *prox; // um ponteiro que aponta para o proximo no
} MembroListaT;

//função para inserir um membro na lista
MembroListaT * inserirMembroLista(MembroListaT * membros,MembroT membro);

//função para procurar um membro na lista, retorna o membro caso o mesmo é encontrado, NULL caso negativo
MembroListaT * procurarMEmbroLista(MembroListaT * membros, int id);
//função pra remover um membro de uma lista
bool removerMembroLista(MembroListaT ** membros, int id);

//função recusiva para apresentar todos os membros registrados
void apresentaMembrosLista(MembroListaT * membros);

//função recusiva para deletar a lista de membros
void deletarListaMembros(MembroListaT * membros);
