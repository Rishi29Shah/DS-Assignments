#include<stdio.h>
int rear=-1,front=-1;
struct Jobseq{
int JobId;
char JobTitle[20];
};
void DisplayQ(struct Jobseq Q[20]){
	for(int i=front+1;i<=rear;i++){
	printf("\nJob Id: %d\nJod Title:%s",Q[i].JobId,Q[i].JobTitle);	
	printf("\n");
	}	
}
int isFull(struct Jobseq Q[20]){
	if(rear==20)
		return 1;
	else
		return 0; 
}
void AddQ(struct Jobseq Q[20],jid,jtitle){
	if(isFull(Q)==0){
		rear=rear+1;
		Q[rear].JobId=jid;
		Q[rear].JobTitle=jtitle;
	}
	else
		printf("Queue is Full\n");
}
int isEmpty(struct Jobseq Q[20]){
	if(rear==front)
		return 1;
	else
		return 0;
}

void DelQ(struct Jobseq Q[20]){
	if(isEmpty(Q)==0){
		front=front+1;
		printf("%d\n",Q[front].JobId);
		printf("%s\n",Q[front].JobTitle);
	}
	else
		printf("Queue is Empty\n");
}
int main(){
	int ch;
	char jid,jtitle;
	struct Jobseq Q[20];
	int exit=0;
	while(exit==0){
		printf("Enter operation to be done:");
		printf("\n1. Add\n2. Delete\n3. Display\n4. Exit\nYour Option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			printf("Enter the ID: ");
			scanf("%d",&jid);
			printf("Enter designation: ");
			scanf("%s",jtitle);
			AddQ(Q,jid,jtitle);
			break;
			case 2:
			DelQ(Q);
			break;
			case 3:
			DisplayQ(Q);
			break;
			case 4:
			printf("Exiting");
			exit=-1;
			break;
			default:
			printf("Enter Valid Choice");
		}
	}
return 0;
}
