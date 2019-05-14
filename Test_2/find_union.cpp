#include <iostream>

using namespace std;

struct Set{
    Set* parent=NULL;
    int value;
    int Size=1;
};

Set* init(int value){
  Set* tmp=new Set;
  tmp->value=value;
  return tmp;
}

Set* Find(Set* Element){
    Set* tmp=Element;
    while(tmp->parent!=NULL)tmp=tmp->parent;
    return tmp;
}

Set* Union(Set* First, Set* Second){
    Set* tmp1=Find(First);
    Set* tmp2=Find(Second);
    if(tmp1->Size<=tmp2->Size){
        tmp1->parent=tmp2;
        tmp2->Size+=tmp1->Size;
        return tmp2;
    }
    tmp2->parent=tmp1;
    tmp1->Size+=tmp2->Size;
    return tmp1;
}

int main(){

}
