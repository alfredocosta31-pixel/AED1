#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int[], int);

int main(){
	int NC, N;
	scanf("%d", &NC);

    int **num= (int**)malloc(NC * sizeof(int*));

    int *tamVetor = (int*)malloc(NC * sizeof(int));

	for(int i=0; i<NC; i++){
		scanf("%d", &N);
        tamVetor[i]=N;
        num[i] = (int*)malloc(N * sizeof(int));
        for(int j=0; j<N; j++){
            scanf("%d", &num[i][j]);
        }
        insertionSort(num[i], N);
	}

    for(int i=0; i<NC; i++){
        for(int j=0; j<tamVetor[i]; j++){
            printf("%d ", num[i][j]);
        }
    printf("\n");
    }

    for (int i = 0; i < NC; i++) {
        free(num[i]);
    }
    free(num);
    free(tamVetor);

    return 0;
}

void insertionSort(int v[], int tam){
    int i, j, key;
    for (i = 1; i < tam; i++) {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
