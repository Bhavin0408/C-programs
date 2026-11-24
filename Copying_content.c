
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source, *target;
    char ch;
    char sourceFile[100], targetFile[100];

    // Accept file names
    printf("Enter source file name: ");
    scanf("%99s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%99s", targetFile);

    // Open source file in read mode
    source = fopen(sourceFile, "r");

    if (source == NULL)
    {
        printf("Error: Cannot open source file.\n");
        return 1;
    }

    // Open destination file in write mode
    target = fopen(targetFile, "w");

    if (target == NULL)
    {
        printf("Error: Cannot create destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, target);
    }

    printf("File contents copied successfully!\n");

    // Close both files
    fclose(source);
    fclose(target);

    return 0;
}
