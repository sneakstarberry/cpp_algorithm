#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int data;
	int cnt;
	struct Node *prev;
}	s_Node;

typedef struct List{
	s_Node *head;
	s_Node *tail;
}	Stack;

int N;
Stack *stack1;



void create(int input){
	s_Node * node;
	node = malloc(sizeof(s_Node));
	node->prev = NULL;
	node->cnt = 1;
	node->data = input;
	stack1->head = node;
	stack1->tail = node;
}

void push(int input){
	s_Node *node;
	node = malloc(sizeof(s_Node));
	node->prev = stack1->tail;
	node->cnt = stack1->tail->cnt+1;
	node->data = input;
	
	stack1->tail = node;
}

void pop(){
	if(stack1->tail == NULL) {
		printf("-1\n");
		return;
	}
	printf("%d\n", stack1->tail->data);
	s_Node * garbage = stack1->tail;
	if(stack1->head != stack1->tail){
		stack1->tail = stack1->tail->prev;
	} else{
		stack1->head = NULL;
		stack1->tail = NULL;
	}
	free(garbage);
} 

void empty(){
	if(stack1->tail ==NULL) {
		printf("1\n");
		return;
	}else {
		printf("0\n");
		return;
	}
}

void top(){
	if(stack1->tail == NULL){
		printf("-1\n");
		return;
	} else {
		printf("%d\n", stack1->tail->data);
		return;
	}
}

int main() {
	scanf("%d", &N);
	stack1 = malloc(sizeof(Stack));
	stack1->head = malloc(sizeof(s_Node));
	stack1->tail = malloc(sizeof(s_Node));
	stack1->head = NULL;
	stack1->tail = NULL;
	for(int i=0; i<N; i++){
		char command[20];
		scanf("%s", command);
		if(!strcmp(command, "push")){	
			int x;
			scanf("%d", &x);
			if(stack1->tail==NULL){
				create(x);
			}else {
				push(x);
			}
		} else if(!strcmp(command, "pop")){
			pop();
		} else if (!strcmp(command, "size")){
			if(stack1->tail == NULL){
				printf("0\n");
			}else {printf("%d\n", stack1->tail->cnt);}
		} else if (!strcmp(command, "empty")){
			empty();
		} else top();
	}
	return 0;
}
