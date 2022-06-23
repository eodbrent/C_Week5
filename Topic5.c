#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct Student {
	char name[100];
	int student_ID;
	char avg;
	int year;
	struct Student *next;
};
typedef struct Student Student;

void freeList(Student *head){
	Student *temp;
	while (head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}

void displayrecords(Student *head){
	Student *temp = head;
	while (temp != NULL){
		printf("Name: %s ; Id: %d ; Year: %d ; Average Grade: %c \n", temp->name, temp->student_ID, temp->year, temp->avg);
		temp = temp->next;
	}
	freeList(temp);
	printf("\n");
}

bool checkrecord(Student *head, int id){
	Student *temp = head;
	while (temp != NULL){
		if(temp->student_ID == id){
			freeList(temp);
			return true;
		}
		temp = temp->next;
	}
	freeList(temp);
	return false;
}

Student *create_Record(char *name, int id, char avg, int year){
	Student *newRecord = malloc(sizeof(Student));
	strcpy(newRecord->name, name);
	newRecord->student_ID = id;
	newRecord->avg = avg;
	newRecord->year = year;
	newRecord->next = NULL;
	return newRecord;
}

void menu(){
	Student *head = NULL;
	Student *record;
	bool loop = true;
	bool recchk = true;
	char name[100];
	char temp;
	int id;
	char avg;
	int year;
	int choice;
	while (loop){
		printf("\t\tWelcome to RU Record Management System\n");
		printf("\tPress\n");
		printf("\t1 to create a new Student Record\n");
		printf("\t2 to view all records\n");
		printf("\t3 to Exit\n\n");
		printf("Enter  your Choice\n");
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter student name: ");
			scanf("%c", &temp); //clear buffer
			scanf("%[^\n]", name);
			printf("Enter student ID: ");
			scanf("%d", &id);
			recchk = checkrecord(head, id);
			if(recchk){
				while(recchk){
					recchk = checkrecord(head, id);
					if (recchk){
						printf("ID is already in system. Please enter new ID: ");
						scanf("%d", &id);
					}
				}
			}
			printf("Enter student's average grade: ");
			scanf(" %c", &avg);
			printf("Enter student's current year: ");
			scanf("%d", &year);
			record = create_Record(name, id, avg, year);
			record->next = head;
			head = record;
		} else if (choice == 2){
			displayrecords(head);
		} else if (choice == 3){
			loop = false;
		} 
	}
}

int main(){
	menu();
	return 0;
}
