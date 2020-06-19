#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WINDOWS
    #include "..\include\validation.h"
	#include "..\include\profile_creation.h"
#else
    #include "../include/validation.h"
	#include "../include/profile_creation.h"
#endif

void create_prof_profile()
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
