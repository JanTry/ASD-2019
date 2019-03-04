#include <iostream>

using namespace std;

const int N=100;
const int K=10;

void merge_it(int tab[K][N])
{
    int t[N][2];
    for(int i=0;i<K;i++)
    {
        int j=0;
        int w=0;
        while(tab[i][j]!=-1 && t[w][i%2]!=-1)
        {
            if(tab[i][j]<t[w][i%2])
            {
                t[w+j][(i+1)%2]=tab[i][j];
                tab[i][j]=-1;
                j++;
            }
            else{
                t[w+j][(i+1)%2]=t[w][i%2];
                t[w][i%2]=-1;
                w++;
            }
        }
    }
}


int main(){

}
