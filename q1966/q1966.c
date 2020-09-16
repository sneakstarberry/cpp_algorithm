#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} t_Node;

t_Node *haed;
t_Node *tail;

int N;

int main(){
 scanf("%d", &N);
 printf("%d", N);

 return 0;
 
}
