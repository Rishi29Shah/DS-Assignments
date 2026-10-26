#include<stdio.h>
struct Employee{
int id;
char name[20];
char desg[20];
};
void printarr(struct Employee e[30],int n){
	for(int i=0;i<n;i++){
		printf("\nID: %d\nName: %s\nDesignation: %s\n",e[i].id,e[i].name,e[i].desg);	
		printf("\n");
	}	
}

void accept(struct Employee e[30],int n){
	for(int i=0;i<n;i++){
		printf("Enter details");
		printf("Enter ID: ");
		scanf("%d",&e[i].id);
		printf("Enter Name: ");
		scanf("%s",e[i].name);
		printf("Enter Designation: ");
		scanf("%s",e[i].desg);
		printf("\n");	
	}
}

void swap(struct Employee *a,struct Employee *b){
	struct Employee temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void linearsearch(struct Employee e[30],int elem,int n){
	for(int i=0;i<n;i++){
		if(e[i].id==elem){
			printf("Found at %d index\n",i);
			printf("\nID: %d\nName: %s\nDesignation: %s\n",e[i].id,e[i].name,e[i].desg);
			break;
			}
		if(i==n){
			printf("Elemnet not found in array");
			}
	}
} 

void binarysearch(struct Employee e[30],int elem,int n){
	int l,h,m;
	l=0;h=n-1;
	while(l<=h){
		m=(l+h)/2;
		if(e[m].id==elem){
			printf("Found at index %d\n",m);
			printf("\nID: %d\nName: %s\nDesignation: %s\n",e[m].id,e[m].name,e[m].desg);
			break;
			}
		else{
			if(e[m].id>elem){
				h=m-1;
				}
			else{
				l=m+1;
				}
			}
		}
	if(l>h){
		printf("Element not found in array");
		}
}

void bubblesort(struct Employee e[30],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(e[j].id>e[j+1].id){
				swap(&e[j],&e[j+1]);
			}	
		}
	}
}

void selectionsort(struct Employee e[30],int n){
	int min,idx;
	for(int i=0;i<n-1;i++){
		min = e[i].id;
		idx = i;
		for(int j=i+1;j<n;j++){
			if(e[j].id<min){
				min = e[j].id;
				idx =j;
				}
			}
		swap(&e[i],&e[idx]);
	}
}

void shellsort(struct Employee e[30],int n){
	int gap,sflag=1,i=0;
	gap=n/2;
	while(gap>0){
		while(sflag==1){
			sflag = 0;
			while(i<n-gap){
				if(e[i].id>e[i+gap].id){
					swap(&e[i],&e[i+gap]);
					sflag = 1;
					i++;
					}
				i++;
				}
		}
		gap = gap/2;
	}
}

void insertionsort(struct Employee e[30],int n){
	for(int i=1;i<n;i++){
		struct Employee keyelem=e[i];
		int j=i-1;
		while(j>=0 && e[j].id>keyelem.id){
			swap(&e[j+1],&e[j]);
			j=j-1;
		}
	}
}
		
int main(){
	struct Employee emp[30];
	int n,elem;
	printf("Enter number of employees: ");
	scanf("%d",&n);
	accept(emp,n);
	int ch;
	printf("\n1. Linear Search\n2. Binary Search\n3. Bubble Sort\n4. Selection Sort\n5. Shell Sort\n6. Insertion Sort\nEnter The Choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: 
		printf("Enter ID: ");
		scanf("%d",&elem);
		linearsearch(emp,elem,n);
		break;
		case 2:
		printf("Enter ID: ");
		scanf("%d",&elem);
		bubblesort(emp,n);
		binarysearch(emp,elem,n);
		break;
		case 3:
		bubblesort(emp,n);
		printf("Sorted Structure:");
		printarr(emp,n);
		break;
		case 4:
		selectionsort(emp,n);
		printf("Sorted Structure:");
		printarr(emp,n);
		break;
		case 5:
		shellsort(emp,n);
		printf("Sorted Structure:");
		printarr(emp,n);
		break;
		case 6:
		insertionsort(emp,n);
		printf("Sorted Structure:");
		printarr(emp,n);
		break;
		default:
		printf("Invalid Choice");
	}
	return 0;
}

