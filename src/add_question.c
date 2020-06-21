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
@@ -34,4 +60,71 @@ char* login(char *u_id, char *pwd){
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
