/*----------------------------------------------------------------
AUTHOR: spexcher
Name: Gourab Modak
email: gm2623@cse.jgec.ac.in
Institution: Jalpaiguri Government Engineering College (B. Tech UG CSE 4 year)
Github: https://github.com/gauravthedeveloper/
linkedin : https://www.linkedin.com/in/gourabmodak/
codeforces : https://codeforces.com/profile/sectumsempra07/
codechef : https://www.codechef.com/users/sectumsempra07/
leetcode : https://leetcode.com/sectumsempra07/
--------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 1000000

// Structure to represent a student record
typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float score;
} Student;

// Function to read a student record from the user
void readStudent(Student *student)
{
    printf("Enter student ID: ");
    scanf("%d", &student->id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", student->name);
    printf("Enter student age: ");
    scanf("%d", &student->age);
    printf("Enter student score: ");
    scanf("%f", &student->score);
}

// Function to write a student record to the CSV file
void writeStudent(FILE *file, const Student *student)
{
    fprintf(file, "%d,%s,%d,%.2f\n", student->id, student->name, student->age, student->score);
}

// Function to read a student record from the CSV file
int readStudentFromFile(FILE *file, Student *student)
{
    return fscanf(file, "%d,%[^,],%d,%f\n", &student->id, student->name, &student->age, &student->score);
}

// Function to display a student record
void displayStudent(const Student *student)
{
    printf("ID: %d, Name: %s, Age: %d, Score: %.2f\n", student->id, student->name, student->age, student->score);
}

// Function to search for a student by ID
int searchStudentByID(FILE *file, int targetID, Student *result)
{
    rewind(file);
    Student student;
    while (readStudentFromFile(file, &student) != EOF)
    {
        if (student.id == targetID)
        {
            if (result != NULL)
            {
                *result = student;
            }
            return 1; // Student found
        }
    }
    return 0; // Student not found
}

// Function to update a student's record by ID
void updateStudentByID(FILE *file, int targetID)
{
    Student student;
    int found = searchStudentByID(file, targetID, &student);
    if (found)
    {
        printf("Student found:\n");
        displayStudent(&student);
        printf("Enter updated information:\n");
        readStudent(&student);
        // Open a temporary file for writing
        FILE *tempFile = fopen("temporary_file.csv", "w");
        rewind(file);
        while (readStudentFromFile(file, &student) != EOF)
        {
            if (student.id != targetID)
            {
                writeStudent(tempFile, &student);
            }
        }
        writeStudent(tempFile, &student);
        // Close both files
        fclose(file);
        fclose(tempFile);
        // Replace the original file with the tempora5ry file
        remove("student_database.csv");
        rename("temporary_file.csv", "student_database.csv");
        printf("Record updated successfully.\n");
    }
    else
    {
        printf("Student with ID %d not found.\n", targetID);
    }
}

// Function to delete a student's record by ID
void deleteStudentByID(FILE *file, int targetID)
{
    int found = 0;
    // Open a temporary file for writing
    FILE *tempFile = fopen("temporary_file.csv", "w");
    rewind(file);
    Student student;
    while (readStudentFromFile(file, &student) != EOF)
    {
        if (student.id != targetID)
        {
            writeStudent(tempFile, &student);
        }
        else
        {
            found = 1;
        }
    }
    // Close both files
    fclose(file);
    fclose(tempFile);
    if (found)
    {
        // Replace the original file with the temporary file
        remove("student_database.csv");
        rename("temporary_file.csv", "student_database.csv");
        printf("Record with ID %d deleted successfully.\n", targetID);
    }
    else
    {
        printf("Student with ID %d not found.\n", targetID);
    }
}

int main()
{
    FILE *file = fopen("student_database.csv", "a+");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    do
    {
        printf("\nStudent Database Menu:\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert student
            if (feof(file))
            {
                rewind(file);
            }
            Student newStudent;
            readStudent(&newStudent);
            writeStudent(file, &newStudent);
            printf("Student record inserted successfully.\n");
            break;
        case 2:
            // Delete student
            if (feof(file))
            {
                printf("No records found.\n");
                break;
            }
            int deleteID;
            printf("Enter the ID of the student to delete: ");
            scanf("%d", &deleteID);
            deleteStudentByID(file, deleteID);
            break;
        case 3:
            // Update student
            if (feof(file))
            {
                printf("No records found.\n");
                break;
            }
            int updateID;
            printf("Enter the ID of the student to update: ");
            scanf("%d", &updateID);
            updateStudentByID(file, updateID);
            break;
        case 4:
            // Search student
            if (feof(file))
            {
                printf("No records found.\n");
                break;
            }
            int searchID;
            printf("Enter the ID of the student to search: ");
            scanf("%d", &searchID);
            Student searchResult;
            int found = searchStudentByID(file, searchID, &searchResult);
            if (found)
            {
                printf("Student found:\n");
                displayStudent(&searchResult);
            }
            else
            {
                printf("Student with ID %d not found.\n", searchID);
            }
            break;
        case 5:
            // Display all students
            if (feof(file))
            {
                printf("No records found.\n");
                break;
            }
            rewind(file);
            printf("Student records:\n");
            Student record;
            while (readStudentFromFile(file, &record) != EOF)
            {
                displayStudent(&record);
            }
            break;
        case 6:
            // Exit
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    // Close the file
    fclose(file);

    return 0;
}
