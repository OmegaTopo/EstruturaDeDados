#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//MATRIZ TAD VETOR

struct matriz  // Criação da estrutura.
{   
  int linha;    // Declaração de variavel de tipo inteiro.
  int coluna;   // Declaração de variavel de tipo inteiro.
  float* valor; // Declaração de variavel de tipo flutuante.

};

// O que faz e para utilizar nesse contexto?
typedef struct matriz Matriz; // definição de TAD

// Explicação: Cria a estrutura 
Matriz* cria(int m, int n){         // Função para criação de Matriz

  Matriz* mat = (Matriz*)malloc(sizeof(Matriz));        // Declaração da função malloc para alocar memória 

  if (mat == NULL){ 
    printf("Memoria insuficiente!\n");                  // imprime a mensagem de memória insuficiente
    exit(1);                                            // fecha o programa
  }

  mat->linha = m;                                       // atribui m para a variavel linha da estrutura mat
  mat->coluna = n;                                      // atribui n para a variavel coluna da estrutura mat
  mat->valor = (float*)malloc(m*n*sizeof(float));       // atribui linha e coluna para o valor

  return mat;

}

void vazia(Matriz* mat){

}

// Explicação: Função que libera a memória da matriz.
void libera(Matriz* mat){                         // Criação da variavel libera de tipo void.

  free(mat->valor);                               // Libera a memória de valor dentro de mat.
  free(mat);                                      // Libera a memória de mat.

}

// Explicação: Acessa o valor da posição determinada pelas coordenadas recebidas.
float acessa(Matriz* mat, int i, int j) {                           // declaração de variavel flutuante de nome acessa

  int k;                                                            // decalração de variavel de tipo inteira "k"

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {      // 
    printf("Acesso invalido!\n");                                   // imprime a frase "acesso invalido"
    exit(1);                                                        // fecha o programa
  }

  k = i * mat->coluna + j;

  return mat->valor[k];

}

// Explicação: Atribui valor para um local específico da matriz.
void atribui(Matriz* mat, int i, int j, float valor) {                  // criação da variavel atribui de tipo void

  int k;                                                                // declaração de variavel de tipo inteira "k"

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {
    printf("Atribuicao invalida!\n");
    exit(1);
  }

  k = i * mat->coluna + j;

  mat->valor[k] = valor;

}

// Explicação: Retorna a quantidade de linhas da matriz.
int linhas(Matriz* mat){

  return mat->linha;

}

// Explicação: Retorna a quantidade de colunas da matriz.
int colunas(Matriz* mat){

  return mat->coluna;

}

// Explicação: Função que percorre a matriz e imprime os valores superiores à diagonal principal.
void superior(Matriz* mat) {

  for (int i = 0; i < mat->linha; i++) {
    for (int j = 0; j < mat->coluna; j++) {
      if (i < j) {
        printf("[%d][%d] = %.1f\n", i, j, acessa(mat, i, j));
      }
    }
  }
}

// Explicação: Função que percorre a matriz de acordo com o tamanho da matriz desejada e valida se o valor faz parte de uma das extremidades.
void extremidades(Matriz* mat){

  for (int i = 0; i < mat->linha; i++) {                   // Percorre todas as linhas
    for (int j = 0; j < mat->coluna; j++) {                 // Percorre todas colunas de determinada linha
      if ((i == 0 && j == 0) || (i == 0 && j == mat->coluna - 1) || (i == mat->linha - 1 && j == 0) || (i == mat->linha - 1 && j == mat->coluna - 1)) { // Valida se o valor é uma das extremidades, se sim, exibe, se não, parte para o próximo
        printf("Valor extremidade (%d, %d): %.2f\n", i, j, acessa(mat, i, j));
      }
    }
  }
}

int main(){             

    Matriz *m;          
    char manterSair;    
    int menuEscolha, linha, coluna, i, j;
    float valor;    

    printf("-------------- GRUPO 3 (Luizas e os Gatoes) --------------\n");

    do { // Do while principal para sair do software 
        
        // Menu de interação 
        do {
            printf("----------------------------------------------------------");
            printf("\n\nMENU DE INTERACAO \n\n");
            printf("(1) Criacao da matriz\n");
            printf("(2) Atribui valores a matriz\n");
            printf("(3) Imprimi a matriz\n");
            printf("(4) Imprimir superior da diagonal principal\n");
            printf("(5) Imprimir as 4 extremidades\n");
            printf("(6) Encerrar o programa\n\n");
            scanf("%d", &menuEscolha);
            
            if(menuEscolha < 0 || menuEscolha > 6)
            {
                printf("\nValor invalido\nRepita...\n");
            }
            
        } while(menuEscolha < 0 || menuEscolha > 6);
        
        switch(menuEscolha)
        {
            case 1: // criar a matriz (pergunta qual tamanho)
                printf("Insira os valores que deseja para matriz!\n");
                
                do{
                    printf("Linhas: ");
                    scanf("%d", &linha);

                        if (linha <= 0 || linha > 10)
                        {
                            printf("Valor invalido\nRepita...\n");
                        }
                } while(linha <= 0 || linha > 10);

                do{
                    printf("Colunas: ");
                    scanf("%d", &coluna);

                        if (coluna <= 0 || coluna > 10)
                        {
                            printf("Valor invalido\nRepita...\n");
                        }
                } while(coluna <= 0 || coluna > 10);    

                m = cria(linha, coluna);
                
                if ((linha * coluna) > 0)
                {
                    printf("\nMatriz criada com sucesso!\n");    
                }else
                {
                    printf("\nA matriz nao foi inicializada, tente novamente.\n");
                }               
              break;
            case 2: // Atribui valores a matriz
                if (linha * coluna == 0)
                {
                   printf("\nA matriz nao foi inicializada, tente novamente.\n");
                }else 
                {
                     printf("Insira os valores da matriz! \n");
                    for (i = 0; i < m->linha; i++)
                    {
                        for (j = 0; j < m->coluna; j++)
                        {   
                            printf("Posicao [%d][%d]: ", i, j);
                            scanf("%f", &valor);
                            atribui(m, i, j, valor);
                        }
                    }
                }
                break; 
            case 3:  // Imprimi a matriz
                if (linha * coluna == 0)
                {
                   printf("\nA matriz nao foi inicializada, tente novamente.\n");
                }else 
                {
                    printf("\nMatriz: \n");
                    for (i = 0; i < linha; i++)
                    {
                        for (j = 0; j < coluna; j++)
                        {   
                            printf("[%d][%d] = %.1f\n", i, j, acessa(m, i, j));
                    }
                    }
                }
                break;
            case 4:  // Imprimir superior da diagonal principal
                if (linha * coluna == 0){
                  printf("\nA matriz nao foi inicializada, tente novamente.\n");
                } 
                else if (linha != coluna){
                    printf("Somente matrizes quadradas acessam esta funcao!\n");
                }else{
                  superior(m); 
                }
                break;
            case 5: // Imprimir as 4 extremidades
                if (linha * coluna == 0){
                  printf("\nA matriz nao foi inicializada, tente novamente.\n");
                } else 
                {
                  extremidades(m); 
                }
                break;
            case 6: // Encerrar o software 
                system("cls");
                printf("\n\nSistema encerrado \n");
                libera(m);
                exit(1);
                break;
            default: 
                printf("Valor invalido");
                break;
        }   
           
    } while(menuEscolha != 6);
      
    return 0;
} 
        

/*
Comente o codigo explicando as funcoes conforme solicitado.
O codigo devera ser apresentado e explicado pelo grupo em aula.
Implemente a main de forma que todas as funcoes sejam utilizadas amplamente pelo usuario.
Ao executar o programa deve ser solicitado ao usuario se deseja criar a matriz: 
  SIM: 
    -Executar a funcao de criacao da matriz.
    -Em seguida deve abrir um menu que permita utilizar amplamente as demais funcoes.
    -Implemente uma opcao que imprime as quatro extremidades da matriz.
    -Implemente a opcao especifica de seu grupo.
    -O programa devera executar ate que o usuario escolha a opcao sair, liberando a memoria e encerrando a execucao do programa.
  NAO: 
    -Encerrar a execucao do programa.


Grupo 3:
-Implemente uma opcao que imprime todos os numeros acima da diagonal principal, 
essa opcao somente pode funcionar se for matriz quadrada quando a quantidade de linhas e colunas 
sao iguais.
*/