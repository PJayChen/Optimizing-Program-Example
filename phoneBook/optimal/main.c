#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA 50000

#define MAX_LAST_NAME_SIZE 16
typedef struct __PHONE_BOOK_DATA {
    char FirstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} PhoneBook_data;

typedef struct __PHONE_BOOK_ENTRY {
    char LastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_DATA *data;
    struct __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;

PhoneBook *FindName(char Last[], PhoneBook *pHead) {
    while (pHead != NULL) {
        if (strcmp(Last, pHead->LastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}


int main(void)
{
	PhoneBook *pb[DATA];
    int i = 0;

    clock_t start_time, end_time;


    //----- allocate memory for phonebook entry
	pb[i] = (PhoneBook*) malloc(sizeof(PhoneBook));
	// strncpy(pb[i]->LastName, "NULL", sizeof("NULL"));
    *(pb[i]->LastName) = '\0';
    while (i++ < DATA) {
    	pb[i] = (PhoneBook*) malloc(sizeof(PhoneBook));
    	// strncpy(pb[i]->LastName, "NULL", sizeof("NULL"));
        *(pb[i]->LastName) = '\0';
    	pb[i-1]->pNext = pb[i];
    } 

    //----- allocate memory for data
    i = 0;
    pb[i]->data = (PhoneBook_data*) malloc(sizeof(PhoneBook_data));
    while (i++ < DATA) {
        pb[i]->data = (PhoneBook_data*) malloc(sizeof(PhoneBook_data));
    } 
    
    //----- write a data at last element of phonebook
    strncpy(pb[DATA - 1]->LastName, "Chen", sizeof("Chen"));
    strncpy(pb[DATA - 1]->data->FirstName, "pjay", sizeof("pjay"));

    printf("(%ld Byte * %d) + (%ld Byte * %d) = %ld KByte\n", sizeof(PhoneBook), DATA, sizeof(PhoneBook_data), DATA, ((sizeof(PhoneBook) * DATA) + (sizeof(PhoneBook_data) * DATA))/1024);

    start_time = clock();
    PhoneBook *getPb = FindName("Chen", pb[0]);
    end_time = clock();

    printf("%f microSec\n", (float)(end_time - start_time));

    if (getPb != NULL) {
    	printf("Contact \"%s %s\" is found.\n", getPb->LastName, getPb->data->FirstName);
    }

    return 0;
}
