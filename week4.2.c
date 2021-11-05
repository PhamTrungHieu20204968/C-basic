# include <stdio.h>
# include <stdlib.h>
#include<string.h>
char arr[80];
int top;
void khoitao(){
	 top=-1;
}
void push(char x){
	top++;
	arr[top]=x;
}
char pop(){
	return arr[top--];
}
int main(){
	int i;
	char a[80];
	fflush(stdin);
	gets(a);
	khoitao();
	for(i=0;i<strlen(a);i++){
		if (a[i] == ')')	printf("%c ",pop());
		if ((a[i] == '+') || (a[i] == '*')){
		push(a[i]);
		}
		if ((a[i] >= '0') && (a[i] <= '9')) printf("%c ", a[i]);
	}
	while(top>=0){
		printf("%c ",pop());
	}
	return 0;
}	

