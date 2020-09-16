#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node * next;
} t_Node;

int N;
int MAX=0;
int IN;
t_Node * head;
t_Node * tail;

void create(int input) {
	t_Node * node;
	node = malloc(sizeof(t_Node));
	node->data= input;
	node->next= NULL;
	head = node;
	tail = node;
}

void add(int input ){
	t_Node * node;
	node = malloc(sizeof(t_Node));
	node->data = input;
	node->next = NULL;
	tail->next = node;
	tail = node;
}

void eval(int input){
	if (MAX < input){
		MAX = input;
	}
	
}

void scan(){
	t_Node * curr = head;
	double avg;
	while (curr->next != NULL){	
		avg += curr->data;
		t_Node * garbage = curr;
		curr = curr->next;
		free(garbage);
	}
	avg+=IN;
	double result = avg/MAX*100/N;

	printf("%f", result);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i < N; i++){
		scanf("%d", &IN);
		if(i==0) create(IN);
		if(i>0) add(IN);
		eval(IN);
	}
	scan();
}
