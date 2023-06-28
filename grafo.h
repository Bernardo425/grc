#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct grafoT{
    int v; // indica o número de vertices do grafo
    int a; // indica o número de arestas no grafo
    int **adj; // um pontonteiro prara uma matriz de adjacencias
}GrafoT;

// função responsavel por inicializar inicializar um grafo
// retorna um grafo vazio
GrafoT * inicializarGrafo(int v);

// função responsável por inicializar uma matrix de adjacencia
// retorna uma matrix
int ** matrixInit(int linha, int coluna);

//função responsável por inserir ligação entre dois vertices em um grafo
// faz a uniao de um vertice inicial e um vertice final
// faz a ligação de A - B  e B - A caso não existam
//retorna TRUE se a aresta foi criada com sucesso e em caso de falha retorna FALSE
bool inserirLigacao(GrafoT * grafo, int vetice_inicial, int vertice_final);

//função responsável por inserir uma aresta em um grafo
// faz a uniao de um vertice inicial e um vertice final
// faz a ligação de A - B  caso não exista
//retorna TRUE se a aresta foi criada com sucesso e em caso de falha retorna FALSE
bool inserirAresta(GrafoT * grafo, int vetice_inicial, int vertice_final);

//função responsável por remover uma ligação do grafo
// remove aresta entre dois verices.
// remove a ligação de A - B e de B - A caso existam
// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removerLigacao(GrafoT * grafo, int vetice_inicial, int vertice_final);

//função responsável por remover uma unica aresta do grafo
// remove aresta entre dois verices.
// remove a ligação de A - B  caso exista
// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removerAresta(GrafoT * grafo, int vetice_inicial, int vertice_final);

//função responsável por remover todas as ligações de e para um vertice
// retorna TRUE em caso de sucesso e FALSE em caso de erro
bool removeTodasArestas(GrafoT * grafo, int vertice);

bool existeAresta(GrafoT * grafo, int vetice_inicial, int vertice_final);

//função responsável por apresentar um grafo
void apresentaGrafo(GrafoT * grafo);

// função responsável por destruir um grafo
void destruirGrafo(GrafoT * grafo);