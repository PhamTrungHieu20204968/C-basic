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

void insertionSort(list a[], int array_size) {
	int i, j;
	list last;
	for (i=1; i < array_size; i++)  {
	last = a[i];j = i;
	while ((j > 0) && (strcmp(a[j-1].name,last.name)>0))   {
	a[j] = a[j-1];
	j = j -1;  
	}
	a[j] = last;
	} 
}
void selection(list a[], int n){
	int i,j,min;
	list temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<=n-1;j++)
			if(strcmp(a[j].name,a[min].name)<0)
			min=j;
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
int main()
{
    int i=0,j;
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
    //insertionSort(person,10);
    selection(person,10);
    for (j=0;j<i;j++)
    {
        printf("%s %s %s\n",person[j].name,person[j].phonenumber,person[j].email);
    }
    return 0;
}
