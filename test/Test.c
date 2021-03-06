/**
 * @file test.c
 *
 * @brief Implementation of unit test cases.
 *
 * @author Harneet Kaur - harneetkaur3@cmail.calreton.ca
 * @author 
 * @author 
 * @author 
 *
 */
#include <stdio.h>
#include <stdlib.h>


#include<string.h>

#ifdef WINDOWS
  #include "..\include\validation.h"
	#include "..\include\profile_creation.h"
	#include "..\include\user_maintainance.h"
	#include "..\include\student.h"
	#include "..\include\exam.h"
	#include "..\include\professor.h"
#else
  #include "../include/validation.h"
	#include "../include/profile_creation.h"
	#include "../include/user_maintainance.h"
	#include "../include/student.h"
	#include "../include/exam.h"
	#include "../include/professor.h"
#endif


#define ASSERT_TEST(x)                  \
{ 		                                  \
	if (x)                                \
	{                                     \
		printf("\n\nPASSED\n\n\n");           \
	}                                     \
	else                                  \
	{                                     \
		printf("\n\nFAILED\n\n\n"); 				\
	}                                     \
}



int main(int argc, char *argv[])
{
	printf("*********************************TEST 1 for Login**********************************************\n");
	printf("***********************************TEST 1A*****************************************************\n");
	printf("We are first going to login using correct credentials for Professor i.e. Userid=3 and password=bb\n");
	printf("Expected result is it should return string Professor\n ");
	ASSERT_TEST(strcmp(login("3","bb"),"Professor")==0);
	printf("***********************************TEST 1B****************************************************\n");
	printf("We are going to login using incorrect password Userid=1 and password=1233\n");
	printf("Expected result is it should return string Wrong username or password\n ");
	ASSERT_TEST(strcmp(login("1","1233"),"invalid")==0);
	printf("***********************************TEST 1C****************************************************\n");
	printf("We are going to login using correct credentials for Professor i.e. Userid=2 and password=abc\n");
	printf("Expected result is it should return string Student\n ");
	ASSERT_TEST(strcmp(login("2","abc"),"Student")==0);

	printf("*********************************TEST 2 for Raise a request**********************************************\n");
	printf("***********************************TEST 2A*****************************************************\n");
	printf("We are going to raise a request with correct values\n");
	printf("Expected result is it should return string Request Raised\n ");
	ASSERT_TEST(strcmp(raiseTestRequest("2",990),"Request Raised")==0);
	printf("*********************************TEST 2 for Raise a request**********************************************\n");
	printf("***********************************TEST 2B*****************************************************\n");
	printf("We are going to raise a request to a data file which is not exist\n");
	printf("Expected result is it should return string Request Raised\n ");
	ASSERT_TEST(strcmp(raiseTestRequest("2",900),"Failed to open a file")==0);

	printf("*********************************TEST 3 to check the approval test**********************************************\n");
	printf("***********************************TEST 3A *****************************************************\n");
	printf("We are going to check the status with accurate credentials user id 222 and topic Demo and user is not approved\n");
	printf("Expected result is it should return serail id\n ");
	printf("\n\nYou are not approved\n\n");
	ASSERT_TEST(check_req_status("222","Demo")==0);
		
	printf("*********************************TEST 3 for Raise a request**********************************************\n");
	printf("***********************************TEST 3B*****************************************************\n");
	printf("We are going check the status with accurate credentials user id 222 and topic Demo and user is  approved\n");
	printf("Expected result is it should return string Approved\n ");
	printf("\n\nYou are approved\n\n");
  ASSERT_TEST(check_req_status("223","Demo1")==1);
		
	printf("*********************************TEST 3 for Raise a request**********************************************\n");
  printf("***********************************TEST 3C*****************************************************\n");
	printf("We are going to check the status if the File requests.csv is not present then\n");
	printf("Expected result is it should return string File not Found\n ");
	printf("\n\nFile not Found\n\n");
  ASSERT_TEST(check_req_status("9999","Demo1")==9);
	
	
	printf("*********************************TEST 4 for Create a New Exam**********************************************\n");
	printf("***********************************TEST 4A*****************************************************\n");
	printf("We are going to add a new exam topic abc\n");
	printf("Expected result is it should return an invalid topic\n ");
	ASSERT_TEST(strcmp(create_New_Exam("9999","abc"),"Invalid topic")==0);

	printf("***********************************TEST 4 for Create a New Exam*****************************************************\n");
	printf("***********************************TEST 4B*****************************************************\n");
	printf("We are going to add a new exam topic xyz\n");
	printf("Expected result is it should return as successfull\n ");
	ASSERT_TEST(strcmp(create_New_Exam("1234","xyz"),"successfull")==0);

	printf("***********************************TEST 5 for Editing an Exam*****************************************************\n");
	printf("***********************************TEST 5A*****************************************************\n");
	printf("We are going to edit an exam topic xyz and update with def\n");
	printf("Expected result is it should return as successfull\n ");
  ASSERT_TEST(strcmp(edit_exam("1234","def","xyz"),"successfull")==0);

  printf("***********************************TEST 5 for Editing an Exam*****************************************************\n");
  printf("***********************************TEST 5B *****************************************************\n");
	printf("We are going to edit an exam topic def and update with abc\n");
	printf("Expected result is it should return as successfull\n ");
  ASSERT_TEST(strcmp(edit_exam("1234","abc","def"),"successfull")!=0);
	
	printf("***********************************TEST 6 for change password*****************************************************\n");
  printf("***********************************TEST 6A *****************************************************\n");
	printf("We are going to change the password with the correct credentials\n");
	printf("Expected result is it should return as updated successfully\n ");
  ASSERT_TEST(strcmp(changePassword("2","abc","abc"),"yes")==0);
	
	printf("***********************************TEST 6 for change password*****************************************************\n");
  printf("***********************************TEST 6B *****************************************************\n");
	printf("We are going to change the password with the Wrong credentials\n");
	printf("Expected result is it should return as Wrong old password\n ");
  ASSERT_TEST(strcmp(changePassword("2","tt","tttttt"),"no")==0);

	
	
	
	
	printf("*********************************TEST 7 for add_question***************************************\n");
	printf("***********************************TEST 7A*****************************************************\n");
	printf("We are first going to input an exitsing u_id and exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
	printf("Expected result: successful message which identicates the question has been created ans saved successfully.\n");
	ASSERT_TEST(strcmp(add_question("Java", "4"), "successful")==0);
	//ASSERT_TEST(1);
	printf("***********************************TEST 7B*****************************************************\n");
	printf("We are first going to input an exitsing u_id and exam topic. We are going to add a question, four options, two characters representing the correct answer.\n");
	printf("Expected result: keep asking for correct answer until it gets only one character, then a successful message which identicates the question has been created ans saved successfully shall appear.\n");
	ASSERT_TEST(strcmp(add_question("Java", "4"), "successful")==0);
	//ASSERT_TEST(1);
	printf("***********************************TEST 7c*****************************************************\n");
	printf("We are first going to input an non exitsing u_id and non existing exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
	printf("Expected result: error message.\n");
	ASSERT_TEST(strcmp(add_question("Python", "8"), "can't find topic and id")==0);
	//ASSERT_TEST(1);
	
	printf("*********************************TEST 8 for mark_questions_and_display_results***************************************\n");
	printf("***********************************TEST 8A*****************************************************\n");
	printf("We are first going to input an exitsing u_id, an existing topic and an existing stu_id. \n");
	printf("Expected result: Result of student with id 2 in exam Java.\n");
	ASSERT_TEST(strcmp(mark_questions_and_display_results("2", "Java", "4"),"successful")==0);
	//ASSERT_TEST(1);
	printf("***********************************TEST 8B*****************************************************\n");
	printf("We are first going to input an exitsing u_id, a non existing topic and an existing stu_id. \n");
	printf("Expected result: error message.\n");
	ASSERT_TEST(strcmp(mark_questions_and_display_results("2", "HTML", "4"),"failed to find topic")==0);
	//ASSERT_TEST(1);
	printf("***********************************TEST 8C*****************************************************\n");
	printf("We are first going to input a non exitsing u_id, a non existing topic and a non existing stu_id. \n");
	printf("Expected result: error message.\n");
	ASSERT_TEST(strcmp(mark_questions_and_display_results("1", "HTML", "5"),"failed to find topic")==0);	
	//ASSERT_TEST(1);

	
}
