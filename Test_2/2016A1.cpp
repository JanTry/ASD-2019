#include <iostream>

using namespace std;

struct HuntingList {
HuntingList* next; // nastêpny element listy
int predator; // numer pokemona, który poluje
int prey; //numer pokemona na którego poluje
};
struct node{
node* next;
int n;
};

struct Pokemon{ //Struktura na pokemony (!)
bool released; //Czy zwolniony
bool passive; //Czy pokemon jest spokojny
node* pred; //lista tych ktore na niego poluja
int w=0; //ile jego ofiar juz zwolniono
};

void Add_list(node* List, int n){ //Proste dodawanie do listy jednokierunkowej
node *p=new node;
p->n=n;
p->next=List;
List=p;
}

void releasePred(Pokemon* pok,int* release, int &j, int n){ //Tutaj jest glowny sens rozwiazania
    //if(pok[n].released)return; sprawdzamy to przed kazdym wywolaniem
    if(pok[n].w<2)return; //Jak nie ma uwolnionych 2 jego ofiar to nie mozemy go uwolnic, wiec wracamy (!)
    release[j++]=n; //Jesli tu dotarlismy, to uwalniamy skurczybyka
    pok[n].released=true;
    node* tmp=pok[n].pred; //I podobnie jak w uwalnianiu spokojnych lecimy po tych co na niego poluja
    while(tmp!=NULL){
        if(!pok[tmp->n].released){
            pok[tmp->n].w++; //zwiekszamy ich liczniki uwolnionych ofiar
            releasePred(pok, release, j, tmp->n); // I probujemy je uwolnic (!)
        }
        tmp=tmp->next;
    }
}

int* releaseThemALL( HuntingList* List, int n){
    Pokemon pok[n]; //tworzymy liste pokemonow (!)
    for(int i=0;i<n;i++){pok[i].released=false; pok[i].passive=true;} //Na poczatek pokemony nie sa wypuszczone i sa spokojne
    HuntingList *tmp=List;
    while(tmp!=NULL){ //przelatujemy po HuntingList
        pok[tmp->predator].passive=false; //Jak znajdziemy ze ten pokemon na kogos poluje to stwierdzamy ze nie jest pasywny
        Add_list(pok[tmp->prey].pred,tmp->predator); //Dodajemy predatorow do listy danej ofiary
        tmp=tmp->next;
    }
    int release[n]; //tablica kolejnosci wypuszczania
    int j=0; //licznik po powyzszej tablicy
    for(int i=0;i<n;i++){ //wypuszczamy pasywne
        if(pok[i].passive){
            pok[i].released=true;
            release[j++]=i;
            node* temp;
            temp=pok[i].pred;
            while(tmp!=NULL){ //Zwiekszamy w o 1 kazdemu pokemonowi ktory poluje na aktualnie uwalnianego (!)
                pok[temp->n].w++;
                temp=temp->next;
            }
        }
    }
    if(j>=n-1)return release; //Jak wszystkie byly pasywne to zwracamy kolejnosc
    for(int i=0;i<n;i++)if(!pok[i].released)releasePred(pok, release,j, n); //Dla kazdego pokemona wywolujemy probe uwolnienia (!)
    if(j>=n-1)return release; //Jezeli udalo sie wszystkie uwolnic to zwracamy kolejnosc
    return NULL; //Jak sie nie udalo to NULL

}




int main(){

}
