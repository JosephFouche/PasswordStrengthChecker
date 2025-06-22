
/*creates a c program that evaluates the strength of a password based on criteria like length, charectaer types
, and entropy. Programa provides feedback if password is weak, medioum or strong */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[100];
    printf("Enter password: ");
    fgets(password, sizeof(password),stdin);
    password[strcspn(password, "\n")]=0;//remove newline

    int len = strlen(password), has_upper =0, has_lower =0, has_digit =0, has_special =0;

    for(int i=0; i<len; i++) {
        if(isupper(password[i])) has_upper =1;
        else if (islower(password[i])) has_lower=1;
        else if (isdigit(password[i])) has_digit=1;
        else has_special =1;


    }

    if(len<8 || !has_upper || !has_lower || !has_digit || !has_special){

        printf("Weak password.Use >8 chars, mix of upper, lower, digits, and special. \n");
    } else{
        printf("Strong password! \n");
    }
    return 0;
    }


