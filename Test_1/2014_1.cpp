#include <iostream>
#include <cmath>

using namespace std;

const int N=100;
const int K=27;

int longest(string A[N]){
    int maxlen=-1;
    for(int i=0;i<N;i++)
        if(A[i].length()>maxlen)maxlen=A[i].length();
    return maxlen;
}

int value(string a, int position){
    if(position>=a.length())return 0;
    return (int)(a[position]-'a')+1;
}

void position_sort(string A[N], int position){
    int tab[K]={0};
    for(int i=0;i<N;i++){
        tab[value(A[i],position)]++;
    }
    for(int i=1;i<K;i++){
        tab[i]+=tab[i-1];
    }
    string B[N];
    for(int i=N-1;i>=0;i--){
        int w=value(A[i],position);
        B[--tab[w]]=A[i];
    }
}


void sortString (string A[N]){
    int p=longest(A);
    for(int i=p-1;p>=0;p--){
        position_sort(A, i);
    }
}

int main(){

}
