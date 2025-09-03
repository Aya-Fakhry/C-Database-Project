#ifndef SDB_H
#define SDB_H
#include<stdio.h>
#include "STD.h"

#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

 typedef enum boolean {
       False, True
}BOOL;

typedef struct SimpleDb 
{ 
uint32 Student_ID; 
uint32 Student_year; 
uint32 Course1_ID; 
uint32 Course1_grade; 
uint32 Course2_ID; 
uint32 Course2_grade; 
uint32 Course3_ID; 
uint32 Course3_grade; 
} student; 

BOOL SDB_IsFull();
uint8 SDB_GetUsedSize();
BOOL SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
BOOL SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
BOOL SDB_IsIdExist(uint32 id);
#endif

