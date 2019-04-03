#include<iostream>
#include<string>
using namespace std;

int siz;

struct Data{
    string imie;
    string nazwisko;
    string adres;
};

struct element{
    int key;
    Data *dane;
    bool to_delete;
    element* next;
};


int hsh(int key){
    return ((13*key+324)%428369)%siz;
}

void insert_list(element* &first, element* elem){
    elem->next=first;
    first=elem;
}

void insert_element(int key, element* tab[], Data* dane=NULL){
    element* elem=new element;
    elem->key=key;
    elem->dane=dane;
    elem->to_delete=false;
    insert_list(tab[hsh(key)], elem);
    cout<<"Wstawiono element"<<endl;
}

void delete_element(int key, element* tab[]){
    element* tmp=tab[hsh(key)];
    while(tmp!=NULL && (tmp->key!=key || tmp->to_delete))tmp=tmp->next;
    if(tmp!=NULL){
        cout<<"Element oznaczono do usuniecia"<<endl;
        tmp->to_delete=true;
    }
    else cout<<"Nie ma takiego elementu"<<endl;
}

element* find_element(int key, element* tab[]){
    element* tmp=tab[hsh(key)];
    while(tmp!=NULL && (tmp->key!=key || tmp->to_delete))tmp=tmp->next;
    if(tmp!=NULL){
        cout<<"Znaleziono odpowiedni element"<<endl;
        return tmp;
    }
    cout<<"Nie ma takiego elementu"<<endl;
    return NULL;
}

int list_deletes(element* &first){
    int counter=0;
    element* tmp=new element;
    tmp->next=first;
    first=tmp;
    while(tmp->next!=NULL){
        if(tmp->next->to_delete){
            element* del=tmp->next;
            tmp->next=del->next;
            delete(del->dane);
            delete(del);
            counter++;
        }
        else tmp=tmp->next;
    }
    tmp=first;
    first=first->next;
    delete(tmp);
    return counter;
}

void make_deletes(element* tab[]){
    int counter=0;
    for(int i=0;i< siz;i++) counter+=list_deletes(tab[i]);
    cout<<"Usunieto "<<counter<<" elementow"<<endl;
}

void cout_tab(element* tab[]){
    cout<<"Aktualny stan tablicy: "<<endl;
    for(int i=0;i<siz;i++){
        element* tmp=tab[i];
        while(tmp!=NULL){
            if(tmp->to_delete)cout<<"*";
            cout<<tmp->key<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
}


int main(){
    cout<<"Podaj rozmiar tablicy: ";
    cin>>siz;
    element** tab=new element*[siz];
    for(int i=0;i<siz;i++){
        tab[i]=NULL;
    }
    cout<<"Tablica zostala przygotowana"<<endl;
    string polecenie;
    bool repeat=true;
    while(repeat){
        cout<<"Wybierz czynnosc: wstaw, usun, znajdz, reorganizuj, wypisz, przerwij"<<endl;
        cin>>polecenie;
        int value=-1;
        if(polecenie=="wstaw")value=0;
        else if(polecenie=="usun")value=1;
        else if(polecenie=="znajdz")value=2;
        else if(polecenie=="reorganizuj")value=3;
        else if(polecenie=="wypisz")value=4;
        else if(polecenie=="przerwij")value=5;
        switch(value)
        {
            case 0: {
                cout<<"Podaj wartosc klucza: ";
                int key;
                cin>>key;
                insert_element(key, tab);
                break;
            }
            case 1: {
                cout<<"Podaj wartosc klucza: ";
                int key;
                cin>>key;
                delete_element(key,tab);
                break;
            }
            case 2: {
                cout<<"Podaj wartosc klucza: ";
                int key;
                cin>>key;
                element* tmp=find_element(key, tab);
                break;
            }
            case 3: {
                make_deletes(tab);
                break;
            }
            case 4: {
                cout_tab(tab);
                break;
            }
            case 5: {
                repeat=false;
                break;
            }
            default: cout<<"Nie poprawne polecenie, sprobuj jeszcze raz"<<endl;
        }
    }
}
