/*
1. 다음 초기 자료에 대하여 삽입 정렬(Insertion Sort)을 이용하여 오름차순 정렬한 경우 PASS1의 결과는?
초기 자료 : 8, 3, 4, 9, 7 

정답 : (4) 3, 8, 4, 9, 7
*/
/*
2. 다음 자료를 버블 정렬을 이용하여 오름차순으로 정렬할 경우 PASS1의 결과는?

정답: (2) 6, 7, 3, 5, 9
*/

/*
3. 다음 자료에 대하여 "선택 정렬"를 사용하여 오름차순으로 정렬할 경우 pass 3의 결과는?

정답: (1) 3, 4, 7, 9, 8
*/

/*
4. 다음은 배열 A에 저장된 n개의 정수를 오름차순으로 정렬하는 삽입 정렬 알고리즘이다. ㄱ과 ㄴ에 순서대로 들어갈 내용으로 옳은것은?

void sort(int A[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++){
		key = A[i];
		for(j = i - 1; ㄱ; j--){
			ㄴ 
		} 
		A[j+1] = key;
	}
}

정답: (4) j >= 0 && key < A[j]  | A[j+1] = A[j];
*/

/*
5. 다음의 정렬기법을 이용하여 다음의 정수 배열을 오름차순으로 정렬하라. 각 단계에서의 배열의 내용을 나타내어라.
7 | 4 | 9 | 6 | 3 | 8 | 7 | 5 |
 
(1) 선택 정렬
1단계) 3 4 9 6 7 8 7 5
2단계) 3 4 9 6 7 8 7 5
3단계) 3 4 5 6 7 8 7 9
4단계) 3 4 5 6 7 8 7 9
5단계) 3 4 5 6 7 8 7 9
6단계) 3 4 5 6 7 7 8 9   
7단계) 3 4 5 6 7 7 8 9 
8단계) 3 4 5 6 7 7 8 9 

(2) 삽입 정렬
1단계) 4 7 9 6 3 8 7 5
2단계) 4 7 9 6 3 8 7 5
3단계) 4 6 7 9 3 8 7 5
4단계) 3 4 6 7 9 8 7 5
5단계) 3 4 6 7 8 9 7 5
6단계) 3 4 6 7 7 8 9 5
7단계) 3 4 5 6 7 7 8 9

(3) 삽입 정렬
1단계) 4 7 6 3 8 7 5 9
2단계) 4 6 3 7 7 5 8 9
3단계) 4 3 6 7 5 7 8 9
4단계) 3 4 6 5 7 7 8 9
5단계) 3 4 5 6 7 7 8 9
6단계) 3 4 5 6 7 7 8 9
7단계) 3 4 5 6 7 7 8 9
8단계) 3 4 5 6 7 7 8 9

(4) 쉘 정렬 
1단계) 간격 5 
7					8
	4					7
		5					9
			6
				3
7 4 5 6 3 8 7 9
2단계) 간격 3
6			7			7
	3			4			9
		5			8		
		
6 3 5 7 4 8 7 9

3단계) 간격 2
4		5		6		7
	3		7		8		9
4 3 5 7 6 8 7 9

4단계) 간격 1
3 4 5 6 7 7 8 9
*/ 

/*
6. 다음의 정렬기법을 이용하여 다음의 정수 배열을 오름차순으로 정렬하라. 각 단계에서의 배열의 내용을 나타내어라.
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 | 

(1) 퀵 정렬
1단계)
71 | 49 92 55 38 82 72 53

49	53	55	38		| 71 |		82	72	92  

2단계)

49	| 53 55 38		| 71 |		82	| 72 92
 
 38		|49|		55 53	|71|		 72		|82| 	92 
 
3단계)
| 38 | 49 |		55 53	|71 | 72 | 82 | 92 |

| 38 | 49 |		53 	| 55 |71 | 72 | 82 | 92 |

4단계)
38 49 53 55 71 72 82 92

(2) 합병 정렬 
1단계) 
71 49 92 55		|		38 82 72 53

71 49	|	92 55	|	38 82	|	72 53

49 | 71		|		55 | 92		|	38 | 82		| 	53 | 72

2단계)
71 49 92 55		|		38 82 72 53

49 55 71 92	|		|	38  53 72 82

3단계)
49 55 71 92		|	38  53 72 82

38 49 53 55 71 72 82 92

(3) 히프 정렬 
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 |
1단계)
38 | 49 | 72 | 53 | 55 | 92 | 82 | 71

49 | 53 | 72 | 71 | 55 | 92 | 82
38 

2단계)
53 | 55 | 72 | 71 | 82 | 92 |
38 49 

3단계)
55 | 71 | 72 | 92 | 82
38 49 53 

4단계)
71 | 82 | 72 | 92
38 49 53 55 

5단계)
72 | 82 | 92
38 49 53 55 71 

6단계) 
82 | 92
38 49 53 55 71 72

7단계)
92
38 49 53 55 71 72 82

8단계)
38 49 53 55 71 72 82 92
*/
/*
7. 다음과 같은 입력 배열을 퀵 정렬을 이용하여 정렬할 때, 피봇을 선택하는 방법을 다르게 하여 각 단계별 내용을 나타내어라.
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
(1) 왼쪽 첫 번째 요소를 피봇으로 하는 방법
1단계)
1	|	2 3 4 5 6 7 8

2단계)
1 | 2	|	3 4 5 6 7 8

3단계)
1 | 2 | 3	|	4 5 6 7 8

4단계)
1 | 2 | 3 | 4	|	5 6 7 8

5단계)
1 | 2 | 3 | 4 | 5 	|	6 7 8

6단계)
1 | 2  | 3 | 4 | 5 | 6	|	7 8

7단계)
1 | 2 | 3 | 4 | 5 | 6 | 7	|	8

8단계)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |

(2) 왼쪽, 중간, 오른쪽 가운데 중간값(median of three) 방법
1단계) 
4	|	1 2 3 5 6 7 8 

1 2 3 	|	4	|	5 6 7 8

2단계) 
2 |	1 3		| 4 |	6	| 5 7 8
1 	| 2 |	3	| 4 |	5	| 6 |	7 8

3단계)
 1 | 2 | 3 | 4 | 5 | 6 | 7 |	8
 
4단계)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
*/

/*
8. 퀵 정렬에서 함수가 수행되면서 정렬의 매 패스마다 다음과 같은 형식으로 화면에  출력하도록 삼수를 수정하여 보라. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y , t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
	pivot = list[left];
	
	int i, n = MAX_SIZE;
//	for(i = 0; i < n; i++){
//			printf("%d\t", list[i]);
//	}
//	printf("\n");
//	for(i = 0; i < low + 1; i++){
//		printf("\t");
//	}
//	printf("low");
//	for(i = 0; i < high - 2; i++){
//		printf("\t");
//	}
//	printf("high");
//	printf("\n");
	
	do{
		
//		for(i = 0; i < n; i++){
//			printf("%d\t", list[i]);
//		}
//		printf("\n");
//		
//		for(i = 0; i < low + 1; i++){
//			printf("\t");
//		}
//		printf("low");
//		
//		for(i = 0; i < high - 2; i++){
//			printf("\t");
//		}
//		printf("high");
//		printf("\n");
		
		do{
			low++;
		} while (list[low] < pivot);
		
		do{
			high--;
		} while(list[high] > pivot);
		if(low <high){
			SWAP(list[low], list[high], temp);
		}
	} while(low < high);
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //부분 리스트의 데이터 개수가 1개가 되면 멈춘다.  
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

int main(void)
{
	int i;
	n = MAX_SIZE;
	int list[n] = {67, 90, 57, 25, 84, 32, 73, 54};

	quick_sort(list, 0, n-1);
	
	printf("[정렬 후] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/

/*
9. 다음 중 안정적인 정렬 방법이 아닌 것은 무엇인가?

정답 : (2) 선택 정렬 
*/

/*
10.다음 중 삽입 정렬이 가장 효율적으로 적용될 수 있을 때는?
정답: (2) 어느 정도 정렬이 되어 있다.
-> 비교연산 횟수가 줄어든다. 이동 여산도 줄어든다. 
*/

/*
11. 퀵정렬을 이용하여 다음의 정수 배열을 정렬하고자 한다.

(a) 첫 번째 분할이 끝난 후의 배열의 내용을 나타내라.
정답: 
5 3 4 |5| 8 9 6 7

(b) 이 첫 번째 분할에서 몇 번의 비교연산이 수행되는가? 
정답: 
[quick_sort]
if(left < right) 1번

[partition]
1)
low 비교 1번
high 비교 1번
low < high 2번 

2)
low 비교 2번
high 비교 2번
low < high 2번 

3)
low 비교 1번 
high 비교 1번
low < high 1번 

총 14번 

(c) 분할이 이루어지면 피봇값은, 피봇값보다 더 작은 서브 배열과 피봇값보다 더 큰 서브배열, 2개의 서브배열의 중간에 위치하게 된다.
이 피봇값의 위치는 다음 단계가 진행되었을 대 변경이 되는가 아니면 되지 않는가? 그 이유는?
정답:
피봇값의 위치는 변경되지 않는다.
문제에서 언급했듯이 피봇값을 기준으로 이미 정렬이 완료되었기 때문에 피봇값의 위치는 다른 비교에 영향을 받지 않는다.

(d) 첫 번째 분할 다음에 호출되는 순환호출들은 무엇인가?
정답: 
서브배열의 크기가 1이 될때까지 계속해서 남은 서브배열을 정렬하기 위해 순환호출된다.
*/

/*
12. 다음의 정수배열을 기수정렬을 이용하여 정렬하고자 한다. 기수정렬의 각 단계를 보여라.

정답:
1단계)
210 220
123 003 513
294
398 528 
409 129

210 220 123 003 513 294 398 528 409 129

2단계)
003 409
210 513
220 123 528 129 
294 398

003 409 210 513 220 123 528 129 294 398

3단계)
003
123 129
210 220 294
398
409 
513 528

003 123 129 210 220 294 398 409 513 528
*/
 
 
/*
13. 삽입 정렬의 코드를 수정하여 숫자가 아니고 레코드를 삽입 정렬하는 프로그램을 구성해보자.
즉 정렬이 되는 단위가 숫자가 아니고 레코드이다. 먼저 레코드를 표현하기 위해 다음과 같은 구조체를 사용한다.
실무와 연관된 실제 프로그램들은 대부분 레코드를 정렬하여야 함을 기억해두길 바란다.
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 6
#define NAME_SIZE 20
//문자열 비교하는 것 있으면 댐 


//레코드를 정의하기 위한 구조체 
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

//삽입정렬 
void insertion_sort(record list[], int n)
{
	int i, j, k;
	char key[NAME_SIZE];

	for(i = 1; i < n; i++){
		printf("<%d단계>", i);
		for(k = 0; k < n; k++){
			printf(" %s |", list[k].name);
		}
		printf("\n");
		
		//문자열 변수 입력시 strcpy 써야한다!! 
		//key  값에 정렬할 문자열 보관 
		strcpy(key, list[i].name); 
		printf("변경할 key값: %s\n", key);
		
		//key 값이 가장 작은 경우 j <- '-1'로 끝남 
		for(j = i - 1; j >= 0 && strcmp(list[j].name, key) == 1; j--){
			strcpy(list[j + 1].name, list[j].name); 
		}
		strcpy(list[j + 1].name, key);
	}
	
} 

int main(void)
{
	int i, n = MAX_SIZE;

	record list[MAX_SIZE] = {{0, "amy"}, {1, "gabriel"}, {2, "tom"} ,{3, "samanda"}, {4, "kevin"}, {5, "bob"}};
	printf("삽입 정렬 전 리스트:\n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	printf("\n");
	//strcmp 앞단어 기준으로 뒷 단어랑 비교 앞단어가 더 빠르면 -1 같으면 0 늦으면 1 
//	printf("%d", strcmp("amy", "abc"));
	
	insertion_sort(list, n);
	printf("삽입 정렬 후 리스트 : \n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	return 0;
} 
*/
 
 
 
 
 
 
/*
14. 삽입 정렬의 코드를 수정하여 삽입 정렬의 각 단계를 출력하도락 하라. 
아래 그림에서 왼쪽 괄호 안에 있는 숫자는 정렬이 되어 있는 숫자들이다.
오른쪽은 정렬을 해야 할 숫자들이다. 
삽입정렬의 단계에서 다음과 같이 출력하도록 insertion_sort 함수를 수정하라.
이를 위하여 사용자로부터 숫자들을 입력받을 수 있도록 하라. 

#include <stdio.h>

#define MAX_SIZE 6

int before_sort[MAX_SIZE];
int after_sort[MAX_SIZE]; 


void insertion_sort(int list[], int n)
{
	int i, j , key, insert = 17;
	//정렬 전 배열 
	printf("()");
	printf("\t");
	printf("(");
	printf("%d", list[0]); //, 표시 때문에 첫번째거만 따로 
	for(i = 1; i < n; i++){
		printf(",%d", list[i]);
	}
	printf(")\n");
	
	for(i = 1; i < n; i++){
		//정렬된 부분 출력 
		printf("(%d", list[0]); 
		for(int k = 1; k < i; k++){
			printf(",%d", list[k]);
		}

		printf(")");
		printf("\t");
		
		//정렬 안된 부분 출력 
		printf("(");
		printf("%d", list[i]);
		for(int k = i + 1; k < n; k++){
			printf(",%d", list[k]);
		}
		printf(")");
		printf("\t");
		printf("%d삽입\n", insert);
		
		
		//정렬할 값을 선택 
		key = list[i];
		insert = key;		
		//key 값이 가장 작은 경우 j <- '-1'로 끝남 
		for(j = i - 1; j >= 0 && list[j] > key; j--){
			list[j + 1] = list[j]; 
		}
		
		//비교를 위해 인덱스 -1 줄었으니 삽입할 떄는 1 더해준다. 
		list[j + 1] = key;
	}
	//마지막 리스트 출력 
	printf("(%d",list[0]);
	for(int k = 1; k < n; k++){
		printf(",%d", list[k]);
	}
	printf(")");
	printf("\t");
	printf("()");
	printf("\t");
	printf("%d삽입\n", insert);
} 

int main(void)
{
	int i, n = MAX_SIZE;
	int list[MAX_SIZE] = {17, 9, 21, 6, 3, 12};
	
	insertion_sort(list, n);
	
	return 0;
}
*/
