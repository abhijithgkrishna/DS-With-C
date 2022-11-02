#include <stdio.h>

typedef struct
{
    int coeff;
    int exp;
} poly;

poly p[10], q[10], r[10];
int k = 0;
int polyAdd(poly p[], poly q[], int m, int n)
{
    int i = 0, j = 0;
    while (i <= m && j <= n)
    {
        if (p[i].exp > q[j].exp)
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff;
            k++;
            i++;
        }
        else if (p[i].exp < q[j].exp)
        {
            r[k].exp = q[j].exp;
            r[k].coeff = q[j].coeff;
            j++;
            k++;
        }
        else
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff + q[j].coeff;
            k++;
            i++;
            j++;
        }
    }
    if (i == m)
    {
        while (j <= n)
        {
            r[k].exp = q[j].exp;
            r[k].coeff = q[j].coeff;
            j++;
            k++;
        }
    }
    if (j == n)
    {
        while (i <= m)
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff;
            i++;
            k++;
        }
    }
}

void main()
{
    int deg1, deg2, i;
    printf("Enter degree of polynomial 1 : ");
    scanf("%d", &deg1);
    for (i = deg1; i >= 0; i--)
    {
        printf("Enter coeff of x^%d : ", i);
        scanf("%d", &p[deg1 - i].coeff);
        p[deg1 - i].exp = i;
    }
    printf("The polynomial is : \n");
    for (i = deg1; i >= 0; i--)
    {
        printf("%dx^%d+", p[deg1 - i].coeff, p[deg1 - i].exp);
    }
    printf("0\n");

    printf("Enter degree of polynomial 2 : ");
    scanf("%d", &deg2);
    for (i = deg2; i >= 0; i--)
    {
        printf("Enter coeff of x^%d : ", i);
        scanf("%d", &q[deg2 - i].coeff);
        q[deg2 - i].exp = i;
    }
    printf("The polynomial is : \n");
    for (i = deg2; i >= 0; i--)
    {
        printf("%dx^%d+", q[deg2 - i].coeff, q[deg2 - i].exp);
    }
    printf("0\n");
    polyAdd(p, q, deg1, deg2);
    printf("\nThe result of addition is :\n");
    for (i = k; i >= 0; i--)
    {
        printf("%dx^%d+", r[k - i].coeff, r[k - i].exp);
    }
    printf("0\n");
}