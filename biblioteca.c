#include "biblioteca.h"

int menu(){
    int tamanho;
    printf("Programa master de ''organizar'' vetores \n");
    printf("Ele vai organizar melhor do que uma mãe organizaria o seu roupeiro\n");
    printf("Informe tamanho do vetor: ");
    scanf("%d", &tamanho);
}

void imprimir(int *vetor, int tamanho){
    printf("\n==============================================================\n");
    printf("Vetor:\n");
    for (int i = 0; i < tamanho; ++i){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

 int *gerar(int tamanho){
     int *vetor= malloc(sizeof(int)*tamanho);
     if(vetor==NULL){
         printf("\nNao tem memoria!\n");
         exit(0);
     }
     for (int i = 0; i < tamanho; i++){
         vetor[i]=rand()% TAM;
     }
     return vetor;
}

int *insertion(int vetor[], int tamanho){
    int temp, i, j;
    for (i = 1; i < tamanho; i++){ //i=1 Porque é preciso comparar o segundo elemento do vetor
        temp=vetor[i];
        j=i-1;
        while (j>=0 && vetor[j]>temp){
            vetor[j+1]=vetor[j]; //Se o numero que está sendo comparado for menor, então o numero atual ira assumir a posição acima do j
            j=j-1;
        }
        vetor[j+1]=temp;
    }
    return vetor;
}

int *selection(int vetor[], int tamanho){
    int temp, menor, i;
    for (i = 0; i < tamanho; i++){
        menor=i;
        for (temp=i; temp<tamanho; temp++){
            if(vetor[temp]<vetor[menor]){
                menor=temp;
            }
        }
        if(menor!=i){
            troca(&vetor[i], &vetor[menor]);
        }
    }
    return vetor;
}

int *quick(int vetor[],int esq, int dir) {
    int inicio, fim, pivo, temp;
    inicio = esq;
    fim = dir;
    pivo = vetor[(esq + dir) / 2];
    while(inicio <= fim) {
        while(vetor[inicio] < pivo && inicio < dir) {
            inicio++;
        }
        while(vetor[fim] > pivo && fim > esq){
            fim--;
        }
        if(inicio <= fim){
            troca(&vetor[inicio], &vetor[fim]);
            inicio++;
            fim--;
        }
    }
    if(fim > esq){
        quick(vetor, esq, fim);
    }
    if(inicio < dir){
        quick(vetor, inicio, dir);
    }
    return vetor;
}

int *merge(int vetor[], int inicio, int fim){
    int pivo;
    if (inicio < fim) {
        pivo = (inicio + fim) / 2;
        merge(vetor, inicio, pivo);
        merge(vetor, pivo + 1, fim);
        separar(vetor, inicio, pivo, fim);
    }
}

int separar(int vetor[], int inicio, int pivo, int fim){
    int i, j, k;
    int piesq, pidir;
    piesq = pivo - inicio + 1;
    pidir = fim - pivo;
    int esq[piesq], dir[pidir];

    for (i = 0; i < piesq; i++)
        esq[i] = vetor[inicio + i];
    for (j = 0; j < pidir; j++)
        dir[j] = vetor[pivo + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < piesq && j < pidir) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i++];
        }
        else {
            vetor[k] = dir[j++];
        }
        k++;
    }
    while (i < piesq) {
        vetor[k++] = esq[i++];
    }
    while (j < pidir) {
        vetor[k++] = dir[j++];
    }
    return vetor;
}

void troca(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tempo(){
    int *vetor;
    long long tempo=0;
    double media;
    struct timespec inicio[NELEMENTOS],fim[NELEMENTOS];
    for (int i = 0; i < NELEMENTOS; ++i) {
        vetor=gerar(NELEMENTOS);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&inicio[i]);
        //insertion(vetor,NELEMENTOS);
        //selection(vetor,NELEMENTOS);
        //quick(vetor, 0, NELEMENTOS);
        merge(vetor, 0, NELEMENTOS);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&fim[i]);
    }
    for (int i = 0; i < NELEMENTOS; ++i) {
        tempo=(fim[i].tv_sec - inicio[i].tv_sec)+(fim[i].tv_nsec - inicio[i].tv_nsec)+tempo;
    }
    media=tempo/NELEMENTOS;
    printf("%.10lf \n",media*1e-9);
}

//TEMPORARIO (Peguei emprestado para ver como os algoritimos se comportam com um vetor "controlado"
    int *embaralhar(int *vetor, int tamanho) {
        //embaralha o vetor;
        for (int i = 0; i < tamanho; ++i) {
            troca(&vetor[i], &vetor[rand() % tamanho]);
        }
        return vetor;
    }
    int *PopularSqc(int *vetor, int tamanho) {
        //Popula o vetor com valores crescentes
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = i + 1;
        }
        return vetor;
    }
//FIM TEMPORARIO
