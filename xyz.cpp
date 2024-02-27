#include <stdio.h>

int searchValue(int arr[], int value, int index, int size) {
    if (index == size) {
        return -1; // Value not found
    }

    if (arr[index] == value) {
        return index; // Value found at index
    }

    return searchValue(arr, value, index + 1, size); // Recursive call
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100]; // Assuming a maximum size of 100 for simplicity
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int valueToSearch;
    printf("Enter the value to search for: ");
    scanf("%d", &valueToSearch);
    
    int result = searchValue(arr, valueToSearch, 0, size);

    if (result != -1) {
        printf("Value %d found at index %d\n", valueToSearch, result);
    } else {
        printf("Value %d not found in the array\n", valueToSearch);
    }

    return 0;
}

