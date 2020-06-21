
/*
 * Create Exam.c
 *
 *  Created on: Jun 06, 2020
 *      Author: Sanjana Dharan
 *
 *

 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>


/* The create exam function presents a UI to the professor to create a new exam format
 * It asks for the exam name, duration of the exam and stores the list of eligible students who can take this exam
 */

void create_New_Exam(void)
{
	FILE *fp;

	/* Set up a data elements to store the student account information */


	  char student_id[50];
	  float duration;
	  char  title[50]; // same as Subject Name
	  int x=1;


      #ifdef WINDOWS
       system("cls");
      #else
       system("clear");
      #endif


	fp=fopen("exam_topics.csv","a"); // open a spread sheet to store the exam topics.

	if(fp==NULL){
         printf ("Error-> The file cannot be opened\n");
	}
	else
	{

          #ifdef WINDOWS
           system("cls");
          #else
           system("clear");
         #endif
		  printf("\n ** New Exam Creation Page **\n\n");
		  printf("\n Enter Title of the Exam\n");
		  scanf("%s",title);
		  printf("\n Enter Maximum Time Duration for the Exam\n");
		  scanf("%f",&duration);
		  fprintf(fp,"%s,%f\n",title,duration);

           #ifdef WINDOWS
            system("cls");
           #else
            system("clear");
          #endif


		  printf("\n ** Please Enter the Student IDs who are eligible to take this exam. Press 2 to exit **\n\n");
		  int k=0;

		  while (x!=2)
		  {
			  printf("\n Enter Student ID of the Student who can take the exam\n");
			  scanf("%s",student_id);
			  fprintf(fp,"%s \n",student_id);
			  printf("\n Enter 2 if you want to Exit or press 1 to enter the next student id..\n");
			  scanf("%d",&x);
		  }

		  fclose(fp);

	 }

}

void edit_exam(void)
{
	FILE *fp;
    char student_id[50];
    float duration;
    char  title[50]; // same as Subject Name
    int i=0;
    char buffer[200];
    int x=1;
    int seek_pointer;

	/* Set up a data structure to maintain the student account information */

        #ifdef WINDOWS
         system("cls");
       #else
        system("clear");
      #endif


	fp=fopen("topics.csv","a"); // open the user profile in an excel spread sheet.
	seek_pointer=open("topics.csv",O_RDONLY);

	if(fp==NULL){
         printf ("Error-> The file cannot be opened\n");
	}
	else
	{

            #ifdef WINDOWS
             system("cls");
            #else
            system("clear");
            #endif

		  printf("\n ** Exam Attributes Update Page **\n\n");

		    printf("                Press 1 to change Exam Name");
		    printf("                Press 2 to change Exam Duration\n");
		    printf("                Press 3 to modify student IDs who are eligible to take the exam\n");
		    printf("                Press 5 Exit\n");
		    scanf("%d",&i);

           switch(i){
            case 1:{
            	    printf("\n Enter Title of the Exam\n");
            	    scanf("%s",title);
    				fprintf(fp,"%s,",title);
    				fclose(fp);
    			break;
    		}
            case 2:{
          	  printf("\n Enter Maximum Time Duration for the Exam\n");
              scanf("%f",&duration);
              pread(seek_pointer,buffer,200,0);
              strtok(buffer,",");
              int length = strlen(buffer);
              fseek(fp,length+1,SEEK_CUR);
              fprintf(fp,"%f",duration);
              break;
            }


    		case 3:{
    		      pread(seek_pointer,buffer,200,0);
    		      strtok(buffer,"\n");
    		      int length = strlen(buffer);
    		      fseek(fp,length+1,SEEK_CUR);
    			  while (x!=2)
    			  {
    				  printf("\n Enter Student ID of the Student who can take the exam\n");
    				  scanf("%s",student_id);
    				  fprintf(fp,"%s \n",student_id);
    				  printf("\n Enter 2 if you want to Exit or press 1 to enter the next student id..\n");
    				  scanf("%d",&x);
    			  }
    			  fclose(fp);

    		}

           }



	 }

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








