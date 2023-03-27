#include <stdio.h>
#include <stdlib.h>

#include "SigleLinkedList.h"

int main()
{
	Node* student = NULL;
	while (1)
    {
        int choice;
		printf("\nWhat would you like to do:\n\n1-Insert Student\n\n2-Knowing Full or Not\n\n3-Get The Used Size\n\n4-Delete Student\n\n5-Read Entry\n\n6-Get id List\n\n7-Does id exist??\n\n8-Exit\n\n");
		scanf("%i",&choice);
		switch(choice)
		{
		case 1:
			 {
			     student = CreateList(student);
                 break;
			 }
        case 2:
            {
                 bool x = SDB_isFull(student);
                 if(x == 0)
                 {
                     printf("No, it is not full");
                 }
                 else
                 {
                     printf("\nYes, it is full");
                 }
                 break;
            }
        case 3:
            {
                 int size = GetUsedSize(student);
                 printf("\nThe size of the data base now = %i\n",size);
                 break;
            }
		case 4:
		    {
                 student = DeleteNode(student);
                 break;
		    }
        case 5:
            {
                bool r = SDB_ReadEntry(student);
                if(r == 1)
                {
                    printf("\nYes, it is found\n");
                }
                else
                {
                    printf("\nNo, not found\n");
                }
                break;
            }
        case 6:
            {
                SDB_GetIDList(student);
                break;
            }
        case 7:
            {
                bool s = SDB_Exsit(student);
                if(s == 1)
                {
                    printf("\nYes, it is found\n");
                }
                else
                {
                    printf("\nNo, not found\n");
                }
                break;
            }
        case 8:
            {
                return 0;
            }
		}
    }
    return 0;
}
