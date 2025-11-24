// Esse código recebe C casos, nos quais, é exibido a forma prefixa, infixa e posfixa de uma árvore binaria de N elementos;
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
}node;//Define a estrutura da árvore binária;

node* newNode(int);
void insertNode(node**, int);
void prefixo(node*);
void infixo(node*);
void posfixo(node*);


int main(){
  int data, N, C;
  node* root=NULL;

  scanf("%d", &C); //Número de casos teste;

  for(int i=0; i<C; i++){
    scanf("%d", &N); //Número de elemetos na árvore;

    for(int j=0; j<N; j++){
      scanf("%d", &data);
      insertNode(&root, data);
    }

    printf("Case %d:\n", i+1);

    printf("pre.: ");
    prefixo(root);
    printf("\n");

    printf("in..: ");
    infixo(root);
    printf("\n");

    printf("pos.: ");
    posfixo(root);
    printf("\n");

    root=NULL; //redefine a árvore para o próximo caso;
  }

  free(root);

  return 0;
}

node* newNode(int data){
  node *new = (node*)malloc(sizeof(node));
  new->data=data;
  new->left=NULL;
  new->right=NULL;
  return new;
}

void insertNode(node **rootRef, int data){
  node *root = *rootRef; //usa um ponteiro para editar diretamente o root;

  if(root==NULL){
    *rootRef = newNode(data);
    return;
  }
  else
    if(data>root->data)
      insertNode(&(root->right), data);
    if(data<root->data)
      insertNode(&(root->left), data);
  
}

void prefixo(node* root){
  //RED
  if(root!=NULL){
    printf("%d ", root->data);
    prefixo(root->left);
    prefixo(root->right);
  }
}

void infixo(node* root){
  //ERD
    if (root != NULL){
      infixo(root->left);
      printf("%d ", root->data);
      infixo(root->right);
  }
}

void posfixo(node* root){
  //EDR
  if(root!=NULL){
    posfixo(root->left);
    posfixo(root->right);
    printf("%d ", root->data);
  }
}
