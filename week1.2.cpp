#include<stdio.h>
#define ALPHABET_LEN 26
int main(){
	char c='\0';
	int count[ALPHABET_LEN] = {0};
	int count1[ALPHABET_LEN] = {0};
	int i;
	printf("Nhap sau cua ban:");
	c=getchar();
	while(c!='\n' && c>=0){
		if(c <= 'z'  &&  c >= 'a')
		++count[c -'a'];
		if(c <= 'Z'  &&  c >= 'A')
		++count1[c -'A'];
		c = getchar();
	}
	for (i = 0; i < 26; ++i){
	if (count1[i] > 0)
	printf("The letter '%c' appears %d time(s).\n", 'A' + i, count1[i]);
	}
	for (i = 0; i < 26; ++i){
	if (count[i] > 0)
	printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
	}
	return 0;
}
