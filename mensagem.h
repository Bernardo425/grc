// registro que define uma mensagem
typedef struct mensagemType{
    int emissor; // identificador unico de quem envia a mensagem
    int receptor; // Identificador unico de quem se destina a mensagem
    char texto[250]; //o conteudo mda mensagem
    char data[10]; //a data do envio da mensagem DD/MM/AAAA
    int span; // define se uma mensagem eh um span ou uma mensagem valida. 0 se a mensagem eh uma mensagem valida e 1 se eh um span
} MensagemT;


// registro que define uma lista de mensagens
typedef struct mensagemLista{
    MensagemT mensagem; // o valor no da lista, neste caso a mensagem
    struct mensagemLista *prox; // um ponteiro que aponta para o proximo no
} MensagemListaT;

//Inserir elementos em uma lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//    2- Variavel do tipo Mensagem
//funcaoo que insere um nó no inicio da lista, retorna o nó inserido, em caso de falha, retorna NULL
MensagemListaT * inserirMensagemLista(MensagemListaT * mensagens, MensagemT mensagem);

//Deletar Lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//fun��o recursiva que apaga todos os n�s de uma lista de mensagens
void deletarLista(MensagemListaT * mensagens);

//Registrar mensagem
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//    2- um inteiro, que representa um emissor
//    3- um inteiro, que representa o receptor
//    4- uma string, do texto da mensagem
//    5- uma string, da data do envio da mensagem
//    6- um inteiro, indicando se a mensagem � span ou n�o
// fun��o insere os dados de uma mensagem em uma lista e registra em um ficheiro.
// Retorna um ponteiro do �ltimo n� inserido na lista, o primeiro n�
// Retorna NULL quando n�o foi possivel ler/escrever em um ficheiro ou ocorrer falha na inser��o na lista

MensagemListaT * registrarMensagem(MensagemListaT * mensagens, int emissor, int receptor, char *texto, char *data, int span);


//Litar mensagens de um emissor ou receptor
//Parametros:
//    1- um inteiro, que representa o tipo de usuario, 1 == emissor, 2 == receptor
//    2- um inteiro, que representa a entidade do emissor ou do receptor
//    3- um inteiro, que indica se a mensagem � um span ou n�o

// esta fun��o � respons�vel retornar uma lista de mensagens, de um emissor ou de um receptor, mensagens span o v�lidas, dependendo dos par�metros da fun��o
// Retorna um ponteiro de uma lista de mensagens
// Retorna NULL quando n�o foi possivel ler/escrever em um ficheiro ou ocorrer falha na inser��o na lista

MensagemListaT * listarMensagens(int tipo, int entidade, int span);
