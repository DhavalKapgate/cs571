#include<stdio.h>
#include<stdlib.h>

struct Result
{
        int reversen;
        unsigned short count;
}result;

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
int main(int argc, char* argv)
{
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
        return 0;
}


