#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
int array[10]={0};
int max=0;
int a= (sizeof(array)/sizeof(int));
 
int number_generator(){

    srand(time(NULL));  
for (int i=0; i < sizeof(array)/sizeof(int); i++){
    
    array[i]= (rand()%99);
}
return 0;
}
int find_max(){
    for(int i=0; i < sizeof(array)/sizeof(int); i++){
        if(max<array[i]){
           max= array[i];
        }
    }
    return 0;
}
float average(){
    int sum_a =0;
    for(int i=0; i < sizeof(array)/sizeof(int); i++){
        sum_a += array[i]; 
    }
    return ((float)sum_a/a);
}
int find_B(){
int B = 0;
    printf("Please enter a number between 0 and 99:");
    scanf("%d",&B);
    for(int i=0; i < sizeof(array)/sizeof(int); i++){
        if(B == array[i])
        {
            B = i;
            }
    else {
        B = -1;
    }}
return B;
}
void print_result(void){
for (int i=0; i < sizeof(array)/sizeof(int); i++){
    
    printf("%d\n", array[i]);
    
}
    printf("Maximum: %d\n", max);
    printf("Avarage %f\n", average());
    printf("Found the digit in array: %d", find_B());
}
 void main (void){
    number_generator();
    find_max();
    average();
    print_result();
 }
 
 
 // E-26
 typedef struct 
    {
        int age;
        float hight;
        char name[16];
    }person_t;
    
 int *get_person(){
    person_t a, b, c;
    printf("skriv ålder längd och namn\n");
    
    scanf("%d %f %s", &(a.age), &(b.hight), (c.name));
    printf("Ålder: %d\n Längd %f\n Namn: %s\n", (a.age) , (b.hight), (c.name));
    return 0;
 }
  int main(){
*get_person();
return 0;
 }*/

 // E-28
 int compare_s(){
    char S[10]={0};
    char V[10]={0};
    int res;
    printf("Please enter a word: \n");
    fgets(S,20, stdin);
    printf("Please enter the second word: \n");
    fgets(V,20,stdin);
    for(int i=0; i<strlen(S)||i<strlen(V); i++)
    {if (S[i] == V[i]){
        res=1;
    }else {
        res=0;
    }}
return res;
 }
 void main(void){
    printf("%d\n", compare_s());
 }