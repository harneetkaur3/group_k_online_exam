#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>

#ifdef WINDOWS
    #include "..\include\validation.h"
	#include "..\include\user_maintainance.h"
#else
    #include "../include/validation.h"
	#include "../include/user_maintainance.h"
#endif

int professor(char *u_id){
	int chh;
	do{
		printf("\n                Press 1 Edit personal profile\n");
		printf("                Press 2 Add new Topic\n");
		printf("                Press 3 Add a Question\n");
		printf("                Press 4 Update a question\n");
		printf("                Press 5 Approve student request\n");
		printf("                Press 6 change password ...........\n");
		printf("                Press 7 to Log Out!!\n");

		scanf("%d",&chh);
		switch(chh){
			case 1:{
				char dcsn[6];
				editProfile(u_id);
				break;
			}
			case 2:{
				
				
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				
				break;
			}
			case 5:{
				
				break;
			}
			case 6:{
				char pwd[15];
				char id1[11];
			    char new_pwd[15];
			    printf("\nEnter your old password:");
			 	scanf("%s",pwd);
				//getchar();
			    printf("\nEnter your new password:");
			 	scanf("%s",new_pwd);
			    stpcpy(pwd,rtrim(pwd));
			    stpcpy(new_pwd,rtrim(new_pwd));

				char user_status[60];
				strcpy(user_status,changePassword(u_id,pwd,new_pwd));
    			puts(user_status);
				break;
			}
			case 7:{
				printf("\n Thank you! Have Good Day....");
				return 1;
			}
			default:{
				printf("wrong input");
				break;
			}
		}
	}while(chh!=7);
}
