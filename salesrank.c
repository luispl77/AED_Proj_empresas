#include "salesrank.h"

/******************************************************************************
 * readFile()
 *
 * Arguments: fpIn - endreco do ficheiro de input
 *            head - topo da lista
 *            n - numero de empresas no .prb
 * Retorno: (void)
 *
 * Description: Le o ficheiro com os dados e vai alocando um bloco para guardar
 * cada linha uma por uma, ate chegar ao numero de empressas definidas.
 * A medida que os blocos sao alocados os apontadores da lista duplamente
 * ligada sao preenchidos.
 *****************************************************************************/
void readFile(FILE* fpIn, CMPDATA* head, int n){

    int i;
    char readstr[MAX_STR];

    for(i=0; i<n; i++){
            fscanf(fpIn, "%s %d", readstr, &head[i].revenue);
            strncpy(head[i].name,readstr , MAX_STR);
    }
    return;
}

/******************************************************************************
 * QSort()
 *
 * Arguments: n - numero de empresas na lista
 *            head - topo da lista
 * 
 * Returns: head - updated topo da lista
 *
 * Description: Algoritmo do bubblesort modificado para utilizar apontadores.
 * Foi melhorado usando uma flag, quebrando o resto das iteracoes caso a lista
 * ja esteja ordenada.  NNNN ----- 1111111
 *****************************************************************************/

void quick_sort(CMPDATA* data, int low, int high) 
{  
  int pivot_index;
  if (low < high)
  {
    pivot_index = partition(data, low, high);
    quick_sort(data, low, pivot_index - 1);
    quick_sort(data, pivot_index + 1, high);
  }
}

int partition(CMPDATA* data, int low, int high)
{
CMPDATA temp;

  int pivot_value = data[high].revenue;
  int i = low;
  int j;
  for (j = low; j < high; j++)
  {
    if (data[j].revenue >= pivot_value)
    {
      if(i !=j){    
            temp.revenue = data[i].revenue;
            strcpy(temp.name, data[i].name);
            data[i].revenue = data[j].revenue;
            strcpy(data[i].name, data[j].name);
            data[j].revenue = temp.revenue;
            strcpy(data[j].name, temp.name); 
      }
      i++;
    }
  }
    if(i != j){ 
            temp.revenue = data[i].revenue;
            strcpy(temp.name, data[i].name);
            data[i].revenue = data[high].revenue;
            strcpy(data[i].name, data[high].name);
            data[high].revenue = temp.revenue;
            strcpy(data[high].name, temp.name);
            }
return i;
}

/******************************************************************************
 * inicialize_list()
 *
 * Arguments: (void)
 * 
 * Retorno: head - topo da lista
 *
 * Description: Aloca o primeiro bloco da lista e coloca os pointers = NULL.
 *****************************************************************************/
CMPDATA* inicialize_memory(int num_lines){
   
    CMPDATA* data_ptr;
    data_ptr = (CMPDATA*)calloc(num_lines, sizeof(CMPDATA));
    return data_ptr;
}

/******************************************************************************
 * swap()
 *
 * Arguments: id - data with connectivity information  *************
 *            N - size of data
 *            fp - file pointer to read data from
 * Retorno: head (novo topo, ou indicacao de que o topo nao foi alterado (NULL)).
 *
 * Description: Realiza a operacao de swap dos enderecos da lista duplamente
 * ligada. O algoritimo baseia-se em 4 blocos em que queremos fazer swap do 
 * b e c, alterando assim a ordem da lista.
 *****************************************************************************/

/******************************************************************************
 * printList()
 *
 * Arguments: head - topo da lista
 * 
 * Retorno: (void)
 *
 * Description: Imprime a lista em stdout ate ao fim da mesma (head == NULL).    
 *****************************************************************************/
void printList(CMPDATA* head, int n){
    
    int i;

    for(i = 0; i < n; i++)
        printf("\n###%s %d", head[i].name, head[i].revenue);
}

/******************************************************************************
 * printOut()
 *
 * Arguments: p - inicio do intervalo do ranking
 *            q - fim do intervalo do ranking
 *            listptr - apontador do primeiro elemento da lista
 *            fpOut - endereco do ficheiro de output
 * Retorno: (void)
 *
 * Descricao: Computa os dados necessarios para imprimir do ficheiro de output
 * como Soma min max.
 *****************************************************************************/



/******************************************************************************
 * createOutPutFileName()
 *
 * Argumento: str - string que vai conter o nome do ficheiro de output
 *            inputName - string que contem o nome do ficheio prb
 * 
 * Retorno: (void)
 *
 * Descricao: copia o nome do ficheiro de input e substitui .prb por .psol
 *****************************************************************************/
void createOutPutFileName(char* str, char* inputName){

    int i;
    
    for(i = 0; (inputName[i]) != '.'; i++){
        if(i < MAX_STR)
          str[i]=(inputName[i]);
    }
    strncat(str, ".soli", MAX_STR);
}


void printOut(int p, int q, CMPDATA* listptr, FILE* fpOut){

    int i;
    long int sum = 0;



    for(i = p ;i <= q; i++)
    sum += (listptr[i].revenue); /*adiciona os dados da pos q*/

    fprintf(fpOut, "%d %d %ld\n", 
    listptr[q].revenue, listptr[p].revenue, sum);   
    quicksort_recursion_alpha(listptr, p, q);

    
for (i = p; i<(q+1); i++){

      fprintf(fpOut, "%s %d\n", listptr[i].name, listptr[i].revenue);
  }
}

void quicksort_recursion_alpha(CMPDATA* array, int low, int high) 
{  
  int pivot_index;
  if (low < high)
  {
    pivot_index = partition_alpha(array, low, high);
    quicksort_recursion_alpha(array, low, pivot_index - 1);
    quicksort_recursion_alpha(array, pivot_index + 1, high);
  }
}

int partition_alpha(CMPDATA* array, int low, int high)
{
CMPDATA temp;

  char pivot_value[MAX_STR];
  
  int i = low;
  int j;
  strcpy(pivot_value, array[high].name);
  for (j = low; j < high; j++)
  {
    if (strcmp(array[j].name, pivot_value) < 0)
    {    
            temp.revenue = array[i].revenue;
            strcpy(temp.name, array[i].name);
            array[i].revenue = array[j].revenue;
            strcpy(array[i].name, array[j].name);
            array[j].revenue = temp.revenue;
            strcpy(array[j].name, temp.name); 
      i++;
    }
  }
            temp.revenue = array[i].revenue;
            strcpy(temp.name, array[i].name);
            array[i].revenue = array[high].revenue;
            strcpy(array[i].name, array[high].name);
            array[high].revenue = temp.revenue;
            strcpy(array[high].name, temp.name);
return i;
}
