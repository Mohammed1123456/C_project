#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"DATA.h"

int main()
{
    int USER_CHOICE = 0;
   while (1)
   {
    printf("*****CHOOSE SURVACE YOU WANT*****\n");
    printf(" 1.ASK IS THE LIST IS FULL\n 2.GET SIZE OF LIST\n 3.ADD NEW STUDENT\n 4.DELETE STUDENT \n 5.PRINET STUDENT DATA\n 6.PRINT LIST OF IDs\n 7.IS ID EXIST \n 0.CLOOSE THE PROGRAM \n");
    scanf("%d",&USER_CHOICE);

    if(USER_CHOICE==0)
    {
        break;
    }
    else
    {
        switch (USER_CHOICE)
        {
        case 1:
            SDB_FULL();
            break;

        case 2:
            SDB_GET_SIZE();
            break;

        case 3:
            SDB_ADD_ENTRY();
            break;

        case 4:
            SDB_DELETE_ENTRY();
            break;

        case 5:
            SDB_READ_ENTRY();
            break;

        case 6:
            SDB_GET_LIST();
            break;
        
        case 7:
            SDB_ISID_ESIST();
            break;

        default:
            printf("ENTER VALID OPTION\n");
            break;
        }
    }

   }
    return 0;
}
