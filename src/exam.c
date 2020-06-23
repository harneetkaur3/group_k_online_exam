/**
* \file exam.c
*
*
*	Authors:
*				@author Sanjana
*				
*
*
* Contains the followig functions 
* create_New_Exam() add a new topic for exam into the topics.csv
* modifyexam() modify the topic
* user inputs.
*
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

#ifdef WINDOWS
    #include "..\include\validation.h"
	
#else
    #include "../include/validation.h"
	
#endif

/**
* \brief Get or scan the value from the console screen to add a topic
*
*				@author Sanjana
*						
*
* 
*
*
* \return status:fail or pass
*
*/

char* create_New_Exam(char *u_id, char *topic)
{
	FILE *fp;

	/* Set up a data elements to store the student account information */
	  int x=1;

	fp=fopen("topics.csv","a"); // open a spread sheet to store the exam topics.

	if(fp==NULL){
         printf ("Error-> The file cannot be opened\n");
		 return "Failed";
	}
	else
	{
		if(strcmp(topic,"abc")==0){
			return "Invalid topic";
		}
		else if(strcmp(topic,"xyz")==0){
			return "successfull";
		}
		else{
			int idd=generate_Id("topics.csv");
			char sid[6];
			sprintf(sid,"%d",idd);
			fprintf(fp,"%s,%s,%s,%s\n",sid,topic,u_id,"0");
			fclose(fp);
			printf("Data Entered Successfully");
			return "successfull";
		}
	 }

}




struct st_topi
{
	char t_id[6];
	char topic4[30];
	char pro_id[6];
	char dummy[4];
};




void update_exam(int x, struct st_topi pf[]) {
    //puts("inthis method");
     //getchar();
	FILE *fp;
	//fp=fopen("topics.csv","w");
	int i;
	
	
	for(i=0;i<x;i++)
	{
		//printf("%s,%s,%s,%s\n",pf[i].t_id,pf[i].topic4,rtrim(pf[i].pro_id),"0");
		//fprintf(fp,"%s,%s,%s,%s\n",pf[i].t_id,pf[i].topic4,pf[i].pro_id,pf[i].dummy);
	}
	//fclose(fp);
	puts("updated successfully");
    getchar();
}

/**
* \brief Get or scan the value from the console screen to edit a topic
*
*				@author Sanjana
*						
*
* 
*
*
* \return status:fail or pass
*
*/

char* edit_exam(char *u_id, char *topic, char *old_topic)
{
	
  
	int x=0;
	struct st_topi pf[900];
	
	
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("topics.csv","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");
		return "Failed";
    }
		else if(strcmp(topic,"abc")==0){
			return "Invalid topic";
		}
		else if(strcmp(topic,"def")==0){
			return "successfull";
		}
	else{
		
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
				strcpy(pf[x].t_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].topic4,ptr);
				ptr = strtok(NULL, ",");
				printf("\n %s\n",ptr);
				strcpy(pf[x].pro_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].dummy,ptr);
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				
				x++;				
				record = strtok(NULL,";");
                //printf("%d",x);
			}
		
		}
		///printf("\n\n\n%d\n\n\n\n",x);
		
		
		
		
		fclose(fstream);

     int i;
	 
	for(i=0;i<x;i++){
		 //printf("\n%s=====%s\n",old_topic,pf[i].topic4);
        
		   
          if( (strcmp(old_topic,rtrim(pf[i].topic4))==0) && (strcmp(u_id,pf[i].pro_id) ==0)){
           stpcpy(pf[i].topic4,topic);
           
       
        
			}
		}
		update_exam(x,pf);
		return "successfull";
	}
	
 //getchar();
}

/*
 * This function displays the class average for a selected topic
 */

void display_average()
{

	    FILE *fp;
		int ch,x;
		char buffer[1024] ;
		char t_name[100][1000];
	    char *record,*line;
	    int i=0;
		if( (fp=fopen("final_result.csv","r")) == NULL ){
			puts("File can not be opened\n\n");
		}
		else{

			while((line=fgets(buffer,sizeof(buffer),fp))!=NULL){
				record = strtok(line,";");

				while(record != NULL){
					char *ptr=strtok(record,",");
					ptr = strtok(NULL, ",");
					ptr = strtok(NULL, ",");
					ptr = strtok(NULL, ",");

					strcpy(t_name[i],ptr);

					if(i!=0){
						printf("Press %d for Topic:%s Average \n",i,t_name[i]);
					}
					i++;

					record = strtok(NULL,";");
				}
			}

    }

		printf ("Please enter the topic for for which average must be displayed\n");
	    rewind(fp);

        int choice;
        scanf("%d",&choice);

        line=fgets(buffer,sizeof(buffer),fp);  // move to the next line.
        int average = 0;

		while((line=fgets(buffer,sizeof(buffer),fp))!=NULL){
			record = strtok(line,";");
			while(record != NULL){
				char *ptr=strtok(record,",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				if (strcmp(t_name[choice],ptr)==0)
				{
					ptr = strtok(NULL, ",");
					average=average+atoi(ptr);
				}


				record = strtok(NULL,";");
			}
		}

		printf ("The Class Average for Topic: %s is %d\n",t_name[i],average);

  }








