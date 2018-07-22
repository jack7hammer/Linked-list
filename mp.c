#include<stdio.h>  // program is limited to positive numbers and two of  the numbers should have same number of digits ( u can enter zeroes if u want to multiply a lesser digit number)
#include<malloc.h>
#include<string.h>

struct node{            // WE are taking 2 data linked list where data1 stores digits of first numbers and data 2 stores digits of second numbers
int data1,data2;
struct node *next,*prev;
};

void create(struct node **start,int a,char ch){  // the blah blah part but we are considering two LLs so im sending two start pointers
struct node *newnode,*p;
newnode=(struct node*)malloc(sizeof(struct node));

if(a==1){
        int d=ch-48;//since im converting it from a char ...so -48
newnode->data1=d;
newnode->data2=0;}
if(a==3) //case for creating a empty linked list basically by feeding it 0 as data (our resultant LL)
{
    newnode->data1=0;
}

newnode->next=NULL;
if(*start==NULL){
    *start=newnode;
    newnode->prev=NULL;
}
else{p=*start;
while(p->next!=NULL){p=p->next;}
p->next=newnode;
newnode->prev=p;
newnode->next=NULL;}  }

void multiply(struct node **start1,struct node **start2){
struct node *p1,*p2,*q,*temp,*r; // two pointers for two numbers and one for the resultant LL
r=*start2;
int carry=0;
p1=*start1;q=*start2;p2=*start1;
while(p1->next!=NULL){
    p1=p1->next;    // take both to end and use two for loops to multiply in pen and paper method
     p2=p2->next;
}
for(;p2!=NULL;p2=p2->prev,r=r->next)
    {
       carry=0;
        for(q=r;p1!=NULL;q=q->next,p1=p1->prev){
                        (q->data1)+=((p1->data1)*(p2->data2)+carry)%10;
                         temp=q;
                        while((q->data1)>9){
                                (q->next->data1)+=(q->data1)/10;      //this solves the problem when a carry was created
                                 (q->data1)%=10;
                                 q=q->next;
                               }
                        carry=((p1->data1)*(p2->data2)+carry)/10;
                         q=temp;
               }
q->data1+=carry;
p1=*start1;
    while(p1->next!=NULL){p1=p1->next;}
}
}

void disp(struct node **start)  // this is to display the result LL backwards
{
 struct node *p;
 p=*start;
 while(p->next!=NULL)
        p=p->next;

while(p->data1==0&&p->prev!=NULL){   //this is to ensure that we dont print any 0s which are at the beginning of the result say 00045 ..we print 45 only
p=p->prev;}
if(p->prev==NULL) //if the answer is 0
    printf("0");
else{
 while(p!=NULL)
 {
     printf("%d",p->data1);
     p=p->prev;
 }
}
}

main(){
    int i,l1,l2,j;
    char string[100]; //we take our input here
struct node *start1=NULL,*start2=NULL,*p; //two LLs .start1 is our link list for the both input numbers and start2 is the LL for result
printf("Enter your first number");
scanf("%s",&string);
l1=strlen(string);
for(i=0;string[i]!='\0';i++)
    create(&start1,1,string[i]);
printf("Enter your second number");
scanf("%s",&string);
l2=strlen(string);

for(p=start1,i=0;p!=NULL||string[i]!='\0';p=p->next,i++)
    p->data2=string[i]-48;

for(i=0;i<l1+l2;i++)
    create(&start2,3,string[0]);

multiply(&start1,&start2);

disp(&start2);

}
