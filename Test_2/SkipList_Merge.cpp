#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;

struct SLNode{
    int value;
    int level;
    SLNode** next;
};

struct SkipList{
    SLNode* first;
    SLNode* last;
};

const int MAX_LEVEL= 10;

SkipList* init(){
    SkipList* List=new SkipList;
    List->first=new SLNode;
    List->last=new SLNode;
    List->first->level=MAX_LEVEL;
    List->last->level=MAX_LEVEL;
    List->first->next=new SLNode*[MAX_LEVEL+1];
    for(int i=1;i<=MAX_LEVEL;i++)List->first->next[i]=List->last;
    return List;
}

int get_level(){
    int i=1;
    srand( time( NULL ) );
    while(true){
    if(rand()%2==1)i++;
    else return min(i,MAX_LEVEL);
    }
}

void add(int value, SkipList* List){
    SLNode* element=new SLNode;
    element->value=value;
    element->level=get_level();
    element->next=new SLNode*[element->level+1];
    SLNode* tmp=List->first;
    int level=element->level;
    while(level>0){
            if(tmp->next[level]!=List->last && tmp->next[level]->value<value)
            tmp=tmp->next[level];
            else {
                    element->next[level]=tmp->next[level];
                    tmp->next[level--]=element;
            }
    }
}

SkipList* Merge(SkipList* first, SkipList* second){
    int i=MAX_LEVEL;
    SkipList* List=init();
    SLNode* tmp=List->first;
    while(i>0){
            while(first->first->next[i]!=first->last && second->first->next[i]!=second->last){
                if(first->first->next[i]->value<second->first->next[i]->value){
                    tmp->next[i]=first->first->next[i];
                    first->first->next[i]=first->first->next[i]->next[i];
                    tmp->next[i]->next[i]=List->last;
                }
                else{
                    tmp->next[i]=second->first->next[i];
                    second->first->next[i]=second->first->next[i]->next[i];
                    tmp->next[i]->next[i]=List->last;
                }
            }
            while(first->first->next[i]!=first->last){
                tmp->next[i]=first->first->next[i];
                first->first->next[i]=first->first->next[i]->next[i];
                tmp->next[i]->next[i]=List->last;
            }
            while(second->first->next[i]!=second->last){
                tmp->next[i]=second->first->next[i];
                second->first->next[i]=second->first->next[i]->next[i];
                tmp->next[i]->next[i]=List->last;
            }
            tmp->next[i]->next[i]=List->last;
            i--;
        }
    return List;
}


void print(SkipList* List){ //dodaj1 1 dodaj1 2 dodaj2 3 dodaj2 4 dodaj1 5 dodaj2 6 dodaj1 7 dodaj2 8 dodaj2 9 dodaj2 10
    SLNode* tmp=List->first;
    if(List->first->next[1]==List->last)cout<<endl<<endl<<endl;
    else tmp=tmp->next[1];
    while(tmp->next[1]!=List->last){cout<<tmp->value<<"   "<<tmp->level<<endl; tmp=tmp->next[1];}
    cout<<tmp->value<<"   "<<tmp->level<<endl;
    cout<<endl<<endl;
}


int main(){

    string a=" ";
    SkipList* List1=init();
    SkipList* List2=init();
    int p;
    while(true){
        cin>>a;
        if(a=="dodaj1"){cin>>p; add(p,List1); cout<<"Pomyslnie dodano"<<endl<<endl<<endl;}
        else if(a=="dodaj2"){cin>>p; add(p,List2); cout<<"Pomyslnie dodano"<<endl<<endl<<endl;}
        else if(a=="wypisz1")print(List1);
        else if(a=="wypisz2")print(List2);
        else if(a=="merge")List1=Merge(List1,List2);
    }
}
