#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[30];
    float marks;
};

void addRecords(FILE *fp, int n)
{
    struct Student s;

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s.id);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }
}

void displayRecord(FILE *fp, int m)
{
    struct Student s;

    fseek(fp, (m - 1) * sizeof(struct Student), SEEK_SET);

    if(fread(&s, sizeof(struct Student), 1, fp))
    {
        printf("\nRecord %d:\n", m);
        printf("ID = %d\n", s.id);
        printf("Name = %s\n", s.name);
        printf("Marks = %.2f\n", s.marks);
    }
    else
    {
        printf("\nRecord not found.\n");
    }
}

void deleteRecord(int recordNo)
{
    FILE *fp, *temp;
    struct Student s;
    int count = 1;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(count != recordNo)
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
        count++;
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("\nRecord deleted successfully.\n");
}

int main()
{
    FILE *fp;
    int n, m, del;

    fp = fopen("student.dat", "wb");

    printf("Enter number of records: ");
    scanf("%d", &n);

    addRecords(fp, n);

    fclose(fp);

    fp = fopen("student.dat", "rb");

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    displayRecord(fp, m);

    fclose(fp);

    printf("\nEnter record number to delete: ");
    scanf("%d", &del);

    deleteRecord(del);

    return 0;
}