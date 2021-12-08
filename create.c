#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int n, a = 0;
    int i = 0;
  
    printf("n = ");
    scanf("%d", &n);

    printf("Enter input type (1.random/2.keyboard)\n");
    scanf("%d", &a);

    if (a==1 || a==2)
    {}
    else
    {
        printf("Error: invalid inputn\n");
    }

    FILE* file = 0;
    file = fopen("textFile.txt", "w");
    fprintf(file, "n = %d\n", n);
  
    if (a == 1)
    {
        srand(time(0));
        for (i = 0; i < n; i++)
        {
            char c =-128 + rand() % (256);
            fprintf(file, "%d\n", c); 
        }
        printf("file created! \n");
    }

    if (a == 2)
    {
        printf("!input:\n");
        for (i = 0; i < n; i++)
        {
        int b = 0;
        scanf("%d", &b);
        if(b > -129 && b < 128)
            fprintf(file, "%d\n", b);
        else 
        {
            printf("\n!input fron -128 to 127\n");
            i--;
        }
    }
    printf("file created! \n");
    }

    return 0;
}