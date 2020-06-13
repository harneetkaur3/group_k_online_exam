#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define range 10
#define length 100
#define QUESTIONs "QUESTION: "
#define O1 "A. "
#define O2 "B. "
#define O3 "C. "
#define O4 "D. "
#define ANSWER "ANSWER: "
#define separator "\n------------------------------- \n"
#define NUMBER_QUESTION 30



struct QUESTION{
	int id;
	char question[length];
	char option1[length];
	char option2[length];
	char option3[length];
	char option4[length];
	char ans[2];
};



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
}








void add_question(char* exam){
	struct QUESTION* q = malloc(sizeof(struct QUESTION*));
	
	FILE * fPtr;
   	
    fPtr = fopen("exam","a"); 
    
    if(fPtr == NULL)
    {
    	printf("Exam cannot be found \n");
    	exit(EXIT_FAILURE);
    } 	
	
	printf("\nEnter the question: ");
   	fgets(q->question, length, stdin);
	fputs(QUESTIONs, fPtr);
   	fputs(q->question, fPtr);
	
	printf("\nEnter the first option - A. ");
   	fgets(q->option1, length, stdin);
	fputs(O1, fPtr);
   	fputs(q->option1, fPtr);
	
	printf("\nEnter the second option - B. ");
   	fgets(q->option2, length, stdin);
	fputs(O2, fPtr);
   	fputs(q->option2, fPtr);
	
	printf("\nEnter the third option - C. ");
   	fgets(q->option3, length, stdin);
	fputs(O3, fPtr);
   	fputs(q->option3, fPtr);
	
	printf("\nEnter the fourth option - D. ");
   	fgets(q->option4, length, stdin);
	fputs(O4, fPtr);
   	fputs(q->option4, fPtr);
	

	printf("\nEnter the letter of the correct answer (A, B, C or D): ");
	fgets(q->ans, length, stdin);
	
	while(strlen(q->ans) != 2){ 
		printf("\nEnter the letter of the correct answer (A, B, C or D): ");
		fgets(q->ans, length, stdin);
	}
	
	fputs(ANSWER, fPtr);
   	fputs(q->ans, fPtr);
	
	fputs(separator, fPtr);
	
	
	fclose(fPtr);
   	
   	printf("\nQuestion added successfully \n" );
   	
	
}