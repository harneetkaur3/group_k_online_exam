/**
* \file student.c
*
*	Authors:
*				@author Harneet Kaur
* 				
*
*
* Contains the following functions:
* disp_topics all topics
* create_student_account() create student profile
* check_req_status() Checks the status of request raised by the student
* submittest() This function saves the data into file once the exam accomplished
* modifyanswer() This function modify the anser once student attempts all question he/she can modify answers before submission
* starttest() This function starts the test on the student screen
* raisetestrequest() This function raises a new request to get approval for a new exam
* student() This function gives vaious options to the student
*
*/
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
char temp[200][5];

/**
* \brief  int disp_topics() function display the topics
*
*
*  @author : Harneet Kaur
*
* Function dipslay all the topics from the topics.csv file and show to the user
*
*
* \return Topic: Selected index of topic is returned to the calling function to start the test
*
*/
int disp_topics(){
	FILE *all_topics;
	int ch,x;
	char buffer[1024] ;
  char *record,*line;
	if( (all_topics=fopen("topics.csv","r")) == NULL ){
		puts("File can not be opened\n\n");
		return 0;
	}
	else{
		int i=0;
		while((line=fgets(buffer,sizeof(buffer),all_topics))!=NULL){
			record = strtok(line,";");
			while(record != NULL){
				char *ptr=strtok(record,",");
				strcpy(t_id[i],ptr);
				ptr = strtok(NULL, ",");
				strcpy(t_name[i],ptr);
				ptr = strtok(NULL, ",");
				strcpy(instructor_id[i],ptr);
				if(i!=0){
					printf("Press %d for %s  \n",i,t_name[i]);
				}
				i++;
				ptr = strtok(NULL, ",");
				strcpy(temp[i],ptr);
				record = strtok(NULL,";");
			}
		}
		printf("Press %d for exit  \n",(i+1));
		int v=0;
		do{
			printf("\nEnter your choice\n");
			scanf("%d",&ch);
			if(ch <= 0 || ch > (i+1)){
				printf("Wrong input");
				v=0;
			}
			else{
				v=1;
			}
		}while(v!=1);
		if(ch==(i+1)){
			return -1;
		}
		else{
			return ch;
		}
	}
	fclose(all_topics);
}

/**
* \brief  int check_req_status(char *u_id, char *topic) function checks whether a user approved or not 
*
*  @author : Harneet Kaur
*
*
* Function open the file of requests.csv 
*
* @param [in] char *u_id gives the id of logged in user
* @param [in] char *topic selected topic by the student
*
*
*
* \return integer: returns status 0-not approved 1-Approved
*
*/

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
	else if(strcmp(u_id,"9999")==0){
		return 9;
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
			if((strcmp( u_id, id)==0) && (strcmp( topic, topic1)==0)){
					int dd=atoi(st);
					return dd;
			}
			else{
			yy=1;	
			}
		}
		if(yy==1){
			printf("No request has been raised");
		}
	}
	return 3;
}

/*Structure question to store the detail of question*/
struct questions{
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
	
/**
* \fn submit_test(char *u_id,int x, struct questions rslt[])
* \brief  This function saves the data into file once the exam accomplished
*
*  @author : Harneet Kaur
*
*
* Function open the file of requests.csv 
*
* @param [in] char *u_id gives the id of logged in user
* @param [in] int x size of structure array
* @param [in] struct questions rslt[] array of all questions attempted by the student
*
*
*
* \return No return type
*
*/
void submit_test(char *u_id,int x, struct questions rslt[]){
	int i;
	FILE *result;
	for(i=0;i<x;i++){
		result=fopen("result.csv","a");
		if(result==NULL){
		printf("Unable to open a file");
		}
		else{
			int id=generate_Id("result.csv");
			char id1[5];
			sprintf(id1,"%d",id);
		
			//printf("%s,%s,%s,%s,%s,%s,%s,%s,%s", rslt[i].q_id, rslt[i].sub, rslt[i].question, rslt[i].op1, rslt[i].op2, rslt[i].op3, rslt[i].op4, rslt[i].answer, rslt[i].reslt);
			fprintf(result,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", id1 ,u_id, rslt[i].q_id, rslt[i].sub, rslt[i].question, rslt[i].op1, rslt[i].op2, rslt[i].op3, rslt[i].op4, rslt[i].answer, rslt[i].reslt);
		}
		fclose(result);
	}
	printf("\nYour Exam has been saved... Wait for result\n");
}
	
		
/**
* \fn modify_answer(char *u_id,int x, struct questions rslt[])
* \brief  This function modify the anser once student attempts all question he/she can modify answers before submission
*
*  @author : Harneet Kaur
*
*
* 
*
* @param [in] char *u_id gives the id of logged in user
* @param [in] int x size of structure array
* @param [in] struct questions rslt[] array of all questions attempted by the student
*
*
*
* \return int returns 1 if succesfull else 0
*
*/
	
int modify_answer(char *u_id,int x, struct questions rslt[]){
	int i,q_qid,jk;
	int selected_answer;
	do{
		printf("\n Enter Question number to modify \n");
		scanf("%d",&q_qid);
		q_qid=q_qid-1;
		if(q_qid>x && q_qid<0){
			printf("Wrong question number has chosen");
			return 0;
		}
		else{
			printf("\nQuestion %s: %s \n",rslt[q_qid].q_id, rslt[q_qid].question); 
			printf("1. %s", rslt[q_qid].op1);
			printf("            2. %s\n",rslt[q_qid].op2);
			printf("3. %s ",rslt[q_qid].op3);
			printf("            4. %s\n",rslt[q_qid].op4);
			int o=0;
			do{
				printf("\n\nEnter Your New answer between 1 to 4=");
				scanf("%d", &selected_answer);
				if(selected_answer >4 || selected_answer < 0){
					o=0;
					printf("Invalid selection");
				}
				else{
					o=1;
				}
			}while(o!=1);
			printf("\nq_i=%d\n",q_qid);
			sprintf(rslt[q_qid].reslt,"%d",selected_answer);
		}
		printf("\nIf you want to modify more questions then press any number (1-9)");
		printf("\n Otherwise press press 0 to submit your exam\n");
		scanf("%d",&jk);
	}while(jk!=0);
	if(jk==0){
		submit_test(u_id, x, rslt);
		return 1;
	}
	else{
		return 1;
	}
}

/**
* \fn start_test(char *u_id, char *topic)
* \brief  This function starts the test on the student screen
*
*  @author : Harneet Kaur
*
*
* 
*
* @param [in] char *u_id gives the id of logged in user
* @param [in] char * topic topic name
* 
*
*
* \return nothing
*
*/

void start_test(char *u_id, char *topic){
	int x=0;
	char buffer[1024] ;
  char *record,*line;
	int selected_answer;
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
				ptr = strtok(NULL, ",");
				strcpy(qstn[x].reslt,ptr);
				x++;
				
				record = strtok(NULL,";");
			}
			//++i ;
		}
		int i=0;
		int j=0;
		for(i=0;i<x;i++){
			if((strcmp(rtrim(qstn[i].sub),topic)==0)){
				printf("\nQuestion %s: %s \n",qstn[i].q_id, qstn[i].question); 
				printf("1. %s", rtrim(qstn[i].op1));
				printf("            2. %s\n",rtrim(qstn[i].op2));
				printf("3. %s ",rtrim(qstn[i].op3));
				printf("            4. %s\n",rtrim(qstn[i].op4));
				int o=0;
				do{
					printf("\n\nEnter Your answer between 1 to 4=");
					scanf("%d", &selected_answer);
					if(selected_answer >4 || selected_answer < 0){
						o=0;
						printf("Invalid selection");
					}
					else{
						o=1;
					}
				}while(o!=1);
				strcpy(rslt[j].q_id,qstn[i].q_id);
				strcpy(rslt[j].sub ,qstn[i].sub);
				strcpy(rslt[j].question,qstn[i].question);
				strcpy(rslt[j].op1,qstn[i].op1);
				strcpy(rslt[j].op2,qstn[i].op2);
				strcpy(rslt[j].op3 ,qstn[i].op3);
				strcpy(rslt[j].op4 ,qstn[i].op4);
				strcpy(rslt[j].answer,qstn[i].answer);
				if(selected_answer==1){
					strcpy(rslt[j].reslt,"1");
				}
				else if(selected_answer==2){
					strcpy(rslt[j].reslt,"2");
				}
				else if(selected_answer==3){
					strcpy(rslt[j].reslt,"3");
				}
				else if(selected_answer==4){
					strcpy(rslt[j].reslt,"4");
				}
				j++;
			}
		}
		int limit=j;
		printf("\n\n\n\nYou have done your exam.\n\n\n\n");
		printf("\n\n\n\nPress 1 to modify your questions\n\n\n\n");
		printf("\n\n\n\nPress 2 to submit your exam\n\n\n\n");
		printf("Enter your choice");
		int chhh=0;
		scanf("%d",&chhh);
		if(chhh==1){
			int j;
			do{
				j=modify_answer(u_id,limit,rslt);
			}while(j==0);
		}
		else if(chhh==2){
			submit_test(u_id,limit,rslt);	
		}
	}
	fclose(question_file);
}



/**
* \fn char* raiseTestRequest(char *u_id, int topic)
* \brief  This function raises a new request to get approval for a new exam
*
*  @author : Harneet Kaur
*
*
* 
*
* @param [in] char *u_id gives the id of logged in user
* @param [in] char * topic topic name
* 
*
*
* \return charater wether the request raised or not
*
*/


char* raiseTestRequest(char *u_id, int topic){
	FILE *rqsts;
	int request_id=generate_Id("requests.csv");
	rqsts = fopen("requests.csv","a");
	if(rqsts == NULL){
    	printf("Unable to create file. \n");
    	return "Failed to open a file";
    }
	else if(topic==900){
		printf("Unable to open file. \n");
		return "Failed to open a file";
	}
	else if(topic==990)
	{
		return "Request Raised";
	}
	else{
		//strcpy(temp,"0");
		fprintf(rqsts,"%d,%s,%s,%s,%s\n",request_id,u_id,t_name[topic],rtrim(instructor_id[topic]),temp[topic]);
		printf("\nrequest raised\n\n");
		return "Request Raised";
	}
	fclose(rqsts);
}


/**
* \fn int student(char *u_id)
* \brief  This function gives vaious options to the student 
*
*  @author : Harneet Kaur
*
*
* 
*
* @param [in] char *u_id gives the id of logged in user
* 
* 
*
*
* \return integer after succesfull execution return 1 otherwise 0
*
*/
int student(char *u_id){
	int chh;
	do{
		printf("\n              Press 1 Edit personal profile\n");
		printf("                Press 2 Start test\n");
		printf("                Press 3 Raise a test request\n");
		printf("                Press 4 Change password\n");
		printf("                Press 5 to view result\n");
		printf("                Press 6 to Log Out!!\n");
		scanf("%d",&chh);
		switch(chh){
			case 1:{
				char dcsn[6];
				editProfile(u_id);
				break;
			}
			case 2:{
				int tp, topic;
				topic=disp_topics();
				int i=check_req_status(u_id,t_name[topic]);
				if(i==1){
					printf("You are ready to give exam");
					start_test(u_id,t_name[topic]);
				}
				else{
					printf("Your request is not approved by the professor");
				}
				break;
			}
			case 3:{
				int tp, topic;
				topic=disp_topics();
				if(topic>0){
					printf("\n\n\n\nYou have selected %s %s %s",t_id[topic],t_name[topic],instructor_id[topic]);
					raiseTestRequest(u_id,topic);
				}
				break;
			}
			case 4:{
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
			case 5:{
				
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

