#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mylib.h"
struct Result *myCount(int n,int d)
{
        struct Result *result=malloc(sizeof(struct Result));
        int nr=n;
        while(n!=0)
        {
                result->reversen=result->reversen*10;
                result->reversen=result->reversen+n%10;
                if(n%10==d)result->count++;
                n=n/10;
        }
        result->reversen=-result->reversen;
        return result;
}

char* myReverse(const char *str)
{
        char *rstr=(char*)malloc(sizeof(str));
        int i;
        for(i=0;i<strlen(str);i++)
        {
        if(str[i]>96 && str[i]<124)
                rstr[strlen(str)-i-1]=str[i]-32;
        else if(str[i]>64 && str[i]<91)
                rstr[strlen(str)-i-1]=str[i]+32;
        else
                rstr[strlen(str)-i-1]=str[i];
        }

        return rstr;
}


