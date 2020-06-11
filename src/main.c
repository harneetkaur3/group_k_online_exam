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
char *rtrim(char *s){
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}


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
