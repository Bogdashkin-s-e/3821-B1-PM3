#include <stdio.h>
#include <stdlib.h>

void PrintMas(char* a, int l)
{
    int i = 0;
    for (i = 0; i < l; i++)
        {
            printf("mas[%d] = %d\n", i, a[i]);
        }
}

void Save(FILE* f, char *a, int n)
{
    f = fopen("textFile.txt", "w");

    fprintf(f, "n = %d\n", n);

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d\n", a[i]);
    }
}

void Bubblesort(char *a, int l)
{
    int i, j;
    int tmp = 0;

    for (i = 0;i < l; i++)
    {
        for (j = 0; j < l - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
            tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
            }
        }
    }
}

void Insortionsort(char *a, int l)
{
    int i, j;
    int tmp = 0;

    for (i = 1;i < l; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > tmp)
            {
            a[j + 1] = a[j];        
            }
            else 
                break;
        }
        a[j + 1] = tmp;
    }
}

void Qsort(char* mas, int l, int u)
{
    int i = l;
    int j = u;

    int tmp = 0;
  
    int x = mas[(int)((l+u)/2)];
  
    do
    {
        while(mas[i] < x) 
            ++i;
        while(mas[j] > x) 
            --j;

        if (i <= j)
        {
            tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i < j);
  
    if (l < j) 
        Qsort(mas, l, j);
    if (i < u) 
        Qsort(mas, i, u);
}

void Quicksort (char *a, int l)
{
    Qsort(a, 0, (l - 1));
}