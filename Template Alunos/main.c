#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

void aleatorizaVet(int vetor[], ssize_t tam){
	for(int i = 0; i < tam; i++){
		vetor[i] = rand() % 101;
	}
}

void imprimeVet(int v[], ssize_t tam){
	for(int i = 0; i < tam; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main() {
	srand(1000);
	
	char nome[MAX_CHAR_NOME];
	size_t idxBusca;
	uint64_t numComp;
	ssize_t tamVetor;
	int *vetor;
	clock_t start;
	clock_t end;
	double total;
	
    tamVetor = 1000000;
    vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
	
	printf("\ntamVet = %zd", tamVetor);
	/*
	printf("\n");
	aleatorizaVet(vetor, tamVetor);
	//imprimeVet(vetor, tamVetor);
	printf("insertionSortRec:\n");
    start = clock();  
    numComp = insertionSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("tempo: %f\n", total);
    printf("comparações: %lu\n", numComp);
	//imprimeVet(vetor, tamVetor);
	printf("\n");
	*/
	aleatorizaVet(vetor, tamVetor);
	//imprimeVet(vetor, tamVetor);
	printf("insertionSort:\n");
	start = clock();  
    numComp = insertionSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("tempo: %f\n", total);
    printf("comparações: %lu\n", numComp);
	//imprimeVet(vetor, tamVetor);
	printf("\n");
	
	aleatorizaVet(vetor, tamVetor);
	printf("selectionSortRec:\n");
	start = clock();  
    numComp = selectionSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("tempo: %f\n", total);
    printf("comparações: %lu\n", numComp);
    //imprimeVet(vetor, tamVetor);
	printf("\n");
	
	aleatorizaVet(vetor, tamVetor);
	printf("selectionSort:\n");
	start = clock();  
    numComp = selectionSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("tempo: %f\n", total);
    printf("comparações: %lu\n", numComp);
    //imprimeVet(vetor, tamVetor);
	printf("\n");
	
	aleatorizaVet(vetor, tamVetor);
	printf("mergeSort:\n");
	start = clock();  
    numComp = mergeSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("tempo: %f\n", total);
    printf("comparações: %lu\n", numComp);
	//imprimeVet(vetor, tamVetor);
	printf("\n");
	
	
	numComp = 0;
	//imprimeVet(vetor, tamVetor);
	printf("buscaSequencial: (idxBusca , comparações) \n");
    idxBusca = buscaSequencial(vetor, tamVetor, 10, &numComp);
    printf("%zd %lu\n", idxBusca, numComp);
    
    numComp = 0;
    //imprimeVet(vetor, tamVetor);
    printf("buscaBinaria: (idxBusca , comparações)\n");
    idxBusca = buscaBinaria(vetor, tamVetor, 10, &numComp);
	printf("%zd %lu\n", idxBusca, numComp);
	
	numComp = 0;
	//imprimeVet(vetor, tamVetor);
	printf("buscaSequencialRec: (idxBusca , comparações) \n");
    idxBusca = buscaSequencialRec(vetor, tamVetor, 10, &numComp);
    printf("%zd %lu\n", idxBusca, numComp);
    
    numComp = 0;
    //imprimeVet(vetor, tamVetor);
    printf("buscaBinariaRec: (idxBusca , comparações)\n");
    idxBusca = buscaBinariaRec(vetor, tamVetor, 10, &numComp);
	printf("%zd %lu\n", idxBusca, numComp);
	
    free(vetor);

    return 0;
}
