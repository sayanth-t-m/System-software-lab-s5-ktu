#include <stdio.h>

// Global variables for maximum, allocated, and need matrices, as well as available resources
int max[100][100], alloc[100][100], need[100][100], avail[100];
int n, r, i, j;

// Function declarations
void input();  // Function to take input from the user
void show();   // Function to display the input matrices
void cal();    // Function to perform the Banker's Algorithm

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();  // Function to take input from the user
    show();   // Function to display the input matrices
    cal();    // Function to perform the Banker's Algorithm
    return 0;
}

// Function to take input from the user
void input() {
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);

    // Input the Max Matrix
    printf("\nEnter the Max Matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Input the Allocation Matrix
    printf("\nEnter the Allocation Matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Input the available Resources
    printf("\nEnter the available Resources\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);
}

// Function to display the input matrices
void show() {
    printf("\nProcess\t Allocation\t Max\t Available\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i + 1);

        // Display Allocation Matrix
        for (j = 0; j < r; j++)
            printf("%d\t", alloc[i][j]);

        printf("\t");

        // Display Max Matrix
        for (j = 0; j < r; j++)
            printf("%d\t", max[i][j]);

        printf("\t");

        // Display Available Resources (only for the first process)
        if (i == 0)
            for (j = 0; j < r; j++)
                printf("%d\t", avail[j]);

        printf("\n");
    }
}

// Function to perform the Banker's Algorithm
void cal() {
    int finish[100], flag = 1, k, c1 = 0;

    printf("\nSafe Sequence is:");

    // Initialize the finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Calculate the Need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\n");

    // Banker's Algorithm
    while (flag) {
        flag = 0;

        for (i = 0; i < n; i++) {
            int c = 0;

            // Check if the process can be executed
            for (j = 0; j < r; j++)
                if ((finish[i] == 0) && (need[i][j] <= avail[j])) {
                    c++;

                    // If all resources are available, execute the process
                    if (c == r) {
                        for (k = 0; k < r; k++) {
                            avail[k] += alloc[i][k];
                            finish[i] = 1;
                            flag = 1;
                        }

                        // Print the executed process
                        printf("P%d->", i + 1);

                        // If the process is executed, exit the loop
                        if (finish[i] == 1)
                            i = n;
                    }
                }
        }
    }

    // Check if all processes are executed
    for (i = 0; i < n; i++) {
        if (finish[i] == 1)
            c1++;
        else
            printf("P%d->", i + 1);
    }

    // Print whether the system is in a safe or unsafe state
    if (c1 == n)
        printf("\nThe system is in a safe state\n");
    else {
        printf("\nProcesses are in a deadlock\n");
        printf("System is in an unsafe state\n");
    }
}
