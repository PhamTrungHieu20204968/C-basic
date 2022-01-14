#include <stdio.h>
#include<string.h>
#include<stdlib.h>
enum {SUCCESS,FAIL,MAX_LEN=81};
typedef struct phoneaddress_t{
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress;
typedef struct treetype{
	phoneaddress data;
	struct treetype *left,*right;
}treetype;
treetype* create_node(char *name,char *tel,char *email){ 
	treetype* N = (treetype*) malloc(sizeof(treetype));
	if (N != NULL){ 
	N->left = NULL;
	N->right = NULL;
	strcpy(N->data.name,name);
	strcpy(N->data.tel,tel);
	strcpy(N->data.email,email);
	}
	return N;
}
int main(){
	FILE *fptr2;
	char buff[MAX_LEN]; 
	char filename2[]= "lab1.txt";
	int reval = SUCCESS;
	if ((fptr2 = fopen(filename2, "r")) == NULL){
	printf("Cannot open %s.\n", filename2);
	reval = FAIL;
	} else {
	while (fgets(buff, MAX_LEN, fptr2) != NULL) {
	printf("%s",buff);
	}
	}
	fclose(fptr2);
	return 0;
}
