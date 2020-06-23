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
#include<windows.h>

#include<string.h>

#ifdef WINDOWS
    #include "..\include\validation.h"
	#include "..\include\profile_creation.h"
	#include "..\include\user_maintainance.h"
	#include "..\include\student.h"
#else
    #include "../include/validation.h"
	#include "../include/profile_creation.h"
	#include "../include/user_maintainance.h"
	#include "../include/student.h"
#endif


 #define ASSERT_TEST(x)                        \
    {                                         \
        if (x)                                \
        {                                     \
            printf("\n\nPASSED\n\n\n");               \
        }                                     \
        else                                  \
        {                                     \
            printf("\n\nFAILED\n\n\n"); \
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
	
	
	printf("*********************************TEST 4 for add_question***************************************\n");
printf("***********************************TEST 1A*****************************************************\n");
printf("We are first going to input an exitsing u_id and exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
printf("Expected result: successful message which identicates the question has been created ans saved successfully.\n");
add_question("Java", 4);
printf("***********************************TEST 4B*****************************************************\n");
printf("We are first going to input an exitsing u_id and exam topic. We are going to add a question, four options, two characters representing the correct answer.\n");
printf("Expected result: keep asking for correct answer until it gets only one character, then a successful message which identicates the question has been created ans saved successfully shall appear.\n");
add_question("Java", 4);
printf("***********************************TEST 4C*****************************************************\n");
printf("We are first going to input an non exitsing u_id and non existing exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
printf("Expected result: error message.\n");
add_question("Python", 8);
printf("***********************************TEST 4D*****************************************************\n");
printf("We are first going to input an exitsing u_id and non existing exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
printf("Expected result: error message.\n");
add_question("Python", 4);
printf("***********************************TEST 4E*****************************************************\n");
printf("We are first going to input an non exitsing u_id and existing exam topic. We are going to add a question, four options, one character representing the correct answer.\n");
printf("Expected result: error message.\n");
add_question("C", 7);




printf("*********************************TEST 5 for mark_questions_and_display_results***************************************\n");
printf("***********************************TEST 5A*****************************************************\n");
printf("We are first going to input an exitsing u_id, an existing topic and an existing stu_id. \n");
printf("Expected result: Result of student with id 2 in exam Java.\n");
mark_questions_and_display_results(2, "Java", 4);
printf("***********************************TEST 5B*****************************************************\n");
printf("We are first going to input a exitsing u_id, an existing topic and a non existing stu_id. \n");
printf("Expected result: error message.\n");
mark_questions_and_display_results(2, "Java", 9);
printf("***********************************TEST 5C*****************************************************\n");
printf("We are first going to input an exitsing u_id, a non existing topic and an existing stu_id. \n");
printf("Expected result: error message.\n");
mark_questions_and_display_results(2, "HTML", 4);
printf("***********************************TEST 5D*****************************************************\n");
printf("We are first going to input a non exitsing u_id, a non existing topic and an existing stu_id. \n");
printf("Expected result: error message.\n");
mark_questions_and_display_results(3, "MatLab", 4);
printf("***********************************TEST 5E*****************************************************\n");
printf("We are first going to input a non exitsing u_id, a non existing topic and a non existing stu_id. \n");
printf("Expected result: error message.\n");
mark_questions_and_display_results(1, "HTML", 5);
		
    	
    	

		
}
