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
	q->id=generate_Id("questions.csv");
	FILE * fPtr;
   	char *topic3=disp_topics1(u_id);
	printf("%s",topic3);
	int x=0;
	
	
    fPtr = fopen(""questions.csv","a"); 
    
    if(fPtr == NULL)
    {
    	printf("Exam cannot be found \n");
    	exit(EXIT_FAILURE);
    } 
	getchar();	
	do{
	printf("\nEnter the question: ");
   	gets(q->question);
	x=notempty(q->question);
	}while(x==0);

	do{
	printf("\nEnter the first option - 1. ");
   	gets(q->option1);
	x=notempty(q->option1);
	} while (x==0);
	
	do{
	printf("\nEnter the second option - 2. ");
   	gets(q->option2);
	x=notempty(q->option2);
	} while (x==0);
	
	do{
	printf("\nEnter the third option - 3. ");
   	gets(q->option3);
	x=notempty(q->option3);
	} while (x==0);
	
	do{
	printf("\nEnter the fourth option - 4. ");
   	gets(q->option4);
	x=notempty(q->option4);
	} while (x==0);
	

	while(strlen(q->ans) != 2){ 
		printf("\nEnter the letter of the correct answer (1, 2, 3 or 4): ");
		gets(q->ans);
	}
	

	fprintf(fPtr,"%d,%s,%s,%s,%s,%s,%s,%s,%s\n",q->id,topic3,q->question,q->option1,q->option2,q->option3,q->option4,q->ans,"0");
	
	fclose(fPtr);
   	
   	printf("\nQuestion added successfully \n" );
   	
	
}
