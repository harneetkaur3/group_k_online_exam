/*
 * Student_Account_Setup.c
 *
 *  Created on: Jun 17, 2020
 *      Author: Sanjana Dharan
 *
 *
 * @param [in]: char *student_identification; NULL or valid student_identification provided by the user to access the account.
The function Create Student Account creates a student profile by saving student attributes on a file in the local file system.
The function accepts a parameter “student_identification” as an argument.
If student identification parameter is NULL, the function asks for the user to enter the student ID and other attributes (contact, email, username, password)
and save this information on the local file system with the student ID as the file name.

If the student identification parameter is provided, that means a filename with a Student ID is already created on the local file system and the function switches to asking the user to enter what attributes he or she wishes to modify
 *
 *
 *
 *
 */





# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

#ifdef WINDOWS
    #include "..\include\user_maintainance.h"
	#include "..\include\validation.h"
	 #include "..\include\student.h"
#else
    #include "../include/user_maintainance.h"
	#include "../include/validation.h"
	#include "../include/student.h"
#endif



void student_account(char *student_identification)
{
	FILE *fp;

	/* Set up a data structure to maintain the student account information */

	struct profile
	{
	  char id[13];
	  char f_name[50];
	  char l_name[50];
	  char age[5];
	  char username[45];
	  char password[45];
	  char phonenumber[20];
	  char gender[10];
	  char email[100];
      char dept[100];
	  char uni[100];
	        //char status[10];
	    };
		struct profile pp;
		int i=0;
	    int x=0;


	int count;
	system("clear");
	fp=fopen("user_profile.csv","a"); // open the user profile in an excel spread sheet.

	if(fp==NULL){
         printf ("Error-> The file cannot be opened\n");
	}
	else
	{
		if (student_identification==NULL)   /* This code snippet creates a new student account and stores the details in an excel file */
		{
		  system("clear");
		  printf("\n ** New Account Creation Page **\n\n");
		  printf("\n Enter Student Identification Number\n");
		  scanf("%s",pp.id);
		  printf("\n Enter First Name of Student\n");
		  scanf("%s",pp.f_name);
		  printf("\n Enter Last Name of Student\n");
		  scanf("%s",pp.l_name);
		  printf("\n Enter contact\n");
		  scanf("%s",pp.phonenumber);
		  printf("\n Email\n");
		  scanf("%s",pp.email);
		  printf("\n Enter username\n");
		  scanf("%s",pp.username);
		  printf("\n Enter password\n");
		  scanf("%s",pp.password);
		  // Harneet is adding the Column Title, header of the table.
		  fprintf(fp,"%s,%s,%s,%s,%s,%s\n",pp.id,pp.f_name,pp.l_name,pp.phonenumber,pp.email,pp.username,pp.password);
		  fclose(fp);
	}
    else   /* This code updates the student account profile */
	{
    	system("clear");
    	printf("\n ** Account Editing Page **\n\n");
    	printf("                Press 1 to Change First Name\n");
        printf("                Press 2 to Change Last Name\n");
        printf("                Press 3 to Change Contact\n");
        printf("                Press 4 to Change Email\n");
        printf("                Press 5 to Change Username\n");
        printf("                Press 6 to Change Password\n");
    	printf("                Press 7 Exit\n");
        scanf("%d",&i);

        switch(i){
                case 1:{
        			do{
        				printf("Enter the new first name: \n");
        				gets(pp.f_name);
        				x=notempty(pp.f_name);
        			}while(x==0);
        			getrow(student_identification,"Firstname", pp.f_name);
        			x=0;
        			break;
        		}
        		case 2:{
        			do{
        				printf("Enter the new last name: \n");
        				gets(pp.l_name);
        				x=notempty(pp.l_name);
        			}while(x==0);
        			getrow(student_identification,"Lastname", pp.l_name);
        			x=0;
        			break;
        		}
        		case 3:{
        			printf("Enter the new Contact: \n");
        			scanf("%s",pp.phonenumber);
        			//getchar();

        			getrow(student_identification,"phonenumber", pp.phonenumber);
        			break;
        		}
        		case 4:{
        			int x=0;
                    getchar();
                    do{
                        printf("Enter the new Email\n");
                        gets(pp.email);
                        x=notempty(pp.email);
                    }while(x==0);
        			getrow(student_identification,"email", pp.email);
        			break;
        		}
        		case 5:{
        			int x=0;
                    getchar();
                    do{
                        printf("Enter the new user name\n");
                        gets(pp.username);
                        x=notempty(pp.username);
                    }while(x==0);
        			getrow(student_identification,"add2", pp.username);
        			break;
        		}
        		case 6:{
        			int x=0;
                    do{
                        printf("Enter the new Password: \n");
                        scanf("%s",pp.password);
                        getchar();
                        x=valid_phone(pp.password);
                    }while(x==0);
        			getrow(student_identification,"pno", pp.password);
        			break;
        		}
        		case 7:{
        			//do nothing.
        		}

        	}

	}


}



void student()
{
	int ch;
	char student_id[100];
	system("clear");
	printf("\n ** Student Access Page **\n\n");
	printf("1.Create New Account\n2. Modify Account\n3. Login to your Account\n\nEnter your choice (1-3) : ");
	scanf("%d",&ch);

	switch(ch){
     case 1:
     student_account(NULL);
     break;

	 case 2:
	printf("\n Enter Student Identification Number\n");
	scanf("%s",student_id);
     student_account(student_id);
     break;

	 case 3:
     break;

   }

}




void display_welcome_screen()

{

	int ch;

	while(ch!=3)

	{

		printf("\n ** Welcome to Online Examination System **\n\n");

		printf("1.Professor Access\n2. Student Access\n3. Exit\n\nEnter your choice (1-3) : ");

		scanf("%d",&ch);

		switch(ch){

		 case 1:

			//admin();  Harneet to implement

			break;

		 case 2:

			student();

			break;

		 case 3:

		   break;

	 }

	}

}
