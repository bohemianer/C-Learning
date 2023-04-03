#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void singleBrute_match(char* char1,char* char2)
{
    int lenChar1 = strlen(char1);
    int lenChar2 = strlen(char2);
    int maxlen = fmax(lenChar1,lenChar2);
    
    if(maxlen = lenChar1)
    {
        for(int i=0;i<maxlen;i++)
        {
            if(char1[i] == char2[0])
            {
                for(int j=0;j<lenChar2;j++)
                {
                    if(char1[i+j] == char2[j])
                    {
                        printf("Matched at %d char1 is %c char2 is %c\n",i+j+1,char1[i+j],char2[j]);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                
                }
            //printf("Matched at %d \n",i+1);
            }
        }

    }
   
    else
    { 
        for(int i=0;i<maxlen;i++)
        {
            if(char2[i] == char1[0])
            {
                for(int j=0;j<lenChar1+1;j++)
                {
                    if(char2[i+j] == char1[j])
                    {
                        printf("Matched at %d\n",i+j+1);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                
                } 
            //printf("Matched at %d \n",i+1);
            }
        }
    }

}
 

// void stringBrute_match()
// {


// }

int main()
{
    char char1[] = "Hello World";
    char char2[] = "World";
    singleBrute_match(char1,char2);

}