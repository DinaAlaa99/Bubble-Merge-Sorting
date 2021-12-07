#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 100


struct student
{
    int id;
    char name[20];

};

struct student s[SIZE];

struct student fillStudent();
void printStudent(struct student s);
int printMenu();
void checkchoice(int choice,int count);
void BubbleSort(int count);
void MergeSort (int low,int high);
void Merge(int low, int middle, int high);
int BinarySearch(int id,int LB,int UB);
void printaftersorting(int count);


int main()
{
    int choice;
    int flag=1;
    int count,i;


    printf("Please Enter number of students:");
    scanf("%d",&count);

    for (i=0; i<count ; i++)
    {
        s[i]=fillStudent();
    }
    system("cls");

    printf("Students before Sorting\n");
    for (i=0; i<count ; i++)
    {
        printStudent(s[i]);
    }

    while (flag)
    {
        choice= printMenu();
        checkchoice(choice,count);

    }
    return 0;
}
struct student fillStudent()
{
    struct student s;


    printf("Please Enter Student ID:\n");
    scanf("%d",&s.id);

    printf("Please Enter Studet Name:\n");
    scanf("%s",s.name);


    return s;

}
void printStudent(struct student s)
{

    printf("\nstudent id : %d \n",s.id);
    printf("student name : %s \n",s.name);

}
int printMenu()
{
    int choice;


    printf("\n****** MENU ******\n");
    printf("\n1.Bubble Sort by id\n");
    printf("\n2.Merge Sort by name\n");
    printf("\n3.Binary Search by id\n");
    printf("\n4.exit\n");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);

    if (choice <1 || choice > 4)
    {
        printf("\nPlease Enter Valid Number\n");
    }
    return choice;
}
void checkchoice(int choice,int count)
{

    int flag;
    int id,location;


    switch(choice)

    {
    case 1:

    {

        BubbleSort(count);
        system("cls");
        printf("Students after Sorting by id\n");
        printaftersorting(count);

    }

    break;

    case 2:

    {

        MergeSort(0,count-1);
        system("cls");
        printf("Students after Sorting by name\n");
        printaftersorting(count);

    }

    break;
    case 3:
        system("cls");
        printf("enter the id you want to search about:\n");
        scanf("%d",&id);
        BubbleSort(count);
        location=BinarySearch(id,0,count-1);
        if(location!=-1)
        {
            printf("the information of id %d \n",id);
            printStudent(s[location]);
        }

        else
            printf("id %d Not found",id);
        break;


    case 4:

        exit(0);

        break;



    }

}
void BubbleSort(int count)
{
    int i,j,swapped;
    struct student temp;

    for(i=0; i<count; i++)
    {
        swapped=0;
        for(j=0; j<count-1-i; j++)
        {
            if(s[j].id>s[j+1].id)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                swapped=1;
            }
        }
    }
}
void MergeSort (int low,int high)
{
    int mid;


    if(low<high)
    {
        mid=(high+low)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }

}
Merge(int low, int middle, int high)
{
    int L1,L2,i;
    struct student temp[SIZE];
    L1=low;
    L2=middle+1;
    i=low;
    int flag;



    while (L1 <=middle && L2<=high)
    {
        flag = strcmp(s[L1].name,s[L2].name);
        if (flag<0) //name1<name2
        {
            temp[i]=s[L1];
            L1++;
            i++;
        }
        else //name1>name2 or equal
        {
            temp[i]=s[L2];
            L2++;
            i++;
        }
    }
    while (L1 <= middle)
    {
        temp[i]=s[L1];
        i++;
        L1++;
    }
    while (L2 <= high)
    {
        temp[i]=s[L2];
        i++;
        L2++;
    }
    for (i=low ; i<=high; i++)
    {
        s[i]=temp[i];
    }



}
int BinarySearch(int id,int LB,int UB)
{
    int location,mid;
    location=-1;

    while(LB<=UB && location ==-1)
    {
        mid =(UB+LB)/2;
        if (s[mid].id==id)
            location=mid;
        else if (s[mid].id<id)
            LB=mid+1;
        else
            UB=mid-1;
    }
    return location;
}
void printaftersorting(int count)
{
    int i;

    for (i=0; i<count; i++)
        printStudent(s[i]);
}
