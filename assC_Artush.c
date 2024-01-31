#include <stdio.h>
#include <string.h>
int Y,M,D,ls,C,temp,i,wrong=0;
char a[16];
int formatcheker()
{
    printf("\n Please enter your Social Security number in the format YYMMDD-xxxx\n");
    
    fgets(a,15,stdin);

    if( (strlen(a)-1)!=11)
    {   
        printf("\nWrong format entered!");
        wrong=1;
    }
    if(a[6]!='-')
        {
            printf("\nWrong format entered!");
            wrong=1;
        }
    for(i=0; i<11; i++)
    {
        if(a[i]!='-')
        {
            if((temp = a[i])<47 || (temp = a[i])> 58)
            {
                printf("\nWrong format entered!");
                wrong=1;
            }
            if((temp = a[10])>47 || (temp = a[10])< 58)
            {
                Y = (a[0]- '0')*10+(a[1]- '0');
                M = (a[2]- '0')*10+(a[3]- '0');
                D = (a[4]- '0')*10+(a[5]- '0');
                ls = (a[7]- '0')*100+(a[8]- '0')*10+(a[9]- '0');
                C = a[10]- '0';
            }
        }
    }
    return 0;
}
int Datechecker()
{
    if (Y>99 || Y<0)
    {
        printf("\nwrong Year format! Please choose 0-99\n");
        wrong=1;
    }
    else if(M>12 || M<1)
    {
        printf("\nWrong month format please choose between 1-12!! \n");
        wrong=1;
    }
    else if ((M== 1 || M== 3 || M== 5 || M== 7 || M== 8 || M== 10 || M== 12) && D > 31 || D<1 ||
                (M== 4 || M== 6 || M== 9 || M== 11) && D>30 || D<1 || ((Y==0 || Y % 4==0) && M== 2 && D>29 || D<1) || Y % 4 !=0 && M==2 && D>28 || D<1)
                {  
                    printf("\nWrong Date format! please try again!\n");
                    wrong=1;
                }
}
int Calculator()
{
    temp = ((((Y/10)*2)/10)+(((Y/10)*2)%10)%10)+((Y%10)%10);
    temp +=((((M/10)*2)/10)+(((M/10)*2)%10)%10)+((M%10)%10);
    temp +=((((D/10)*2)/10)+(((D/10)*2)%10)%10)+((D%10)%10);
    temp +=((((ls/100)*2)/10)+(((ls/100)*2)%10)%10)+(((ls%100)%100)/10)+((((ls%10)%10)*2)/10)+((((ls%10)%10)*2)%10)%10;
    if((temp%10)==C)
    {
        printf("You have successfully entered correct SSN");
        wrong = 0;
    }
}
void main()
{
    do
    {
        formatcheker();
        Datechecker();
        Calculator();
        if((temp%10)!=C)
        {
            printf("\nInvalid Social Security Number");
        }

    } while(((temp%10)!=C)||( wrong ==1));
}
