#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

struct node{
    node* next;
    int val;
};

node* fixSortedList(node *L){
    node* temp=L;
    node* temp2=L;
    node* position=L;
    while(temp->next!=NULL && temp->val < temp->next->val){
        temp2=temp;
        temp=temp->next;
    }
    if(temp->next=NULL)return L;
    int val=temp->val;
    while(position->next!=NULL && position->val<=val){
        position=position->next;
    }
    temp2->next=temp->next;
    temp->next=position->next;
    position->next=temp;
    return L;
}

int main(){

}
