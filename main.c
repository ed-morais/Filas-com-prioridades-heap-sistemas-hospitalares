// Bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// Bibliotecas do projeto
#include "FilaPrioridade.h"

/*
[Fila de Prioridade para Pacientes com Sintomas de COVID-19]

O sistema consiste em uma fila de pacientes que apresentam os diferentes graus de risco do COVID-19.
Devido à escassez de testes, os pacientes são graduados de 1 a 5 em de acordo com o grupo de risco, para então serem
chamados para realizar os testes, de acordo com risco que eles apresentam.
 - Pacientes mais críticos possuem prioridade maior nos exames, recebendo risco = 1;
 - Pacientes com menor risco possuem prioridade menor nos exames, recebendo risco = 5;

O sistema deve possuir opções de inserir ou chamar pacientes. 

*/

//----Prototipo da funcao que anota dados de um paciente----//
void dadosPaciente();
//----------------------------------------------------------//




//-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-Programa principal-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
int main(void) {

	int auxiliarTamanho;       //Auxiliar para controlar retirada de senhas

	char nome[30];             //Auxiliar para receber nome de paciente
	int prioridade;            //Auxiliar para receber prioridade de paciente

	int contadorPacientes = 0; //Funcionará como contador do loop
	char checkContinue = ' ';  //Funcionará como contador do loop

	//Criando fila
	Fila *filaDePacientes = NULL; 
  filaDePacientes = criarFila();
  //


  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\n|                                                        |");
  printf("\n|                 ~ Fila de atendimento  ~               |");
  printf("\n|                                                        |");
  printf("\n|    (Testes para pacientes com suspeita de COVID-19)    |");
  printf("\n|                                                        |");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  printf("\n\nDevido a escassez de testes, no momento os pacientes são classificados");
  printf("\nde 1 a 5, sendo testados primeiramente os com maior chance de portarem");
  printf("\na doença\n\n");
  

  funcaoAguardar();

  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  //                    LOOP PRINCIPAL => Fila recebendo pacientes
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  do
  {
    system("clear");

    if (contadorPacientes == 0) {
      //Se ainda nao houverem pacientes, cadastrar pacientes
      dadosPaciente(nome, &prioridade);
      inserir_paciente(filaDePacientes, nome, prioridade);
      contadorPacientes++;
    }


    else{
      //Se ja houverem pacientes, perguntar se deseja cadastrar outro
      printf("Deseja adicionar outro paciente a fila? \n"); 
      printf("Digite S para sim, N para não\n");
      
      do{ 
      scanf("%c", &checkContinue);
      }
      //Condicoes de leitura da variavel que checa se adiciona pacientes
      while (checkContinue != 'S' && checkContinue != 's'
      && checkContinue != 'N' && checkContinue != 'n');
      //-------------------------------------------------------------//




      // Se informou que deseja adicionar outro paciente, chama funcao de informar
      // dados de paciente
      if (checkContinue == 'S' || checkContinue == 's') {
        system("clear");
        dadosPaciente(nome, &prioridade);
        inserir_paciente(filaDePacientes, nome, prioridade);
        contadorPacientes++;
      }

      // Se informou que nao deseja adicionar outro paciente, sai do
      // loop de leitura
      if (checkContinue == 'N' || checkContinue == 'n') 
        break;
    }
  // Condicao de continuar a informar pacientes
  // - Vetor nao preenchido
  // - Usuario informar 'N'
  } while ( (contadorPacientes != 15) 
  || (checkContinue != 'S') 
  || (checkContinue != 's') );


	

  //  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=///
  //     Aviso de inicio de fim das operacoes de retirada de senhas   ///
  //                e inicio de chamada das senhas                    ///
  //  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=///

  auxiliarTamanho = tamanhoFila(filaDePacientes);
  system("clear");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\n|   ATENCAO: INICIO DOS ATENDIMENTOS   |\n");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  funcaoAguardar();
  system("clear");



  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  //                    LOOP SECUNDARIO => Chamando pacientes
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	for (int i = 1; i<= auxiliarTamanho; i++) {
    system("clear");
    chamar_paciente(filaDePacientes);
    printf("\n\n\n\n\n");
  	imprimir_fila(filaDePacientes);
    funcaoAguardar();

  }

  desalocar(filaDePacientes);
  
  
  return 0;

	


}
//-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-Fim do Programa principal-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-




//----------------Funcao que anota dados de um paciente---------------------//
void dadosPaciente(char *nome, int *prioridade){

  printf("\nPor favor, informe o nome do Paciente: ");
  scanf(" %[^\n]s", nome); 

  printf("\nPor favor, informe a prioridade de atendiomento do Paciente");
  printf("\n(Obrigatoriamente entre 1 e 5):\n");
  do{ 
    scanf("%d", prioridade);
  }
  //Condicoes de leitura da variavel que checa prioridade dos pacientes
  //Precisa estar entre 1 e 5
  while (*prioridade != 1 && *prioridade != 2
  && *prioridade != 3 && *prioridade != 4 && *prioridade != 5);
  //------------------------------- ------------------------------//
}
//-------------------------------------------------------------------------//