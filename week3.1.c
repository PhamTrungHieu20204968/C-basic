#include<stdio.h>
#include<stdlib.h>
typedef struct phonelist{
	char name[30];
	char phone[10];
	char mail[30];
}Address;
struct AddressList {
	struct AddressList *next;
	Address addr;
};

struct AddressList *createNewNode(Address X){
    struct AddressList *newnode=(struct AddressList*)malloc(sizeof(struct AddressList));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    newnode->addr=X;
    newnode->next=NULL;

    return newnode;
}
struct AddressList * them(struct AddressList *head,struct AddressList *newnode){
	struct AddressList *cur;
	cur=head;
	if(head==NULL){
		head=newnode;
		return head;
	}else{
		while(cur->next!=NULL) cur=cur->next;
		cur->next=newnode;
	}
	return head;
}
void show(struct AddressList *head){
	struct AddressList *p=head;
	while(p!=NULL){
		printf("%s",p->addr.name);
		printf("%s",p->addr.phone);
		printf("%s",p->addr.mail);
		printf("\n");
		p=p->next;
	}
}
struct AddressList * xoa(struct AddressList *head){
	struct AddressList *p=head;
	if(head==NULL){
		printf("Khong co du lieu.\n");
		return head;
	}
	head=head->next;
	free(p);
	return head;
}
int main(){
	int i,n;
	struct AddressList *head=NULL;
	printf("Nhap so nguoi can them:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		Address newphone;	
		printf("name:");
		fflush(stdin);
		gets(newphone.name);
		printf("phone:");
		fflush(stdin);
		gets(newphone.phone);
		printf("mail:");
		fflush(stdin);
		gets(newphone.mail);
		printf("\n");
		struct AddressList *newnode=createNewNode(newphone);
		head=them(head,newnode);
	}
	show(head);
	head=xoa(head);
	show(head);
	return 0;
}
