#include<stdio.h>

int main()
{
    int i;
    char **a=(char**)malloc(sizeof(char*)*4);
    //(a+1)=(char*)malloc(sizeof(char)*20);
    //(a+2)=(char*)malloc(sizeof(char)*20);
    //(a+3)=(char*)NULL;
   for(i=0;i<4;i++){
    a[i]=(char*)malloc(sizeof(char)*20);
       //(*(a+i+0))=i;
       (*(a+i+0))="hi";
       printf("%x,",(a+i+0));
       printf("%s\n",*(a+i+0));
   }
}
