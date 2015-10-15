/* 
author : Sheldon Cook 

Purpose : Creates a Dictionary of words, user  entering letters until the word is to long
          of SIZE 40 it will terminate and dump the Frequency of each word
*/




#include <cstdio>
#include <cctype>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    #define SIZE     40
    char DICT[50][20] = {'\0'};
    int row = 0;
    int numWords = 0;
    char buffer[40] = {'\0'};
    int  frequency[50] = {0};
   


    char ch;
    int newLine= 0;
    
    bool wordTooLong = false;

    while( cin.good() )
    {
        //clear buffer
        for (int i=0; i<SIZE; i++)
        {
            buffer[i] = '\0';
        }

        //put word in buffer
        for (int i=0; i<=SIZE; i++)
        {
            ch = cin.get();
            if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
            {
                buffer[i] = tolower(ch);
            }
            else
            {
                break;
            }
            if (i==SIZE)        // if a word of SIZE 40, the dictionary  dumps with a break statement;
            {
                printf("Word is too long\n");
                wordTooLong = true;
                break;
            }
        }
        
        if(wordTooLong==true) break;

        //check if word is already in dictionary
        // increment the Frequency of the word
        for (int i=0; i <= numWords; i++)
        {      
            if ( strcmp(DICT[i],buffer) ==0)
            {
                frequency[i]++;
                break;
            }
            //add Word to Dictionary
            else if (i == numWords)
            {
                for (int i=0; i<strlen(buffer); i++)
                {                    
                    DICT[numWords][i] = buffer[i]; //The Dictionary
                }
                frequency[numWords]=0;
                frequency[numWords]++;
                numWords++;    
                break;
            }
        }
    }

    //out put  of the Dictionary 
    printf ("WORD             FREQUENCY\n");
    printf ("--------------------------\n");
    
    //Dump  dictionary and frequency 
    for(int i=0; i<numWords; i++)
    {
        printf ("%-16s %9d\n", DICT[i], frequency[i]);
    }

return 0;
}


