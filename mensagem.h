#include "mensagemLista.h"

MensagemListaT * registrarMensagem(MensagemListaT * mensagens, int emissor, int receptor, char *texto, char *data, int span);
MensagemListaT * listarMensagensEmissor(int tipo, int entidade, int span);
