#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct NODE
{
    char name[50];
    int ID;
    int YEAR;
    char COURSE_NAME[50];
    int GRADE;
    struct NODE* NEXT_STUDENT;
}STUDENT;


void SDB_FULL(void);
void SDB_GET_SIZE(void);
void SDB_ADD_ENTRY(void);
void SDB_DELETE_ENTRY(void);
void SDB_READ_ENTRY(void);
void SDB_GET_LIST(void);
void SDB_ISID_ESIST(void);

#endif // DATA_H_INCLUDED
