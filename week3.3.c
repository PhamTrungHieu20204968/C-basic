#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student_t {
	char id[4];
	char name[30];
	int grade;
	struct Student_t *next; 
} Student;
Student *newstudent(){
	Student *p;
	p=(Student*)malloc(sizeof(Student));
	printf("Name:");
	fflush(stdin);
	gets(p->name);
	printf("ID:");
	fflush(stdin);
	gets(p->id);
	printf("Grade:");
	scanf("%d",&p->grade);
	p->next=NULL;
	return p;
}
Student *them1(Student *root,Student *add){
	Student *cur,*prev=NULL;
	if(root==NULL){
		return add;
	}
	if(add->grade>root->grade){
		add->next=root;
		return add;
	}
	cur=root;
	while(cur!=NULL && add->grade<cur->grade){
		prev=cur;
		cur=cur->next;
	}
	prev->next=add;
	add->next=cur;
	return root;
}
Student *find(Student *root,char* id){
	Student *tim=root;
	while(tim!=NULL){
		if(strcmp(tim->id,id)==0) return tim;
		tim=tim->next;
	}
	printf("Khong tim thay ket qua\n");
	return NULL;
}
Student *xoa(Student *root,char* id){
	if(root==NULL){
		printf("Khong co hoc sinh nao.\n");
		return root;
	}
	Student *cur,*prev;
	cur=root;
	while(cur!=NULL && strcmp(cur->id,id)!=0 ){
		prev=cur;
		cur=cur->next;
	}
	if(cur!=NULL){
		prev->next=cur->next;
		free(cur);
	}
	return root;
}
Student *change_grade(Student *root, char* id, int diem){
	Student* std = find(root, id);
	Student* p=(Student*)malloc(sizeof(Student));
	strcpy(p->name,std->name);
	strcpy(p->id,std->id);
	p->grade=diem;
	p->next=NULL;
	free(std);
	return them1(root,p);
}
int main(){
	Student *list=NULL;
	int i,n,size;
	char temp[4];
	int diem;
	do{
		printf("Menu:\n");
		printf("1.Them hoc sinh.\n");
		printf("2.Tim hoc sinh.\n");
		printf("3.Xoa hoc sinh.\n");
		printf("4.Doi diem.\n");
		printf("5.An nut khac de thoat.\n");
		printf("Nhap lua chon cua ban:");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Nhap so luong sinh vien:");
				scanf("%d",&size);
				for(i=0;i<size;i++){
					Student *add=newstudent();
					list=them1(list,add);
				}
				break;
			case 2:
				printf("Nhap Id cua hoc sinh:");
				fflush(stdin);
				gets(temp);
				Student *tim=find(list,temp);
				if(tim!=NULL){
				printf("%s\n",tim->name);
				printf("%s\n",tim->id);
				printf("%d\n",tim->grade);
			}
				break;
			case 3:
				printf("Nhap Id cua hoc sinh:");
				fflush(stdin);
				gets(temp);
				list=xoa(list,temp);
				printf("DA XOA!\n");
				break;
			case 4:
				printf("Nhap Id cua hoc sinh:");
				fflush(stdin);
				gets(temp);
				printf("Nhap diem moi cho hoc sinh:");
				fflush(stdin);
				scanf("%d",&diem);
				list=change_grade(list,temp,diem);
				break;
		}
	}while(0<n && n<5);
	return 0;
}
