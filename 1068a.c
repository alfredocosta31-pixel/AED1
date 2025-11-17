#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char V[1000];
    int N, cont=0, isCorrect=0;
    fgets(V, sizeof(V), stdin);

    for(int i=0; i<strlen(V);i++){
        if(V[i]==')'){
            cont--;
            if (cont<0){
                isCorrect = 0;
                break;
            }
        }
        else 
            if(V[i]=='('){
            cont++;
            }
    }

    if(cont==0)
        isCorrect=1;

    if(isCorrect==1)
        printf("correct\n");
    else
        printf("incorrect\n");

    return 0;
}
