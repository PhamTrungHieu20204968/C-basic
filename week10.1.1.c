#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 1000

typedef struct list
{
    char name[100];
    char phonenumber[100];
    char email[100];
}list;
typedef struct Treenode{
	list data;
	struct Treenode *next;
}tree; 
list person[100];
tree *Newnode(list a){
	tree* p=(tree*)malloc(sizeof(tree));
	if(p==NULL) exit(-1);
	else{
		strcpy(p->data.name,a.name);
		strcpy(p->data.phonenumber,a.phonenumber);
		strcpy(p->data.email,a.email);
		p->next=NULL;
	}
	return p;
}
void chen(tree *root,tree *p,tree *add){
	if(root==NULL) return;
	else{
		tree *temp=root;
		while(temp!=NULL && temp!=p){
			temp=temp->next;
		}
		if(temp==NULL) return;
		else{
			add->next=p->next;
			p->next=add;
		}
	}
}
tree *Them(tree *root,tree *add){
	if(root==NULL) return add;
	if(strcmp(root->data.name,add->data.name)>0){
		add->next=root;
		root=add;
		return root;
	}
	tree *pre=NULL,*temp=root;
	while(temp!=NULL){
		if(strcmp(temp->data.name,add->data.name)<0){
			if(temp->next==NULL){
				temp->next=add;
				return root;
			} 
		}else{
			chen(root,pre,add);
			return root;
		}
		pre=temp;
		temp=temp->next;
	}
	return root;
}
tree *insertionSort(tree *root) {
	int i;
	for (i=0;i<10;i++)
    {
        tree *add=Newnode(person[i]);
        root=Them(root,add);
    }
	return root;
}
tree *selection(tree *root){
	int i,j,min;
	list temp;
	for(i=0;i<10;i++){
		min=i;
		for(j=i+1;j<=10;j++)
			if(strcmp(person[j].name,person[min].name)<0)
			min=j;
		tree *add=Newnode(person[min]);
		root=Them(root,add);
		temp=person[i];
		person[i]=person[min];
		person[min]=temp;
	}
	tree *add=Newnode(person[10]);
	root=Them(root,add);
	return root;
}
int main()
{
	tree *root=NULL;
    int i=0;
    FILE* f=fopen("test.txt","r");
    if(f == NULL){
        printf("Can't read file!\n");
        return 0;
    }
    while(!feof(f))
    {
    	fflush(stdin);
        fscanf(f,"%s%s%s",&person[i].name,&person[i].phonenumber,&person[i].email);
		++i;
    }
    //root=insertionSort(root);
    root=selection(root);
    tree *p=root;
    while(p!=NULL){
    	printf("%s %s %s\n",p->data.name,p->data.phonenumber,p->data.email);
    	p=p->next;
	}
    return 0;
}
