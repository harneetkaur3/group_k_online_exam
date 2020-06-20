#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#include<ctype.h>



int generate_Id(char *f_name)
{
	char buffer[1024] ;
    char *record,*line;
	FILE *rqsts;
	int max=0;
	int i=0;
	rqsts = fopen(f_name,"r");
	if(rqsts == NULL){
    	printf("Unable to open a file. \n");
    	exit(EXIT_FAILURE);
    }
	else{
		while((line=fgets(buffer,sizeof(buffer),rqsts))!=NULL){
			record = strtok(line,";");
			while(record != NULL){
				char *ptr=strtok(record,",");
				int t=atoi(ptr);
				if(t>max){
					max=t;
				}
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				ptr = strtok(NULL, ",");
				record = strtok(NULL,";");
			}
			++i; 
			
		}
	}
	return (max+1);
}



/**
* \brief Removes the extra spacing
*
* It will delete or trim the extra space in the array of characters by calling this function
*
* @param[in] char *s Array of Character Pointer, pointing to the character of size char
*
* \return User_Type: Pointer to the array of character
*
*/
char *rtrim(char *s){
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}


/**
* \brief Validating that string is empty or not
*
* Given string by the user is validated that it is empty or not
*
* @param[in] char num[] Array of characters given by the user
*
* \return User_Type: 0: For Error of the invalid character
* 					  1: Positive case for valid character
*
*/
int notempty(char num[] ){
    if(strlen(num)<=1){
        printf("Invalid value\n");
        return 0;
    }
    return 1;
}

/**
* \brief Validating the given string
*
* Given string by the user is validated that email is having with '@' and '.'
*
* @param[in] char test[] Array of characters given by the user
*
* \return User_Type: 0: For Error of the invalid email
* 					  1: Positive case for valid email
*
*/
int valid_email(char test[]){
    int     i;
    char    *pos1, *pos2;
    char    *ch;
    while (1){
        for (i = 0, ch = test; *ch; *ch++){
            if (*ch == '@'){
                pos1 = ch;  /*stores last @ address*/
                i++;
            }
        }
        pos2 = ch;
        /* If there is only one "@" */
        if (i == 1){
            while (pos1 - test && ch - pos1 > 1) {
                /* From the end of string to "." has to be atleast 2 chars */
                if ((pos2 - ch) > 2 && *ch == '.') {
                    return 1;
                }
                ch--;
            }
        }
        printf("Email wrong!\n");
        return 0;
    } /* End while */
    return 1;
}

/**
* \brief Validating the Phone number
*
* Validating the given array of character that it is of length 10
* If not of length 10, gives an invalid message
*
* @param[in] char phone[] Array of character pointers
*
* \return User_Type: 0: For Error of the invalid phone number
* 					  1: Positive case the valid phone number
*/


int valid_phone(char phone[]){
    if(strlen(phone)!=10){
        printf("Invalid phone number\n");
        return 0;
    }else{
        int i;
        for(i=0; i<strlen(phone);i++){
            if(isalpha(phone[i]) != 0){
                printf("Invalid phone number\n");
                return 0;
            }
        }
        return 1;
    }
}

