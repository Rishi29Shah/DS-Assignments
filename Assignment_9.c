#include<stdio.h>
#include<string.h>
int rear=0,front=0;
int sizeQ=6;
struct Jobseq{
int JobId;
char JobTitle[];
};
int isFull(struct Jobseq Q[sizeQ]){
	if((rear+1)%sizeQ==front)
		return 1;
	else
		return 0; 
}
void AddQ(struct Jobseq Q[sizeQ],int jid,char jtitle[]){
	if(isFull(Q)==0){
		rear=(rear+1)%sizeQ;
		Q[rear].JobId=jid;
		strcpy(Q[rear].JobTitle, jtitle);
		printf("Element added\n");
	}
	else
		printf("Queue is Full\n");
}
int isEmpty(struct Jobseq Q[sizeQ]){
	if(rear==front)
		return 1;
	else
		return 0;
}

void DelQ(struct Jobseq Q[20]){
	if(isEmpty(Q)==0){
		front=(front+1)%sizeQ;
		printf("%d\n",Q[front].JobId);
		printf("%s\n",Q[front].JobTitle);
	}
	else
		printf("Queue is Empty\n");
}
int main(){
	int ch,jid;
	char jtitle[20];
	struct Jobseq Q[sizeQ];
	int exit=0;
	while(exit==0){
		printf("Enter operation to be done:");
		printf("\n1. Add\n2. Delete\n3. Exit\nYour Option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			printf("Enter the ID: ");
			scanf("%d",&jid);
			printf("Enter designation: ");
			scanf("%s",jtitle);
			AddQ(Q,jid,jtitle);
			printf("\n");
			break;
			case 2:
			DelQ(Q);
			printf("\n");
			break;
			case 3:
			printf("Exiting");
			exit=-1;
			break;
			default:
			printf("Enter Valid Choice\n");
		}
	}
return 0;
}
