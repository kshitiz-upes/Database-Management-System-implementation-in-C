#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct
{
	char* line;
	size_t input;
	ssize_t input_length;
   
}InputBuffer;

struct student
{
    char name[50];
    int roll;
    float marks;
    
};


InputBuffer* create_Buffer()
{
	InputBuffer* input_buffer=malloc(sizeof(InputBuffer));
	input_buffer->line=NULL;
	input_buffer->input=0;
	input_buffer->input_length=0;
	return input_buffer;
}
void print_prompt()
{
	printf("DBMS>");
}
void check_input(InputBuffer* input_buffer)
{
	ssize_t input_read = getline(&(input_buffer->line),&(input_buffer->input_length),stdin);
  

	if(input_read<=0)
	{
		printf("Error reading input");
		exit(EXIT_FAILURE);
	}
	input_buffer->input_length=input_read-1;
	input_buffer->line[input_read-1]=0;

}
void close_buffer(InputBuffer* input_buffer)
{
	free(input_buffer);
}
void execute_insert()
{
	 FILE *fptr;
    struct student *ptr;
    int i,j, noofrecords;
    printf("enter no. of records: ");
    scanf("%d", &noofrecords);
    ptr = (struct student*) malloc (noofrecords * sizeof(struct student));
    printf("Enter information of students:\n");
    fptr = fopen("data warehouse.json", "a+");
    // storing information
    for(i=0; i<noofrecords; i++)
    {
        printf("Enter roll no: ");
        scanf("%d",&(ptr+i)->roll);
       /* sscanf("%d","%s","%f",&(ptr+i)->roll,&(ptr+i)->name,&(ptr+i)->marks);*/
        fprintf(fptr, "Roll no = %d \n", (ptr+i)->roll);
        printf("Enter name: ");
        scanf("%s",(ptr+i)->name);
        fprintf(fptr, "Name = %s \n", (ptr+i)->name);
        printf("Enter marks: ");
        scanf("%f",&(ptr+i)->marks);
        fprintf(fptr, "Marks = %.2f \n", (ptr+i)->marks);
        
        printf("\n");
        printf("\n");
    }
    fclose(fptr);
	

}
void execute_select()
{
	printf("This is where we do select\n\n");

}
void execute_delete()
{
	printf("This is where we would do the delete operation\n\n");
}
int main()
{
	  InputBuffer* input_buffer = create_Buffer();
	  
  printf("\n\t                              MINOR PROJECT\t\n\n\t                    ACESSSING FILE SYSTEM THROUGH C\t\n\n");
  while(true)
  {
  	print_prompt();
  	check_input(input_buffer);
  	if(strcmp(input_buffer->line,".exit")==0)
  	{
  		close_buffer(input_buffer);
  		exit(EXIT_SUCCESS);
  	}
  	else if(strcmp(input_buffer->line,"insert")==0)
  	{
  		
      execute_insert();
      /*Row* a= malloc(sizeof(Row));
  		int args_assigned = sscanf(input_buffer->line,"insert %d %s %s",&(a->id),a->name,a->email);*/
      
  		

  	}
  	else if (strcmp(input_buffer->line,"select")==0)
  	{
  		execute_select();
  	}
  	else if (strcmp(input_buffer->line,"delete")==0)
  	{
  		execute_delete();
  	}
  	else
  	{
  		printf("Unrecognized command '%s'\n",input_buffer->line);
  	}

  }
  return 0;
}