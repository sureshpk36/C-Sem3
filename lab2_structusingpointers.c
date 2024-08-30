#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *ptr, p1;
    ptr = &p1;   

    printf("Enter age: ");
    scanf("%d", &ptr->age);

    printf("Enter weight: ");
    scanf("%f", &ptr->weight);

    printf("Age: %d", ptr->age);
    printf("weight: %f", ptr->weight);

    return 0;
}





