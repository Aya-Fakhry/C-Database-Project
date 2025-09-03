#include<stdio.h>
#include<stdlib.h>
#include "STD.h"
#include "SDB.h"

// functioon = the main application menu shows user all the Available options in the database
// The loop keeps running until the user enters '0'
// We use a flag (running) to control when to stop loop
// If the user chooses no. uppove 0, ---> call SDB_action() functions
void SDB_APP () {
    uint8 choice;
    BOOL running = True; 
        while (running){
            printf("\nTo add entry, enter 1 \n ");
            printf(" To get used size in database, enter 2 \n");
            printf(" To read student data, enter 3 \n");
            printf(" To get the list of all student IDs, enter 4 \n");
            printf(" To check is ID is existed, enter 5  \n");
            printf(" To delete student data, enter 6 \n");
            printf(" To check is database is full, enter 7 \n");
            printf(" To exit enter 0 \n");
            scanf(" %c",&choice);

        if (choice == '0') {
            running = False;   
        } else {
            SDB_action(choice);
        }
    }
}

void SDB_action (uint8 choice){
    uint32 test_id, list[MAX_STUDENTS];
    uint8 count;

    switch (choice)
    {
    case '1':
        {
            if (SDB_IsFull())
                printf("***** The Databsae is full or you Entered A not correct data re_Enter the data Again ***** \n");
            else{

            if (SDB_AddEntry())
                printf(" Data saved \n");
            else
                printf(" Error while saving data \n");
            }

        }break;

    case '2':
        printf(" Number Of The Student :    %d \n", SDB_GetUsedSize());
        break;

    case '3':
        {
            printf("Plz, Enter The ID: ");
            scanf("%d", &test_id);
            if (!SDB_ReadEntry(test_id))
             printf("The Student Doesn't Exist \n");
        }break;

    case '4':
            SDB_GetList(&count, list);
            printf(" IDs:  ");
            for (uint8 i=0; i<count; i++) 
            printf("%d  , ", list[i]);
            printf("\n");
                break;

    case '5':
        {
            printf(" Enter the Student ID : \t ");
            scanf("%d",&test_id);
            if (SDB_IsIdExist(test_id)){
                printf(" The ID Exists \n");
            }else{
               printf(" The ID Doesn't Exists \n");
            }
        }break;

    case '6':
        {

            printf("Plz, Enter The ID: ");
            scanf("%u", &test_id);
            SDB_DeletEntry(test_id);
        }break;

    case '7':
        {
            if (SDB_IsFull())
            {
                printf(" The Storage is full \n");
            }
        }break;

    default:          
        printf(" Wrong Number____*****plz Enter Your Choice Again*****______  \n");

        break;
    }
}
