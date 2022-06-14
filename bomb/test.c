#include<stdio.h>
union test
{
    /* data */
    char s[5];
    int val;
};

int main(){
    int a=-9;
    printf("%d %d\n",a/2,(a+1)>>1);
}