#include<stdio.h>
#include<string.h>
int BruteForceMatch(char T[],char P[]){
	int i,j;
	for(i=0;i<strlen(T);i++){
		for(j=0;j<strlen(P);j++){
			if(T[i+j]!= P[j]) break;
		}
		if (j==strlen(P)) return 1;
	}
	return -1;
}
int main(){
	char string[2000];
	char P[200];
	printf("Nhap xau\n");
	fflush(stdin);
	gets(string);
	printf("Nhap xau can tim\n");
	fflush(stdin);
	gets(P);
	if(BruteForceMatch(string,P)==1) printf("string have P");
	else printf("no match found");
	return 0;
}
