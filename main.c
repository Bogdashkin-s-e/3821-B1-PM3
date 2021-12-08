#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortirovka.c"

int main ()
{ 
    int n, i, a, b = 0;
    char *mas, *masRes;

    FILE* file = 0;
    file = fopen("textFile.txt", "r");

    if (file == NULL)
    {
        printf("Error: cannot open file\n");
        return 0;
    }

    fscanf(file, "n = %d\n", &n);
    printf("total elements: %d \n", n);

    mas = (char*)malloc(n*sizeof(char));
    masRes = (char*)malloc(n*sizeof(char));

    for(i = 0; i < n; i++)
    {
        fscanf(file, "%hhd\n", &masRes[i]);
        mas[i] = masRes[i];
    }
    clock_t t2 = clock();

    while (a != 4)
    {
        printf("\n1. print\n2. sort\n3. reset\n4. Exit\n");
        scanf("%d", &a);
        clock_t t1 = clock();
        if (a == 1)
            PrintMas(mas, n);
        else if (a == 2)
        {
            printf("\n1. Bubble sort\n2. Insertion sort\n3. Quick sort\n4. Back\n");
            scanf("%d", &b);
            if (b == 1)
            {
                Bubblesort(mas, n);
                clock_t t2 = clock();
                printf("\n clock = %lf\n", (((double)(t2 - t1))/ CLOCKS_PER_SEC));
            }
            else if  (b == 2)
            {
                Insortionsort(mas, n);
                clock_t t2 = clock();
                printf("\n clock = %lf\n", (((double)(t2 - t1))/ CLOCKS_PER_SEC));
            }
            else if  (b == 3)
            {
                Quicksort(mas, n);
                clock_t t2 = clock();
                printf("\n clock = %lf\n", (((double)(t2 - t1))/ CLOCKS_PER_SEC));
            } 
            else if  (b == 4)
            {
                continue; 
            }
        }
        else if (a == 3)
        {
            for(i = 0; i < n; i++)
                mas[i] = masRes[i];
        }
        else if (a == 4)
        {
            Save(file, mas, n);
            printf("EXIT.");
        }
        else 
            printf("ne vibran punkt\n");

    }

  free(mas);
  free(masRes);

  return 0;
}
