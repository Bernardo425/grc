#define TEMANHO_CARACTERES 26

typedef struct spanTrieT{
    int folha;
    struct spanTrieT * caracter[TEMANHO_CARACTERES];
}SpanTrieT;

SpanTrieT * criarNo();

int inserirNo(SpanTrieT * raiz, char * str);

int procurarPalavra(SpanTrieT * raiz, char *str);

int temFilhos(SpanTrieT * raiz);

int deletarNo(SpanTrieT ** raiz, char * str);
