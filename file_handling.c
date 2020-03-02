#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[50];
    int roll;
    float marks;
    float price;
    char author_name[50];
} ;
int main()
{
    FILE *fptr;
    struct student *ptr;
    int i,j, noofrecords;
    printf("enter no. of records: ");
    scanf("%d", &noofrecords);
    ptr = (struct student*) malloc (noofrecords * sizeof(struct student));
    printf("Enter information of students:\n");
    fptr = fopen("data_warehouse", "a+");
    // storing information
    for(i=0; i<noofrecords; i++)
    {
        printf("Enter roll no: ");
        scanf("%d",&(ptr+i)->roll);
        fprintf(fptr, "Roll no = %d \n", (ptr+i)->roll);
        printf("Enter name: ");
        scanf("%s",(ptr+i)->name);
        fprintf(fptr, "Name = %s \n", (ptr+i)->name);
        printf("Enter Computer marks: ");
        scanf("%f",&(ptr+i)->marks);
        fprintf(fptr, "Marks = %.2f \n", (ptr+i)->marks);
        printf("Enter Book price: ");
        scanf("%f",&(ptr+i)->price);
        fprintf(fptr, "Price = %.2f \n", (ptr+i)->price);
        printf("Enter author name: ");
        scanf("%s",(ptr+i)->author_name);
        fprintf(fptr, "Author name = %s \n", (ptr+i)->author_name);
        printf("\n");
        printf("\n");
    }
    fclose(fptr);
    return 0;
}
