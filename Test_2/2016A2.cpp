#include <iostream>

using namespace std;

struct HT{
    int* table;
    int s;
};

int Hash(int x){
return x*73+14;
}

void Insert(HT* ht, int x){
    int n=Hash(x)%ht->s;
    for(int i=0;i<ht->s;i++){
        if(ht->table[(n+i)%ht->s]==-1){
                ht->table[(n+i)%ht->s]=x;
                return;
        }
    }
}

void enlarge( HT* ht){
    int n=ht->s;
    HT*nht;
    nht=new HT;
    nht->s=2*n;
    for(int i=0;i<2*n;i++)nht->table[i]=-1;
    for(int i=0;i<n;i++)if(nht->table[(Hash(ht->table[i]))%(2*n)]==-1){nht->table[(Hash(ht->table[i])%(2*n))]=ht->table[i]; ht->table[i]=-1;}
    for(int i=0;i<n;i++)if(ht->table[i]!=-1)Insert(nht,ht->table[i]);
}













int main(){
}
