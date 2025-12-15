#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m; // size of hash table

// Function to initialize hash table
void initialize()
{
    for (int i = 0; i < m; i++)
        hashTable[i] = -1; // -1 indicates empty location
}

// Hash function H(K) = K mod m
int hashFunction(int key)
{
    return key % m;
}

// Function to insert a key using Linear Probing
void insert(int key)
{
    int index = hashFunction(key);

    // Linear probing in case of collision
    while (hashTable[index] != -1)
    {
        index = (index + 1) % m;
    }

    hashTable[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

// Function to display hash table
void display()
{
    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d\t", i);
        if (hashTable[i] == -1)
            printf("EMPTY\n");
        else
            printf("%d\n", hashTable[i]);
    }
}

int main()
{
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    initialize();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
