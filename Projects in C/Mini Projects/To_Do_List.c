#include <stdio.h>
#include <string.h>
#define MAX 50

char tasks[MAX][100];
int count=0;

void addTask(){
    if(count<MAX){
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[count++]);
        printf("Task added successfully!\n");
    } else printf("Task limit reached!\n");
}

void displayTasks(){
    if(count==0){ printf("No tasks to display.\n"); return; }
    printf("\n--- To-Do List ---\n");
    for(int i=0;i<count;i++) printf("%d. %s\n", i+1, tasks[i]);
    printf("Total tasks: %d\n", count);
}

void deleteTask(){
    if(count==0){ printf("No tasks to delete.\n"); return; }
    int t; displayTasks();
    printf("Enter task number to delete: ");
    scanf("%d",&t);
    if(t<1 || t>count){ printf("Invalid number!\n"); return; }
    for(int i=t-1;i<count-1;i++) strcpy(tasks[i], tasks[i+1]);
    count--;
    printf("Task deleted successfully!\n");
}

int main(){
    int choice;
    printf("=== Advanced To-Do List Manager ===\n");
    do{
        printf("\n1. Add Task\n2. Display Tasks\n3. Delete Task\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: deleteTask(); break;
            case 4: printf("Thank you for using To-Do List Manager. Goodbye!\n"); break;
            default: printf("Invalid choice! Select 1-4.\n");
        }
    }while(choice!=4);
    return 0;
}
