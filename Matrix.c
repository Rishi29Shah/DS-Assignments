#include<stdio.h>

void accept(int a[20][20],int r,int c){
	printf("Enter elements of matrix: ");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
}

void display(int a[20][20],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
}

void addition(int a1[20][20],int a2[20][20],int r1,int c1,int r2,int c2){
	if(r1==r2 && c1==c2){
		printf("\nThe addition of both the matrices is:\n");
		for(int i=0;i<r1;i++){
			for(int j=0;j<c1;j++){
				printf(" %d",a1[i][j]+a2[i][j]);
			}
			printf("\n");
		}
	}
}

void subtraction(int a1[20][20],int a2[20][20],int r1,int c1,int r2,int c2){
	if(r1==r2 && c1==c2){
		printf("\nThe subtraction of both the matrices is:\n");
		for(int i=0;i<r1;i++){
			for(int j=0;j<c1;j++){
				printf(" %d",a1[i][j]-a2[i][j]);
			}
			printf("\n");
		}
	}
}


void multiply(int a1[20][20],int a2[20][20],int r1,int c1,int r2,int c2){
	if(c1==r2){
		printf("Multiplication of matrices is:\n");
		int p=0,a=0;
		for(int k=0;k<c2;k++){
			for(int i=0;i<r1;i++){
				for(int j=0;j<r2;j++){
					a = a1[k][j]*a2[j][i];
					p=p+a;		
				}
				printf("%d ",p);
					p=0;
			}
			printf("\n");
		}
	}
}

void transpose(int a[20][20],int t[20][20],int r, int c){
	printf("\nThe transpose of the matrix is:");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			t[i][j] = a[j][i];
		}
	}
	printf("\n");
}

int main()
{
	int a1[20][20],a2[20][20],ch,r1,c1,r2,c2,t[20][20];
	printf("Enter Row of matrix: ");
	scanf("%d",&r1);
	printf("Enter Column of matrix: ");
	scanf("%d",&c1);
	printf("1. Display\n2. Addition\n3. Subtraction\n4. Multiplication\n5. Transpose\nChoose an option: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: 
			accept(a1,r1,c1);
			display(a1,r1,c1);
			break;

		case 2: 
			printf("Enter Row of matrix 2: ");
			scanf("%d",&r2);
			printf("Enter Column of matrix 2: ");
			scanf("%d",&c2);
			accept(a1,r1,c1);
			accept(a2,r2,c2);
			addition(a1,a2,r1,c1,r2,c2);
			break;

		case 3: 
			printf("Enter Row of matrix 2: ");
			scanf("%d",&r2);
			printf("Enter Column of matrix 2: ");
			scanf("%d",&c2);
			accept(a1,r1,c1);
			accept(a2,r2,c2);
			subtraction(a1,a2,r1,c1,r2,c2);
			break;

		case 4: 
			printf("Enter Row of matrix 2: ");
			scanf("%d",&r2);
			printf("Enter Column of matrix 2: ");
			scanf("%d",&c2);
			accept(a1,r1,c1);
			accept(a2,r2,c2);
			multiply(a1,a2,r1,c1,r2,c2);
			break;

		case 5:
			accept(a1,r1,c1);
			transpose(a1,t,r1,c1);
			display(t,c1,r1);
			break;

		default:
			printf("Invalid Operation");
	}

	return 0;
}
