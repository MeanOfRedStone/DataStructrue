/*
1. 다음 중 NULL 포인터가 존재하지 않는 구조체는?
답 : (2) 원형 연결리스트
-> 마지막 노드가 최초의 노드와 연결되기 때문

2.리스트의 n번째 요소를 가장 빠르게 찾을 수 있는 구현 방법은?
답 : (4) 이중 연결 리스트
->처음과 끝 중 더 가까운 곳에서부터 시작해 링크를 타고 이동할 수 있기 때문

3.단순 연결 리스트에서 포인터 last가 마지막 노드를 가진다고 할 때 다음 수식 중 참인 것은
답 : (3) last->link == NULL 
-> 마지막 데이터는 존재하고 그 다음으로 연결된 링크만 없는 것이다.

4.단순 연결 리스트의 노드를 포인터 p로 방문하고자 한다. 현재 p가 가리키는 노드에서 다음 코드로 가려면?  
답 : (3) p = p->link
->현재 노드의 링크는 그 다음 노드와 같다.
즉, 노드는 포인터 그 자체와 같다.

5.다음과 같이 변수 p가 2를 저장하는 노드를 가리키도록 하는 문장을 작성하라.
현재 상태
p = 1 / node a
node a = 2 / node b
node b = 3 / null

p = node a(링크를 넣어줌) 
p->link = node b 
->링크만 넣어주면 된다. 링크는 노드 그 자체 

6.다음과 같이 변수 q가 1를 저장하는 노드를 가리키도록 하는 문장을 적어라 
링크p = 1 / node a
node a = 2 / node b
node b = 3 / null 

링크 q = 2 / node b
링크 r = 3 / null 

링크 q = 1 / node a

7.다음과 같은 연결 리스트에서 아래와 같은 코드를 실행한다고 하자, 실행이 끝난 후에 포인터 p가 가리키는 노드는 어떤 노드인가?
답 : NULL이다. 마지막 노드가 가리키는 링크는 NULL인데, 해당 for 반복문은 마지막까지 이동시키기 때문이다.

8.덱은 삽입과 삭제가 양끝에서 임의로 수행되는 자료 구조이다. 다음 그림과 같이단순연결리스트로 덱을 구현한다고 할 때 O(1) 시간
내에 수행할 수 없는 연산은? 
풀이 
(1) insertFirst  : Node x->data = value / Node x->link = first / first = Node x -> 무조건 3개 연산만
(3) deletFirst : removed = first / head = Node x -> link / free(removed) -> 무조건 3개 연산만 가능
답 
(4) deleteLast 
deleteLast의 경우 마지막 노드 이전의 노드를 알아야 하는데 이를 위해서는 단순 연결 리스트에서는 head부터 for반복문으로 이동해야 한다.
*/ 
//9.다음과 같이 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램을 작성하라.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;

	for(int i = 0; i < n; i++)
	{
		ListNode *node;
		element value;
		printf("노드 #%d의 데이터 : ", i+1);
		scanf("%d", &value);
		node->data = value;
		head = node;
		node->link = location->link;
		location->link = node->link;
	}

	print_list(head);
	
	return 0;	
} 
	

