#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int value;
    struct node* next;
} node;


int main(){
    int n;
    int val;
    scanf("%d", &n);
    node* list=malloc(sizeof(node));
    list->next=NULL;
    node* tmp=list->next;
    int i;
    for (i=0;i<n;i++){
       scanf("%d",&val);
       list->next=malloc(sizeof(node));
       list->next->next=tmp;
       tmp=list->next;
       tmp->value=val;
    }
    tmp=list->next;
    free(list);
    list=tmp;
    for (i=0; i<n;i++){
        printf("%d\n", list->value);
        tmp=list;
        list=list->next;
        free(tmp);
    }
}
