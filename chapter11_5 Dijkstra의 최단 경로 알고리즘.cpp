//알고리즘 11.6 최단거리 알고리즘
//입력: 가중치 그래프 G, 가중치는 음수가 아님.
//출력: distance 배열, distance[u]는 v에서 u까지의 최단 거리이다.

//주어진 시작 정점에서 모든 다른 정점까지 거리 
/*
shortest_path(G, v):
	
	S<-{v}
	for 각 정점 w (- G do
		distance[w]<-weight[v][w];
	while 모든 정점이 S에 포함되지 않으면 do
		u<-집합 s에 속하지 않는 정점 중에서 최소 distance 정점;
		S<- S U {u}
		for u에 인접하고 S에 있는 각 정점 z 애
			if distance[u] + weight[u][z] < distance[z]
				then distance[z] <- distance[u] + weight[u][z];  
*/

//프로그램 11.10 최단 경로 Dijkstra 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /*무한대로 가정*/

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;

int distance[MAX_VERTICES]; /*시작 정점으로부터의 최단경로 거리*/
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i =0; i <n; i++){
		if(distance[i] < min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
} 
//<1>
//	distance:  	0  7  *  *  3 10  *
//	found:  	1  0  0  0  0  0  0
//	u = choose();
//	u= 4
//				3  2  *  11 0  *  5
//<2>
//	distance:  	0  5  * 14  3 10  8
// 	found:  	1  0  0  0  1  0  0
// 	u = choose
//	 
//	
//{{0, 7, INF, INF, 3, 10, INF},
//	{7, 0, 4, 10, 2, 6, INF},
//	{INF, 4, 0, 2, INF, INF, INF},
//	{INF, 10, 2, 0, 11, 9, 4},
//	{3, 2, INF, 11, 0, INF, 5},
//	{10, 6, INF, 9, INF, 0, INF},
//	{INF, INF, INF, 4, 5, INF, 0} }

void print_status(GraphType * g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for(int i = 0; i < g->n; i++){
		if(distance[i] == INF){
			printf(" * ");
		}
		else{
			printf("%2d ", distance[i]);
		}
	}
	printf("\n");
	printf(" found: ");
	for(int i = 0; i < g->n; i++){
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

//
void shortest_path(GraphType * g, int start)
{
	int i, u, w;
	for(i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	} 
//	printf(">>>>>>Debug distance[i] 확인\n");
//	for(i = 0; i < g->n; i++){
//		printf(" %d |", distance[i]);
//	}
	found[start] = TRUE; /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for(i = 0; i < g->n-1; i++){
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for(w = 0; w < g->n; w++){
			if(!found[w]){
				if(distance[u] + g->weight[u][w] < distance[w]){
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
	}
	print_status(g); 
}

int main(void)
{
	GraphType g = {7,
	{{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0} }
	};
	shortest_path(&g, 0);
	
	return 0;
}

/*
Quiz01.
<1>
	distance:  	0  7  *  5  *  2  *  *
	found:  	1  0  0  0  0  0  0  0
<2>
	distance:	0  7  *  5  4  2  6  *
	found:		1  0  0  0  0  1  0  0
<3>
	distance:	0  6  *  5  4  2  6  8
	found:		1  0  0  0  1  1  0  0  
<4>
	distance:	0  6  7  5  4  2  6  8
	found:		1  0  0  1  1  1  0  0
<5>
	distance:	0  6  7  5  4  2  6  8
	found:		1  1  0  1  1  1  0  0
<6>
	distance:	0  6  7  5  4  2  6  8 
	found:		1  1  0  1  1  1  1  0
<7>
	distance:	0  6  7  5  4  2  6  8 
	found:		1  1  1  1  1  1  1  0
<8>
	distance:	0  6  7  5  4  2  6  8 
	found:		1  1  1  1  1  1  1  1
	*/
