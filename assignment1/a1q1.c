#include <stdio.h>
int main() {
    // Part 1 - Create array
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr1) / sizeof(int);

    // Part 2 - Display original array
    printf("The array made is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\n");

    // Part 3 - Insert element
    int n, pos;
    printf("Enter the number and the position you want to insert: ");
    scanf("%d %d", &n, &pos);

    int arr2[size + 1];
    for (int i = 0; i <= size; i++) 
    {
        if (i < pos - 1) 
        {
            arr2[i] = arr1[i];
        } 
        else if (i == pos - 1)
        {
            arr2[i] = n;
        } 
        else
        {
            arr2[i] = arr1[i - 1];
        }
    }
    size++; 
    // size increases after insertion

    printf("The inserted array is: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d\t", arr2[i]);
    }
    printf("\n");

    // Part 4 - Delete element
    int del, p = -1;
    printf("Enter the number you want to delete: ");
    scanf("%d", &del);

    for (int i = 0; i < size; i++) 
    {
        if (arr2[i] == del) {
            p = i;
            break;
        }
    }
    if (p != -1) 
    {
        for (int i = p; i < size - 1; i++) 
        {
            arr2[i] = arr2[i + 1];
        }
        size--;
        printf("The deleted array is: ");
        for (int i = 0; i < size; i++) 
        {
            printf("%d\t", arr2[i]);
        }
        printf("\n");
    } 
    else 
    {
        printf("Element not found for deletion.\n");
    }

    // Part 5 - Search element
    int search, found = 0;
    printf("Enter the number you want to search: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++) {
        if (search == arr2[i]) {
            printf("The number %d is found at position %d\n", search, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
    // Part 6 - Exit ARRAY
    return 0;
}
