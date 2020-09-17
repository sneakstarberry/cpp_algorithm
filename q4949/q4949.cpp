#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node *pre;
	char data;
};

struct Node * head=NULL;
struct Node * last=NULL;
void s_popcheck(char glho);
void s_push(char glho);
void s_clear();
bool first=true;
bool fail=false;

void order(char glho){
	if(glho=='(' || glho=='['){
		s_push(glho);
		return;
	}
	if(glho==')' || glho==']'){
		s_popcheck(glho);
		return;
	}

}

void nojam4949(){
	for(;;){
		int start=1;
		char glho;
		while(1){
			scanf("%1c",&glho);
			if(start==1&&glho=='.')return;
			order(glho);
			start++;
			if(glho=='\n') break;
		}
		s_clear();
		if(fail){
			printf("NO\n");
			fail=false;
		}else{
			printf("YES\n");
		}
	}
}

int main(){
	nojam4949();
}

void s_push(char glho){
	struct Node * node;
	node = (struct Node *)malloc(sizeof(struct Node));
	if(first){
		node->pre = NULL;
		node->data = glho;
		head=node;
		last=node;
		first=false;
	}else{
		node->pre = last;
		node->data = glho;
		last = node;
	}
}

void s_popcheck(char glho){
	if(first){
		fail=true;
		return;
	}
	struct Node * garbege=last;
	if(garbege->data=='(' && glho == ']'){
		fail=true;
		return;
	}
	if(garbege->data=='['&& glho == ')'){
		fail=true;
		return;
	}
	if(garbege->pre==NULL){
		head=NULL;
		last=NULL;
		free(garbege);
		first=true;
	}else{
		last=garbege->pre;
		free(garbege);
	}
}

void s_clear(){
	if(head==NULL){
		return;
	}
	struct Node * tracker;
	tracker=last;
	head=NULL;
	last=NULL;
	while(tracker->pre!=NULL){
		struct Node * garbege;
		garbege=tracker;
		tracker=tracker->pre;
		free(garbege);
	}
	fail=true;
	first=true;
}