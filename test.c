#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Record{
    char surname[30];       // Student Surname
    char sex;               // M - Male or F = Female
    char year[5];               // Year part of the student number
    char studentNumber[10];      // Last (5) digits of the student number
    char department[50];    // Department of the student
} Record;

// Function Prototypes
void displayIntro();
int getNumStudents();
Record *createRecord(int num);
void addRecords(int num, Record students[]);
void displayRecords(int num, Record *recordList);

// Main Function
int main(){

    int numStudents;
    Record *create_record;

    displayIntro();
    numStudents = getNumStudents();
    create_record =  createRecord(numStudents);
    addRecords(numStudents, create_record);
    displayRecords(numStudents, create_record);
}

// Display Intro Message
void displayIntro(){
    printf("=============================================================\n");
	printf("\t  This program is a Simple Student Record\n");
	printf("=============================================================\n");
}
// Get the number of Students
int getNumStudents(){
    int num;
    printf("\nEnter the number of students: ");
    scanf("%d", &num);
    return num;
}
// Allocate memory for the Records DB for a certain number of students
Record *createRecord(int num){
    Record *record_list = (Record *)malloc(num * sizeof(Record));
    return record_list;
}
// Add Student Information for Records
void addRecords(int num, Record students[]){
    int count = 0;
    while(count < num){
        printf("\nStudent %d Information:", count+1);

        printf("\nSurname: ");
        scanf(" %[^\n]", students[count].surname);

        printf("\nSex: ");
        scanf(" %c", &students[count].sex);

        printf("\nYear Enrolled: ");
        scanf(" %[^\n]", students[count].year);

        printf("\nStudent Number: ");
        scanf(" %[^\n]", students[count].studentNumber);

        // Concatenate the year into the student number to make it whole as one
        char temp[12];
        strcpy(temp, students[count].year);
        strcat(temp, students[count].studentNumber);
        strcpy(students[count].studentNumber, temp);

        printf("\nDepartment: ");
        scanf(" %[^\n]", students[count].department);

        count++;
    }
}

void displayRecords(int num, Record *recordList){
    int i = 0;
    printf("\n=============================================================\n");
	printf("Displaying Student Records...\n");
	printf("=============================================================\n\n");
    printf("No\t | Surname\t | Sex\t | Year\t | Student Number\t | Department\n");
    while(i < num){
        printf("%-2d\t | %-14s\t | %-13c | %-13s | %-14s\t | %-8s\t", i+1, recordList[i].surname, recordList[i].sex, recordList[i].year, recordList[i].studentNumber, recordList[i].department);
        i++;
    }
}