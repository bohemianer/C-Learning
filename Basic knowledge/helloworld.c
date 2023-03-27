#include<stdio.h>

int var[] = {1,2,3,4,5,6,7,8,9};
int size = sizeof(var)/sizeof(var[0]);
double avg;

double average(int *arr, int size);

int main()
{

    avg = average(var, size);
    printf("The average is %f, size is %d\n", avg, size);

}

double average(int *arr, int size)
{
    int i;
    double sum = 0;
    for(i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)(sum/size);
}