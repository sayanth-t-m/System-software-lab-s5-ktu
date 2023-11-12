#include<stdio.h>

int main() {
    int i, sum = 0, n, disk, ar[20], tm[20];

    // Display a prompt for the user
    printf("FCFS Disk Scheduling....");

    // Get the number of locations from the user
    printf("\nEnter the no. of locations:\t");
    scanf("%d", &n);

    // Check if the entered number of locations is within a valid range
    if (n <= 0 || n > 20) {
        printf("Invalid number of locations. Please enter a value between 1 and 20.\n");
        return 1; // Return an error code
    }

    // Get the initial position of the disk head from the user
    printf("\nEnter the position of the head:\t");
    scanf("%d", &disk);

    // Get the elements of the disk queue from the user
    printf("\nEnter the elements of the disk queue:\n");

    // Loop through each element in the disk queue
    for (i = 0; i < n; i++) {
        // Get the next element of the disk queue
        scanf("%d", &ar[i]);

        // Calculate the distance between the current and previous disk positions
        tm[i] = disk - ar[i];

        // If the distance is negative, calculate the absolute distance
        if (tm[i] < 0) {
            tm[i] = ar[i] - disk;
        }

        // Update the disk position to the current element
        disk = ar[i];

        // Accumulate the total movement distance
        sum += tm[i];
    }

    // Display the sequence of movements
    printf("Sequence of movements: ");
    for (i = 0; i < n - 1; i++) {
        printf("%d + ", tm[i]);
    }
    printf("%d\n", tm[n - 1]);  // Print the last element without the +

    // Display the total movement of cylinders
    printf("Movement of total cylinders = %d\n", sum);

    return 0; // Return success code
}
