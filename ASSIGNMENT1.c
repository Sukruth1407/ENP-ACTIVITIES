#include <stdio.h>

int main()
{
    int TEC = 0, REC = 0;
    int choice;

    while (1)
    {
        printf("\n--- CAN BUS ERROR SIMULATOR ---\n");
        printf("1. Transmission Error\n");
        printf("2. Reception Error\n");
        printf("3. Successful Transmission\n");
        printf("4. Successful Reception\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            TEC = TEC + 8;
            printf("Transmission Error!\n");
        }

        else if (choice == 2)
        {
            REC = REC + 1;
            printf("Reception Error!\n");
        }

        else if (choice == 3)
        {
            if (TEC > 0)
                TEC--;

            printf("Successful Transmission!\n");
        }

        else if (choice == 4)
        {
            if (REC > 0)
                REC--;

            printf("Successful Reception!\n");
        }

        else if (choice == 5)
        {
            break;
        }

        else
        {
            printf("Invalid choice!\n");
        }

        /* Determine CAN node state */

        if (TEC > 255)
            printf("State: BUS OFF\n");

        else if (TEC > 127 || REC > 127)
            printf("State: ERROR PASSIVE\n");

        else
            printf("State: ERROR ACTIVE\n");

        printf("TEC = %d\n", TEC);
        printf("REC = %d\n", REC);
    }

    return 0;
}
