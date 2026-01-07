#include<stdio.h>
#include<stdlib.h>
#define LEN  sizeof(struct student) 

int n;



struct student
{
    long num;
    float score;
    struct student * next;
};

struct student * insert(struct student *head, struct student *stud);
struct student * creat(void);
void print(struct student *head);
struct student * del(struct student *head, long num);

struct student *create()
{
    struct student *p;
    struct student *head=NULL;
    p=(struct student *)malloc(LEN);
    scanf("%ld,%f",&p->num,&p->score);
    while (p->num!=0)
    {
        head=insert(head,p);
        p=(struct student *)malloc(LEN);
        scanf("%ld,%f",&p->num,&p->score);
        n++;
    }
    free(p);
    return head;
}

void print(struct student*head)
{
    struct student *p;
    if(head == NULL)
        printf("\n该链表为一个空链表\n");
    else
    {
    	printf("\n现在有%d组数据:\n",n);
        p=head;
        do
        {
            printf("%ld,%.2f\n",p->num,p->score);
            p=p->next;
        } while (p!=NULL);
    }
}

struct student * del(struct student *head,long num)
{
    struct student *p1,*p2;
    p1 = head;
    if(head == NULL)
    {
        printf("空链表\n");
        return head;
    }
    while (num != p1->num && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num==p1->num)
    {
        if(p1==head)
        {
            head=p1->next;
        }
        else
        {
            p2->next=p1->next;
        }
        printf("Deleted:%ld\n",num);
        free(p1);
        n--;
        if(n==0)
        	return NULL;
        return head;
    }
    if(num != p1->num)
    {
    	printf("没有要删除的节点\n");
	}
    return head;
}

struct student * insert(struct student *head,struct student *stud)
{
    struct student *p0 = stud;
    struct student *p1 = head;
    struct student *p2;
    if(head==NULL)
    {
        head = p0;
        p0->next=NULL;
    }
    else
    {
        while(p0->num>p1->num && p1->next!=NULL)
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num>p1->num)
        {
            p1->next=p0;
            p0->next=NULL;
        }
        else
        {
            if(p1==head)
            {
                head=p0;
            }
            else
            {
                p2->next=p0;
            }
            p0->next=p1;
        }
    }
    return head;
}

int main()
{
    struct student *head,*p;
    long del_num;
    int choice;
    printf("*****创建清单*****\n");
    printf("请输入记录:(0,0)以退出\n");
    head=create();
    print(head);
    do
    {
        printf("\n1.  INSERT\t2. DELETE \t0. EXIT\n");
        choice=-1;
        printf("请输入选择:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                    printf("请输入学号和分数:");
                    p=(struct student *) malloc(LEN);
                    scanf("%ld,%f",&p->num,&p->score);
                    head=insert(head,p);
                    n++;
                    printf("Inserted:%ld\n",p->num);
                    print(head);
                    break;
            case 2:
                    printf("请输入学号:");
                    scanf("%ld",&del_num);
                    head=del(head,del_num);
                    print(head);
                    break;
            case 0:
                    break;
            default:
                    printf("输入错误，重新输入\n");
                    while(getchar()!='\n');
        }
    } while (choice != 0);
    return 0;
}
