//SIMPLE TO-DO LIST Using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<graphics.h>

//Macro
#define MAX 50

int count =0;

//functions
void welcome();
void header();
void add_Task();
void display(int no);
void completeTask();
void modifyTask();
void choice();
void delay(int mili_sec);

//Linked Lisst node
struct node {
    char data[MAX];
    int done;
    struct node* next;
};
struct node* head = NULL;

//main function
int main(){
	system("Color DF");
	welcome();
	return 0;
}

//welcome fuction
void welcome(){
	char choice;
	system("cls");
	header();
    while (1) {
    printf("\n\n\t\t\t\t\t-----> 1. Add Task\n");
    printf("\t\t\t\t\t-----> 2. View Tasks\n");
    printf("\t\t\t\t\t-----> 3. Complete Task\n");
    printf("\t\t\t\t\t-----> 4. Modify Task\n");
    printf("\t\t\t\t\t-----> 5. Set Priority\n");
    printf("\t\t\t\t\t-----> 6. Exit\n\n\t\t\t\t\t");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    printf("\n");
    switch (choice) {
        case '1':
                add_Task();
            break;
        case '2':
                display(1);
            break;
        case '3':
                completeTask();
            break;
            case '4':
                modifyTask();
            break;
            case '5':
//                setPriority();
            break;
        case '6':
            printf("Thanks for using\nExiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
    }
	}
}

//header function
void header(){
	printf("\t\t\t\t");
	for(int i=1;i<20;i++){
		printf("*");
		if(count==0)
			delay(1);
	}
	for(int i=1;i<20;i++){
		printf("-");
		if(count==0)
			delay(1);
	}
	for(int i=1;i<20;i++){
		printf("*");
		if(count==0)
			delay(1);
	}
	printf("\n\n\t\t\t\t\t-----------WELCOME to TO-DO LIST---------\t\t\n\t\t\t\t\t\t\t\t\t\n\t\t\t\t");
		for(int i=1;i<20;i++){
		printf("*");
		if(count==0)
			delay(1);
	}
	for(int i=1;i<20;i++){
		printf("-");
		if(count==0)
			delay(1);
	}
	for(int i=1;i<20;i++){
		printf("*");
		if(count==0){
			delay(1);
			count++;
		}
	}
}

//create Node function
struct node* createNode(char data[]) {
    
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data, data);
    ptr->next = NULL;
    return ptr;
    
}

//add_Task Function
void add_Task() {
		system("cls");
		header();
		printf("\n\n\t\t\t\t----->Enter task :  ");
    char data[MAX];
    scanf("%s",data);
    struct node* ptr = createNode(data);

    if (head == NULL) {
        head = ptr;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("\n\t\t\t\t");
		for(int i=0;i<3;i++){
			printf(".");
			delay(1);
		}
    printf(" Task Added\n");
    choice();
}

//view task function
void display(int no) {
	system("cls");
	header();
    int i=1;
    struct node* temp = head;
    if(head==NULL)
    	printf("\n\n\t\t\t\t\t\t  \4\4\4\4Nothing TO-DO\4\4\4\4\n");
    	printf("\n\n");
    while (temp != NULL) {
        printf("\t\t\t\t\t%d. [%c] %s\n",i,temp->done?'X':' ',temp->data);
        i++;
        temp = temp->next;
    }
    if(no==1)
    	choice();
}

//complete task function
void completeTask(){
	if(head==NULL){
			system("cls");
			header();
    	printf("\n\n\t\t\t\t\t\t\4\4\4\4No task to complete\4\4\4\4\n");
    	choice();
  }
	display(3);
	printf("\n\t\t\t\t\tEnter number to mark task as completed\n\t\t\t\t\t");
	int choose;
	struct node *temp=head;
	scanf("%d",&choose);
	while(temp!=NULL){
		if(choose-1==0){
			temp->done=1;
			break;	
		}
		else{
			choose--;
			temp=temp->next;
		}
	}
	printf("\n\t\t\t\t\t\4\4\4Task Completed\4\4\4\n");
	choice();
}

//modify function
void modifyTask(){
	if(head==NULL){
			system("cls");
			header();
    	printf("\n\n\t\t\t\t\t\t\4\4\4\4No task to modify\4\4\4\4\n");
    	choice();
  }
	display(3);
	printf("\n\t\t\t\t\tEnter task number to modify\n\t\t\t\t\t");
	int choose;
	struct node *temp=head;
	scanf("%d",&choose);
	while(temp!=NULL){
		if(choose-1==0){
			printf("\n\t\t\t\tEnter the task : ");
			scanf("%s",temp->data);
			break;	
		}
		else{
			choose--;
			temp=temp->next;
		}
	}
	printf("\n\t\t\t\t\t\4\4\4Task Modified\4\4\4\n");
	choice();
}

//chioce fuction
void choice(){
	start:
    printf("\n\t\t\t\tPress 1 for menu\n\t\t\t\t");
    int n;
    scanf("%d",&n);
    if(n==1)
    	welcome();
    else
    	goto start;
}

//FUNCTION FOR DELAY
void delay(int mili_sec)
{
	int sec,start_time;
	sec = 100*mili_sec;
	start_time = clock();
	while(clock()<start_time+sec){
	}
}
