#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

struct node{
    node* next;
    node* val;
};

void move_to(node* &from, node* &to){
    node* temp=from;
    from=from->next;
    temp->next=to;
    to=temp;
}

void Partition(node* &head, node* &head2){
    node* head1=NULL;
    node* key=head;
    head=head->next;
    while(head!=NULL)
        if(head<key->val) move_to(head, head1);
        else move_to(head, head2);
    move_to(key,head1);
    head=head1;
}

void Quicksort(node* &head){
    if(head!=NULL){
        node* head2=NULL;
        Partition(head, head2);
        Quicksort(head);
        Quicksort(head2);
        node*temp=head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=head2;
    }
}



int main(){

}
