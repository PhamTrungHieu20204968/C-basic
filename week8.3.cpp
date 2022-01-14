#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
enum {SUCCESS,FAIL};
typedef struct phoneaddress_t {
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress;
typedef struct Node{
	phoneaddress key; 
	struct Node* left, *right;
} NodeType;
typedef Node* TreeType;
TreeType Search(char* email,TreeType Root){ 
	if (Root == NULL) return NULL; 
	if (strcmp((Root->key).email, email) == 0) 
	return Root; 
	else if (strcmp((Root->key).email, email) < 0)
	return Search(email,Root->right); 
	else { 
	return Search(email,Root->left); 
	}
}
void InsertNode(phoneaddress x,TreeType *Root ){ 
	if (*Root == NULL){
	*Root=(NodeType*)malloc(sizeof(NodeType)); 
	(*Root)->key = x; (*Root)->left = NULL; 
	(*Root)->right = NULL; 
	} else if (strcmp(((*Root)->key).email, x.email) > 0) InsertNode(x, &(*Root)->left);
	else if (strcmp(((*Root)->key).email, x.email) > 0) InsertNode(x,&(*Root)->right); 
} 
int main(void){
	FILE *fp;phoneaddress phonearr[MAX];
	TreeType root;int i,n, irc,reval;
	reval = SUCCESS;
	n=10;
	if ((fp = fopen("lab1.txt","rb")) == NULL){
	printf("Can not open %s.\n", "lab1.txt");
	reval = FAIL;
	}
	irc = fread(phonearr, sizeof(phoneaddress), n, fp);
	fclose(fp);
	for (i=0; i<n; i++)
	InsertNode(phonearr[i],&root);
	return 0;
}
