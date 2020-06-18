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




void Create_New_Exam(void)
{
	FILE *fp;

	/* Set up a data structure to maintain the student account information */

	struct student
	{
		char student_id[50];
	};

	struct exam
	{
	  float duration;
	  char  title[50]; // same as Subject Name
	};

	struct student student_list[20]; // Students who are eligible to take the exam. Maximum of 20 students who can take the exam

		struct exam ex;
		int x=1;


	system("clear");
	fp=fopen("exam_profile.csv","a"); // open the user profile in an excel spread sheet.

	if(fp==NULL){
         printf ("Error-> The file cannot be opened\n");
	}
	else
	{

		  system("clear");
		  printf("\n ** New Exam Creation Page **\n\n");
		  printf("\n Enter Title of the Exam\n");
		  scanf("%s",ex.title);
		  printf("\n Enter Maximum Time Duration for the Exam\n");
		  scanf("%s",ex.duration);
		  fprintf(fp,"%s.%f",ex.title,ex.duration);
		  system("clear");
		  printf("\n ** Please Enter the Student IDs who are eligible to take this exam. Press 2 to exit **\n\n");
		  fclose(fp);
		  int k=0;

		  fp=fopen("student_list.csv","a"); // open the user profile in an excel spread sheet.

		  while (x!='2')
		  {
			  printf("\n Enter Student ID of the Student who can take the exam\n");
			  scanf("%s",student_list.student_id[k]);
			  fprintf(fp,"%s",student_list.student_id[k]);
			  k++;
			  printf("\n Enter 2 if you want to Exit or press 1 to enter the next student id\n");
			  scanf("%c",x);
		  }


	 }

}




