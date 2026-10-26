#include <stdio.h>
void accept(int a[20][20],int r,int c){
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
	printf("\n");
}

void compact(int a[20][20],int cp[20][20],int r,int c){
	cp[0][0]=r;
	cp[0][1]=c;
	int n=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]!=0){
				cp[n][0]=i;
				cp[n][1]=j;
				cp[n][2]=a[i][j];
				n++;
			}
		}
	}
	cp[0][2]=n-1;
}

void simpletranspose(int cp[20][20],int st[20][20]){
	st[0][0]=cp[0][1];
	st[0][1]=cp[0][0];
	st[0][2]=cp[0][2];
	int k=1;
	for(int i=0;i<cp[0][0];i++){
		for(int j=1;j<=cp[0][2];j++){
			if(cp[j][1]==i){
				st[k][0]=cp[j][1];
				st[k][1]=cp[j][0];
				st[k][2]=cp[j][2];
				k++;
			}
		}
	}
}

void fasttranspose(int cp[20][20],int ft[20][20]){
	int rterm[cp[0][1]],rpos[cp[0][1]];
	ft[0][0]=cp[0][1];
	ft[0][1]=cp[0][0];
	ft[0][2]=cp[0][2];
	for(int i=0;i<cp[0][1];i++){
		rterm[i]=0, rpos[i]=0;
		for(int j=0;j<=cp[0][2];j++){
			if (cp[j][1]==i)
				rterm[i]++;
		}
	}
	rpos[0]=1;
	for(int j=0;j<cp[0][1]-1;j++){
		rpos[j+1]=rpos[j]+rterm[j];
	}
	for(int j=1;j<=cp[0][2];j++){
		ft[rpos[cp[j][1]]][0]=cp[j][1];
		ft[rpos[cp[j][1]]][1]=cp[j][0];
		ft[rpos[cp[j][1]]][2]=cp[j][2];
		rpos[cp[j][1]]++;
	}	
}
			
int main(){
	int a[20][20],cp[20][20],st[20][20],ft[20][20],r,c,ch;
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of columns: ");
	scanf("%d",&c);
	accept(a,r,c);

	printf("Input Matrix \n");
	display(a,r,c);

	compact(a,cp,r,c);
	printf("Compact Form \n");
	display(cp,cp[0][2]+1,3);

	printf("1) Simple Transpose\n2) Fast Transpose\nChoose an option: ");
	scanf("%d",&ch);

	switch(ch){
	case 1:
		simpletranspose(cp,st);
		printf("Simple Transpose \n");
		display(st,st[0][2]+1,3);
		break;
	case 2:
		printf("Fast Transpose \n");
		fasttranspose(cp,ft);
		display(ft,ft[0][2]+1,3);
		break;
	default:
		printf("Invalid Operation");
	}

	return 0;
}
