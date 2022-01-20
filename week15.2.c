#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 7
typedef struct Node{
	int value;
	struct Node *next;
}Node;

void initHash(Node *root[]){
	int i;
	for(i=0;i<M;i++){
		root[i]=NULL;
	}
}

Node *createNode(int x){
	Node *p=(Node*)malloc(sizeof(Node));
	if(p==NULL) exit(-1);
	else{
		p->value=x;
		p->next=NULL;
	}
	return p;
}

int hashFunction(int x){
	return x%M;
}

void insertNode(Node *root[],int x){
	int h=hashFunction(x);
	Node *r=root[h];
	Node *pre=NULL;
	while(r!=NULL && r->value<x){
		pre=r;
		r=r->next;
	}
	Node *p=createNode(x);
	if(pre==NULL){
		root[h]= p;
		p->next=r;
	}else if(r==NULL){
		pre->next=p;
	}else{
		p->next=r;
		pre->next=p;
	}
}

void display(Node *root[]){
	int i;
	for(i=0;i<M;i++){
		if(root[i]!=NULL){
			printf("BUCKET thu %d: ",i);
			Node *p=root[i];
			while (p!=NULL){
				printf("%d ",p->value);
				p=p->next;
			}
			printf("\n");
		}
	}
}

Node *search(Node *root[],int x){
	int h=hashFunction(x);
	Node *r=root[h];
	while(r!=NULL && r->value!=x) r=r->next;
	return r;
}

void removeNode(Node *root[],int x){
	int h=hashFunction(x);
	Node *r=root[h];
	Node *pre=NULL;
	while(r!=NULL && r->value!=x){
		pre=r;
		r=r->next;
	}
	if(r!=NULL){
		pre->next=r->next;
		free(r);
	}
}
int main(){
	Node *root[M];
	initHash(root);
	
	insertNode(root,8);
	insertNode(root,4);
	insertNode(root,9);
	insertNode(root,3);
	insertNode(root,15);
	insertNode(root,18);
	insertNode(root,26);
	
	display(root);
	
	if(search(root,6)==NULL) printf("KO TIM THAY 6\n");
	if(search(root,18)!=NULL) printf("TIM THAY 18\n");
	if(search(root,32)==NULL) printf("KO TIM THAY 32\n");
	
	removeNode(root,18);
	display(root);
	
	return 0;
}
