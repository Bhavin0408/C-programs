
#include <stdio.h>

int main()
{
    char name[50];
    float basic, ta, hra, income;
    char post[30];

    printf("Enter employee name: ");
    scanf(" %[^\n]", name);

    printf("Enter basic income: ");
    scanf("%f", &basic);

    // Calculate TA and HRA
    ta = basic * 0.23;
    hra = basic * 0.30;

    // Calculate total income
    income = basic + ta + hra;

    // Assign post according to income
    if (income < 60000)
    {
        sprintf(post, "Junior Clerk");
    }
    else if (income <= 80000)
    {
        sprintf(post, "Senior Clerk");
    }
    else if (income <= 100000)
    {
        sprintf(post, "Manager");
    }
    else
    {
        sprintf(post, "Senior Clerk");
    }

    // Display result in tabular form
    printf("\n");
    printf("---------------------------------------------------------------\n");
    printf("%-20s %-12s %-12s %-12s %-20s\n",
           "Name", "Basic", "TA", "HRA", "Post");
    printf("---------------------------------------------------------------\n");

    printf("%-20s %-12.2f %-12.2f %-12.2f %-20s\n",
           name, basic, ta, hra, post);

    printf("---------------------------------------------------------------\n");
    printf("Total Income: %.2f\n", income);

    return 0;
}
