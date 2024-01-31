#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[20]={0},s;
int i,j,G,D,gcd,L,M,lcm=0;
int GCD()
{
    printf("\nPlease enter two numbers to find GCD\n");
    scanf("%d %d",G,D);
    for(i=0; i<G; i++)
    {
        if (G%i==0 && D%i==0)
        {
            gcd= i;
        }
    }
    printf("\nGCD is: %d", gcd);
    return 0;
}
int LCM()
{
    printf("\nPlease enter two numbers to find LCM\n");
    scanf("%d %d",L,M);
    for(i=0; i<L*10 || i<M*10; i++)
    {
        if (i%L==0 && i%M==0 && lcm==0)
        {
            lcm= i;
        }
    }
    printf("\nLCM is %d\n",lcm);
    return 0;
}
void SAO()
{
    printf("\nPlease enter letters\n");
    scanf("%s",str);
    
    for(i=0;i<strlen(str);i++)
    {
        if(isalpha(str[i])!=0)
        {
            for(j=i+1;j<strlen(str);j++)
            {
                if(strcmp(str[i],str[j])>0)
                {
                    strcpy(s,str[i]);
                    strcpy(str[i],str[j]);
                    strcpy(str[j],s);
                }
            }
        }else
        {
            printf("\nYou entered non letter\n");
        }
    }
}
void main()
{
    GCD();
    LCM();
    SAO();
}