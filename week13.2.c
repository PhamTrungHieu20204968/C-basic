#include<stdio.h>
#include<string.h>
typedef struct lastfound{
	char a[200];
	int b[200];
}lastfound;
lastfound L;
char characters[]="abcdef";
void lastOccurenceFunction(char P[]){
	int i,j;
	for(i=0;i<strlen(characters);i++) L.a[i]=characters[i];
	for(i=0;i<strlen(P);i++){
		for(j=0;j<strlen(characters);j++){
			if(L.a[j]==P[i]) L.b[j]=i;
		}
	}
}
int find(char X){
	int i;
	for(i=0;i<strlen(L.a);i++)
		if(L.a[i]=='X') return L.b[i];
}
int BoyerMooreMatch(char T[],char P[]){
	lastOccurenceFunction(P);
	int i,j;
	int m=strlen(P);
	i=m-1; j=m-1;
	while(i<strlen(T)-1){
		if(T[i]==P[j]){
			if(j==0) return i;
			else{
				i--; j--;
			}
		}else{
			int l=find(T[i]);
			if(j<l+1) i=i+m-j;
			else i=i+m-(l+1);
			j=m-1;
		}
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
	if(BoyerMooreMatch(string,P)!=-1) printf("string have P");
	else printf("no match found");
	return 0;
}
