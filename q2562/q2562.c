#include<stdio.h>
#include<stdlib.h> 
typedef struct Node{
	int data;
	int count;
	struct Node * next;
} t_Node;

t_Node * head;
t_Node * tail;

int N;
int MAX = 0;

void create(int input){
	t_Node * node;
	node = malloc(sizeof(t_Node));
	node->data = input;
	node->next = NULL;
	node->count = 1;
	head = node;
	tail = node;
}

void add(int input, int i){
	t_Node * node;
	node = malloc(sizeof(t_Node));
	node->data = input;
	node->next = NULL;
	node->count = i+1;
	tail->next = node;
	tail = node;
}

void eval(int input){
	if (MAX < input) MAX = input;	
}

void scan(){
	t_Node * curr = head;
	for(int i=0; i < 9; i++){
		if (curr->data == MAX){
			printf("%d\n%d", curr->data, curr->count);
		}
		curr = curr->next;
		t_Node * garbage = curr;
		free(garbage);
	}
}

int main() {
	for(int i=0; i<9; i++){
		scanf("%d", &N);
		eval(N);
		if(i == 0) create(N);
		if(i > 0) add(N, i);
	}
	scan();
}
