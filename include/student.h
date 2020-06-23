/** @file student.h
*/





#ifndef student_H
#define student_H

/**  @brief Function prototypes to view student menu
 *
 *  
 * This function is used to view student menu
 * 
 *
 */
int student(char*);


 /**  @brief Function prototypes to raise a request form exam
 *
 *  
 * This function is used to raise a request for exam
 * 
 *
 */

char* raiseTestRequest(char *, int);

 /**  @brief Function prototypes to check whether the user approved or not
 *
 *  
 * This function is used to check whether the user approved or not
 * 
 *
 */

int check_req_status(char *, char *);

#endif
