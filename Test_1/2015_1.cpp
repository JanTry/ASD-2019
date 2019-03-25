#include <iostream>
#include <cmath>

using namespace std;

const int N=100;

int Partition(long long C[][2], int last, int first){
    int key=C[last][0];
    int j=first;
    for(int i=first;i<last;i++)
        if(C[i][0]<key){
            swap(C[j][1],C[i][1]);
            swap(C[j][0],C[i][0]);
            j++;
        }
    swap(C[j][1],C[last][1]);
    swap(C[j][0],C[last][0]);
    return j;
}

void Sort_and_remember(long long C[][2], int last, int first=0){
    if(first<last){
    int q=Partition(C, last, first);
    Sort_and_remember(C, q-1, first);
    Sort_and_remember(C, last, q+1);
    }
}

void SumSort(int A[], int B[], int n){
    long long C[n][2]={0};
    for(int i=0;i<n;i++)
        C[i][1]=i;
    for(int i=0;i<n*n;i++)C[i/100][0]+=A[i];
    Sort_and_remember(C, n-1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) B[C[i][1]*100+j]=A[i*100+j];
}

int main(){

}
