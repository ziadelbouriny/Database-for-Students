#include <stdio.h>
#include <stdlib.h>

#include "SigleLinkedList.h"

Node* CreateList(Node* start)
{
	bool t = SDB_isFull(start);
	if(t == 1)
    {
        printf("\nData Base is full\n");
        return start;
    }
    else
    {
        int numberOfNodes;
        uint8_t id, year;
        uint8_t courseid[3];
        uint8_t coursegrade[3];
        printf("\nEnter the number of nodes : ");
        scanf("%d",&numberOfNodes);
        int counter;
        int size = GetUsedSize(start);

        if(0 == numberOfNodes)
        {
            return start;
        }
        else if((numberOfNodes > 11) || (numberOfNodes > (10 - size)))
        {
            while((numberOfNodes > 11) || (numberOfNodes > (10 - size)))
            {
                printf("\nEnter the number of again (maximum 10 students) : ");
                scanf("%i",&numberOfNodes);
            }
        }

         printf("\nEnter the no.1 student's id : ");
        scanf("%i",&id);

        printf("\nEnter the no,1 student's year : ");
        scanf("%i",&year);

       for(int j = 0; j < 3; j++)
       {
            printf("\nEnter the id of the course no.%i : ",j+1);
            scanf("%i",&(courseid[j]));
            printf("\nEnter the grade of the course no.%i: ",j+1);
            scanf("%i",&(coursegrade[j]));
       }

        start = InsertInBeginning(start,id,year,courseid,coursegrade);

        for(counter = 1; counter < numberOfNodes ; counter++)
        {
            printf("\nEnter the no.%i student's id : ",counter+1);
            scanf("%i",&id);

            printf("\nEnter the no.%i student's year : ",counter+1);
            scanf("%i",&year);

                for(int j = 0; j < 3; j++)
                {
                    printf("\nEnter the id of the course no.%i : ",j+1);
                    scanf("%i",&(courseid[j]));

                    printf("\nEnter the grade of the course : ",j+1);
                    scanf("%i",&(coursegrade[j]));
                }
            InsertAtEnd(start,id,year,courseid,coursegrade);
        }
        printf("\nAdded Correctly\n");
        return start;
    }
}


Node* InsertInBeginning(Node* start, uint8_t id,uint8_t year, uint8_t* courseid[], uint8_t* coursegrade[])
{
	Node* temp =(Node*) malloc(sizeof(Node));

	if(temp != NULL)
	{
		temp -> student_id = id;
		temp -> student_year = year;
		for(int j = 0; j < 3; j++)
        {
            temp -> course_id[j] = *(courseid + j);

            temp -> course_grade[j] = *(coursegrade + j);
        }
		temp -> link = start;
		start = temp;
	}
	return start;
}

void InsertAtEnd(Node* start, uint8_t id,uint8_t year, uint8_t* courseid[], uint8_t* coursegrade[])
{
	Node* temp =(Node*) malloc(sizeof(Node));
	if(temp != NULL)
	{
		Node* ptr = start;

		while(ptr->link != NULL)
		{
			ptr = ptr->link;
		}

		temp -> student_id = id;
		temp -> student_year = year;
		for(int j = 0; j < 3; j++)
        {
            temp -> course_id[j] = *(courseid+j);

            temp -> course_grade[j] = *(coursegrade+j);
        }
		ptr->link   = temp;
		temp->link  = NULL;
	}
}

Node* DeleteNode(Node * start)
{

    uint8_t id;
    printf("\nEnter the id you want to delete : ");
    scanf("%i",&id);
    Node* temp;

	if(start == NULL)/* List is empty */
	{
		printf("\nList is empty \n");
		return NULL;
	}

	/* Delete the first Node at the List */
	if((start->student_id) == id)
	{
		if(GetUsedSize(start) == 1)
        {
            free(start);
            return NULL;
        }
        else
        {
            Node* sec;
            sec = start -> link;
            free(start);
            return sec;
        }
	}

	/* Delete in between the Nodes or at the end */
	Node * ptr = start;
	while(ptr->link != NULL)
	{
		if(ptr->link->student_id == id)
		{
			temp = ptr->link;
			break;
		}
		ptr = ptr->link;
	}

	if(ptr->link == NULL)
	{
		printf("\nElement of the value %d is not in the List\n",id);
	}
	else
	{
		ptr->link = temp -> link;
		free(temp);
	}
	return start;
}

bool  SDB_isFull(Node* start)
{
    int temp = 0;
    if(start == NULL)
    {
        return false;
    }
    else
    {
        Node* ptr = start;
        while(ptr!=NULL)
        {
            temp++;
            ptr = ptr->link;
        }
        if(temp == 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

uint8_t GetUsedSize(Node* start)
{
     int size = 1;
     if(start == NULL)
     {
         return 0;
     }

     Node* temp = start;
     while(temp -> link != NULL)
     {
         size++;
         temp = temp -> link;
     }
     return size;
}

bool SDB_ReadEntry(Node* start)
{
    uint8_t id;
    printf("\nEnter the id you want to search : ");
    scanf("%i",&id);

    Node* temp = start;
     while(temp != NULL)
     {
         if(id == (temp -> student_id))
         {
             printf("\nThe student year = %i\n",(temp -> student_year));
             for(int j = 0; j < 3; j++)
             {
                printf("\nThe course id = %i\n",(temp->course_id[j]));
                printf("\nThe course grade = %i\n",(temp->course_grade[j]));
             }
             return true;
         }
         else
         {
            temp = temp -> link;
         }
     }
     return false;
}

void SDB_GetIDList(Node* start)
{
    int size = 0;

    Node* temp = start;
     while(temp != NULL)
     {
         size++;
         printf("%i",(temp -> student_year));
         temp = temp -> link;
     }
     printf("\nThe number of students now = %i\n",size);
}

bool SDB_Exsit(Node* start)
{
    uint8_t id;
    printf("\nEnter the id you want to search : ");
    scanf("%i",&id);
    Node* temp = start;
    while(temp != NULL)
    {
         if(id == (temp -> student_id))
         {
             return true;
         }
         else
         {
            temp = temp -> link;
         }
    }
    return false;
}
