

/**
* \file professor_creation.c
*
*	Authors:
*				@author Sanjana
* 				@author Esraa 
*
*
* Contains the following functions:
* create_prof_profile() create professor profile
* create_student_account() create student profile
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WINDOWS
    #include "..\include\validation.h"
	#include "..\include\profile_creation.h"
	#include "..\include\user_maintainance.h"
#else
    #include "../include/validation.h"
	#include "../include/profile_creation.h"
	#include "../include/user_maintainance.h"
#endif

#define number0 5
#define number1 10
#define number2 20
#define number3 50
#define number4 200

/**
 * \fn create_prof_profile()
 * This function creates a professor profile. It takes the required fields: id, first and last name, age, address, phone number, 
 * gender, email, university, and department, from the user and stores it in a csv file, "user_profiles.csv". If the file is not 
 * existing, it will create it, otherwise, it will add to the existing file.
 *
 *  
 *      Author: Esraa Abujayyab
 *
 *
 *
 * @return: returns no value
 */


void create_prof_profile()
{
	char id[number1];
	char f_name[number3];
	char l_name[number3];
	char age[number0];
	char address1[number3];
	char address2[number3];
	char phonenumber[number2];
	char gender[number1];
	char email[number4];
	char dept[number4];
	char uni[number4];
	int x=0;
    char ch;
    int num;
    getchar();
    int id1=generate_Id("user_Profile.csv");
	sprintf(id,"%d",id1);
    do{
        printf("Enter the first name of Professor\n");
        gets(f_name);
        x=notempty(f_name);
    }while(x==0);
    x=0;
    do{
        printf("Enter the Last name of Professor\n");
        gets(l_name);
        x=notempty(l_name);
    }while(x==0);
    x=0;
    printf("Enter the age of Professor\n");
    scanf("%s",age);
    getchar();
    do{
        printf("Enter house/apartment number and street\n");
        gets(address1);
        x=notempty(address1);
    }while(x==0);
    x=0;
    do{
        printf("\nEnter city and country\n");
        gets(address2);
        x=notempty(address2);
    }while(x==0);
    x=0;
    do{
        printf("Enter Phone number\n");
        scanf("%s",phonenumber);
        x=valid_phone(phonenumber);
    } while(x==0);
    x=0;
    do{
        printf("\nEnter gender Male , Female or Others\n");
        scanf("%s",gender);
        if (strcasecmp(gender,"Male")==0 || strcasecmp(gender,"Female")==0 || strcasecmp(gender,"Female")==0){
            x=1;
            break;
        }
    } while(x==0);
    x=0;
    do{
        printf("Enter email\n");
        scanf("%s",email);
        x=valid_email(email);
    }while(x==0);
    x=0;
    do{
        printf("Enter the department of Professor\n");
        gets(dept);
        x=notempty(dept);
    }while(x==0);
    x=0;

    do{
        printf("Enter the designation of Professor\n");
        gets(uni);
        x=notempty(uni);
    }while(x==0); 
	FILE * fPtr = fopen("user_profiles.csv","a"); 
   
	
    if(fPtr == NULL)
    {
    	printf("unable to create file. \n");
    	exit(EXIT_FAILURE);
    } 
	else{
		fprintf(fPtr,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s \n",id,f_name,l_name,age,address1,address2,phonenumber,gender,email,dept,uni,"Professor");
		printf("\nAccount created and saved successfully \n" );
	}
	fclose(fPtr);
}









/*
 * Student_Account_Setup.c
 *
 *  Created on: Jun 17, 2020
 *      Author: Sanjana Dharan
 *
 *
 * @param [in]: char *student_identification; NULL or valid student_identification provided by the user to access the account.
The function Create Student Account creates a student profile by saving student attributes on a file in the local file system.
The function accepts a parameter â€œstudent_identificationâ€ as an argument.
If student identification parameter is NULL, the function asks for the user to enter the student ID and other attributes (contact, email, username, password)
and save this information on the local file system with the student ID as the file name.

If the student identification parameter is provided, that means a filename with a Student ID is already created on the local file system and the function switches to asking the user to enter what attributes he or she wishes to modify
 *
 *
 *
 *
 */


void create_student_account(char *student_identification)
{
	/* Set up a data structure to maintain the student account information */
	struct profile
	{
		char id[13];
		char f_name[50];
		char l_name[50];
		char age[5];
		char address1[45];
		char address2[45];
		char phonenumber[20];
		char gender[10];
		char email[100];
		char dept[100];
		char uni[100];
		char username[45];
		char password[45];
	};
	struct profile pp;
	int x=0;
    char ch;
    int num;
    getchar();
	if(student_identification==NULL)
	{
		int id1=generate_Id("user_Profile.csv");
		sprintf(pp.id,"%d",id1);
		do{
			printf("Enter the first name of Student\n");
			gets(pp.f_name);
			x=notempty(pp.f_name);
		}while(x==0);
		x=0;
		do{
			printf("Enter the Last name of Student\n");
			gets(pp.l_name);
			x=notempty(pp.l_name);
		}while(x==0);
		x=0;
		printf("Enter the age of student\n");
		scanf("%s",pp.age);
		getchar();
		do{
			printf("Enter house/apartment number and street\n");
			gets(pp.address1);
			x=notempty(pp.address1);
		}while(x==0);
		x=0;
		do{
			printf("\nEnter city and country\n");
			gets(pp.address2);
			x=notempty(pp.address2);
		}while(x==0);
		x=0;
		do{
			printf("Enter Phone number\n");
			scanf("%s",pp.phonenumber);
			x=valid_phone(pp.phonenumber);
		} while(x==0);
		x=0;
		do{
			printf("\nEnter gender Male , Female or Others\n");
			scanf("%s",pp.gender);
			if (strcasecmp(pp.gender,"Male")==0 || strcasecmp(pp.gender,"Female")==0 || strcasecmp(pp.gender,"Female")==0){
				x=1;
				break;
			}
		} while(x==0);
		x=0;
		do{
			printf("Enter email\n");
			scanf("%s",pp.email);
			x=valid_email(pp.email);
		}while(x==0);
		x=0;
		do{
			printf("Enter the department of student\n");
			gets(pp.dept);
			x=notempty(pp.dept);
		}while(x==0);
		x=0;

		do{
			printf("Enter the designation of student\n");
			gets(pp.uni);
			x=notempty(pp.uni);
		}while(x==0); 
		
		do{
		    printf("Enter Username\n");
			gets(pp.username);
			x=notempty(pp.username);
		  }while(x==0);

		do{
		    printf("Enter password\n");
			gets(pp.password);
			x=notempty(pp.password);
		   }while(x==0);



		FILE * fPtr = fopen("user_profiles.csv","a"); 
	   
		if(fPtr == NULL) // open the user profile in an excel spread sheet.
		{
			printf("unable to create file. \n");
			exit(EXIT_FAILURE);
		} 
		else{
			fprintf(fPtr,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s \n",pp.id,pp.f_name,pp.l_name,pp.age,pp.address1,pp.address2,pp.phonenumber,pp.gender,pp.email,pp.dept,pp.uni,"Student");
			printf("\nAccount created and saved successfully \n" );
		}
		fclose(fPtr);
	}
	else   /* This code updates the student account profile */
	{
		int i;
    	system("clear");
    	printf("\n ** Account Editing Page **\n\n");
    	printf("                Press 1 to Change First Name\n");
        printf("                Press 2 to Change Last Name\n");
        printf("                Press 3 to Change phone number\n");
        printf("                Press 4 to Change Email\n");
    	printf("                Press 5 Exit\n");
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
                    gets(pp.address1);
                    x=notempty(pp.address1);
                }while(x==0);
    			getrow(student_identification,"email", pp.email);
    			break;
    		}
    		case 5:{
    			
    		}
        }
	}
}
