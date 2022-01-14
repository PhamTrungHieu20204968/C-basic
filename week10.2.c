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

list person[100];

void adjust(list a[], int root, int n){
	int child;   
	list temp;
	temp=a[root];     
	child=2*root;
	while (child <= n) {
	if ((child < n) &&(strcmp(a[child].name, a[child+1].name)<0))
		child++;
	if (strcmp(a[root].name, a[child].name)>0) break;
	else {
	a[child/2] = a[child];
	child *= 2;
		}
	}
	a[child/2] = temp;
}
void heapsort(list a[], int n){
	int i, j;
	list temp;
	for (i=n/2; i>0; i--) adjust(a, i, n);
	for (i=n-1; i>0; i--) {
	temp=a[1];
	a[1]=a[i+1];
	a[i+1]=temp;
	adjust(a, 1, i);
	}
}
int main()
{
    int i=1,j;
    FILE* f=fopen("test.txt","r");
    FILE* f1=fopen("lab1.txt","w");
    if(f == NULL){
        printf("Can't read file!\n");
        return 0;
    }
    if(f1 == NULL){
        printf("Can't open file!\n");
        return 0;
    }
    while(!feof(f))
    {
    	fflush(stdin);
        fscanf(f,"%s%s%s",&person[i].name,&person[i].phonenumber,&person[i].email);
		++i;
    }
    heapsort(person,10);
    for (j=0;j<i;j++)
    {
        fprintf(f1,"%s %s %s\n",person[j].name,person[j].phonenumber,person[j].email);
    }
    return 0;
}
