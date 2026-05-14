#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    float marks;
};

// Function to write records and store seek positions
void writeRecords(struct Student s[], int n, long pos[])
{
    FILE *fp;
    int i;

    fp = fopen("student.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    for(i = 0; i < n; i++)
    {
        // Store beginning position of each record
        pos[i] = ftell(fp);

        fprintf(fp, "%d %s %.2f\n",
                s[i].id,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);
}

// Function to display record using seek position
void displayRecord(long position)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    // Move file pointer to desired position
    fseek(fp, position, SEEK_SET);

    // Read the record
    fscanf(fp, "%d %s %f",
           &s.id,
           s.name,
           &s.marks);

    printf("\nRecord Found:\n");
    printf("ID     : %d\n", s.id);
    printf("Name   : %s\n", s.name);
    printf("Marks  : %.2f\n", s.marks);

    fclose(fp);
}

int main()
{
    int n, i, choice;
    struct Student s[100];
    long pos[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input records
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Write records and store positions
    writeRecords(s, n, pos);

    printf("\nStored Seek Positions:\n");
    for(i = 0; i < n; i++)
    {
        printf("Record %d starts at position %ld\n",
               i + 1, pos[i]);
    }

    // Display a record using seek position
    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= n)
    {
        displayRecord(pos[choice - 1]);
    }
    else
    {
        printf("Invalid record number.\n");
    }

    return 0;
}
