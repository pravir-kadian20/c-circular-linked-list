#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void insertathead(node *&head,int data){
    node *n=new node(data);
    n->next=head;
    node *temp=head;
    if(head!=NULL){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
    }
    else{
        n->next=n;
    }
    head=n;
}

void print(node *&head){
    node *temp=head;
    while(temp->next!=head){
        cout << temp->data<< "->";
        temp=temp->next;
    }
    cout << temp->data << "->";
}
int main() {
    node *head=NULL;
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,1);
    insertathead(head,9);
    print(head);
}
