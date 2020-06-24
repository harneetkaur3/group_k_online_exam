/** @file professor.h
*/



#ifndef professor_H
#define professor_H

/**  @brief Function prototypes to view professor menu
 *
 *  
 * This function is used to view professor menu
 * 
 *
 */
int professor(char *);


 /**  @brief Function prototypes to add a question
 *
 *  
 * This function is used to add a question
 * 
 *
 */

char* add_question(char* , char *);


 /**  @brief Function prototypes to generate a result
 *
 *  
 * This function is used to gerate the result
 * 
 *
 */

char* mark_questions_and_display_results(char* ,char *, char *);


#endif
