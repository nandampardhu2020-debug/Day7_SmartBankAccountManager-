#include <stdio.h>

int main() {
    char name[50], regNo[20], section[10];
    int numEmployees, i, j, choice;
    float salary[10], total = 0, average, highest, lowest, temp;
    int aboveAvg = 0, belowAvg = 0;

    // Step 1: Input Student Information
    printf("=== Employee Salary Analysis System ===\n");
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Registration Number: ");
    scanf(" %s", regNo);
    printf("Enter Section: ");
    scanf(" %s", section);

    // Step 2: Input Employee Salary Data
    printf("\nEnter number of employees (max 10): ");
    scanf("%d", &numEmployees);

    if (numEmployees > 10 || numEmployees <= 0) {
        printf("Invalid number of employees! Please enter between 1 and 10.\n");
        return 0;
    }

    printf("\nEnter the salary of each employee:\n");
    for (i = 0; i < numEmployees; i++) {
        printf("Employee %d Salary: ", i + 1);
        scanf("%f", &salary[i]);
    }

    // Step 3: Menu-driven System
    do {
        printf("\n-----------------------------------------------\n");
        printf("Code2Grow: Day 17 Challenge – Employee Salary Analysis\n");
        printf("Submitted by: %s | Reg No: %s | Section: %s\n", name, regNo, section);
        printf("-----------------------------------------------\n");

        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Employees Above and Below Average\n");
        printf("5. Display Sorted Salaries (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                printf("All Employee Salaries:\n");
                for (i = 0; i < numEmployees; i++) {
                    printf("Employee %d: %.2f\n", i + 1, salary[i]);
                }
                break;

            case 2:
                total = 0;
                for (i = 0; i < numEmployees; i++)
                    total += salary[i];
                average = total / numEmployees;
                printf("Total Salary: %.2f\n", total);
                printf("Average Salary: %.2f\n", average);
                break;

            case 3:
                highest = salary[0];
                lowest = salary[0];
                for (i = 1; i < numEmployees; i++) {
                    if (salary[i] > highest)
                        highest = salary[i];
                    if (salary[i] < lowest)
                        lowest = salary[i];
                }
                printf("Highest Salary: %.2f\n", highest);
                printf("Lowest Salary: %.2f\n", lowest);
                break;

            case 4:
                total = 0;
                for (i = 0; i < numEmployees; i++)
                    total += salary[i];
                average = total / numEmployees;

                aboveAvg = 0;
                belowAvg = 0;
                for (i = 0; i < numEmployees; i++) {
                    if (salary[i] > average)
                        aboveAvg++;
                    else if (salary[i] < average)
                        belowAvg++;
                }
                printf("Employees Above Average: %d\n", aboveAvg);
                printf("Employees Below Average: %d\n", belowAvg);
                break;

            case 5:
                // Bubble sort for ascending order
                for (i = 0; i < numEmployees - 1; i++) {
                    for (j = 0; j < numEmployees - i - 1; j++) {
                        if (salary[j] > salary[j + 1]) {
                            temp = salary[j];
                            salary[j] = salary[j + 1];
                            salary[j + 1] = temp;
                        }
                    }
                }
                printf("Salaries in Ascending Order:\n");
                for (i = 0; i < numEmployees; i++) {
                    printf("%.2f ", salary[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

    } while (choice != 6);

    // Step 4: End of Program Output
    printf("\n-----------------------------------------------\n");
    printf("Submitted by: %s | Reg No: %s | Section: %s\n", name, regNo, section);
    printf("Challenge Day 17 – Code2Grow Program\n");
    printf("-----------------------------------------------\n");

    return 0;
}