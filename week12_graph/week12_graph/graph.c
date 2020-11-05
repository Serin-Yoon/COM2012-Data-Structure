#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 7 // vertex 최대 개수

typedef struct Node {
	int vertex; // 출력할 때엔 ASCII 코드 이용하여 문자로 변환
	struct Node* link;
} Node;

typedef struct Graph {
	int n; // 정점 개수
	Node* matrix[MAX];
} Graph;


/* ADT 목록 */

void init(Graph* g);
void insertVertex(Graph* g, int a);
void deleteVertex(Graph* g);
void insertEdge(Graph* g, int a, int b);
void deleteEdge(Graph* g, int a, int b);
void printGraph(Graph* g);
void adjacent(Graph* g, int a);
int degreeofVertex(Graph* g, int a);
int numofVertex(Graph* g);
int numofEdge(Graph* g);
int isConnected(Graph* g);
int pathExist(Graph* g, int a, int b);
int isEmpty(Graph* g);


/* 메인 함수*/

int main() {

	Graph* graph;

	init(&graph); // Graph 초기화

	int command;
	char vertex1, vertex2;
	int result1, result2;
	int answer;

	/* 사용자에게 ADT 목록 안내 */

	printf("\n ===================== Undirected Graph ADT =====================\n\n");
	printf("   01. Insert Vertex   02. Delete Vertex    03. Add Edge \n");
	printf("   04. Delete Edge     05. Adjacent         06. Degree of Vertex \n");
	printf("   07. Num of Vertex   08. Num of Edge      09. Print \n");
	printf("   10. Is Connected    11. Path Exist       12. Clear \n");
	printf("   13. Is Empty        14. End Program\n\n");
	printf(" ----------------------------------------------------------------\n");
	printf("  Vertex is based on ASCII Code. You should write CAPITAL LETTER \n");
	printf(" ----------------------------------------------------------------\n");

	/* 초기 Graph 설정 */

	insertVertex(&graph, 0);
	insertVertex(&graph, 1);
	insertVertex(&graph, 2);
	insertEdge(&graph, 0, 1);
	insertEdge(&graph, 0, 2);
	insertEdge(&graph, 1, 2);

	printf("\n\n ▶ Command: ");
	scanf(" %d", &command);

	while (command != 14) {
		int number;

		switch (command) {

		case 1:
			printf("\n ▷ New Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			insertVertex(&graph, result1);
			break;

		case 2:
			deleteVertex(&graph);
			// 해결 해야 함 어느정도
			break;

		case 3:
			printf("\n ▷ First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n ▷ Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			insertEdge(&graph, result1, result2);
			break;

		case 4:
			printf("\n ▷ First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n ▷ Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			deleteEdge(&graph, result1, result2);
			break;

		case 5:
			printf("\n ▷ Which Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			adjacent(&graph, result1);
			break;

		case 6:
			printf("\n ▷ Which Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			result2 = degreeofVertex(&graph, result1);
			printf("\n ▷ Degree of Vertex %c >> %d \n", vertex1, result2);
			break;

		case 7:
			result1 = numofVertex(&graph);
			printf("\n ▷ Num of Vertex >> %d \n", result1);
			break;

		case 8:
			result1 = numofEdge(&graph);
			printf("\n ▷ Num of Edge >> %d \n", result1);
			break;

		case 9:
			printGraph(&graph);
			break;

		case 10:
			result1 = isConnected(&graph);
			if (result1) printf("\n ▷ Graph is Connected. \n");
			else printf("\n ▷ Graph is Not Connected. \n");
			break;

		case 11:
			printf("\n ▷ First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n ▷ Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			answer = pathExist(&graph, result1, result2);
			if (answer == 1) printf("\n ▷ Path exist between %c and %c! \n", vertex1, vertex2);
			else if (answer == -1) printf("\n ▷ Vertex doesn't exist! \n");
			else printf("\n ▷ Path doesn't exist between %c and %c \n", vertex1, vertex2);
			break;

		case 12:
			init(&graph);
			break;

		case 13:
			result1 = isEmpty(&graph);
			if (result1)  printf("\n ▷ Graph is Empty. \n");
			else printf("\n ▷ Graph is Not Empty. \n");
			break;
		}

		printf("\n ▶ Command: ");
		scanf(" %d", &command);
	}

	return 0;
}

void init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX; i++) g->matrix[i] = NULL;
} // clear

void insertVertex(Graph* g, int a) {

	printf("\n ▷ Trying to Insert %c ... ", a + 65);

	if ((a < 0) || (a > 25)) {
		printf("Should input Capital Letter! \n");
		return;
	} // 대문자 이외의 문자 입력시 (ex. a, ...)
	else if ((g->n) >= MAX) {
		printf("Graph is Full! \n");
		return;
	} // 정점 개수가 최대 개수인 경우
	else if ((g->n) != a) {
		printf("Wrong Command! \n");
		return;
	} // 이미 있는 정점을 입력하는 등의 경우

	printf("Done! \n");
	g->n++;

}

void deleteVertex(Graph* g) {

	Node* ptr;
	int num = (g->n - 1);

	// 마지막 정점 삭제
	g->matrix[num] = NULL;
	g->n--;

	// 간선 삭제
	for (int i = 0; i < num; i++) {
		ptr = g->matrix[i];

		while (ptr != NULL) {
			if (ptr->vertex == num) {
				ptr->vertex = -1;
				break;
			}
			else ptr = ptr->link;
		}
	}
	printf("\n ▷ Deleted Latest Vertex. \n");
}

void insertEdge(Graph* g, int a, int b) {

	Node* node1, * node2;

	printf("\n ▷ Trying to edge %c and %c ... ", a + 65, b + 65);

	if (a >= g->n || b >= g->n) {
		printf("Vertex Doesn't Exist! \n");
		return;
	} // 정점 존재하지 않는 경우

	node1 = g->matrix[a];
	node2 = g->matrix[b];


	while (node1 != NULL) {

		if (node1->vertex != b) {
			node1 = node1->link;
		}
		else if (node1->vertex == b) {
			printf("Already Linked! \n");
			return;
		}
	} // 두 정점 사이에 이미 간선이 있는 경우

	node1 = (Node*)malloc(sizeof(Node));
	node1->vertex = b;
	node1->link = g->matrix[a];
	g->matrix[a] = node1;

	node2 = (Node*)malloc(sizeof(Node));
	node2->vertex = a;
	node2->link = g->matrix[b];
	g->matrix[b] = node2;

	printf("Done! \n");

}

void deleteEdge(Graph* g, int a, int b) {

	Node* node1, * node2;
	int result = 0; // 간선 있으면 1 없으면 0

	node1 = g->matrix[a];
	node2 = g->matrix[b];

	printf("\n ▷ Trying to delete edge between %c and %c ... ", a + 65, b + 65);

	if (a >= g->n || b >= g->n) {
		printf("Vertex Doesn't Exist! \n");
		return;
	} // 정점 존재하지 않는 경우

	while (node1 != NULL) {
		if (node1->vertex != b) {
			node1 = node1->link;
		}
		else if (node1->vertex = b) {
			result = 1;
			break;
		}
	}
	if (!result) {
		printf("Edge Doesn't Exist! \n");
		return;
	} // 간선 존재하지 않는 경우

	// 간선 삭제 과정
	while (node1 != NULL) {
		if (node1->vertex != b) {
			node1 = node1->link;
		}
		else if (node1->vertex == b) {
			node1->vertex = -1;
			break;
		}
	}

	while (node2 != NULL) {
		if (node2->vertex != a) {
			node2 = node2->link;
		}
		else if (node2->vertex == a) {
			node2->vertex = -1;
			break;
		}
	}

	printf("Done! \n");
}

void printGraph(Graph* g) {

	Node* ptr;

	printf("\n ▷ Graph >> ");
	for (int i = 0; i < g->n; i++) {
		printf(" (%c) ", i + 65); // ASCII code로 문자 출력
		ptr = g->matrix[i];

		while (ptr != NULL) {

			if (ptr->vertex == -1 && ptr->link == NULL) break;
			else if (ptr->vertex == -1 && ptr->link != NULL) ptr = ptr->link;

			printf("%c ", ptr->vertex + 65);
			ptr = ptr->link;
		}
		printf(" ");
	}
	printf("\n");
}

void adjacent(Graph* g, int a) {

	Node* ptr;
	ptr = g->matrix[a];

	printf("\n ▷ (%c) ", a + 65);
	while (ptr != NULL) {
		printf("%c ", ptr->vertex + 65);
		ptr = ptr->link;
	}
	printf("\n");

}

int degreeofVertex(Graph* g, int a) {

	Node* ptr;
	ptr = g->matrix[a];
	int degree = 0;
	while (ptr != NULL) {
		degree++;
		ptr = ptr->link;
	}

	return degree;
}

int numofVertex(Graph* g) {
	int num;
	num = g->n;
	return num;
}

int numofEdge(Graph* g) {

	Node* ptr;

	int degree;
	int total = 0;
	int num = g->n;

	for (int i = 0; i < num; i++) {
		ptr = g->matrix[i];
		degree = 0;
		while (ptr != NULL) {
			ptr = ptr->link;
			degree++;
		}
		total += degree;
	}

	return total / 2;
}

int isConnected(Graph* g) {

	Node* ptr;

	int num = g->n;
	int full; // 모두 연결되어 있을 때 간선 개수
	int edge;

	full = num * (num - 1) / 2;
	edge = numofEdge(g);

	if (edge == full) return 1;
	else return 0;
}

int pathExist(Graph* g, int a, int b) {

	Node* node1, * node2;
	int result = 0; // 간선 존재하면 1 없으면 0

	if (a >= g->n || b >= g->n) {
		printf(" ▷ Vertex Doesn't Exist! \n");
		return -1;
	} // 정점 존재하지 않는 경우

	node1 = g->matrix[a];
	node2 = g->matrix[b];

	while (node1 != NULL) {

		if (node1->vertex != b) {
			node1 = node1->link;
		}
		else if (node1->vertex = b) {
			result = 1;
			return result;
		}
	}

	return result;
}

int isEmpty(Graph* g) {
	int num;
	num = numofVertex(g);

	if (num <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}