#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define range 10


#ifdef WINDOWS
    #include "..\include\validation.h"
#else
    #include "../include/validation.h"
#endif

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

