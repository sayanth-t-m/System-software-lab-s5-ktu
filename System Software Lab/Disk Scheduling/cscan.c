#include<stdio.h>

int main() {
    int i, j, sum = 0, n, d[20], disk, temp, max, dloc;

    // Display a prompt for the user
    printf("C-SCAN Disk Scheduling....");

    // Get the number of locations from the user
    printf("\nEnter the no. of locations:\t");
    scanf("%d", &n);

    // Get the initial position of the disk head from the user
    printf("\nEnter the position of the head:\t");
    scanf("%d", &disk);

    // Get the elements of the disk queue from the user
    printf("\nEnter the elements of the disk queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    // Add the initial disk head position to the disk queue
    d[n] = disk;
    n = n + 1;

    // Sort the disk queue in ascending order
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    // Set the maximum position to 199 (assuming the maximum disk position)
    max = 199;

    // Find the location of the disk head in the sorted queue
    for (i = 0; i < n; i++) {
        if (disk == d[i]) {
            dloc = i;
            break;
        }
    }

    // Print the sequence of movements from the initial position to the end (199)
    for (i = dloc; i < n; i++) {
        printf("%d-->", d[i]);
    }

    // Print the sequence of movements from the end (199) to the beginning (0)
    printf("199-->0-->");

    // Print the sequence of movements from the beginning to the initial position
    for (i = 0; i < dloc; i++) {
        printf("%d-->", d[i]);
    }

    // Calculate and display the total movement of cylinders
    sum = d[i - 1] + (max - disk) + max;
    printf("\nMovement of total cylinders :%d", sum);

    return 0; // Return success code
}
