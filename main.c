#include <stdio.h>
#include <stdlib.h>

int* get (const int *tri, const unsigned int x, const unsigned int y)
    {
    return tri + (x * (x+1) / 2 + y);
    }

void read (const FILE *input, int *tri, const unsigned int h)
    {
    for (int i = 0; i < h; ++i)
        {
        for (int j = 0; j < i + 1; ++j)
            fscanf(input, "%d", get(tri, i, j));    
        }   
    }   

void print (const int *tri, const unsigned int h)
    {
    for (int i = 0; i < h; ++i)
        {
        for (int j = 0; j < i + 1; ++j)
            printf("%d ", *get(tri, i, j));

        printf("\n");   
        }   
    }   

int main () 
    {

    FILE *input = NULL;
    input       = fopen("test", "r");

    unsigned int h;
    fscanf(input, "%u", &h);

    int *tri = malloc((h * (h+1) / 2) * sizeof(int));
    read(input, tri, h);

    print(tri, h);
    printf("\n");

    (*get(tri, 1, 1)) = 100500;
    print(tri, h);

    free(tri);

    return 0;
    }