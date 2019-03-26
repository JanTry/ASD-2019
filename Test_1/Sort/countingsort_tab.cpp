#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

int key(int tab[], int i){
    return tab[i];
}

void counting_sort(int tab[], int n, int k){
    int cnt[k+1]={0};
    int tmp[n];
    for(int i=0;i<n;i++)cnt[key(tab,i)]++;
    for(int i=1;i<k;i++)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)tmp[cnt[key(tab,i)]-1]=tab[i];
    for(int i=0;i<n;i++)tab[i]=tmp[i];
}

int main(){

}
