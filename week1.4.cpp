#include<stdio.h>
void thaythe(char arr[],char a,char b){
	int i;
	for(i=0;arr[i]!='\0';i++){
		if(arr[i]==a) arr[i]=b;
		printf("%c",arr[i]);
	}
}
int main(){
	char arr[10];
	char a,b;
	printf("Nhap xau:\n");
	fflush(stdin);
	gets(arr);
	printf("Nhap ki tu 1:\n");
	fflush(stdin);
	a=getchar();
	printf("Nhap ki tu 2:\n");
	fflush(stdin);
	b=getchar();
	thaythe(arr,a,b);
	return 0;
}
