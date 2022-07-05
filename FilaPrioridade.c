#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h"

//-------------------------------//
// Definição do struct Paciente
//-------------------------------//
typedef struct paciente{
  char nome[30];
  int risco;
}Paciente;
//-------------------------------//



//----------------------------------------//
// Definição do struct Fila de Pacientes
//----------------------------------------//
struct fila{

  // Tamanho da árvore definido arbitrariamente, tentando simular
  // um hospital pequeno de uma cidade como Itajubá, que possui
  // 30 leitos dedicados ao tratamento de COVID-19   
  Paciente arvore[15];
  //------------------------------------------------------------//

  int tamanho;
};
//-------------------------------//



//---------------------------------------------//
// Função para alocar memória do tipo Paciente
//---------------------------------------------//
Paciente* criar_paciente(){
  Paciente *no = (Paciente*) malloc(sizeof(Paciente));  
  return no;
}
//---------------------------------------------//



//---------------------------------------------//
// Função para alocar memória do tipo Fila
//---------------------------------------------//
Fila* criarFila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi == NULL){
        return NULL;
    }

    else {
      	fi->tamanho = 0;
    }

    return fi;
}
//---------------------------------------------//



//---------------------------------------------//
// Função para inserir um novo elemento no Heap
//---------------------------------------------//
void inserir_paciente(Fila *fila, char *nome, int risco){

	//Criando elementos auxiliares
	Paciente *aux, *newPaciente;
	aux = criar_paciente();
	newPaciente = criar_paciente();
  int tamanhoVetor = fila->tamanho;

	//Carregando o novo paciente com seus dados  
  strcpy(newPaciente->nome, nome);
	newPaciente->risco = risco;

	//Insere o paciente no final da arvore
	fila->arvore[tamanhoVetor] = *newPaciente;


	int idFilho = tamanhoVetor + 1;
	int idPai = idFilho / 2;

	//Mantendo o Heap consistente
	while(idFilho > 1){
		//Encontra o nó pai
		idPai = idFilho / 2;

		//Caso o valor do risco do nó filho seja menor (prioridade maior) que a do nó pai, troca de lugar. 
		if(fila->arvore[idFilho-1].risco < fila->arvore[idPai-1].risco){
			*aux = fila->arvore[idPai-1];
			fila->arvore[idPai-1] = fila->arvore[idFilho-1];
			fila->arvore[idFilho-1] = *aux;
			idFilho = idPai;
		} else{
			idFilho = 0;
		}
	};

  fila->tamanho++;

  free(aux);
  free(newPaciente);
	return ;
}
//---------------------------------------------//



//---------------------------------------------//
// Remove o paciente da fila e chama seu nome
//---------------------------------------------//
void chamar_paciente(Fila *fila){

	//Criando elementos auxiliares
	int ok = 0;
	int idPai = 1;
	int idFilhoLeft;
	int idFilhoRight;
  	int tamanhoVetor = fila->tamanho;
	
	Paciente *pop, *aux;
	pop = criar_paciente();
  aux = criar_paciente();

	//Retira o nó raiz e coloca em seu lugar o ultimo nó
	*pop = fila->arvore[0];
	fila->arvore[0] = fila->arvore[tamanhoVetor-1];

	//Mantendo o Heap consistente
	//Avalia o(s) filho(s). Caso um filho seja menor que o pai, troca.
	//Repete até que não exista mais filhos ou que o pai seja menor que os filhos.
	while(ok == 0){

		//Definindo os filhos
		idFilhoLeft = idPai*2;
		idFilhoRight = 1 + idPai*2;

		//Caso o pai só possua o filho da esquerda...
		if(idFilhoLeft <= tamanhoVetor && idFilhoRight > tamanhoVetor){
			//Caso a raiz seja menor que esse filho...
			if(fila->arvore[idPai-1].risco > fila->arvore[idFilhoLeft-1].risco){
				*aux = fila->arvore[idPai-1];
				fila->arvore[idPai-1] = fila->arvore[idFilhoLeft-1];
				fila->arvore[idFilhoLeft-1] = *aux;
				idPai = idFilhoLeft;
				ok = 1;
			}else{
				ok = 1;
			}
		//Caso o pai não possua nenhum filho...
		}else if(idFilhoLeft > tamanhoVetor && idFilhoRight > tamanhoVetor){
			ok = 1;
		//Caso o pai possua os dois filhos...
		}else{
			//Caso o nó da esquerda seja o menor...
			if(fila->arvore[idFilhoLeft-1].risco <= fila->arvore[idFilhoRight-1].risco){
				//Caso a raiz seja menor que esse filho...
				if(fila->arvore[idPai-1].risco > fila->arvore[idFilhoLeft-1].risco){
					*aux = fila->arvore[idPai-1];
					fila->arvore[idPai-1] = fila->arvore[idFilhoLeft-1];
					fila->arvore[idFilhoLeft-1] = *aux;
					idPai = idFilhoLeft;
				//Caso contrario, deixa como está e encerra a reordenação
				}else{
					ok = 1;
				}
			//Caso o nó da direita seja o menor...
			}else{
				//Caso a raiz seja menor que esse filho...
				if(fila->arvore[idPai-1].risco > fila->arvore[idFilhoRight-1].risco){
					*aux = fila->arvore[idPai-1];
					fila->arvore[idPai-1] = fila->arvore[idFilhoRight-1];
					fila->arvore[idFilhoRight-1] = *aux;
					idPai = idFilhoRight;
				//Caso contrario, deixa como está e encerra a reordenação
				}else{
					ok = 1;
				}
			}
		}	
	}

	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	printf("\n|                                       |");
	printf("\n|        PROXIMO PACIENTE CHAMADO       |");
	printf("\n|                                       |");
	printf("\n          %s    -    %d  \n", pop->nome, pop->risco);
	printf("\n|                                       |");
	printf("\n|                                       |");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	fila->tamanho--;
  free(pop);
  free(aux);
	
	return;
}
//---------------------------------------------//



//---------------------------------------------//
// Retorna o tamanho da fila de pacientes
//---------------------------------------------//
int tamanhoFila(Fila *filaDePacientes){
  
  return filaDePacientes-> tamanho; 

}
//---------------------------------------------//



//---------------------------------------------//
// Imprime a fila de pacientes
//---------------------------------------------//
int imprimir_fila(Fila *fila){
	Paciente *aux;
  int tamanhoVetor = fila->tamanho;
	aux = criar_paciente();
  
  
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\n|                                       |");
  printf("\n|          ~ FILA DE PACIENTES ~        |");
  printf("\n|                                       |");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n");
	
  
  for(int c = 0; c < tamanhoVetor; c++){
		*aux = fila->arvore[c];
        printf("(%d)\t - \t%s   -   %d\n", c, aux->nome, aux->risco);
	}

  free(aux);
	return 0;
}
//---------------------------------------------//



//---------------------------------------------------------------------------//
// Funcao que aguarda a digitacao de um caractere para continuar a execucao
//---------------------------------------------------------------------------//
void funcaoAguardar () {
  char continuar;

  printf("\n\nDigite qualquer caraceter e aperte enter para continuar\n");
  
  //Mantendo o programa aguardando a digitacao de um caracetre
  do
  scanf("%c", &continuar);
  while(continuar<32 || continuar>126);

  return;
}
//---------------------------------------------------------------------------//



//---------------------------------------------------------------------------//
// Funcao que desaloca a memoria utilizada no programa
//---------------------------------------------------------------------------//
void desalocar(Fila *fila) {
  
  system("clear");
  free(fila);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\n|                                       |");
  printf("\n|   Todos pacientes foram chamados!!    |");
  printf("\n|                                       |");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n\n\n\n");

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\n|      Encerrando o programa...        |");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
  return;
}
//---------------------------------------------------------------------------//
