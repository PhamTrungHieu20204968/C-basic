#include<stdio.h>
int Dk(int a[],int i){
	int j;
	for(j=0;j<i;j++){
		if(a[i]==a[j]) return 0;
	}
	return 1;
}
int main(){
	int i,a[10];
	printf("Nhap 10 phan tu cua mang:\n");
	for(i=0;i<10;i++){
		printf("Nhap phan tu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
	printf("Mang gom:");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Mang gom:");
	for(i=0;i<10;i++){
		if(Dk(a,i)==1)
		printf("%d ",a[i]);
	}
	return 0;
}

