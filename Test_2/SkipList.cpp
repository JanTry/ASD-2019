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

void print(SkipList* List){ //dodaj 1 dodaj 2 dodaj 3 dodaj 4 dodaj 5 dodaj 6 dodaj 7 dodaj 8 dodaj 9 dodaj 10
    SLNode* tmp=List->first;
    if(List->first->next[1]==List->last)cout<<endl<<endl<<endl;
    else tmp=tmp->next[1];
    while(tmp->next[1]!=List->last){cout<<tmp->value<<"   "<<tmp->level<<endl; tmp=tmp->next[1];}
    cout<<endl<<endl;
}


int main(){

    string a=" ";
    SkipList* List=init();
    int p;
    while(true){
        cin>>a;
        if(a=="dodaj"){cin>>p; add(p,List); cout<<"Pomyslnie dodano"<<endl<<endl<<endl;}
        else if(a=="wypisz")print(List);
    }
}
