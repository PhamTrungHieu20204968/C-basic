#include<stdio.h>
int main(){
	int arr[10];
	int i;
	for(i=0;i<=10;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<=10;i++){
		if(arr[i]==11) printf("%d",i);
	}if(i==10) printf("0");
	return 0;
}
