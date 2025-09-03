#include<stdio.h>
#include<stdlib.h>
#include "STD.h"
#include "SDB.h"

static student *data = NULL; 
static uint8 stu_counter = 0;

// checks if the database is full
// It compares the number of students (stu_counter) with max no. of the database (MAX_STUDENTS) 
// If stu_counter reached the maximum limit, it returns True
// Otherwise, it returns False
BOOL SDB_IsFull (){
    if (stu_counter >= MAX_STUDENTS){
        printf(" Database isn't full \n");
     return True;
    }
    return False;
}

// return no. of student in the database until now
uint8 SDB_GetUsedSize(){       
    return stu_counter;
}

// adds a new student to the database
// First, checks if the database is not full by SDB_IsFull()
// In Case Not Full, takes input from the user for student details
// student info = include ID, year,three courses with their grades
// The new student is stored in the data array at index stu_counter
// After saving, stu_counter is increased by one to count the new student
// At the end it returns True --> data was saved, or False --> database was full
BOOL SDB_AddEntry() {
    if (!SDB_IsFull()) {
        student stu_info;
        printf(" Student Information Form \n");
        printf("_____________________________________________ \n");

        printf(" Enter Student ID: \t ");
        scanf("%u", &stu_info.Student_ID);

        printf(" Enter Student Year: \t ");
        scanf("%u", &stu_info.Student_year);

        printf(" Enter Course 1 ID: \t ");
        scanf("%u", &stu_info.Course1_ID);

        printf(" Enter Course 1 Grade: \t ");
        scanf("%u", &stu_info.Course1_grade);

        printf(" Enter Course 2 ID: \t ");
        scanf("%u", &stu_info.Course2_ID);

        printf(" Enter Course 2 Grade: \t ");
        scanf("%u", &stu_info.Course2_grade);

        printf(" Enter Course 3 ID: \t ");
        scanf("%u", &stu_info.Course3_ID);

        printf(" Enter Course 3 Grade: \t ");
        scanf("%u", &stu_info.Course3_grade);

        printf("_____________________________________________\n");

        data = (student*) realloc(data, (stu_counter + 1) * sizeof(student));
        if (data == NULL) {
            printf("Memory allocation failed!\n");
            return False;
        }

        data[stu_counter] = stu_info;
        stu_counter++;
        return True;
    }else
    return False;
}

// deletes a student from the database by using- ID
// process : loops through all students to find the matching Student_ID
// If found, replaces that student with the last student in the array
// Then decreases stu_counter to update number of students in the data arry  
// If the database becomes empty, it frees the memory and sets pointer to NULL
// Otherwise, it reallocates memory to fit the new smaller size
// Finally, it prints confirmation if deleted, or "Not Found" if no match
void SDB_DeletEntry (uint32 id){

    for (uint8 i=0; i<stu_counter ; i++) {
        if (data[i].Student_ID == id) {
            data[i] = data[stu_counter - 1];
            stu_counter--;

            if (stu_counter == 0) {
                free(data);
                data = NULL;
            } else {
                data = (student*) realloc(data, stu_counter * sizeof(student));
            }
            printf(" student info. has been successfully deleted  %d\n", id);
            return;        
        }
    }
    printf("Student Not Found \n");

}

// function displays a student’s details by ID
// It searches through all students stored in the database
// If it finds a match, it prints the student’s details
// After printing, it returns True --> confirm the student exists
// If no student with the given ID is not found, it returns False
BOOL SDB_ReadEntry (uint32 id){
        for (uint8 i = 0; i < stu_counter; i++) {
        if (data[i].Student_ID == id) {
            printf("\n Student Information Card \n");
                printf("_____________________________________________\n");
            printf("ID: %d, Year: %d\n", data[i].Student_ID, data[i].Student_year);
            printf("Course1: %d ---> Grade: %d \n", data[i].Course1_ID, data[i].Course1_grade);
            printf("Course2: %d ---> Grade: %d \n", data[i].Course2_ID, data[i].Course2_grade);
            printf("Course3: %d ---> Grade: %d \n", data[i].Course3_ID, data[i].Course3_grade);
                printf("_____________________________________________\n");
            return True;
        }
    }
    return False;

} 

// creates a list of all student IDs in the database
// first sets count to the number of students (stu_counter)
// Then it loops through all students and copies their IDs into the list array
// This allows the user to know how many students exist and their IDs
void SDB_GetList (uint8 * count, uint32 * list) {

    *count = stu_counter;
    for (uint8 i=0; i<stu_counter; i++)
     {
        list[i] = data[i].Student_ID;
     }
}

// This function checks if a student (specific ID) exists in the database
// It goes through each student + compares stored Student_ID with the given id
// If ID matches, it returns True
// If no match is found (loop ends) match, it returns False
BOOL SDB_IsIdExist (uint32 id){
    
    for (uint8 i=0; i<stu_counter; i++) {
        if (data[i].Student_ID == id) 
        return True;
    }
        return False;

}
