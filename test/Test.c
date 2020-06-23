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
		
    	
    	

		
}
