#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* myReverse(const char *str);
int main(int argc,char* argv)
{
	printf("Enter the string to be reversed\n");
	const char *str=(char*)malloc(100*sizeof(char));
	scanf("%[^\n]s",str);
	//printf("%s\n",str);
	char *rstr;
	rstr=myReverse(str);
	printf("Reversed string : %s\n",rstr);
	return 0;
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
