#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int iniciar() {
    GrafoT * grafo = inicializarGrafo(6);
    inserirLigacao(grafo, 1, 5);
    inserirLigacao(grafo, 1, 2);
    inserirLigacao(grafo, 5, 2);
    apresentaGrafo(grafo);
    removeTodasArestas(grafo, 1);

    apresentaGrafo(grafo);
    destruirGrafo(grafo);
}
