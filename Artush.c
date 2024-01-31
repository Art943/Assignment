#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main (void){
    int array[10];
    int a;
srand(time(NULL));
for (int i=0; i < sizeof(array)/sizeof(int); i++){
    
    array[i]= (rand()%10);
    printf("%d", array[i]);
}

for (int i=0; i < sizeof(array)/4-1; i++){
    for (int j=i+1; j <sizeof(array)/4 ; j++){
    if(array[i]>array[j]){
        a= array[i];
        array[i]=array[j];
        array[j]=a;
    }
    }
    
}
printf("\n");
for (int i=0; i < sizeof(array)/4; i++){
    printf("%d", array[i]);
}



   /*char i;
   char b;
 printf("                Player 1\n");
printf("Please enter s for stone, x for scisors, y for papper\n");
scanf(" %c", &i);
printf("                Player 2\n");
printf("Please enter s for stone, x for scisors, y for papper\n");
scanf(" %c", &b);

if (i==b){
    
    printf("New game\n");
}
else if(i=='s' && b=='x' || i=='x' && b=='y' || i=='y' && b=='s'){
   printf("Player 1 is the WINNER!!!!\n");
   
}
else if (b=='s' && i=='x' || b=='x' && i=='y' || b=='y' && i=='s'){
    printf("Player 2 is the WINNER!!!!\n");
   
}*/
    
}