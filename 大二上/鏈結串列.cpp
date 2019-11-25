#include<stdio.h>
#include<stdlib.h>

struct listNode {
 int data;
 listNode *link;
};

struct MyStack {
 listNode *top;
 void Push(int data); 	//利用 malloc()跟記憶體要空間並加入堆疊中
 int Pop();        		//從堆疊中得到一筆資料，並利用 free()函數將空間還給記憶體。
 bool IsEmpty();   		//堆疊是否為空，堆疊為空回傳 true，堆疊不為空回傳 false
 						//當 top 指標指向 NULL 的時候為空
 bool IsFull();    		//堆疊是否為滿，堆疊為滿回傳 true，堆疊不為滿回傳 false
 				   		//當與記憶體要空間( malloc() )卻得不到空間的時候為滿
 				   		//當呼叫 malloc()回傳為 NULL 時，則為要空間失敗
 void show(MyStack);
 MyStack() {    		//撰寫建構子，代表產生 MyStack 物件時，Stack 為空的。
  top = NULL;
 }
};

int main() {
 MyStack s;
 int option,num;

 printf("1.Push\n");
 printf("2.Pop\n");
 printf("3.IsEmpty\n");
 printf("4.IsFull\n");
 printf("5.Exit\n");

 printf("=======================\n");

 s.show(s);

 printf("=======================\n");
 printf ("option:\n");
 while (scanf(" %d",&option)!=EOF) {
  switch (option) {
   case 1:
    printf ("請輸入要放入堆疊的數字:");
    scanf (" %d",&num);
    s.Push(num);
    s.show(s);
    break;
   case 2:
    //num=s.Pop();
    if (s.IsEmpty()==0){
     printf ("%d已彈出\n",num);
    }
    s.show(s);
    break;
   case 3:
    if (s.IsEmpty()==0){
     printf ("堆疊不為空\n");
    }
    else {
     printf ("堆疊為空\n");
    }
    break;
   case 4:
    if (s.IsFull()==1){
     printf ("空間已滿\n");
    }
    else {
     printf ("仍有空間\n");
    }
    break;
   case 5:
    return 0;
    break;
   default:
    break;
  }
  printf ("\noption:\n");
 }
 return 0;
}

//======Stack===================================================================
bool MyStack::IsEmpty() {
 if (top==NULL)
  return true;
 else
  return false;
}

bool MyStack::IsFull() {
 if(malloc(sizeof(listNode))==NULL)
  return true;
 else
  return false;
}

void MyStack::Push(int data) {
 listNode* newnode;

 if(IsFull()!=true) {
  newnode = (listNode*) malloc(sizeof(listNode));
  newnode->data = data;
  newnode->link = top;
  top = newnode;
 } else {
  printf("Stack is Full!!\n");
 }
}

int MyStack::Pop() {
 listNode *popdata=top;
 int data;
 if(IsEmpty()!=true) {
  top = top->link;
  data=popdata->data;
  free (popdata);
  return data;
 } else {
  printf("Stack is Empty!!\n");
  return 0;
 }
}

void MyStack::show(MyStack s){
 printf ("Show:");
 if (s.IsEmpty()==1){
  printf ("NULL");
 }
 while (s.IsEmpty()==0){
  printf ("%d ",s.Pop());
 }
 printf ("\n");
}