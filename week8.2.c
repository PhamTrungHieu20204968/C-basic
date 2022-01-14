#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
typedef struct Node{
	int key; 
	struct Node *left, *right;
}NodeType;
NodeType *Search(int x,NodeType* tree){
	if(tree==NULL) return NULL;
	else if(tree->key==x) return tree;
	else if(tree->key<x) return Search(x,tree->right);
		else return Search(x,tree->left);
}
void them(int x,NodeType* root){
	if(root==NULL){
		NodeType* N=(NodeType*)malloc(sizeof(NodeType));		
		if(N != NULL){
		N->key = x; 
		N->left = NULL; 
		N->right = NULL;
		root=N;
		printf("2");

	}
	}else if(root->key<x) them(x,root->right);
			else them(x,root->left);
}
int DeleteMin(NodeType *Root ){ 
	int k; 
	if (Root->left == NULL){ 
	k=Root->key; 
	Root = Root->right; return k; 
	} else return DeleteMin(Root->left); 
}
void DeleteNode(int x,NodeType *Root){ 
	if (Root!=NULL) 
		if (x < Root->key) DeleteNode(x, Root->left);
		else if (x > Root->key) DeleteNode(x, Root->right); 
			else if (Root->left==NULL && Root->right==NULL) Root=NULL; 
				else if (Root->left == NULL) Root = Root->right; 
					else if (Root->right==NULL)  Root = Root->left;
						 else (Root->key = DeleteMin(Root->right)); 
} 
void freetree(NodeType* tree){
	if (tree!=NULL){
	freetree(tree->left);
	freetree(tree->right);
	free(tree);
	}
}
int main(){
	/*NodeType* tree=NULL,*p;
	char *prefix;
	int i,n=0;
	srand(time(NULL));
	for ( i = 0; i < 10; i++ ) 
		them(rand() % 100, tree );
	do {
	printf("Enter key to search (-1 to quit):");
	scanf("%d", &n);
	p= Search(n, tree);
	if (p!=NULL) printf("Key %d found on the tree\n",n);
	else them(n, tree);
	}while (n!=-1);*/
	NodeType *tree=NULL;
	them(4,tree);
	printf("%d",tree->key);
	NodeType *p=Search(5,tree);
	printf("Key %d found on the tree\n",p->key);
	printf("2");
	return 0;
}
