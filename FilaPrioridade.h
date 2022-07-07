#ifndef _PACIENTES
#define _PACIENTES

//typedef struct paciente* Pacientes;
typedef struct fila Fila;

//Função para inserir um novo paciente na fila
void inserir_paciente(Fila *fila, char *nome, int risco);

//Função para remover um paciente da fila e chama-lo
void chamar_paciente(Fila *fila);

//Imprime a fila de paciente
int imprimir_fila(Fila *fila);

// Funcao para aguardar digitacao de um caractere -> Sinal de continuacao
void funcaoAguardar();


Fila* criarFila();
void desalocar(Fila *fila);
int tamanhoFila(Fila *filaDePacientes);

#endif 