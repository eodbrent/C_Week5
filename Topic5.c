/*menu options
create new student record
display all student records
exit

create record
Name of student
Student ID
Current average grade (A, B, C,...)
A pointer to a structure instance of the next student

needs to check if the ID already exists in the batabase before going forward.
	if it does, display a message to the user and return to the menu options.
	if it doesnt, add new record to database

avoid memory leaks, use free() when memory no longer needed.

display one line per record, Name, ID, Avg Grade, Year. then back to menu

Exit - exits DB
*/

//records MUST be as structs
	//data structure to save records is linked list
	//single .c file
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	int student_ID;
	struct Student *next;
};

typedef struct Student Student;

bool check_ID_Exist(){
	bool exist = false;
	return exist;
}

void display_Records(){
	printf("Displaying records\n");
	/*while (current != NULL){
		printf("student record data");
		current = current->next;
	}*/
}

Student *create_Record(int id_num){
	Student *record = malloc(sizeof(Student));
	record->student_ID = id_num;
	record->next = NULL;
	return record;
}

void create(){
	int id_num;
	printf("\nEnter ID number: ");
	scanf("%d", &id_num);
	create_Record(id_num);
}

void menu(){

	bool loop = true;
	int choice;
	while (loop){
		printf("\t\tWelcome to RU Record Management System\n");
		printf("\tPress\n");
		printf("\t1 to create a new Student Record\n");
		printf("\t2 to view all records\n");
		printf("\t3 to Exit\n");
		printf("\n");
		printf("Enter  your Choice\n");
		scanf("%d", &choice);
		if(choice == 1){
			create();
		} else if (choice == 2){
			display_Records();
		} else if (choice == 3){
			loop = false;
		} 
	}	
}
//https://www.learn-c.org/en/Linked_lists
int main(){
	Student *head = NULL;
	head = (struct Student*)malloc(sizeof(struct Student));
	Student *current;
	current = (struct Student*)malloc(sizeof(struct Student));
	current->next = head;
	menu();
	return 0;
}
