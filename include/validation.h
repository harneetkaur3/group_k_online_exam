/** @file validation.h
*/

#ifndef validation_H
#define validation_H
/**  @brief Function prototypes to validate a phone number
 *
 *
 * This function is used to validate a phone number
 *
 *
 */
int valid_phone(char[]);

/**  @brief Function prototypes to validate a email id
 *
 *
 * This function is used to validate a email id
 *
 *
 */
int valid_email(char []);

/**  @brief Function prototypes to check if given data is empty or not
 *
 *
 * This function is used to check if given data is empty or not
 *
 *
 */
int notempty(char [] );

/**  @brief Function prototypes to generate unique id for a file
 *
 *
 * This function is used to generate unique id for a file
 *
 *
 */

int generate_Id(char*);

/**  @brief Function prototypes to remove the extra spaces
 *
 *
 * This function is used to to remove the extra spaces
 *
 *
 */

char *rtrim(char*);

#endif