#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int main() {
    int buffer[BUFFER_SIZE];
    int head = 0;    // next insertion index
    int count = 0;   // number of stored elements
    int n, value, i;

    printf("Enter number of values to input: ");
    scanf("%d", &n);

    // Insert values entered by user
    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        buffer[head] = value;
        head = (head + 1) % BUFFER_SIZE;

        if (count < BUFFER_SIZE) {
            count++;
        }
    }

    // Find the index of the oldest element
    int start = (head - count + BUFFER_SIZE) % BUFFER_SIZE;

    // Print values in chronological order
    printf("\nOn print: oldest is %d → ", buffer[start]);
    for (i = 0; i < count; i++) {
        printf("%d ", buffer[(start + i) % BUFFER_SIZE]);
    }

    return 0;
}
