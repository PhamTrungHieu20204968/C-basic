#include<stdio.h>
#include<string.h>
int f[2000];
void Algorithm_failureFunction(char *P){
	int m=strlen(P);
	int i=1;
	int j=0;
	f[0]=0;
	while(j<m){
		if(P[i]==P[j]){
			f[i]=j+1;
			i++;
			j++;
		}else if(j>0) j=f[j-1];
			else{
				f[i]=0;
				i=i+1;
			} 
	}
}
int Algorithm_KMPMatch(char *T,char *P){
	Algorithm_failureFunction(P);
	int i=0,j=0;
	while(i<strlen(T)){
		if(T[i]==P[j]){
			if(j==strlen(P-1)) return i-j;
			else{
				i++;
				j++;
			}
		}else if(j>0) j=f[j-1];
			else i++;
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
	if(Algorithm_KMPMatch(string,P)==-1) printf("No macth\n");
	else printf("found\n");
	return 0;
}
