#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#ifdef WINDOWS
    #include "..\include\user_maintainance.h"
	#include "..\include\validation.h"
#else
    #include "../include/user_maintainance.h"
	#include "../include/validation.h"
#endif

char t_id[2000][5];
char t_name[2000][20];
char instructor_id[2000][5];

/**
* \brief  int disp_topics() function display the topics
*
* Function dipslay all the topics from the topics.txt file and show to the user
*
*
* \return Topic: Selected index of topic is returned to the calling function to start the test
*
*/
int disp_topics(){
	FILE *all_topics;
	int ch;
	if( (all_topics=fopen("topics.txt","r")) == NULL ){
		puts("File can not be opened\n\n");
		return 0;
	}
	else{
		int i=1;
		while( !feof(all_topics)){
			fscanf(all_topics,"%s %s %s",t_id[i],t_name[i],instructor_id[i]);
			printf("Press %d for %s  \n",i,t_name[i]);
			i++;
		}
		printf("Press %d for exit  \n",i);
		int v=0;
		do{
			printf("\nEnter your choice\n");
			scanf("%d",&ch);
			if(ch <= 0 || ch > (i)){
				printf("Wrong input");
				v=0;
			}
			else{
				v=1;
			}
		}while(v!=1);
		if(ch==i){
			return -1;
		}
		else{
			return ch;
		}
	}
	fclose(all_topics);
}
int check_req_status(char *u_id, char *topic)
{
	
	char buffer[1024] ;
    char *record,*line;
	FILE *rqsts;
	char id[11];
	char t_id1[9];
	char topic1[20];
	char prof[20];
	char st[3];
	int max=0;
	int i=0;
	int yy=0;
	rqsts = fopen("requests.csv","r");
	if(rqsts == NULL){
    	printf("Unable to open a file. \n");
    	exit(EXIT_FAILURE);
    }
	else{
		while((line=fgets(buffer,sizeof(buffer),rqsts))!=NULL){
			record = strtok(line,";");
			while(record != NULL){
				char *ptr=strtok(record,",");
				strcpy(t_id1,ptr);
				
				ptr = strtok(NULL, ",");
				strcpy(id,ptr);
				ptr = strtok(NULL, ",");
				
				strcpy(topic1,ptr);
				
				ptr = strtok(NULL, ",");
				strcpy( prof,ptr);
				ptr = strtok(NULL, ",");
				
				strcpy(st,ptr);
				record = strtok(NULL,";");
			}
			if((strcmp( u_id, id)==0) && (strcmp( topic, topic1)==0))
			{
					int dd=atoi(st);
					return dd;
			}
			else
			{
			yy=1;	
			}
			
			
			//++i; 
			
		}
		if(yy==1)
		{
			printf("No request has been raised");
		}
	}
	return 3;
}

void start_test(char *u_id, char *topic)
{
	int x=0;
	char buffer[1024] ;
    char *record,*line;
	int selected_answer;
	struct questions
	{
		char q_id[4];
		char sub[25];
		char question[150];
		char op1[30];
		char op2[30];
		char op3[30];
		char op4[30];
		char answer[4];
		char reslt[5];
	};
	struct questions qstn[1500];
	struct questions rslt[100];
	
	int quest_id=generate_Id("exam_results.csv");
	FILE *question_file;
	question_file = fopen("questions.csv","r");
	if(question_file == NULL){
    	printf("Unable to create filedddddd. \n");
    	exit(EXIT_FAILURE);
    }
	else{
		while((line=fgets(buffer,sizeof(buffer),question_file))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
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
				
				x++;
				
				record = strtok(NULL,";");
			}
			//++i ;
		}
		int i=0;
		//printf("\n%d\n\n",x);
		int j=0;
		for(i=0;i<x;i++)
		{
			if((strcmp(rtrim(qstn[i].sub),topic)==0))
			{
				
				printf("\nQuestion %s: %s \n",qstn[i].q_id, qstn[i].question); 
				printf("1. %s", rtrim(qstn[i].op1));
				printf("            2. %s\n",rtrim(qstn[i].op2));
				printf("3. %s ",rtrim(qstn[i].op3));
				printf("            4. %s\n",rtrim(qstn[i].op4));
				strcpy(rslt[j].q_id,qstn[i].q_id);
				strcpy(rslt[j].sub ,qstn[i].sub);
				strcpy(rslt[j].question,qstn[i].question);
				strcpy(rslt[j].op1,qstn[i].op1);
				strcpy(rslt[j].op2,qstn[i].op2);
				strcpy(rslt[j].op3 ,qstn[i].op3);
				strcpy(rslt[j].op4 ,qstn[i].op4);
				strcpy(rslt[j].answer,qstn[i].answer);
				sprintf(rslt[j].reslt,"%d",selected_answer);
				j++;
				int o=0;
				do{
					printf("\n\nEnter Your answer between 1 to 4=");
					scanf("%d", &selected_answer);
					if(selected_answer >4 || selected_answer < 0)
					{
						o=0;
						printf("Invalid selection");
					}
					else
					{
						o=1;
					}
				}while(o!=1);
			}
		}
		
	}
	fclose(question_file);
}



char* raiseTestRequest(char *u_id, int topic){
	FILE *rqsts;
	int request_id=generate_Id("requests.csv");
	rqsts = fopen("requests.csv","a");
	if(rqsts == NULL){
    	printf("Unable to create file. \n");
    	exit(EXIT_FAILURE);
    }
	else{
		fprintf(rqsts,"%d,%s,%s,%s,%s\n",request_id,u_id,t_name[topic],instructor_id[topic],"0");
		printf("request raised");
		
	}
	fclose(rqsts);
}


int student(char *u_id){
	int chh;
	do{
		printf("\n                Press 1 Testdeatil......\n");
		printf("                Press 2 Edit personal profile\n");
		printf("                Press 3 ________________\n");
		printf("                Press 4 Start test\n");
		printf("                Press 5 Raise a test request\n");
		printf("                Press 6 to Log Out!!\n");
		scanf("%d",&chh);
		switch(chh){
			case 1:{
				
				break;
			}
			case 2:{
				char dcsn[6];
				editProfile(u_id);
				
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				int tp, topic;
				topic=disp_topics();
				int i=check_req_status(u_id,t_name[topic]);
				if(i==1)
				{
					printf("You are ready to give exam");
					start_test(u_id,t_name[topic]);
				}
				else{
					printf("Your request is not approved by the professor");
				}
				
				break;
			}
			case 5:{
				int tp, topic;
				topic=disp_topics();
				if(topic>0){
					printf("\n\n\n\nYou have selected %s %s %s",t_id[topic],t_name[topic],instructor_id[topic]);
					raiseTestRequest(u_id,topic);
				}
				
				break;
			}
			case 6:{
				printf("\n Thank you! Have Good Day....");
				return 1;
			}
			default:{
				printf("wrong input");
				break;
			}
		}
	}while(chh!=6);
}

