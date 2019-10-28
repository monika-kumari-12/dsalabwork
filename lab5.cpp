#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

struct node
{
    int id;
    char name[20];
    int sem;
    struct node *next;
};

void clrscr(void)
{
    system("clear");
}
void list_display(struct node *);
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return (p);
}

struct node *freenode(struct node *p)
{
    free(p);
    p = NULL;
}

struct node *insert(struct node *list)
{
    struct node *p, *q;
    int i, pos, ch, id, sem;
    char name[20];

    clrscr();

    p = getnode();

    printf("\n***INSERTION MENU***\n");
    printf("\n1.Insert At The Beginning");
    printf("\n2.Insert at the End");
    printf("\n3.Insert At The Specified Position");
    printf("\nEnter Your Choice:");
    scanf("%d", &ch);

    p = getnode();

    printf("\nEnter (Student ID \\Student Name \\ Semester):");
    scanf("%d%s%d", &id, name, &sem);

    p->id = id;
    strcpy(p->name, name);
    p->sem = sem;
    p->next = NULL;

    switch (ch)
    {

    case 1:
        if (list == NULL)
            list = p;

        else
        {
            p->next = list;
            list = p;
        }
        break;

    case 2:
        q = list;

        while (q->next != NULL)
            q = q->next;

        q->next = p;

        break;

    case 3:
        printf("Enter the Position: ");
        scanf("%d", &pos);

        q = list;

        for (i = 1; i < pos - 1; i++)
            q = q->next;

        p->next = q->next;
        q->next = p;

        break;

    default:
        printf("Invalid Choice!");
    }

    return (list);
}

struct node *deletee(struct node *list)
{
    struct node *p, *q;
    int ch, ids;

    clrscr();

    printf("Enter the Student ID: ");
    scanf("%d", &ids);

    if (list == NULL) /* Empty List */
        printf("List Underflow!");

    else if (list->id == ids) /* If the ID is in */
    {                         /* the first node  */
        p = list;
        list = list->next;
        p->next = NULL;
        free(p);
    }

    else /* Searches in the */
    {    /* remaining nodes */
        p = list;
        q = list->next;

        while (q != NULL && q->id != ids)
        {
            p = q;
            q = q->next;
        }

        if (q->next == NULL && q->id == ids) /* If ID is in   */
        {                                    /* the last node */
            p->next = NULL;
            free(q);
        }

        else if (q->id == ids) /*   If ID is   */
        {                      /*    found     */
            p->next = q->next;
            q->next = NULL;
            free(q);
        }
        else
            printf("Node not present ");
    }
    return (list);
}

int search_list(struct node *list)
{

    int sem1, no, ch3;
    char a[20];

    printf("\nEnter the Student ID: ");
    scanf("%d", &no);

    while (list != NULL)
    {
        if (list->id == no)
        {
            printf("\nStudent ID: %d", list->id);
            printf("\nName: %s", list->name);
            printf("\nSemester: %d", list->sem);
            break;
        }

        else

            list = list->next;
    }

    if (list == NULL)
        printf("\nStudent Record not Present!");

    getchar();
}

void display(struct node *list)
{
    printf("Student ID\tName\tSemester\n");

    while (list != NULL)
    {
        printf("%d\t\t", list->id);
        printf("%s\t", list->name);
        printf("%d\n", list->sem);
        list = list->next;
    }

    getchar();
}

int main()
{
    int choice;
    int count = 0;
    struct node *list = NULL;

    while (1)
    {

        clrscr();
        printf("***MAIN MENU***\n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Search \n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit   \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            list = insert(list);
            count++;
            break;

        case 2:
            deletee(list);
            count--;
            break;

        case 3:
            search_list(list);
            getchar();
            break;

        case 4:
            display(list);
            getchar();
            break;

        case 5:
            printf("count of students are %d\n", count);

        case 6:
            exit(1);

        default:
            printf("Invalid Choice!");
            getchar();

            return 0;
        }
    }
}
