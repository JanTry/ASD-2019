#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

struct node{
    node* next;
    double val;
};

void change_n_sort(node* first, node* &second){
    node* tmp=second;
    while(tmp!=NULL && tmp->val<first->val)tmp=tmp->next;
    node* tmp2=first;
    first=first->next;
    tmp2->next=tmp->next;
    tmp->next=tmp2;
    if(tmp->next==second)second=tmp;
}

void join(node* List, node* buckets[], int i){
    node*tmp;
    node*actual=List;
    for(int j=0;j<i-1;j++){
        tmp=buckets[j];
        actual->next=tmp;
        if(tmp!=NULL){
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            actual=tmp;
        }
    }
    actual->next=NULL;
}

void Sort(node* List){
    int i;
    node* tmp=List->next;
    for(i=0;tmp!=NULL;i++)tmp=tmp->next;
    i=i/2;
    node* buckets[i];
    tmp=List;
    while(tmp->next!=NULL){
        change_n_sort(tmp->next,buckets[(int)(tmp->next->val*i)]);
    }
    join(List,buckets,i);
}

int main(){

}
