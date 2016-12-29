#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int carry=0;
char *charMul(char *n1, char *n2);
int carry_adjust(int *res,int len);
/////////////////////////////////////////////////////////////////
int main(int argc,char *argv[])
{
    char *arr1,*arr2;
    int i;
    arr1=malloc(100*sizeof(char));
    arr2=malloc(100*sizeof(char));
    printf("Enter first number\n");
    scanf("%s",arr1);
    printf("Enter second number\n");
    scanf("%s",arr2);
    char *res;
    res=calloc(200,sizeof(char));
    res=charMul(arr1,arr2);
    printf("RESULT:\n");
    for(i=0;i<strlen(arr1)+strlen(arr2)-1;i++)
        printf("%d ",res[i]);
    printf("\n");
	return 0;
}
//////////////////////////////////////////////////////////////
int carry_adjust(int result[],int len)
{
    int i,cary=0;
    for(i=len;i>=0;i--)
        if(result[i]>9)
        {
            cary=result[i]/10;
            result[i]=result[i]%10;
            result[i-1]=result[i-1]+cary;
            cary=0;
        }
    return *result;
}
////////////////////////////////////////////////////////////////
char *charMul(char *arr1, char *arr2)
{
    int temp,i,j;
    char *res1;
    res1=calloc(200,sizeof(char));
    int *res;
    res=calloc(200,sizeof(int));
    for(j=strlen(arr2)-1;j>=0;j--)
    {
        carry=0;
        for(i=strlen(arr1)-1;i>=0;i--)
        {
            temp=(arr1[i]-'0')*(arr2[j]-'0');
            res[i+j]=res[i+j]+temp%10;
            if(carry!=0)
                res[i+j]=res[i+j]+carry;
            carry=temp/10;
        }
        carry_adjust(res,strlen(arr1)+strlen(arr2)-1);
        if(carry!=0)res[0]=carry;
    }
    for(i=0;i<strlen(arr1)+strlen(arr2)-1;i++)
        res1[i]=res[i];
    return res1;
}


