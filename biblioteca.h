#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000
#define NELEMENTOS 500

int menu();
void imprimir(int *vetor, int tamanho);
int *gerar(int tamanho);
int *insertion(int vetor[], int tamanho);
int *selection(int vetor[], int tamanho);
int *quick(int vetor[],int esq, int dir);
int *merge(int vetor[], int inicio, int fim);
int separar(int vetor[], int inicio, int pivo, int fim);
void troca(int *a, int *b);
void tempo();

int *embaralhar(int *vetor, int tamanho);
int *PopularSqc(int *vetor, int tamanho);

