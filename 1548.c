//Esse código recebe as notas de M alunos em N filas e retorna quantos alunos não precisaram trocar de lugar para a fila ficar ordenada;
#include <stdio.h>

void sort(int[], int);
void copia_vetor(int[], int[], int);
int compara_vetor(int[], int[], int);

int main(){
	int N, M; //nùmero de casos teste (N) e núemro de alunos (1<=M<=1000);

	scanf("%d", &N);

    int results[N+1], k=0;//vetor de resultados;

	for(int i=0; i<N; i++){
		scanf("%d", &M);
		int P[M+1], Pcopy[M+1]; //vetor que armazena a nota de cada aluno na fila;

		for(int j=0; j<M; j++)
			scanf("%d", &P[j]);

		copia_vetor(P, Pcopy, M);

		sort(P, M);
		
		results[k++] = compara_vetor(P, Pcopy, M);
	}
	
	printf("\n");
	for(int i=0; i<k; i++)
		printf("%d\n", results[i]);

	return 0;
}

void sort(int P[], int M){
	int id, temp;

	for(int i=0; i<M; i++){
		id=i;

		for (int j=i+1; j<M; j++)
			if(P[j]< P[id]){
				id = j;
			}
	    if(id!=i){
		    temp=P[id];
		    P[id]=P[i];
		    P[i]=temp;
	    }
	}
}

void copia_vetor(int P[], int Pcopy[], int M){
	for (int i=0; i<M; i++)
		Pcopy[i]=P[i];
}

int compara_vetor(int P[], int Pcopy[], int M){
	int cont=0;
	for(int i=0; i<M; i++)
		if(P[i]==Pcopy[i])
			cont++;
	return cont;
}
