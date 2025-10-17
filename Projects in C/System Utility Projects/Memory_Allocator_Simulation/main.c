#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024

char memory[MEMORY_SIZE];
int allocated[MEMORY_SIZE];

void *my_malloc(int size)
{
    int i, count;
    for (i = 0; i <= MEMORY_SIZE - size; i++)
    {
        count = 0;
        for (int j = i; j < i + size; j++)
        {
            if (allocated[j] == 0)
                count++;
            else
                break;
        }
        if (count == size)
        {
            for (int j = i; j < i + size; j++)
                allocated[j] = 1;
            printf("Allocated %d bytes at index %d\n", size, i);
            return &memory[i];
        }
    }
    printf("Memory allocation failed!\n");
    return NULL;
}

void my_free(void *ptr, int size)
{
    int index = (char *)ptr - memory;
    for (int i = index; i < index + size; i++)
        allocated[i] = 0;
    printf("Freed %d bytes from index %d\n", size, index);
}

int main()
{
    void *p1, *p2;
    p1 = my_malloc(100);
    p2 = my_malloc(200);
    my_free(p1, 100);
    p1 = my_malloc(50);
    return 0;
}
