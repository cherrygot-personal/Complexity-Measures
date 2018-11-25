/**
 *  This is a sample
 *  multiline comment.
 */

#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return (a + b);
}

int main() {
    int size = 10;
    int arr[size];
    int sum = 0;

    printf("Enter array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > 0) {
            sum += add(sum, arr[i]);
        }
        else {
            sum += add(sum, arr[i]);
        }
    }

    printf("The sum is : ");
    do {
        printf("%d", sum);
    } while(0);

    return 0;
}