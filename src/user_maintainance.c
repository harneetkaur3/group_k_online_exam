#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define range 10


#ifdef WINDOWS
    #include "..\include\validation.h"
#else
    #include "../include/validation.h"
#endif










struct user{
    char username[10];
	char password[10];
	char user_type[20];
};

char* changePassword(char *uname,char *oldpwd,char *newpwd){

    // char username[10];
	// char password[10];
	// char user_type[20];
    int x=0;
	struct user pf[150];
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("login_detail.txt","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");

    }
	else{
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record," ");
				strcpy(pf[x].username,ptr);
				ptr = strtok(NULL, " ");
				strcpy(pf[x].password,ptr);
				ptr = strtok(NULL, " ");
				strcpy(pf[x].user_type,ptr);
										
				x++;				
				record = strtok(NULL,";");
                //printf("%d",x);
			}
		
		}
		///printf("\n\n\n%d\n\n\n\n",x);
		
	}
	fclose(fstream);

    int i;
	for(i=0;i<x;i++){
       
            if( (strcmp(uname,pf[i].username)==0) && (strcmp(oldpwd,pf[i].password) ==0)){               
                    stpcpy(pf[i].password,newpwd);           
                   // strcat(pf[i].user_type,"\n");
                     
                    //update_questions(x,pf);
       
        
        }
    }
    FILE *u_profile;
	u_profile=fopen("login_detail.txt","w");
	int j;
	for(j=0;j<x;j++)
	{
		if(u_profile==NULL){
			printf("Unable to create a file");
		}
		else{
			
			fprintf(u_profile,"%s %s %s",pf[j].username,pf[j].password,pf[j].user_type);
		}
			
	}
	fclose(u_profile);
	puts("updated successfully");
   // getchar();

    return "yes";
 	

}




/**
*
* \fn struct profile1
* \brief it would get all the data of a file user_profiles to updte particular value
*
*
*/
struct profile1{
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
        char type[50];
    };

/**
*
* \fn char* login(char *id, char *pwd)
* \brief Checks the login credentials from database file to assign the user type: Admin,Student,Professor.
*
* Accesses the login_details table from database and matches
* login credentials provided by the user corresponding to the
* data entry in the database
*
* @param[in] id Unique login id for the user
* @param[in] pwd Password for the user
*
* \return User_Type: admin, student or professor for successful login
*		   Wrong username/password for incorrect login credentials
*		   User deactivated if the user is deactivated in database
*
*/



char* login(char *u_id, char *pwd){
	FILE *user_credentials;
	char un[range];
	char pw[range];
	char u_type[20];
	if( (user_credentials=fopen("login_detail.txt","r")) == NULL ){
		puts("File can not be opened\n\n");
	}
	else{
		while( !feof(user_credentials) ){
			fscanf(user_credentials,"%s %s %s",un,pw, u_type);
			
			if((strcmp(un,u_id)==0) && (strcmp(pw,pwd)==0)){
				if(strcmp(u_type,"Admin")==0){
					return "Admin";
				}
				else if(strcmp(u_type,"Student")==0){
					return "Student";
				}
				else if(strcmp(u_type,"Professor")==0){
					return "Professor";
				}
				else{
					return "Problem";
				}
			}
		}
		if(feof(user_credentials)){
			printf("\n\nInvalid Username/Password\n\n");
			return "invalid";
		}
	}
	fclose(user_credentials);
}

void update_file(int x, struct profile1 pf[])
{
	FILE *u_profile;
	u_profile=fopen("user_profiles.csv","w");
	int i;
	for(i=0;i<x;i++)
	{
		if(u_profile==NULL){
			printf("Unable to create a file");
		}
		else{
			
			fprintf(u_profile,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",pf[i].id,pf[i].f_name,pf[i].l_name,pf[i].age,pf[i].address1,pf[i].address2,pf[i].phonenumber,pf[i].gender,pf[i].email,pf[i].dept,pf[i].uni,pf[i].type);
		}
			
	}
	fclose(u_profile);
	
}
/**
*
* \fn void getrow(char *u_id, char *arg_type, char *upadteval)
* \brief This function gets a record form the file to update and call the function update file
*
* access the user_profiles file
* 
* @param[in] U_id Unique id who logged in
* @param[in] arg_type which field needs to be update 
* @param[in] upadteval uprocides the new value
* 
*/
void getrow(char *u_id, char *arg_type, char *upadteval){
	
	int x=0;
	struct profile1 pf[150];
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("user_profiles.csv","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");

    }
	else{
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
				strcpy(pf[x].id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].f_name,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].l_name,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].age,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].address1,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].address2,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].phonenumber,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].gender,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].email,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].dept,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].uni,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].type,ptr);
				
				x++;
				
				record = strtok(NULL,";");
			}
			//++i ;
		}
		printf("\n\n\n%d\n\n\n\n",x);
		//while(
	}
	fclose(fstream);
	int i;
	for(i=0;i<x;i++){
		if((strcmp(u_id,pf[i].id))==0){
			if((strcmp(arg_type,"Firstname"))==0){
				stpcpy(pf[i].f_name,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"Lastname"))==0){
				stpcpy(pf[i].l_name,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"age"))==0){
				stpcpy(pf[i].age,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"add1"))==0){
				stpcpy(pf[i].address1,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"add2"))==0){
				stpcpy(pf[i].address2,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type, "pno"))==0){
				stpcpy(pf[i].phonenumber,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"gender"))==0){
				stpcpy(pf[i].gender,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"email"))==0){
				stpcpy(pf[i].email,upadteval);
				update_file(x, pf);
			}
			else if((strcmp(arg_type,"dept"))==0){
				stpcpy(pf[i].dept,upadteval);
				update_file(x, pf);
			}
		}
	}
}



/**
*
* \fn char* editProfile(char *u_id)
* \brief Allows the admin to modify employee details.
*
* Allows the admin to modify existing employee details.
* Depending on admin input different fields can be modified.
*
* @param[in] emp_id employee id whose details to be modified by the admin
*
* \return string message for modify employee status
*
*/


char* editProfile(char *u_id){
	struct profile{
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
        //char status[10];
    };
	struct profile pp;
	int i=0;
    int x=0;
	printf("                Press 1 First Name\n");
    printf("                Press 2 Last Name\n");
    printf("                Press 3 Age\n");
    printf("                Press 4 Address Line 1\n");
    printf("                Press 5 Address Line 2\n");
    printf("                Press 6 Phone Number\n");
    printf("                Press 7 Gender\n");
    printf("                Press 8 Email\n");
	printf("                Press 9 Enter your department\n");
	printf("                Press 10 Enter your University\n");
    printf("                Press 11 Exit\n");
    scanf("%d",&i);
	switch(i){
        case 1:{
			do{
				printf("Enter the new first name: \n");
				gets(pp.f_name);
				x=notempty(pp.f_name);
			}while(x==0);
			getrow(u_id,"Firstname", pp.f_name);
			x=0;
			break;
		}
		case 2:{
			do{
				printf("Enter the new last name: \n");
				gets(pp.l_name);
				x=notempty(pp.l_name);
			}while(x==0);
			getrow(u_id,"Lastname", pp.l_name);
			x=0;
			break;
		}
		case 3:{
			printf("Enter the age: \n");
			scanf("%s",pp.age);
			//getchar();
			
			getrow(u_id,"age", pp.age);
			break;
		}
		case 4:{
			int x=0;
            getchar();
            do{
                printf("Enter address line 1\n");
                gets(pp.address1);
                x=notempty(pp.address1);
            }while(x==0);
			getrow(u_id,"add1", pp.address1);
			break;
		}
		case 5:{
			int x=0;
            getchar();
            do{
                printf("Enter address line 2\n");
                gets(pp.address2);
                x=notempty(pp.address2);
            }while(x==0);
			getrow(u_id,"add2", pp.address2);
			break;
		}
		case 6:{
			int x=0;
            do{
                printf("Enter the phone number: \n");
                scanf("%s",pp.phonenumber);
                getchar();
                x=valid_phone(pp.phonenumber);
            }while(x==0);
			getrow(u_id,"pno", pp.phonenumber);
			break;
		}
		case 7:{
			do{
                printf("\nEnter gender Male , Female or Others\n");
                scanf("%s",pp.gender);
                if (strcasecmp(pp.gender,"Male")==0 || strcasecmp(pp.gender,"Female")==0 || strcasecmp(pp.gender,"Female")==0){
                    x=1;
                    break;
                }
            } while(x==0);
			getrow(u_id,"gender", pp.gender);
			break;
		}
		case 8:{
			int x=0;
            do{
                printf("Please provide the email: \n");
                scanf("%s",pp.email);
                getchar();
                x=valid_email(pp.email);
            }while(x==0);
			getrow(u_id,"email", pp.email);
			break;
		}
		case 9:{
			int x=0;
            getchar();
            do{
                printf("Enter the departmen\n");
                gets(pp.dept);
                x=notempty(pp.dept);
            }while(x==0);
			getrow(u_id,"dept", pp.dept);
			break;
			
		}
		case 10:{
			int x=0;
            getchar();
            do{
                printf("Enter the university\n");
                gets(pp.uni);
                x=notempty(pp.uni);
            }while(x==0);
			getrow(u_id,"uni", pp.uni);
			break;
		}
		case 11:{
			return "ok";
		}
		
	}
		
}