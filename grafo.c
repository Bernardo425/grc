#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct grafoT{
    int v; // indica o número de vertices do grafo
    int a; // indica o número de arestas no grafo
    int **adj; // um pontonteiro prara uma matriz de adjacencias
}GrafoT;

// função responsável por inicializar uma matrix de adjacencia
// retorna uma matrix
int ** matrixInit(int linha, int coluna){
    int ** mtx = (int *) malloc(linha * sizeof(int *)); // aloca memoria para m linhas do tipo * int
    if(mtx == NULL) return NULL;

    for(int i = 0; i < linha; ++i){
        mtx[i] = (int *) malloc(coluna * sizeof(int)); //aloca n colunas para cada linha alocada anteiormente
        if(mtx[i] == NULL) return NULL;
    }

    //para cada elemento da matriz, é atribuido o valor 0 inicialmente
    for(int i = 0; i < linha;  ++i){
        for(int j = 0; j < coluna; ++j){
            mtx[i][j] = 0;
        }
    }

    return mtx;
}

// função responsavel por inicializar inicializar um grafo
// retorna um grafo vazio
GrafoT * inicializarGrafo(int v){
    GrafoT * g = (GrafoT *) malloc(sizeof(GrafoT));
    g->v = v;
    g->a = 0; // inicialmente no grafo existem 0 arestas
    g->adj = matrixInit(v, v);
}



//função responsável por inserir ligação entre dois vertices em um grafo
// faz a uniao de um vertice inicial e um vertice final
// faz a ligação de A - B  e B - A caso não existam
//retorna TRUE se a aresta foi criada com sucesso e em caso de falha retorna FALSE
bool inserirLigacao(GrafoT * grafo, int vetice_inicial, int vertice_final){
    if(grafo == NULL) return FALSE;
    // para cada elemento a ser inserido, é subtraido 1, pois cada elemento na matriz é representado no intervalo de 0 a grafo-v - 1;
    vertice_final--;
    vetice_inicial--;
    // aqui é verificado se o vertice_inicial e final são positivos ou menores que o número de vertices no grafo e se ambos são distintos
    if((vetice_inicial < 0) || (vetice_inicial >= grafo->v)) return FALSE;
    if((vertice_final < 0) || (vertice_final >= grafo->v)) return FALSE;
    if(vetice_inicial == vertice_final) return FALSE;

    if(grafo->adj[vetice_inicial][vertice_final] == 0){
        grafo->adj[vetice_inicial][vertice_final] = 1;
        grafo->a++;
    }

    if(grafo->adj[vertice_final][vetice_inicial] == 0){
        grafo->adj[vertice_final][vetice_inicial] = 1;
        grafo->a++;
    }

    return TRUE;
}

//função responsável por inserir uma aresta em um grafo
// faz a uniao de um vertice inicial e um vertice final
// faz a ligação de A - B  caso não exista
//retorna TRUE se a aresta foi criada com sucesso e em caso de falha retorna FALSE
bool inserirAresta(GrafoT * grafo, int vetice_inicial, int vertice_final){
    if(grafo == NULL) return FALSE;
    // para cada elemento a ser inserido, é subtraido 1, pois cada elemento na matriz é representado no intervalo de 0 a grafo-v - 1;
    vertice_final--;
    vetice_inicial--;
    // aqui é verificado se o vertice_inicial e final são positivos ou menores que o número de vertices no grafo e se ambos são distintos
    if((vetice_inicial < 0) || (vetice_inicial >= grafo->v)) return FALSE;
    if((vertice_final < 0) || (vertice_final >= grafo->v)) return FALSE;
    if(vetice_inicial == vertice_final) return FALSE;

    if(grafo->adj[vetice_inicial][vertice_final] == 0){
        grafo->adj[vetice_inicial][vertice_final] = 1;
        grafo->a++;
    }

    return TRUE;
}

//função responsável por remover uma ligação do grafo
// remove aresta entre dois verices.
// remove a ligação de A - B e de B - A caso existam
// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removerLigacao(GrafoT * grafo, int vetice_inicial, int vertice_final){
    if(grafo == NULL) return FALSE;
    // para cada elemento a ser inserido, é subtraido 1, pois cada elemento na matriz é representado no intervalo de 0 a grafo-v - 1;
    vertice_final--;
    vetice_inicial--;
    // aqui é verificado se o vertice_inicial e final são positivos ou menores que o número de vertices no grafo e se ambos são distintos
    if((vetice_inicial < 0) || (vetice_inicial >= grafo->v)) return FALSE;
    if((vertice_final < 0) || (vertice_final >= grafo->v)) return FALSE;
    if(vetice_inicial == vertice_final) return FALSE;

    if(grafo->adj[vetice_inicial][vertice_final] == 1){
        grafo->adj[vetice_inicial][vertice_final] = 0;
        grafo->a--;
    }

    if(grafo->adj[vertice_final][vetice_inicial] == 1){
        grafo->adj[vertice_final][vetice_inicial] = 0;
        grafo->a--;
    }
    return TRUE;
}

//função responsável por remover uma unica aresta do grafo
// remove aresta entre dois verices.
// remove a ligação de A - B  caso exista
// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removerAresta(GrafoT * grafo, int vetice_inicial, int vertice_final){
    if(grafo == NULL) return FALSE;
    // para cada elemento a ser inserido, é subtraido 1, pois cada elemento na matriz é representado no intervalo de 0 a grafo-v - 1;
    vertice_final--;
    vetice_inicial--;
    // aqui é verificado se o vertice_inicial e final são positivos ou menores que o número de vertices no grafo e se ambos são distintos
    if((vetice_inicial < 0) || (vetice_inicial >= grafo->v)) return FALSE;
    if((vertice_final < 0) || (vertice_final >= grafo->v)) return FALSE;
    if(vetice_inicial == vertice_final) return FALSE;

    if(grafo->adj[vetice_inicial][vertice_final] == 1){
        grafo->adj[vetice_inicial][vertice_final] = 0;
    }

    grafo->a--;
    return TRUE;
}

//função responsável por remover todas as ligações de e para um vertice

// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removeTodasArestas(GrafoT * grafo, int vertice){

    if(grafo == NULL) return FALSE;
    // para cada elemento a ser inserido, é subtraido 1, pois cada elemento na matriz é representado no intervalo de 0 a grafo-v - 1;
    vertice--;
    // aqui é verificado se o vertice é positivo ou menor que o número de vertices no grafo
    if((vertice < 0) || (vertice >= grafo->v)) return FALSE;


    for(int i = 0; i < grafo->v; ++i){
        if(grafo->adj[vertice][i] == 1){
            grafo->adj[vertice][i] = 0;
            grafo->a--;
        }
    }

    for(int i = 0; i < grafo->v; ++i){
        if(grafo->adj[i][vertice] == 1){
            grafo->adj[i][vertice] = 0;
            grafo->a--;
        }
    }
    return TRUE;
}


bool existeAresta(GrafoT * grafo, int vetice_inicial, int vertice_final){
    if(grafo == NULL) return FALSE;

    // aqui é verificado se o vertice_inicial e final são positivos ou menores que o número de vertices no grafo e se ambos são distintos
    if((vetice_inicial < 0) || (vetice_inicial >= grafo->v)) return FALSE;
    if((vertice_final < 0) || (vertice_final >= grafo->v)) return FALSE;
    if(vetice_inicial == vertice_final) return FALSE;

    return (grafo->adj[vetice_inicial][vertice_final] == 1)?TRUE:FALSE;
}


//função responsável por apresentar um grafo
void apresentaGrafo(GrafoT * grafo){
    for(int i = 0; i < grafo->v; ++i){
        printf("%2d:", i + 1);
        for(int j = 0; j < grafo->v;++j){
            if(grafo->adj[i][j] == 1) printf(" --%2d", j + 1);
        }
        printf("\n");
    }
}

// função responsável por destruir um grafo
void destruirGrafo(GrafoT * grafo){
    if(grafo != NULL){
        for(int i = 0; i < grafo->v; ++i){
            free(grafo->adj[i]);
        }
        free(grafo->adj);
        free(grafo);
    }
}
