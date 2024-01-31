#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
int i, j, R, C;
int min=10, max=1000;
int *matrix;
int *sum_C, *sum_R;
// Here we generate our numbers up to 1000 and check if they are even numbers
int number_generator()
{
    srand(time(NULL));  
    for(j=0; j< R*C; j++)
    {   
        matrix[j]= (rand()%max);
        
        if (matrix[j]<10)
        {
            matrix[j]=10;
            
        }
        if(matrix[j]%2!=0)
        {
            matrix[j]= matrix[j]+1;
        }
    }
    // Here we check our numbers are unique if not we add 2 until they are if we pass the maximum it goes back to min and adds 2 until the number is unique
    for(j=0; j< R*C; j++)
    {
        for (i=0; i <= R*C; i++)
        {
            if(i!=j)
            {
                if(matrix[j]==matrix[i])
                {
                    matrix[j] = matrix[j]+2;
                    if(matrix[j]>max)
                    {
                        matrix[j]=min;
                    }
                } 
            }  
        }
    }
    return 0;
}
// Here we are adding all the columns and storing in sum_C
void calcfunc_C()
{
    for(i=0; i<C; i++)
    {   
        sum_C[i]=0;
        for(j=0; j<R; j++)
        {   
            sum_C[i]+= matrix[j*C+i];
        }
    }
}
// Here we are adding all the rows and storing in sum_R
void calcfunc_R()
{
    for(i=0; i<R; i++)
    {
        sum_R[i]=0;
        for(j=0; j<C; j++)
        {
            sum_R[i] += matrix[i*C+j];
        }
    }
}
//Here we print all our results
void Printfunc ()
{
    //Printing the matrix all the collumns have a tab every row prints a new line
    printf("\nMatrix: \n");
    for(j=0; j< R; j++)
    {
        for (i=0; i < C; i++)
        {
            printf("%d\t",matrix[j*C+i]);
        }
        printf("\n");
    }
    // Here we are printing sum of each row with every sum from the new line
    printf("\n Sum of each row:\n");
    for (i=0; i < R; i++)
    {
        printf("%d\n",sum_R[i]);
    }
    // Here we print the sum of columns every sum has a tab inbetween
    printf("\n Sum of each column:\n");
    for (i=0; i < C; i++)
    {
        printf("%d\t",sum_C[i]);
    }
}

// Here we initialize our program and give our matrix a scope as well call out to all functions in succession
void main ()
{
    //Here we ask for an input and check if entered number is biger then zero and an integer
    Head:
    printf("\nPlease enter number of rows R: ");
    if((scanf(" %d", &R)==0)||R<=0)
    {
        printf("\nWrong format enter please enter an integer 1 and higher");
        while ((getchar()) != '\n');
        goto Head;
    }
    Wrong:
    printf("\nPlease enter number of columns C: ");
    if((scanf(" %d", &C)==0)||C<=0)
    {
        printf("\nWrong format enter please enter an integer 1 and higher");
        while ((getchar()) != '\n');
        goto Wrong;
    }
    matrix = (int*) malloc (sizeof(int*)* (R*C));
    sum_C = (int*)malloc(C * sizeof(int));
    sum_R = (int*)malloc(R * sizeof(int));
    number_generator();
    calcfunc_R();
    calcfunc_C();
    Printfunc();
}
