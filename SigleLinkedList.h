#ifndef SigleLinkedList_H_
#define SigleLinkedList_H_
#include <stdbool.h>
typedef unsigned int uint8_t;

typedef struct n
{
	uint8_t student_id;
	uint8_t student_year;
	uint8_t course_id[3];
	uint8_t course_grade[3];
	struct n* link;
}Node;

Node* CreateList         (Node* start);
Node* InsertInBeginning  (Node* start, uint8_t id,uint8_t year, uint8_t* courseid[], uint8_t* coursegrade[]);
void   InsertAtEnd       (Node* start, uint8_t id,uint8_t year, uint8_t* courseid[], uint8_t* coursegrade[]);
Node* DeleteNode         (Node * start);
bool  SDB_isFull(Node* start);
uint8_t GetUsedSize(Node* start);
bool SDB_ReadEntry(Node* start);
void SDB_GetIDList(Node* start);
bool SDB_Exsit(Node* start);
#endif
