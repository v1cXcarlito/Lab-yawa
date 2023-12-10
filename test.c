#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Record{
    char surname[30];       // Student Surname
    char sex;               // M - Male or F = Female
    char year[5];               // Year part of the student number
    char studentNumber[11];      // Last (5) digits of the student number
    char department[50];    // Department of the student
} Record;

// Function Prototypes
void displayIntro();
int getNumStudents();
Record *createRecord(int num);
void addRecords(int num, Record students[]);
void displayRecords(int num, Record *recordList);
void displayFilteredRecords(int num, Record *recordList, int filterOption);
void findStudentByNum(int num, Record *recordList, char *snum);

// Main Function
int main(){

    int numStudents;
    Record *create_record;

    displayIntro();

    int flag = 1, filterFlag = 1;
    int answer, filter, filter2, findAnswer;
    char findStudent[5];
    while(flag){
        numStudents = getNumStudents();
        create_record =  createRecord(numStudents);
        addRecords(numStudents, create_record);
        displayRecords(numStudents, create_record);

        while(filterFlag){
            printf("\n\nFilter records [1] Sex [2] Year [3] Department: ");
            scanf("%d", &filter);

            displayFilteredRecords(numStudents, create_record, filter);
            printf("\n\nFilter Again? [1] Yes [0] No: ");
            scanf("%d", &filter2);
            if(filter2 == 1){
                filterFlag = 1;
            } else if (filter2 == 0){
                filterFlag = 0;
            }
        }
        
        int find = 1;

        while(find){
            printf("\n\nFind Student by number: ");
            scanf("%s", &findStudent);
            findStudentByNum(numStudents, create_record, findStudent);
            
            printf("\nFind again? [1] Yes [0] No: ");
            scanf("%d", &findAnswer);
            if(findAnswer == 1){
                find = 1;
            }
            else if (findAnswer == 0){
                find = 0;
            }
        }

        printf("\n\nDo you want to start again? [1] Yes [0] No -> ");
        scanf("%d", &answer);
        if(answer == 1){
            flag = 1;
        } else if (answer == 0){
            flag = 0;
        }
    }
    
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
        printf("\nStudent %d Information:\n", count+1);

        printf("\nSurname: ");
        scanf(" %[^\n]", students[count].surname);

        printf("Sex: ");
        scanf(" %c", &students[count].sex);

        printf("Year Enrolled: ");
        scanf(" %[^\n]", students[count].year);

        printf("Student Number: ");
        scanf(" %[^\n]", students[count].studentNumber);

        // Concatenate the year into the student number to make it whole as one
            // Concatenate the 'year' and 'studentNumber' fields of a student record into a single string
            char temp[11];
            snprintf(temp, sizeof(temp), "%s-%s", students[count].year, students[count].studentNumber);
    
            // Store the concatenated string back in the 'studentNumber' field
            strncpy(students[count].studentNumber, temp, sizeof(students[count].studentNumber) - 1);
            students[count].studentNumber[sizeof(students[count].studentNumber) - 1] = '\0';

        printf("Department: ");
        scanf("  %[^\n]", students[count].department);

        count++;
    }
}

void displayRecords(int num, Record *recordList){
    int i = 0;
    printf("\n=============================================================\n");
	printf("Displaying Student Records...\n");
	printf("=============================================================\n\n");
    printf("\nNo\t | Surname\t\t | Sex\t\t | Year\t\t | Student Number\t | Department\n");
    while(i < num){
        printf("\n%-2d\t | %-14s\t | %-13c | %-13s | %-10s\t\t | %-8s\t\n", i+1, recordList[i].surname, recordList[i].sex, recordList[i].year, recordList[i].studentNumber, recordList[i].department);
        i++;
    }
}

void displayFilteredRecords(int num, Record *recordList, int filterOption) {
    printf("\n=============================================================\n");
    printf("Displaying Filtered Student Records...\n");
    printf("=============================================================\n\n");
    printf("No\t | Surname\t | Sex\t | Year\t | Student Number\t | Department\n");

    for (int i = 0; i < num; i++) {
        // Check the filter option and display records accordingly
        switch (filterOption) {
            case 1: // Sex
                if (recordList[i].sex == 'M' || recordList[i].sex == 'F' || recordList[i].sex == 'm' || recordList[i].sex == 'f') {
                    printf("%-2d\t | %-14s\t | %-13c | %-13s | %-14s\t | %-8s\t\n",
                           i + 1, recordList[i].surname, recordList[i].sex,
                           recordList[i].year, recordList[i].studentNumber,
                           recordList[i].department);
                }
                break;

            case 2: // Year
                // Assuming 'year' is a string, modify as needed if it's an integer
                if (strlen(recordList[i].year) > 0) {
                    printf("%-2d\t | %-14s\t | %-13c | %-13s | %-14s\t | %-8s\t\n",
                           i + 1, recordList[i].surname, recordList[i].sex,
                           recordList[i].year, recordList[i].studentNumber,
                           recordList[i].department);
                }
                break;

            case 3: // Department
                if (strlen(recordList[i].department) > 0) {
                    printf("%-2d\t | %-14s\t | %-13c | %-13s | %-14s\t | %-8s\t\n",
                           i + 1, recordList[i].surname, recordList[i].sex,
                           recordList[i].year, recordList[i].studentNumber,
                           recordList[i].department);
                }
                break;

            default:
                printf("Invalid filter option.\n");
        }
    }
}

void findStudentByNum(int num, Record *recordList, char *snum) {
    printf("\n=============================================================\n");
    printf("Displaying Student Record(s) for Student Number: %s\n", snum);
    printf("=============================================================\n\n");
    printf("No\t | Surname\t | Sex\t | Year\t | Student Number\t | Department\n");

    for (int i = 0; i < num; i++) {
        // Check if the last five digits of the student number match
        if (strcmp(snum, recordList[i].studentNumber + strlen(recordList[i].studentNumber) - 5) == 0) {
            printf("%-2d\t | %-14s\t | %-13c | %-13s | %-14s\t | %-8s\t\n",
                   i + 1, recordList[i].surname, recordList[i].sex,
                   recordList[i].year, recordList[i].studentNumber,
                   recordList[i].department);
        }
    }
}