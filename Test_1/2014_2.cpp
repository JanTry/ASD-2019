#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

struct node{
    node* next;
    int val;
};
struct TwoLists{
    node* even;
    node* odd;
};

void add(node*&element,node*&head){
    node* temp=element->next;
    element->next=head;
    head=element;
    element=temp;
}


TwoLists split(node* List){
    TwoLists head;
    head.odd=NULL;
    head.even=NULL;
    while(List!=NULL){
        if((List->val)%2==0)add(List,head.even);
        else add(List,head.odd);
    }
    return head;
}




int main(){

}
