#include<stdio.h>
#include<stdlib.h>
#include "mylib.h"
#include<string.h>
int main(int argc, char* argv)
{
        printf("\nQ1:\n");
        struct Result *result=malloc(sizeof(struct Result));
        printf("Enter the Number to be reversed:\n");
        int n,d;
        scanf("%d",&n);
        printf("Enter the digit to be counted\n");
        scanf("%d",&d);
        result=myCount(n,d);
        printf("reverse of %d : %d\n",n,result->reversen);
        printf("count : %d\n",result->count);
        free(result);

        ////////////////////////////////////////////////////

        printf("\nQ2:\n");
        printf("Enter the string to be reversed\n");
        const char *str=(char*)malloc(100*sizeof(char));
        scanf(" %[^\n]s",str);
        //printf("%s\n",str);
        char *rstr;
        rstr=myReverse(str);
        printf("Reversed string : %s\n",rstr);

        return 0;
}

