#include <stdio.h>
#include <string.h>
#include <time.h>
void main(void){
   /* int arr[3][3]={0};
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
        scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    //exercise 19:
    char word[15]={0};
    int i=0;
    getchar("%s",word);
    do{
if(word[i]!=' ')
{
    printf("%c", word[i]);
    i++;
    }else{
        printf("\n");
        i++;
    }
    
    }while(i != strlen(word));*/

    //exercise 20/24
    int Y;
    int M;
    int D;
    int H;
    int m;
    int S;
    printf(" Please enter year xxxx, month 1-12, date 1-31, hours 0-23, minutes 0-59, seconds 0-59:\n");

scanf("%d %d %d %d %d %d", &Y, &M, &D, &H, &m, &S);
if (Y>9999 || Y<0){
    printf("wrong Year format!! please write with 4 digits: xxxx\n");
}else if(M>13 || M<0){
    printf("Wrong month format please choose between 1-12!! \n");
}else if ((M== 1 || M== 3 || M== 5 || M== 7 || M== 8 || M== 10 || M== 12) && D>32 || D<0 ||
(M== 4 || M== 6 || M== 9 || M== 11) && D>31 || D<0 || M== 2 && D>30 || D<0)
{if(Y % 100){
    printf(" Leap year please input the date 1-29!!\n");
}else if(Y % 4) {
    printf(" Leap year please input the date 1-29!!\n");
}
}else if (0>m>60){
    printf("incorrect minute format \n");
}else if (0>S>60){
    printf("Incorrect second format \n");
}else{
    printf("%04d year %02d month %02d day %02d hour %02d minutes %02d seconds", Y, M, D, H, m, S);
}
}