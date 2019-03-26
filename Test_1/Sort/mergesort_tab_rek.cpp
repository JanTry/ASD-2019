#include <iostream>
#include <cmath>

using namespace std;

const int N=100;


void Merge(int tab[], int left, int middle, int right){
    int j=left, p=middle;
    int tmp[right+1];
    int i;
    for(i=left; i<right && j<middle && p<=right; i++){
        if(tab[j]<=tab[p])tmp[i]=tab[j++];
        else tmp[i]=tab[p++];
    }
    while(j<middle)tmp[i++]=tab[j++];
    while(p<=right)tmp[i++]=tab[p++];
    for(i=left;i<=right;i++)tab[i]=tmp[i];
}

void Mergesort(int tab[], int left, int right){
    if(left<right){
        int middle=(left+right)/2;
        Mergesort(tab, left, middle-1);
        Mergesort(tab, middle, right);
        Merge(tab, left, middle, right);
    }
}



int main(){

}
