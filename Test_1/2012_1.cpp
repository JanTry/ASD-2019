#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

struct node{
node* next;
int val;
};

void Add(node* &element, node* &head){
    node* temp=head;
    head=element;
    element=element->next;
    head->next=temp;
}

node* join(node* first, node* second, node* third){
    node *temp;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=second;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=third;
}

node* Partition(node* &head, node* &first, node* &second, node* &third){
    if(head==NULL)return head;
    node* key=head;
    head=head->next;
    key->next=NULL;
    while(head!=NULL)
        if(head->val<key->val)Add(head, first);
        else if(head->val>key->val)Add(head, third);
            else Add(head, second);
    Add(key,second);
}


node* quickersort(node* head){
    node* first=NULL;
    node* second=NULL;
    node* third=NULL;
    Partition(head, first, second, third);
    quickersort(first);
    quickersort(third);
    return join(first,second,third);
}

int main(){

}
