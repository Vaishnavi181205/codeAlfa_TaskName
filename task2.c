//TASK 3: High – Student Management System

/*Objective:
Create a menu-driven C program to manage student records.
Features include:

Add, Display, Search, Update, and Delete Records

Uses structures and file handling for permanent data storage*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "Roll No", "Name", "Age", "Marks");
    printf("----------------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%-10d %-20s %-10d %-10.2f\n", s.rollNo, s.name, s.age, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll No to Search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo == roll) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nAge: %d\nMarks: %.2f\n", s.rollNo, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nStudent with Roll No %d not found!\n", roll);
}

void updateStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;
    long pos;

    fp = fopen("students.dat", "rb+");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll No to Update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo == roll) {
            printf("\nEnter new Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new Age: ");
            scanf("%d", &s.age);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);

            pos = -1L * sizeof(s);
            fseek(fp, pos, SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("\nRecord updated successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nStudent with Roll No %d not found!\n", roll);
}

void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("\nEnter Roll No to Delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nStudent with Roll No %d not found!\n", roll);
}


