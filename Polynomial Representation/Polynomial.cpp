//polynomial p(x)=3x^5+2x^4+5x^2+2x+7
//in this we will learn how to do things with polynomial;
//1.Polynomial Represenetation
//2.Evaluation of Polynomial
//3.Addition of Two Polynomials
#include<stdio.h>
#include<stdlib.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *terms;
};
void create(struct Poly *p)
{
    int i;
    printf("number of terms?");
    scanf("%d",&p->n);
    p->terms=(struct Term*)malloc(p->n*sizeof(struct Term));
    printf("enter terms in decreasing order of exponent\n");
    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
    }
};
void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        printf("%dx^%d+",p.terms[i].coeff,p.terms[i].exp);
    }
    printf("\n");
};
int main()
{    struct Poly p1;
    create(&p1);
    display(p1);
    return 0;
}
