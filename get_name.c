#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_name.h"
/* -The program ask for input of 30 strings of names, every name is in a length of max 20 characters and the program check if they    identical. If the user input an exist name, there will be a massge on the screen that will ask for a unique name. 
   -The unique names will be present on the screen after the user input 30 unique names. 
   -The program will generate 10 random names from the 30 name and present them on the screen with a massage.
*/

char names[NUM_OF_NAMES][LENTH_NAME]; /*global array of strings*/

void fillnames() /*function that fill the array, check if not identical and finaly present the valid names of the screen*/
{
  int i;
  char name[LENTH_NAME]; /*an aray to store the potential name before checking*/
  printf("please insert 30 names,\n");
  printf("after each name press Enter\n");
  
  for(i=0; i<NUM_OF_NAMES; i++) /*loop for filling the array of strings*/
  {
    int j;
    scanf("%s",name); /*input a name from the user*/
    for(j=i-1; j>=0; j--) /*loop for checking if the input name is not identical*/
    {
        if(strcmp(name,names[j])==0) /*check if the two strings name are identcal*/
        {
         printf("The name exist, Please insert another name\n"); /*print a massage for the user to input a valid name*/
         i=i-1;  /*return to the right index and break the loop*/
         break;
        }     
    } 

    if(j==-1)  /*the name is unique, so it can store in the array*/
          *strcpy(names[i],name);  
  }

  printf("The names are:\n"); /*Present the valid names from the array*/
  for(i=0; i<NUM_OF_NAMES; i++)
  {
    printf("%s\n",names[i]);
    
  }
  
}

const char * get_name() /*The function that return a random name from the strings array 'names'*/
{

  return names[rand() %NUM_OF_NAMES];

}

int main() /*The main function call the functions in the required order*/
{
  int i;
  fillnames();

  printf("The 10 random names are:\n"); /*call 10 times to the get name function and print the random names in order*/
  for(i=1; i<=10; i++) 
  {
  printf("the name number %d is: %s\n",i,get_name());
  }

  return 0;
} 











