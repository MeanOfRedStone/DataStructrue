/*
노드의 정의 : 데이터 필드 + 포인터 

top = 마지막 스택을 가리키는 구조체 포인터로 대체

typedef int element;
typedef struct STackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct{
	StackNode *top;
} LinkedStackType;
*/

//프로그램 7.9 연결된 스택 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;
} StackNode;

typedef struct{
	StackNode *top;
} LinkedStackType;

//초기화 함수 
void init(LinkedStackType *s)
{
	s->top = NULL;
}

//공백상태 검출 함수
int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
} 

//포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
	return 0;
}

//삽입함수

void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
} 

void print_stack(LinkedStackType *s)
{
	for(StackNode *p = s->top; p != NULL; p = p->link){
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

//삭제 함수
element pop(LinkedStackType *s)
{
	if(is_empty(s)){
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

//피크 함수
element peek(LinkedStackType *s)
{
	if(is_empty(s)){
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else{
		return s->top->data;
	}
}

int main(void)
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	print_stack(&s);
	push(&s, 2);
	print_stack(&s);
	push(&s, 3);
	print_stack(&s);
	
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	
	return 0;
}
