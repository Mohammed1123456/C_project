#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"DATA.h"

static STUDENT* HEAD = NULL;
int counter = 0 ;

//FUNCTION TO CHECK IS THE LIST IS FULL OR NOT
void SDB_FULL(void)
{
    if(HEAD!=NULL)
    {
        if(counter==10)
        {
            printf("LIST IS FULL\n");

        }
        else
        {
            printf("LIST CAN TAKE %d MORE STUDENTS\n",(10-counter));
        }
    }
    else
    {
        printf("THERE IS NO LIST\n");
    }
}


//FUNCTION TO GET NUMBER OF STUDENTS IN LIST
void SDB_GET_SIZE(void)
{
    if(HEAD!=NULL)
    {
        printf("size of list is %d\n",counter);
    }
    else
    {
         printf("THERE IS NO LIST \n");
    }
}


//FUNCTION TO ADD STUDENT DATA
void SDB_ADD_ENTRY(void)
{
    if(HEAD==NULL)
    {
        HEAD =(STUDENT*)malloc(sizeof(STUDENT));
        printf("ENTER DATA OF STUDENT:\n");
        printf("ENTER NAME\n");
        scanf("%s",&HEAD->name);
        fflush(stdin);
        printf("ENTER ID\n");
        scanf("%d",&HEAD->ID);
        fflush(stdin);
        printf("ENTER YEAR\n");
        scanf("%d",&HEAD->YEAR);
        fflush(stdin);
        printf("ENTER COURSE NAME\n");
        scanf("%s",&HEAD->COURSE_NAME);
        fflush(stdin);
        printf("ENTER COURSE GRADE\n");
        scanf("%d",&HEAD->GRADE);
        fflush(stdin);

        HEAD->NEXT_STUDENT = NULL;
        counter++;
        printf("HEAD CREATED AND STUDENT DATA SAVED\n");

    }
    else if(HEAD!=NULL)
    {
        STUDENT* NEW_STUDENT =NULL;
        STUDENT* TEMP =HEAD;
            while(TEMP->NEXT_STUDENT!=NULL)
            {
                TEMP = TEMP->NEXT_STUDENT;
            }

            NEW_STUDENT =(STUDENT*)malloc(sizeof(STUDENT));
            printf("ENTER DATA OF STUDENT:\n");
            printf("ENTER NAME\n");
            scanf("%s",&NEW_STUDENT->name);
            fflush(stdin);
            printf("ENTER ID\n");
            scanf("%d",&NEW_STUDENT->ID);
            fflush(stdin);
            printf("ENTER YEAR\n");
            scanf("%d",&NEW_STUDENT->YEAR);
            fflush(stdin);
            printf("ENTER COURSE NAME\n");
            scanf("%s",&NEW_STUDENT->COURSE_NAME);
            fflush(stdin);
            printf("ENTER COURSE GRADE\n");
            scanf("%d",&NEW_STUDENT->GRADE);
            fflush(stdin);
            counter++;
            
            TEMP->NEXT_STUDENT = NEW_STUDENT;
            TEMP->NEXT_STUDENT->NEXT_STUDENT = NULL;
            printf("STUDENT DATA SAVED\n");

        
    }
    else
    {
       printf("DATA NOT SAVED\n");
    }
}


//FUNCTION TO DELETE STUDENT USING ID
void SDB_DELETE_ENTRY(void)
{
    int ID = 0;
    printf("ENTER STUDENT ID;\n");
    scanf("%d",&ID);
    STUDENT* TEMP = HEAD;
    STUDENT* DELETE_STUDENT = NULL;
    if(HEAD==NULL)
    {
        printf("NO LIST EXIST\n");
    }
    else if(HEAD!=NULL)
    {
        if((TEMP->ID==ID) && (TEMP->NEXT_STUDENT==NULL))
        {
            free(HEAD);
            counter--;
            printf("HEAD DELETED AND NOW THERE IS NO LIST");
        }
        else if((TEMP->ID==ID) && (TEMP->NEXT_STUDENT!=NULL))
        {
            DELETE_STUDENT = TEMP;
            HEAD = TEMP->NEXT_STUDENT;
            free(DELETE_STUDENT);
            counter--;
        }
        else
        {
            DELETE_STUDENT = HEAD->NEXT_STUDENT;
            while (DELETE_STUDENT!=NULL)
            {
                if(DELETE_STUDENT->ID==ID)
                {
                    break;
                }
                else
                {
                    DELETE_STUDENT = DELETE_STUDENT->NEXT_STUDENT;
                    TEMP = TEMP->NEXT_STUDENT;
                }
            }
            TEMP->NEXT_STUDENT = TEMP->NEXT_STUDENT->NEXT_STUDENT;
            free(DELETE_STUDENT);
            counter--;
            printf("STUDENT DELETED\n");
        }
    }
    else
    {
       printf("ID NOT FOUND IN A LIST\n");
    }
}



//FUNCTION TO SEARCH FOR STUDENT DATA AND SHOW IT USING ID
void SDB_READ_ENTRY(void)
{
    int ID = 0;
    printf("ENTER STUDENT ID:\n");
    scanf("%d",&ID);
    STUDENT* TEMP = HEAD;
    int check = 0 ;
    if(HEAD==NULL)
    {
        printf("NO LIST EXIST\n");
    }
    else
    {
        while ((TEMP!=NULL))
        {
            if(TEMP->ID==ID)
            {
                check = 1;
                break;
            }
            TEMP = TEMP->NEXT_STUDENT;
        }
        if(check == 0)
        {
            printf("STUDENT NOT FOUND IN THE LIST\n");
        }
        else 
        {
            printf("STUDENT EXIST \n");
            printf("STUDENT DATA:\n");
            printf("STUDENT NAME:%s\n",TEMP->name);
            printf("STUDENT ID:%d\n",TEMP->ID);
            printf("STUDENT YEAR:%d\n",TEMP->YEAR);
            printf("STUDENT COURSE:%s\n",TEMP->COURSE_NAME);
            printf("STUDENT NAME:%d\n",TEMP->GRADE);
        }
    }
}



// FUNCTION TO PRINT LIST OF STUDENT ID
void SDB_GET_LIST(void)
{
    
    STUDENT* TEMP = HEAD;
    if(HEAD==NULL)
    {
        printf("NO LIST EXIST\n");
    }
    else
    {
        printf("STUDENTS ID:\n");
        while(TEMP!=NULL)
        {
            printf("ID : %d \n",TEMP->ID);
            TEMP = TEMP->NEXT_STUDENT;
        }
    }
}


//FUNCTION TO SEE IF ID EXIST OR NOT
void SDB_ISID_ESIST(void)
{
    int ID = 0;
    int check = 0;
    printf("ENTER STUDENT ID:\n");
    scanf("%d",&ID);
    STUDENT* TEMP = HEAD;
    if(HEAD==NULL)
    {
        printf("NO LIST EXIST\n");
    }
    else
    {
        while(TEMP!=NULL)
        {
            if(TEMP->ID==ID)
            {
                check = 1; 
                break;
            }
            TEMP = TEMP->NEXT_STUDENT;
        }
        if (check==1)
        {
            printf("ID EXIST\n");
        }
        else
        {
             printf("ID NOT EXIST\n");
        }
    }

}



