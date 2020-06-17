#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define range 10
#define NUMBER_QUESTION 30
#define STUDENT_ID "Student_ID: "
#define GRADE "Mark: "


struct QUESTION{
	int q_id;
	char question[length];
	char option1[length];
	char option2[length];
	char option3[length];
	char option4[length];
	char ans[2];
};

struct QUESTION* exam = malloc(sizeof(QUESTION)*30);


struct STUDENT_SOLUTION{
	int s_id;
	char ans[2];
	int student_id;
}

struct STUDENT_SOLUTION* sol = malloc(sizeof(STUDENT_SOLUTION)*30);



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


int show_exam_result(){

	char s;
	
	FILE * fPtr;
   	
    fPtr = fopen("STUDENT_RESULTS.txt","r"); 
    
    if(fPtr == NULL)
    {
    	printf("Unable to read results. \n");
    	exit(EXIT_FAILURE);
    } 	
	
	while((s=fgetc(fPtr))!= EOF) {
      printf("%c",s);
	}
	
	
	fclose(fPtr);
	
	
	return 0;
}



void mark_questions_and_display_results(){
	
	FILE * fPtr;
   	
    fPtr = fopen("STUDENT_RESULTS.txt","a"); 
    
    if(fPtr == NULL)
    {
    	printf("unable to create file. \n");
    	exit(EXIT_FAILURE);
    } 	
	

	int total_mark = 0;
	
	
	for (int i=0; i<= NUMBER_QUESTION; i++){
		if(exam[i].q_id == sol[i].s_id && exam[i].ans == sol[i].ans){
			total_mark += total_mark;
		} else{
			total_mark = total_mark;
		}
	}
	
	
	fputs(STUDENT_ID, fPtr);
   	fputs(student_id, fPtr);
	
	fputs(GRADE, fPtr);
   	fputs(total_mark, fPtr);
	
	fclose(fPtr);
	
	printf("You result is: %d", total_mark);
}





