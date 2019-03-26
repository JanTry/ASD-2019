#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

int Partition(int T[], int left, int right){
    int key=T[right];
    int j=left;
    for(int i=left;i<right;i++) if(T[i]<=key)swap(T[i],T[j++]);
    swap(T[right],T[j]);
    return j;
}

int Select(int T[], int left, int right, int i){
    if(left==right)return T[left];
    int q=Partition(T,left, right);
    int k=q-left+1;
    if(k==i)return T[q];
    if(k>i)return Select(T,left,q-1,i);
    else return Select(T,q+1,right,i-k);
}

int SumBetween(int T[], int from, int to, int n){
    int p=Select(T, 0, n-1, from);
    int q=Select(T, 0, n-1, to);
    int sum=0;
    for(int i=0;i<n;i++) if(T[i]<=q && T[i]>= p)sum+=T[i];
    return sum;
}

int main(){

}
