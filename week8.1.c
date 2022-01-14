#include<stdio.h>
# include <stdlib.h>
typedef  int  elmType;
typedef struct nodeType {
	elmType element;
	struct nodeType *left, *right;
}node_Type;
void MakeNullTree(node_Type *T){ 
	T=NULL; 
} 
int EmptyTree(node_Type* T){ 
	return T==NULL; 
}
node_Type* LeftChild(node_Type* n){ 
	if (n!=NULL) return n->left;
	 else return NULL;
}
node_Type* RightChild(node_Type* n){ 
	if (n!=NULL) return n->right;
	else return NULL;
}
node_Type* create_node(elmType NewData){ 
	node_Type* N = (node_Type*) malloc(sizeof(node_Type));
	if (N != NULL){ 
	N->left = NULL;
	N->right = NULL;
	N->element = NewData;
	}
	return N;
}
int isleaf(node_Type* n){
	if(n!=NULL)
	if(LeftChild(n)==NULL && RightChild(n)==NULL) return 1;
	else return 0;
}
int sonut(node_Type* tree){
	if(EmptyTree(tree)) return 0;
	 else return 1+sonut(LeftChild(tree))+sonut(RightChild(tree));
}
node_Type* themtrainhat(node_Type* tree,elmType NewData){
	node_Type* N=create_node(NewData);
	if(N==NULL) return N;
	if(tree==NULL){
		tree=N;
	}else{
		node_Type* Lnode=tree;
		while(Lnode->left!=NULL)
			Lnode=Lnode->left;
		Lnode->left=N;
	}
	return N;
}
node_Type* themphainhat(node_Type* tree,elmType NewData){
	node_Type* N=create_node(NewData);
	if(N==NULL) return N;
	if(tree==NULL){
		tree=N;
	}else{
		node_Type* Rnode=tree;
		while(Rnode->right!=NULL)
			Rnode=Rnode->right;
		Rnode->right=N;
	}
	return N;
}
int demla(node_Type* tree){
	if(tree==NULL) return 0;
	if(tree->left==NULL && tree->right==NULL) return 1;
		else return demla(tree->left)+demla(tree->right);
}
int demnuttrong(node_Type* tree){
	return sonut(tree)-demla(tree)-1;
}
int docao(node_Type* tree){
	if(tree==NULL) return 0;
	if(isleaf(tree)==1) return 1;
	int i=2,count=1;
	while(sonut(tree)>=i){
		i=i*2;
		count++;
	}
	return count;
}
int main(){
	node_Type* tree=create_node(1);
	tree->left=create_node(2);
	tree->right=create_node(3);
	printf("%d\n",sonut(tree));
	printf("%d\n",LeftChild(tree)->element);
	printf("%d\n",RightChild(tree)->element);
	node_Type* N=themtrainhat(tree,4);
	printf("%d\n",tree->left->left->element);
	node_Type* P=themphainhat(tree,5);
	printf("%d\n",tree->right->right->element);
	printf("%d\n",demla(tree));
	printf("%d\n",demnuttrong(tree));
	printf("%d\n",docao(tree));
	return 0;
}
