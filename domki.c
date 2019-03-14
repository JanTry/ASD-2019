#include<stdlib.h>
#include<stdio.h>


int find_divider(int* tab, int n){
    int l=0;
    int r=n-1;
    int s=0;
    while(l<r){
        if(s>0){
            s=s-tab[r];
            r=r-1;
        }
        else{
            s=s+tab[l];
            l=l+1;
        }
    }
    return l;
}


int main(){
    int n;
    scanf("%d", &n);
    int* tab = malloc(n* sizeof(int));
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &tab[i]);
    }
    printf("%d\n", find_divider(tab, n));
    free(tab);
}
