#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

int key(string a, int pos){
    if(a.length()<=pos)return 0;
    return (int)(a[pos]-'a'+1);
}

int maxlength(string tab[],int n){
    int maxlen=0;
    for(int i=0;i<n;i++)if(tab[i].length()>maxlen)maxlen=tab[i].length();
    return maxlen;
}

void counting_sort(string tab[], int n, int k, int pos){ //Copied from countingsort_tab
    int cnt[k+1]={0};
    string tmp[n];
    for(int i=0;i<n;i++)cnt[key(tab[i],pos)]++;
    for(int i=1;i<k;i++)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)tmp[cnt[key(tab[i],pos)]-1]=tab[i];
    for(int i=0;i<n;i++)tab[i]=tmp[i];
}

void radix_sort(string tab[], int n, int k){
    int q=maxlength(tab,n);
    for(int i=q-1;i>=0;i--){
        counting_sort(tab,n,k,i);
    }
}

int main(){

}
