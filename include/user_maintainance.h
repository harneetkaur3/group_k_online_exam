/** @file user_maintainance.h
*/


#ifndef user_maintainance_H
#define user_maintainance_H

/**  @brief Function prototypes to login in professor/student account
 *
 *  
 * This function is used to login in professor/student account
 * 
 *
 */
char* login(char*, char*);


 /**  @brief Function prototypes to edit professor profile
 *
 *  
 * This function is used to edit professor profile
 * 
 *
 */
char* editProfile(char*);


 /**  @brief Function prototypes to change the current password
 *
 *  
 * This function is used to change the current password
 * 
 *
 */

char* changePassword(char *,char *,char *);




 /**  @brief Function prototypes to get the recode from the file
 *
 *  
 * This function is used to get the recode from the file
 * 
 *
 */

void getrow(char *, char *, char *);

#endif
