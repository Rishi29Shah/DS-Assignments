#include <stdio.h>
#include <stdlib.h>
struct poly{
	int coeff;
	int exp;
	struct poly *next;
};
void create(struct poly *head){
    struct poly *newnd,*last;
    last=head;
    char ch;
    printf("Do you want to create polynomial (y/n)?");
    scanf(" %c",&ch);
    while(ch=='y'){
        newnd=(struct poly *)malloc(sizeof(struct poly));
        printf("\nEnter Coefficient: ");
        scanf("%d",&newnd->coeff);
        printf("\nEnter Exponent: ");
        scanf("%d",&newnd->exp);
        newnd->next=head;
        last->next=newnd;
        last=newnd;
        printf("\nDo you want to add more node (y/n)?");
        scanf(" %c",&ch);
    }
}

void display(struct poly *head){
    struct poly *temp;
    temp=head->next;
    if(head->next==head)
        printf("LL is empty");
    else{
        while(temp!=head){
            printf("%d*x^%d",temp->coeff,temp->exp);
            temp=temp->next;
            if (temp!=head)
                printf(" + ");
        }
    }
}

void add(struct poly *h1, struct poly *h2,struct poly *h3) {
    struct poly *p,*q;
    struct poly *newnd, *last;
    last=h3;
    p=h1->next;
    q=h2->next;
    int c;
    while (p != h1 && q != h2) {
        if (p->exp == q->exp) {
            newnd=(struct poly *)malloc(sizeof(struct poly));
            c=p->coeff+q->coeff;
            newnd->coeff=c;
            newnd->exp=p->exp;
            newnd->next=h3;
            last->next=newnd;
            last=newnd;
            p=p->next;
            q=q->next;
        }
        else if(p->exp > q->exp) {
            newnd=(struct poly *)malloc(sizeof(struct poly));
            newnd->coeff=p->coeff;
            newnd->exp=p->exp;
            newnd->next=h3;
            last->next=newnd;
            last=newnd;
            p=p->next;
        }
        else {
            newnd=(struct poly *)malloc(sizeof(struct poly));
            newnd->coeff=q->coeff;
            newnd->exp=q->exp;
            newnd->next=h3;
            last->next=newnd;
            last=newnd;
            q=q->next;
        }
    }
    while (p != h1) {
        newnd=(struct poly *)malloc(sizeof(struct poly));
        newnd->coeff=p->coeff;
        newnd->exp=p->exp;
        newnd->next=h3;
        last->next=newnd;
        last=newnd;
        p=p->next;
    }
    while (q != h2) {
        newnd=(struct poly *)malloc(sizeof(struct poly));
        newnd->coeff=q->coeff;
        newnd->exp=q->exp;
        newnd->next=h3;
        last->next=newnd;
        last=newnd;
        q=q->next;
    }
}


int main(){
    struct poly *head1,*head2,*head3;
    head1=(struct poly *)malloc(sizeof(struct poly));
    head1->next=head1;
    printf("Enter polynomial 1\n");
    create(head1);
    head2=(struct poly *)malloc(sizeof(struct poly));
    head2->next=head2;
    printf("Enter polynomial 2\n");
    create(head2);
    head3=(struct poly *)malloc(sizeof(struct poly));
    head3->next=head3;
    add(head1,head2,head3);
    printf("Sum of polynomials:");
    display(head3);
    return 0;
}
