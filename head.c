/******************************************************************************
 * Truc Nguyen
 * This project is to write a version of "head" command in Linux/Unix.
 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  SIZE 100

void display(FILE* file, char *option, char* name, int num);

char *file[SIZE];
int j = 0;

int main(int argc, char *argv[])
{
    char *c, *s;
    int num = 0;
    char *option, *filename;
    FILE* fileF;

    /* 
     * First check argc:
     * * argc == 3 : user only input head and textfile name. This is easy case.
     * * argc > 3  : program will check what is the last called command,
     *   and work on that.
     */ 
    if(argc == 3)  
    {
        if( (fileF = fopen(argv[2], "r")) != NULL)
        {
            option = argv[1];
            display(fileF, option, filename, num);
            fclose(fileF);
        }
        else
        {
            printf("Error Opening Fils..");
        }
    }
    else
    {
    for(int i = 1; i < argc; i++)
    {
      // Check if argv[i] is a command or not
      c = strchr(argv[i], '-');
      //argv[i] is a command.
        if(c != NULL)
        {
            option = argv[i];
        }
	//argv[i] is not a command, check if argv[i] is a text file.
        else if(c == NULL)
        {
            c = strstr(argv[i], ".txt");
            if(c != NULL)
            {
                if(j == argc)
                {
                    break;
                }
                else
                {
                filename = argv[i];
                file[j] = filename;
                j++;
                }
                
            }
	    // argv[i] is not a file. Assume user input correctly, it wil
	    // a number for command
            else if(c == NULL)
            {
                c = strstr(argv[i], "head");
                if(c != NULL)
                {
                    option = argv[i];
                }
                else if(c == NULL)
                    num = atoi(argv[i]);
            }
        }
    }
    }
    printf("This is the last num: %d\n", num);
    printf("This is the last command: %s\n", option);

    for(int k = 0; k < argc; k++)
    {
        if(file[k] != NULL)
        {
            fileF = fopen(file[k], "r");
            filename = file[k];
            display(fileF,option,filename,num);
            fclose(fileF);
        }
    }
    
    return 0;
}




/******************************************************
    void display(FILE* file, char *option, char *name, int num);
    Function will take input: file to read from, option of command from users,
   a string name of file and number N(if any).
    * -n N : N is a positive number. Print the first N lines of file.
    * -c N : N is a positive number. Print the first N bytes of file.
    * -v N : Print the filename header and the content of the file. 
    * -q   : Function will never print filename header. 
 ******************************************************/
void display(FILE *fileS, char *option, char *name, int num)
{
    char *line = NULL;
    char c;
    size_t len = 0;
    int count = 0;
    char *arr;
    int i = 0;

    //If option is not -q, system will print teh file name.
    if(strcmp(option,"-q"))
    {
        printf("====>%s<=====\n",name);
    }
    
    // -c N : N is a positive number. Print the first N bytes of file.
    if(strcmp(option, "-c") == 0)
    {
        while( (c = fgetc(fileS)) != EOF)
        {
            if(count < num)
            {
                printf("%c",c);
            }
            count++;
        }
    }
    // Read file into *str
    while(getline(&line,&len,fileS) != EOF)
    {
        if(strcmp(option,"head") == 0)
        {
            if(count == 10)
                break;
            printf("%s",line); 
            count++;
        }
        // -n N : N is a positive number. Print the first N lines of file.
        else if(strcmp(option,"-n") == 0)
        {
            if(count == num)
                break;
            printf("%s",line); 
            count++;
        }
        else if(strcmp(option, "-q") == 0)
        {
            printf("%s",line);
        }
    
        //-v N : Print the filename header and the content of the file.
        else if(strcmp(option,"-v") == 0)
        {
            printf("%s",line);
        }
        
    }
}









