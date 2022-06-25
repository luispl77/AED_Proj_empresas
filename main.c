#include "salesrank.h"

int main(int argc, char *argv[]){

    FILE* fpIn, *fpOut;
    int n, p, q;
    CMPDATA* head;
    char str[MAX_STR];

    if (argc < 2){
        exit (0);
    }
    fpIn = fopen(argv[1], "r");
    if (fpIn == NULL){    
        exit(0);
    }
    if(fscanf(fpIn, "%d %d %d", &n, &p, &q) != 3){
        exit(0);
    }

    head = inicialize_memory(n);
    readFile(fpIn, head, n);
    fclose(fpIn);    
    quick_sort(head, 0, n-1);
    createOutPutFileName(str, argv[1]);
    fpOut = fopen(str, "w");
    printOut(p-1, q-1, head, fpOut);
    free(head);
    fclose(fpOut);
    
    return 0;
}