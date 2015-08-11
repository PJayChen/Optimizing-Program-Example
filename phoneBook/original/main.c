#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA 50000

#define MAX_LAST_NAME_SIZE 16
typedef struct __PHONE_BOOK_ENTRY {
    char LastName[MAX_LAST_NAME_SIZE];
    char FirstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
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

	pb[i] = (PhoneBook*) malloc(sizeof(PhoneBook));
	strncpy(pb[i]->LastName, "aaa", sizeof("aaa"));
	// strncpy(pb[i]->LastName, "pjay", sizeof("pjay"));
    while (i++ < DATA) {
    	pb[i] = (PhoneBook*) malloc(sizeof(PhoneBook));
    	strncpy(pb[i]->LastName, "aaa", sizeof("aaa"));
    	pb[i-1]->pNext = pb[i];
    } 
    strncpy(pb[DATA - 1]->LastName, "pjay", sizeof("pjay"));
    
    printf("%ld Byte * %d = %ld KByte\n", sizeof(PhoneBook), DATA, (sizeof(PhoneBook) * DATA)/1024);

    start_time = clock();
    PhoneBook *getPb = FindName("pjay", pb[0]);
    end_time = clock();

    printf("%f microsec\n", (float)(end_time - start_time));

    if (getPb != NULL) {
    	printf("%s\n", getPb->LastName);
    }

    return 0;
}
