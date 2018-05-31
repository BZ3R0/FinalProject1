/*
Autor: Caio Wallison dos Santos Rocha
Universidade Federal da Bahia
Orientadora: Aline Andrade dos Santos
Projeto de Iniciação Cientifíca e Trabalho de Conclusão de Curso
Semestre: 2018.1

Algoritmo para realizar composição de Diagramas de Sequência (DS) Extendidos
Temos um vetor ordenado como entrada para o Algoritmo. Para cada DS Extendido ordenamos suas mensagens uma a uma
sequencialmente e adicionamos elas nesse vetor (vetorOrdenado)
Temos também um vetor (DSOriginal) como entrada para o Diagrama de Sequencia original (que gerou o KMTS)

O algoritmo cria um DS Final baseado no DS Original, respeitando a sua sequência já estabelicida.
A saída do algoritmo é justamente esse DSFinal gerado.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    //fflush(stdout);
    // Vetor com mensagens ordenadas na sequencia do DS Original
    char DSOriginal[6][10] = {"sa", "vd", "id", "idm", "so", "rr"};
    // vetor com mensagens ordenadas na sequencia dos DSExtendidos
    char vetorOrdenado[12][4] = {"sa", "vd", "id", "idm", "sa", "idm", "so", "rr", "vd", "id", "so", "rr"};
    // Diagrama de Sequencia final, baseado no DS Original
    char DSFinal[10][10] = {""};
    // variaveis auxiliares
    int cont = 0, posicaoFinal = 0;

    for (int i = 0; i < sizeof(DSOriginal)/sizeof(DSOriginal[0]); i++)
    {
      for (int j = 0; j < sizeof(vetorOrdenado)/sizeof(vetorOrdenado[0]); j++)
      {
        if (strcmp(DSOriginal[i], vetorOrdenado[j]) == 0) // Verifica se nov
        {
          for (int k = 0; k < sizeof(DSFinal)/sizeof(DSFinal[0]); k++)
          {
            // printf("k: %d\n", k);
            // printf("j: %d\n", j);
            // printf("FIN: %s\n", DSFinal[k]);
            // printf("VET: %s\n", vetorOrdenado[j]);
            if (strcmp(DSFinal[k], vetorOrdenado[j]) == 0)
            {
              cont = 1;
              break;
            }
          }
          // printf("CONT: %d\n", cont);
          if (cont != 1){
            strcpy(DSFinal[posicaoFinal], vetorOrdenado[j]);
            posicaoFinal++;
          }
          cont = 0;
        }
      }
    }

    for (int k = 0; k < sizeof(DSFinal)/sizeof(DSFinal[0]); k++)
    {
      printf("%s\n", DSFinal[k]);
    }

    return 0;
}

/*
OBS1: O algoritmo ainda não está completo, necessita realizar a verificação para as mudanças geradas pelo KMTS,
isto é, caso tenha sido adicionado transições no KMTS, gera-lás no DSFinal, do jeito que está, ele só gera
no DSFinal transições que foram excluidas do DSOriginal e/ou transições que não foram alteradas, caso tenha sido
alterado apenas a valoração das pre e poscondições isso não interfere no algoritmo, pois, o que é importante aqui
são as mensagens, não importanto também se elas são may ou must

OBS2: A interpretação de um DS para esse projeto, é um vetor de mensagens ordenadas sequencialmente.
*/
