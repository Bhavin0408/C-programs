
#include <stdio.h>

int isLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int year, month, days, day, startDay;
    int i;

    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    scanf("%d", &year);

    // Check for leap year
    if (isLeapYear(year))
        monthDays[1] = 29;

    // Calculate the first day of the year
    // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    startDay = (1 + (year - 1) * 365
                + (year - 1) / 4
                - (year - 1) / 100
                + (year - 1) / 400) % 7;

    // Print all 12 months
    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        days = monthDays[month];

        // Print spaces before the first date
        for (i = 0; i < startDay; i++)
            printf("    ");

        // Print dates
        for (day = 1; day <= days; day++)
        {
            printf("%4d", day);

            if ((startDay + day) % 7 == 0)
                printf("\n");
        }

        printf("\n");

        // Calculate starting day of next month
        startDay = (startDay + days) % 7;
    }

    return 0;
}
