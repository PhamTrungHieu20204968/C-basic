# include <stdio.h>
# include <stdlib.h>
#include<string.h>
struct node { 
	char data[80];
	struct node *link;
};
enum {SUCCESS, FAIL,MAX_LEN=81};
struct node * creat(char *data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("ERROR");
		return;
	}
	strcpy(newnode->data,data);
	newnode->link=NULL;
	return newnode;
}
struct node *push(struct node *top,struct node *add){
	if(top==NULL) return add;
	add->link=top;
	top=add;
	return top;
}
struct node *pop(struct node *top){
	if(top==NULL) return;
	struct node *p=top;
	top=top->link;
	return p;
}
void ReadWrite(FILE *fin, FILE *fout,char *name){
	struct node* top=NULL;
	char buff[MAX_LEN]; 
	int count=0;
	while (fgets(buff, MAX_LEN, fin) != NULL) {
		if(strstr(buff,name)){
		printf("%s",buff);
		struct node *add=creat(buff);
		top=push(top,add);
		break;
		}
	}
	while(top!=NULL){
		fprintf(fout,"%s",top->data);
		top=top->link;
	}
}
int main(void) {
	char Name[30];
	FILE *fptr1, *fptr2;
	char filename1[]= "lab1a.txt";
	char filename2[]= "lab1.txt";
	int reval = SUCCESS;
	if ((fptr1 = fopen(filename1, "w")) == NULL){
	printf("Cannot open %s.\n", filename1);
	reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r")) == NULL){
	printf("Cannot open %s.\n", filename2);
	reval = FAIL;
	} else {
	printf("Nhap ten can tim:");
	fflush(stdin);
	gets(Name);
	ReadWrite(fptr2, fptr1,Name);
	fclose(fptr1);
	fclose(fptr2);
}
	return reval;
}
