#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[]) {
    strncpy(nome, "Aurelio Gabriel Ortiz Vieira", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  
}

uint32_t getGRR() { return 20231953; }

ssize_t buscaSequencialIt(int v[], ssize_t a, ssize_t b,
							int x, uint64_t *comp){
	for(int i = a; i < b; i++){
		(*comp)++;
		if(x <= v[i]){
			return i;
		}
	}
	return b;
}

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
	ssize_t x;
	
	x = buscaSequencialIt(vetor, 0, tam-1, valor, numComparacoes);
	(*numComparacoes)++;
	if(vetor[x] != valor){
		return -1;
	}
	return x;
}

ssize_t buscaSequencialRecursiva(int v[], ssize_t a, ssize_t b, 
				int x, uint64_t *comp){
	if(a == b){
		return a;
	}
	(*comp)++;
	if(x <= v[a]){
		return a;
	}
	return buscaSequencialRecursiva(v, a+1, b, x, comp);
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes) {
	ssize_t x;
	
	x = buscaSequencialRecursiva(vetor, 0, tam-1, valor, numComparacoes);
	(*numComparacoes)++;
	if(vetor[x] != valor){
		return -1;
	}
	return x;
}

ssize_t buscaBinariaIt(int v[], ssize_t a, ssize_t b, 
					int x, uint64_t *comp){
	ssize_t m;
	
	while(a < b){
		m = (a+b) / 2;
		
		(*comp)++;
		if(x <= v[m]){
			b = m-1;
		}else{
			a = m+1;
		}
	}
	(*comp)++;
	if(v[a] < x){
		return a+1;
	}
	return a;
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
	ssize_t x;
	
	x = buscaBinariaIt(vetor, 0, tam-1, valor, numComparacoes);
	(*numComparacoes)++;
	if(vetor[x] != valor){
		return -1;	
	}
	return x;
}

ssize_t buscaBinariaRecursiva(int v[], ssize_t a, ssize_t b,
								int x, uint64_t *comp){
	ssize_t m;
	
	if(a >= b){
		(*comp)++;
		if(v[a] < x){
			return a+1;
		}	
		return a;
	}

	m = (a + b) / 2;
	(*comp)++;	
	if(x <= v[m]){
		return buscaBinariaRecursiva(v, a, m-1, x, comp);
	}
	return buscaBinariaRecursiva(v, m+1, b, x, comp);																
}								

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        	uint64_t* numComparacoes) {
	ssize_t x;
	
	x = buscaBinariaRecursiva(vetor, 0, tam-1, valor, numComparacoes);
	(*numComparacoes)++;
	if(vetor[x] != valor){
		return -1;
	}	
	return x;
}

void trocar(int v[], ssize_t a, ssize_t b){
	int aux;
	
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

void inserir(int v[], ssize_t a, ssize_t b, uint64_t *comp){
	ssize_t j, i;
	
	j = buscaBinariaRecursiva(v, a, b, v[b], comp);
	//j = buscaSequencialRecursiva(v, a, b, v[b], comp);
	//j = buscaBinariaIt(v, a, b, v[b] , comp);
	//j = buscaSequencialIt(v, a, b, v[b], comp);
	i = b;
	while(j != b){
		trocar(v, i, i-1);
		j++;
		i--;
	}	
}

void insertionSortIt(int v[], ssize_t a, ssize_t b, uint64_t *comp){
	int k;
	
	k = a+1;
	while(k <= b){
		inserir(v, a, k, comp);	
		k++;
	}
}

uint64_t insertionSort(int vetor[], size_t tam) {
	uint64_t numComp;
	
	numComp = 0;
	insertionSortIt(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

void insertionSortRecursivo(int v[], ssize_t a, ssize_t b,
								uint64_t *comp){
	if(a == b){
		return;
	}
	insertionSortRecursivo(v, a, b-1, comp);
	inserir(v, a, b, comp);	
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
	uint64_t numComp;
	
	numComp = 0;
	insertionSortRecursivo(vetor, 0, tam-1, &numComp);

	return numComp;
}

ssize_t minimoVetIt(int v[], ssize_t a, ssize_t b,
						uint64_t *comp){
	size_t m, i;
	
	m = a;
	for(i = a; i <= b; i++){
		(*comp)++;
		if(v[m] > v[i]){
			m = i;
		}
	}
	
	return m;
}

void selectionSortIt(int v[], ssize_t a, ssize_t b,
						uint64_t *comp){
	size_t k;
	
	k = a;
	while(k <= b) {
		trocar( v, k, minimoVetIt(v, k, b, comp) );
		k++;
	}
}

uint64_t selectionSort(int vetor[], size_t tam) {
	uint64_t numComp;
	
	numComp = 0;
	selectionSortIt(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

ssize_t minimoVetRec(int v[], ssize_t a, ssize_t b,
						uint64_t *comp){
	size_t m;
	
	if(a == b) {
		return a;
	}
	
	m = minimoVetRec(v, a, b-1, comp);
	(*comp)++;	
	if(v[b] < v[m]) {
		m = b;
	}
	return m;
}

void selectionSortRecursivo(int v[], ssize_t a, ssize_t b,
								uint64_t *comp){
	if(a >= b){
		return;
	}
	trocar( v, a, minimoVetRec(v, a, b, comp) );
	selectionSortRecursivo(v, a+1, b, comp);
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
	uint64_t numComp;
	
	numComp = 0;
	selectionSortRecursivo(vetor, 0, tam-1, &numComp);
	
	return numComp;
}

void copiar(int v[], ssize_t a, ssize_t b, int aux[]){
	size_t i, j;
	
	j = 0;
	for(i = a; i < b; i++){
		v[i] = aux[j];
		j++;
	}
}

void merge(int v[], ssize_t a, ssize_t m, 
				size_t b, size_t *comp) {
	size_t p1, p2;
	size_t i, j;
	int *aux;
	
	aux = malloc((b+1) * sizeof(int));
    if (aux == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return;
    }
	
	if(a >= b){
		return;
	}
	
	p1 = a;	
	p2 = m+1;		
	i = 0;	
	
	while( (i <= b) && (p1 <= b) ){
		(*comp)++;
		if( (p2 > b) || (p1 <= m && v[p1] <= v[p2]) ) {
			j = p1;
			p1++;
		}else{
			j = p2;
			p2++;
		}
		aux[i] = v[j];
		i++;
	}
	copiar(v, a, b+1, aux);
	free(aux);
}

void merge_sort(int v[], ssize_t a, ssize_t b,
					uint64_t *comp){
	size_t m;
	
	if(a >= b){
		return;
	}
	m = (a+b) / 2;
	merge_sort(v, a, m, comp);
	merge_sort(v, m+1, b, comp);
	merge(v, a, m, b, comp);
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
	uint64_t numComp;

	numComp = 0;
	merge_sort(vetor, 0, tam-1, &numComp);
	
	return numComp;
}
