#include <iostream>
#include <cmath>

using namespace std;

const int N=100;
const int K=30;

bool possible(char* u, char* v, char* w){
    int wyst[K]={0};
    for(int i=0;u[i]!=NULL;i++)wyst[u[i]]++;
    for(int i=0;v[i]!=NULL;i++)wyst[v[i]]++;
    for(int i=0;w[i]!=NULL;i++)if(0==(wyst[w[i]]--))return false;
    return true;
}



int main(){
}
