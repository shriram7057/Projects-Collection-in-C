#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

int hash(int key) { return key % SIZE; }

void insert(int key)
{
    int idx = hash(key);
    while (hashTable[idx] != -1)
        idx = (idx + 1) % SIZE;
    hashTable[idx] = key;
}

int search(int key)
{
    int idx = hash(key), start = idx;
    while (hashTable[idx] != -1)
    {
        if (hashTable[idx] == key)
            return idx;
        idx = (idx + 1) % SIZE;
        if (idx == start)
            break;
    }
    return -1;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d:%d\n", i, hashTable[i]);
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    display();
    int res = search(15);
    printf("15 found at index %d\n", res);
    return 0;
}
