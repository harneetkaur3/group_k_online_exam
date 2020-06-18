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

void start_test(char *u_id)
{
	
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
		fprintf(rqsts,"%d,%s,%s\n",request_id,t_name[topic],instructor_id[topic]);
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
				start_test(u_id);
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

