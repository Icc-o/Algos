//������ķ�ת

#include <iostream>

using namespace std;

struct Node{
    Node* next;
    int num;
};

Node* construct_list(int* arr, int size)
{
    Node* head = new Node();
    Node* curNode = head;
    for(int i=0; i<size; i++)
    {
        if(!curNode)
            curNode = new Node();
        curNode->num = arr[i];
        
        if(i==size-1)
            return head;
        curNode->next = new Node();
        curNode = curNode->next;
    }
    return nullptr;
}

void destruct_list(Node* head)
{
    Node* curNode = head;
    while(curNode)
    {
        Node* n= curNode;
        curNode = curNode->next;
        delete n;
    }
}

void traverse(Node* head)
{
    Node* curNode = head;
    while(curNode)
    {
        Node* n= curNode;
        curNode = curNode->next;
        //delete n;
        cout<<"get "<<n->num<<endl;
    }
}

Node* revert_func(Node* curNode, Node* head_new)
{
    if(curNode->next)
    {
        Node* n = revert_func(curNode->next, head_new);
        cout<<"address1 "<<(head_new)<<endl;
        n->next = curNode;          //��һ���head_new��ֵ�ı���
        return curNode;
    }
    else
    {
        //cout<<"aaaaa "<<(*head)->num<<endl;
        (head_new) = curNode;
        cout<<"sssssss"<<(head_new)->num<<endl;
        cout<<"address "<<(head_new)<<endl;
        return curNode;
    }
}

Node* revert(Node* head)
{
    Node* head_new;
    revert_func(head, head_new);
    head->next = nullptr;
    cout<<"first: "<<(head_new)->num<<endl;
    cout<<"address  "<<(head_new)<<endl;
    return head_new;
}

//ѭ������
Node* revert_loop(Node* head)
{
    Node *preNode=nullptr, *curNode=head, *nextNode=head->next; 
    while(curNode)
    {
        cout<<"cur node "<<curNode->num<<endl;
        if(preNode)
        {
            curNode->next = preNode;
        }
        else
        {
            //����߽�����
            curNode->next = nullptr;
        }
        
        if(nextNode)
        {
            preNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
        }
        else
        {
            break;
        }
    }
    return curNode;
}

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    
    Node* list = construct_list(arr, 10);
    traverse(list);

    //list = revert_loop(list);
    list = revert(list);
    traverse(list);

    destruct_list(list);

    return 0;
}