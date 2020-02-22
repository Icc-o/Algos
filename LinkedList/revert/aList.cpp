#include <iostream>

//双向链表反转
using namespace std;

/*typedef*/ struct Node{
    int num;
    Node* prev;
    Node* next;
} ;

//反转列表
Node* revert(Node* head)
{
    Node *curNode = head;
    Node *nextNode = nullptr;
    Node* preNode = nullptr;
    while(curNode)
    {
        cout<<"revert cur: "<<curNode->num<<endl;
        preNode = curNode->prev;
        nextNode = curNode->next;

        curNode->next = preNode;
        curNode->prev = nextNode;
        
        if(!nextNode)
            return curNode;

        curNode = nextNode;
    }
}

//构造列表
Node* construct_list(int *arr, int size)
{
    Node* head = new Node();;
    Node *preNode, *curNode;
    curNode = head;
    preNode = nullptr;
    for(uint32_t i=0; i<size; i++)
    {
        if(curNode == nullptr)
            curNode = new Node();
        curNode->num = arr[i];

        curNode->prev = preNode;
        curNode->next = nullptr;

        //第一个不能这么赋
        if(curNode->prev)
            curNode->prev->next = curNode;

        preNode = curNode;
        curNode = nullptr;
    }

    return head;
}

//释放列表内存
void desctruct_list(Node* head)
{
    Node* curNode = head;
    Node* nextNode;// = cur->next;

    while(curNode)
    {
        nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
}

//遍历链表
void traverse(Node* head)
{
    Node* curNode = head;
    Node* nextNode;// = cur->next;

    while(curNode)
    {
        nextNode = curNode->next;
        cout<<"get "<<curNode->num<<endl;
        curNode = nextNode;
    }
}

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    Node* list = construct_list(arr, 10);

    traverse(list);
    list = revert(list);
    traverse(list);

    desctruct_list(list);
    return 0;
}

