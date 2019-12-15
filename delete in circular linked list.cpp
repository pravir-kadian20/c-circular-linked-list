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

node *getnode(node *head,int data){
    node *temp=head;
    while(temp->next!=head){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){
        return temp;
    }
    else{
        return NULL;
    }
}

void deletenode(node *&head,int data){
    node *del=getnode(head,data);
    node *temp=head;
    if(del==NULL){
        cout << "node not present" << endl;
        return;
    }
    else if(del==head){
        while(temp->next!=head){
            temp=temp->next;
        }
        head = del->next;
        temp->next=head;
        delete del;
    }
    else{
        while(temp->next!=del){
            temp=temp->next;
        }
        temp->next=del->next;
        delete del;
    }
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
    deletenode(head,4);
    print(head);
}
