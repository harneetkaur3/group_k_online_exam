/**
* \file main.c
*
* Contains the main function from which different functions
* located in other files are called to perform different
* tasks assigned for student and Professor based on the
* user inputs.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<string.h>
#include<ctype.h>

#define range 5
#define id_range 10

#ifdef WINDOWS
    #include "..\include\user_maintainance.h"
#else
    #include "../include/user_maintainance.h"
#endif

#ifdef WINDOWS
    #include "..\include\student.h"
#else
    #include "../include/student.h"
#endif


/**
* \brief Removes the extra spacing
*
* It will delete or trim the extra space in the array of characters by calling this function
*
* @param[in] char *s Array of Character Pointer, pointing to the character of size char
*
* \return User_Type: Pointer to the array of character
*
*/
char *rtrim(char *s){
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

/**
* \brief Get or scan the value from the console screen
*
* Function can be called for any type of user-> Admin, Manager, Employee who want to scan the values from console screeen
*
* @param [void] No Arguments will be passed
*
* \return User_Type: Integer value 'ch' for all case
*
*/

int getch(void){
    struct termios oldt,newt;
    int   ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}


/**
* \brief The main function which distributes various tasks to other functions.
*
* Expects a user type from the login function
* Based on the functionalities provided for the user type
* and corresponding user inputs calls the other functions.
*
*/


int main(int argc, char *argv[]){
	int i,id;
    char ch[range];
    char pwd[25];
	char id1[11];
    char u_type[25];
	system("clear");
	printf("\n*********************************************************************\n");
    printf("                               Welcome to online Examination                                   \n");
    printf("\n*********************************************************************\n");

    printf("                Press 1 LOGIN\n");
    printf("                Press 2 EXIT\n");
	fgets(ch,range,stdin);
	switch(atoi(ch)){
		case 1:
			printf("\nEnter your employee id:");
			fgets(id1,id_range,stdin);
			//id=atoi(id1);
			printf("\nEnter your Password:");
			int p=0;
			do{
                pwd[p]=getch();
                if((pwd[p]=='\b' ||pwd[p]==127)&& p>0){
                    p--;
                    printf("\b \b");
                    continue;
                }
                if(pwd[p]!='\r'){
                    printf("*");
                }
                if(pwd[p]=='\n'||pwd[p]==13){
                    p++;
                    break;
                }
                p++;
            }while(pwd[p-1]!='\r'||pwd[p-1]!=13);
            pwd[p-1]='\0';
			stpcpy(id1,rtrim(id1));
			strcpy(u_type,login(id1,pwd));
			if(strcmp(u_type,"Admin")==0){
				//code
			}
			else if(strcmp(u_type,"Student")==0){
				student(id1);
				
		
			}
			else if(strcmp(u_type,"Professor")==0){
				//code
			}
			else{
				
			}
			printf("%s\n",u_type);
			break;
		case 2:
			printf("Thank you Exit\n");
			break;
		default:
			 printf("Have a Good Day!");
	}
}
