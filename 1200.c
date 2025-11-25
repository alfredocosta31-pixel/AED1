//Esse código cria uma árvore binária de busca usando letras (a-z). As oprações I e P, respectivamente e seguidas do elemento (a-z), inserem o elemento e verificam a existencia do elemento. Além disso também é possível imprimir a árvore nos 3 percursos PREFIXA, INFIXA e POSFIXA;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node *left;
	struct Node *right;
}node;

node* newNode(char);
void insertNode(node**, char);
int buscaNode(node*, char);
void prefixo(node*);
void infixo(node*);
void posfixo(node*);


int main(){
	char data;
	char Op[10]; //Operação atual;
	node *root=NULL;

	while((scanf("%s", Op))==1){
		if(strcmp(Op, "I")==0){
			scanf(" %c", &data);
			insertNode(&root, data);
			continue;
		}
		if(strcmp(Op, "P")==0){
			scanf(" %c", &data);
			if(buscaNode(root, data))
				printf("%c existe\n", data);
			else
				printf("%c nao existe\n", data);
			continue;
		}
		if(strcmp(Op, "PREFIXA")==0){
			prefixo(root);
			printf("\n");
			continue;
		}
		if(strcmp(Op, "INFIXA")==0){
			infixo(root);
			printf("\n");
			continue;
		}
		if(strcmp(Op, "POSFIXA")==0){
			posfixo(root);
			printf("\n");
			continue;
		}
	}
}

node* newNode(char data){
	node *new = (node*)malloc(sizeof(node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

void insertNode(node **rootRef, char data){
	node *root = *rootRef;

	if(root==NULL){
		*rootRef = newNode(data);
		return;
	}
	else
		if(data>root->data)
			insertNode(&(root->right), data);
		else if(data<root->data)
			insertNode(&(root->left), data);
	
}

int buscaNode(node* root, char data){
	if(root==NULL)
		return 0;
	if(data == root->data)
		return 1;
	if(data<root->data)
		return buscaNode(root->left, data);
	else if(data>root->data)
		return buscaNode(root->right, data);
}

void prefixo(node* root){
  //RED
  if(root!=NULL){
    printf("%c ", root->data);
    prefixo(root->left);
    prefixo(root->right);
  }
}

void infixo(node* root){
  //ERD
  	if (root != NULL){
	    infixo(root->left);
	    printf("%c ", root->data);
	    infixo(root->right);
	}
}

void posfixo(node* root){
  //EDR
  if(root!=NULL){
    posfixo(root->left);
    posfixo(root->right);
    printf("%c ", root->data);
  }
}
