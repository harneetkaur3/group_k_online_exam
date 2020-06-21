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




void mark_questions_and_display_results(char *u_id, char *topic, char *stu_id){

struct question1
	{
		char r_id[4];
		char stu_id[15];
		char q_id[15];
		char sub[25];
		char question[150];
		char op1[30];
		char op2[30];
		char op3[30];
		char op4[30];
		char answer[4];
		char reslt[5];
};

	int x=0;
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("result.csv","r");
	struct question1 qstn[1500];
    if(fstream == NULL){
        printf("\n file opening failed ");

    }
	else{
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
                		strcpy(qstn[x].r_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(qstn[x].stu_id ,ptr);
				ptr = strtok(NULL, ",");
				strcpy(qstn[x].q_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(qstn[x].sub,ptr);
                		ptr = strtok(NULL, ",");
				strcpy(qstn[x].question,ptr);
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].op1,ptr);
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].op2,ptr);	
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].op3,ptr);	
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].op4,ptr);	
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].answer,ptr);	
				ptr = strtok(NULL, ",");	
				strcpy(qstn[x].reslt,ptr);	
				ptr = strtok(NULL, ",");	
				
				x++;				
				record = strtok(NULL,";");
                //printf("%d",x);
			}
		
		}
		///printf("\n\n\n%d\n\n\n\n",x);
		
	}
	fclose(fstream);
    //puts(professorid);
    int i;
	
	int counter=0,total1=0;
	for(i=0;i<x;i++){
		//printf("%s",qstn[i].r_id);
		 //((strcmp(rtrim(qstn[i].answer),rtrim(qstn[i].reslt)))==0) && ((strcmp("0",rtrim(qstn[i].sub==topic)) ==0)
		 if(strcmp(rtrim(qstn[i].sub),topic)==0 &&  strcmp(rtrim(qstn[i].stu_id),stu_id)==0){
			total1++;
		 }
		 
		if(strcmp(rtrim(qstn[i].answer),rtrim(qstn[i].reslt))==0 &&  strcmp(rtrim(qstn[i].sub),topic)==0 &&  strcmp(rtrim(qstn[i].stu_id),stu_id)==0 ){
			counter++;
			//printf("\n%s    %s     %s   %s ", );
		}
	}
	printf("\n\nResult of student %s. Marks got %d out of %d\n\n",stu_id,counter, (x-1));
	FILE *u_profile;
	
	u_profile=fopen("final_result.csv","a");
	int j;
		if(u_profile==NULL){
			printf("Unable to create a file");
		}
		else{
			printf("hello");
			int id=generate_Id("final_result.csv");
			char id1[5];
			sprintf(id1,"%d",id);
			fprintf(u_profile,"%s,%s,%s,%s,%d,%d\n",id1,u_id,stu_id,topic,counter,total1);
		}
	fclose(u_profile);

}


int show_exam_results(){

	char s;
	
	FILE * fPtr;
   	
    fPtr = fopen("final_result.csv","r"); 
    
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






