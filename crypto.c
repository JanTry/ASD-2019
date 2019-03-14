#include <stdlib.h>
#include <stdio.h>

int length(char* message, int n){
    int i=0;
    while(i<n && message[i]!=' ')i++;
    return i;
}

char cryptooo(char a, int p){
    if(a==' ')return a;
    int w=(int)a-'a';
    w=(w+p)%26;
    w=w+'a';
    return (char)w;
}


void encrypt(char* message, int n){
    int p=length(message, n);
    int i=0;
    for( i=0; i<n; i++)
    message[i]=cryptooo(message[i], p);
}

int main(){
    int n;
    scanf("%d", &n);
    char* message = (char*)malloc((n+1) * sizeof(char));
    fgets(message, n+1, stdin);
    fgets(message, n+1, stdin);
    encrypt(message, n);
    printf("%s\n",message);
    free(message);
}
