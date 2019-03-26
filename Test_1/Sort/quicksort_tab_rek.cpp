#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

int Partition(int tab[], int left, int right){
    int j=left;
    for(int i=left;i<right;i++)
        if(tab[i]<tab[right])swap(tab[i],tab[j++]);
    swap(tab[right],tab[j]);
    return j;
}

void quicksort(int tab[], int left, int right){
    if(left<right){
        int q=Partition(tab,left,right);
        quicksort(tab,left,q-1);
        quicksort(tab,q+1,right);
    }
}

int main(){

}
