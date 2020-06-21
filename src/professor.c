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



#ifdef WINDOWS
    #include "..\include\validation.h"
	#include "..\include\profile_creation.h"
#else
    #include "../include/validation.h"
	#include "../include/profile_creation.h"
#endif




#define range 30
#define length 100
#define QUESTIONs "QUESTION: "
#define O1 "A. "
#define O2 "B. "
#define O3 "C. "
#define O4 "D. "
#define ANSWER "ANSWER: "
#define separator "\n------------------------------- \n"
#define NUMBER_QUESTION 30


/**
* \brief  int disp_topics() function display the topics
*
* Function dipslay all the topics from the topics.csv file and show to the user
*
*
* \return Topic: Selected index of topic is returned to the calling function to start the test
*
*/
char* disp_topics1(char *prof_id){
	
	
	char t_id[2000][5];
	char t_name[2000][20];
	char instructor_id[2000][5];
	char temp[200][5];
	FILE *all_topics;
	int ch,x;
	char buffer[1024] ;
    char *record,*line;
	if( (all_topics=fopen("topics.csv","r")) == NULL ){
		puts("File can not be opened\n\n");
		return "error";
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
				if(strcmp(instructor_id[i],prof_id)==0){
					printf("Press %d for %s  \n",i,t_name[i]);
				}
				i++;
				ptr = strtok(NULL, ",");
				strcpy(temp[i],ptr);
				record = strtok(NULL,";");
			}
		}
		
		/*while( !feof(all_topics)){
			fscanf(all_topics,"%s %s %s",t_id[i],t_name[i],instructor_id[i]);
			printf("Press %d for %s  \n",i,t_name[i]);
			i++;
		}*/
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
		char *topic3=t_name[ch];
		return topic3;
	}
	fclose(all_topics);
}





struct QUESTION{
	int id;
	char question[length];
	char option1[30];
	char option2[length];
	char option3[length];
	char option4[length];
	char ans[2];
};







struct request{
    char requestid[10]; 
    char studentid[10];
	char topic[20];
	char professorid[20];
    char allow[5];
};
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





void update_questions(int x, struct questions pf[]) {
    //puts("inthis method");
     //getchar();
	FILE *u_profile;
	u_profile=fopen("questions.csv","w");
	int i;
	
	
	for(i=0;i<x;i++)
	{
		if(u_profile==NULL){
			printf("Unable to create a file");
		}
		else{
			
			fprintf(u_profile,"%s,%s,%s,%s,%s,%s,%s,%s,%s \n",pf[i].q_id,pf[i].sub,pf[i].question,pf[i].op1,pf[i].op2,pf[i].op3,pf[i].op4,pf[i].answer,"0");
		}
			
	}
	fclose(u_profile);
	puts("updated successfully");
    getchar();
}


// Edit question


void editQuestion(char *topic){
// puts(queid);
  puts(topic);
 	char questionid[10];
	printf("Enter the question id: ");
	scanf("%s",questionid);
   	//fgets(questionid, 5, stdin);
       
puts(questionid);
    
   /// struct questions q ;
  ///  = malloc(sizeof(struct questions*));	
	char question[120];
	
	int x=0;
	getchar();
	do{
		printf("Enter the question: ");
		gets(question);
		x=notempty(question);
	}while(x==0);
	
	
	
	char op1[30];
	do{
		printf("\nEnter the first option - A. ");
		gets(op1);
		x=notempty(op1);
	}while(x==0);
	//fgets(q->option1, length, stdin);
	//fputs(O1, fPtr);
	//fputs(q->option1, fPtr);
	char op2[30];
	do{
		printf("\nEnter the second option - B. ");
		gets(op2);
		x=notempty(op2);
	}while(x==0);
	char op3[30];
	do{
		printf("\nEnter the third option - C. ");
		gets(op3);
		x=notempty(op3);
	}while(x==0);
	char op4[30];
	do{
		printf("\nEnter the fourth option - D. ");
		gets(op4);
		x=notempty(op4);
	}while(x==0);
	char answer[10];
	printf("\nEnter the letter of the correct answer (1, 2, 3 or 4): ");
	scanf("%s",answer);
	
	
   	/*//fgets(question, 100, stdin);
      // stpcpy(question,rtrim(question));
//puts(question);
	char op1[30];
	printf("Enter the first option - A. ");
   	fgets(op1, 30, stdin);	
       stpcpy(op1,rtrim(op1));
//puts(op1);
	char op2[30];
	printf("Enter the second option - B. ");
   	fgets(op2, 30, stdin);
        stpcpy(op2,rtrim(op2));
//puts(op2);
	char op3[30];
	printf("Enter the third option - C. ");
   	fgets(op3, 30, stdin);
        stpcpy(op3,rtrim(op3));
//puts(op3);
	char op4[30];
	printf("Enter the fourth option - D. ");
   	fgets(op4, 30, stdin);
        stpcpy(op4,rtrim(op4));
//puts(op4);
	char answer[10];	
	printf("Enter the correct answer (1, 2, 3 or 4): ");
	fgets(answer, 10, stdin);
     stpcpy(answer,rtrim(answer));*/
//puts(answer);	
	/*while(strlen(answer) != 1){ 
		printf("\nEnter the letter of the correct answer (1, 2, 3 or 4): ");
		fgets(answer,10, stdin);
        stpcpy(answer,rtrim(answer));
	}*/
  ///// finding total rows of the file
  x=0;
	struct questions pf[150];
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("questions.csv","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");

    }
	else{
		
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
				strcpy(pf[x].q_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].sub,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].question,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op1,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op2,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op3,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op4,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].answer,ptr);
				ptr = strtok(NULL, ",");						
				x++;				
				record = strtok(NULL,";");
                //printf("%d",x);
			}
		
		}
		///printf("\n\n\n%d\n\n\n\n",x);
		
	}
	fclose(fstream);
///// updating the edit file
///puts("checking no of lines in file");
//getchar();
     int i;
	 
	for(i=0;i<x;i++){
		 printf("\n%s=====%s\n",questionid,pf[i].q_id);
        //  puts(questionid);
        //       printf("Length of questionid string is: %d\n", strlen(questionid));
        //     puts(pf[i].q_id);
        //      printf("Length of qid string is: %d\n", strlen(pf[i].q_id));
        //     puts(topic);
        //     printf("Length of topic string is: %d\n", strlen(topic));
        //     puts(pf[i].sub);
        //        printf("Length of string is: %d\n", strlen(pf[i].sub));
      //  if((strcmp(questionid,pf[i].q_id)==0))  {
		   
            if( (strcmp(questionid,pf[i].q_id)==0) && (strcmp(topic,pf[i].sub) ==0)){
               printf("hello");
            stpcpy(pf[i].question,question);
            stpcpy(pf[i].op1,op1);
            stpcpy(pf[i].op2,op2);
            stpcpy(pf[i].op3,op3);
            stpcpy(pf[i].op4,op4);
            stpcpy(pf[i].answer,answer);
            //strcat(pf[i].answer,"\n");
                        //printf("%d\n",i); 

          update_questions(x,pf);
       
        
        }
    }
 //getchar();
}

//End edit question


// deleting a questions

 void deleteQuestion(char *topic,char *quid){

   //// finding total rows of the column
    int x=0;
	struct questions pf[150];
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("questions.csv","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");

    }
	else{
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
				strcpy(pf[x].q_id,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].sub,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].question,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op1,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op2,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op3,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].op4,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].answer,ptr);
				ptr = strtok(NULL, ",");						
				x++;				
				record = strtok(NULL,";");
			}
			//++i ;
		}
		//printf("\n\n\n%d\n\n\n\n",x);
		//while(
	}
	fclose(fstream);
        ////

   FILE *u_profile;
	u_profile=fopen("questions.csv","w");
    int i;
       
	for(i=0;i<x;i++){
         if(u_profile==NULL){
			printf("Unable to create a file");
		}
       else if( (strcmp(quid,pf[i].q_id)==0) && (strcmp(topic,pf[i].sub) ==0)){
            
           // update_questions(x,pf);
        }
        else{				
			fprintf(u_profile,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",pf[i].q_id,pf[i].sub,pf[i].question,pf[i].op1,pf[i].op2,pf[i].op3,pf[i].op4,pf[i].answer,"0");
		}
			
	}
	fclose(u_profile);
    puts("deeleted successfully");
    getchar();  		
 }

//end of deleting question function
// Allow student

void allowstudent(char *professorid){
	
   // puts(professorid);
    //puts("in thsi func");
     int x=0;
	struct request pf[150];
	char buffer[1024] ;
    char *record,*line;
	FILE *fstream = fopen("requests.csv","r");
    if(fstream == NULL)  {
        printf("\n file opening failed ");

    }
	else{
		while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL){
			record = strtok(line,";");
			while(record != NULL){

				char *ptr=strtok(record,",");
                strcpy(pf[x].requestid,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].studentid,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].topic,ptr);
				ptr = strtok(NULL, ",");
				strcpy(pf[x].professorid,ptr);
                ptr = strtok(NULL, ",");
				strcpy(pf[x].allow,ptr);
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
	
	printf("\nPending Requests");
	printf("\n============================================================================\n");
	printf("\nPending Requests");
	printf("\nS ID===Stu_ID====Topic======Pending request=================\n");
	for(i=0;i<x;i++){
		if( ((strcmp(professorid,rtrim(pf[i].professorid)))==0) && ((strcmp("0",rtrim(pf[i].allow))) ==0)){
			
			printf("\n%s    %s     %s   %s ", pf[i].requestid,pf[i].studentid ,pf[i].topic ,pf[i].allow);
		}
	}
	/*for(i=0;i<x;i++){
       // puts(professorid);
        puts(pf[i].professorid);
        puts(pf[i].allow);
       // puts("professorid");
       
            if( (strcmp(professorid,pf[i].professorid)==0) && (strcmp("0",pf[i].allow) ==0)){               
                    stpcpy(pf[i].allow,"1");           
                    strcat(pf[i].allow,"\n");                     
                    //update_questions(x,pf);
                    printf("\n\n\n%d\n\n\n\n",i);

       
        
        }
    }*/
	int r_ch;
	printf("\nEnter the serial ID to approve the request\n");
	scanf("%d",&r_ch);
	strcpy(pf[r_ch].allow,"1");
	
    FILE *u_profile;
	u_profile=fopen("requests.csv","w");
	int j;
	for(j=0;j<x;j++)
	{
		printf("hello");
		if(u_profile==NULL){
			printf("Unable to create a file");
		}
		else{
			printf("hello");
			fprintf(u_profile,"%s,%s,%s,%s,%s\n",pf[j].requestid,pf[j].studentid,pf[j].topic,pf[j].professorid,pf[j].allow);
		}
			
	}
	fclose(u_profile);
	puts("student allowed successfully");
   getchar();

    

}

// end Allow student





int professor(char *u_id){
	int chh;
	do{
		printf("\n                Press 1 Edit personal profile\n");
		printf("                Press 2 Add new Topic\n");
		printf("                Press 3 Add a Question\n");
		printf("                Press 4 Update a question\n");
		printf("                Press 5 Delete a question\n");
		printf("                Press 6 Approve student request\n");
		printf("                Press 7 Generate Result\n");
		printf("                Press 8 change password ...........\n");
		printf("                Press 9 to Log Out!!\n");
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
				char *topic3=disp_topics1(u_id);
				editQuestion(topic3);
				break;
			}
			case 5:{
				char *topic3=disp_topics1(u_id);
				char qqid[5];
				printf("\n Enter question id to delete");
				scanf("%s",qqid);
				deleteQuestion(topic3,qqid);
				break;
			}
			case 6:{
				//printf("hello");
				allowstudent(u_id);
				break;
			}
			case 7:{
				
				//printf("hello");
				//allowstudent(u_id);
				break;
			}
			case 8:{
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
			case 9:{
				printf("\n Thank you! Have Good Day....");
				return 1;
			}
			default:{
				printf("wrong input");
				break;
			}
		}

=======
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


void add_question(char* exam, char *u_id){
	struct QUESTION* q = malloc(sizeof(struct QUESTION*));


	q->id=generate_Id("questions.csv");
	//printf("%d",id);
	char *topic3=disp_topics1(u_id);
	printf("%s",topic3);
	int x=0;
	getchar();
	do{
		printf("\nEnter the question: ");
		gets(q->question);
		x=notempty(q->question);
	}while(x==0);
	
	//fputs(QUESTIONs, fPtr);
	//fputs(q->question, fPtr);

	char op1[30];
	do{
		printf("\nEnter the first option - A. ");
		gets(op1);
		x=notempty(op1);
	}while(x==0);
	//fgets(q->option1, length, stdin);
	//fputs(O1, fPtr);
	//fputs(q->option1, fPtr);
	char op2[30];
	do{
		printf("\nEnter the second option - B. ");
		gets(op2);
		x=notempty(op2);
	}while(x==0);
	do{
		printf("\nEnter the third option - C. ");
		gets(q->option3);
		x=notempty(q->option3);
	}while(x==0);
	do{
		printf("\nEnter the fourth option - D. ");
		gets(q->option4);
		x=notempty(q->option4);
	}while(x==0);
	printf("\nEnter the letter of the correct answer (1, 2, 3 or 4): ");
	scanf("%s",q->ans);
		
	
	FILE *qtn;
	qtn = fopen("questions.csv","a");
	if(qtn==NULL){
		printf("Exam cannot be found \n");
		exit(EXIT_FAILURE);
	}
	else{
		//printf("%d,%s,%s,%s,%s,%s,%s,%s,%s",q->id,topic3,q->question,op1,op2,q->option3,q->option4,q->ans,"0");
		fprintf(qtn,"%d,%s,%s,%s,%s,%s,%s,%s,%s\n",q->id,topic3,q->question,op1,op2,q->option3,q->option4,q->ans,"0");
		printf("\nQuestion added successfully \n" );
		fclose(qtn);
	}
} 



void create_prof_profile()
{
	char id[13];
	char f_name[50];
	char l_name[50];
	char age[5];
	char address1[45];
	char address2[45];
	char phonenumber[20];
	char gender[10];
	char email[100];
	char dept[100];
	char uni[100];
	int x=0;
    char ch;
    int num;
    getchar();
    int id1=generate_Id("user_Profile.csv");
	sprintf(id,"%d",id1);
    do{
        printf("Enter the first name of Professor\n");
        gets(f_name);
        x=notempty(f_name);
    }while(x==0);
    x=0;
    do{
        printf("Enter the Last name of Professor\n");
        gets(l_name);
        x=notempty(l_name);
    }while(x==0);
    x=0;
    printf("Enter the age of Professor\n");
    scanf("%s",age);
    getchar();
    do{
        printf("Enter house/apartment number and street\n");
        gets(address1);
        x=notempty(address1);
    }while(x==0);
    x=0;
    do{
        printf("\nEnter city and country\n");
        gets(address2);
        x=notempty(address2);
    }while(x==0);
    x=0;
    do{
        printf("Enter Phone number\n");
        scanf("%s",phonenumber);
        x=valid_phone(phonenumber);
    } while(x==0);
    x=0;
    do{
        printf("\nEnter gender Male , Female or Others\n");
        scanf("%s",gender);
        if (strcasecmp(gender,"Male")==0 || strcasecmp(gender,"Female")==0 || strcasecmp(gender,"Female")==0){
            x=1;
            break;
        }
    } while(x==0);
    x=0;
    do{
        printf("Enter email\n");
        scanf("%s",email);
        x=valid_email(email);
    }while(x==0);
    x=0;
    do{
        printf("Enter the department of Professor\n");
        gets(dept);
        x=notempty(dept);
    }while(x==0);
    x=0;

    do{
        printf("Enter the designation of Professor\n");
        gets(uni);
        x=notempty(uni);
    }while(x==0); 
	FILE * fPtr = fopen("user_profiles.csv","a"); 
   
	
    if(fPtr == NULL)
    {
    	printf("unable to create file. \n");
    	exit(EXIT_FAILURE);
    } 
	else{
		fprintf(fPtr,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s \n",id,f_name,l_name,age,address1,address2,phonenumber,gender,email,dept,uni,"Professor");
		printf("\nAccount created and saved successfully \n" );
	}
	fclose(fPtr);
}







