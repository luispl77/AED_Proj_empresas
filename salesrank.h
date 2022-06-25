#ifndef SALESRANK_H_
#define SALESRANK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

    typedef struct companySales{
        char name[MAX_STR];
        int revenue;
    } CMPDATA;

CMPDATA* inicialize_memory(int num_lines);
void readFile(FILE* fpIn, CMPDATA* head, int n);
CMPDATA* bSort(int n, CMPDATA* head);
CMPDATA* swap(CMPDATA* b);
void createOutPutFileName(char* str, char* inputName);
void printOut(int p, int q, CMPDATA* listptr, FILE* fpOut);
void setFree(CMPDATA* head);
void printList(CMPDATA* head, int n);
void quick_sort(CMPDATA data[], int low, int high);
int partition(CMPDATA* data, int low, int high);
void quicksort_recursion_alpha(CMPDATA* array, int low, int high);
int partition_alpha(CMPDATA* array, int low, int high);

#endif