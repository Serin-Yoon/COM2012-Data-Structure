#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 7 // vertex �ִ� ����

typedef struct Node {
	int vertex; // ����� ���� ASCII �ڵ� �̿��Ͽ� ���ڷ� ��ȯ
	struct Node* link;
} Node;

typedef struct Graph {
	int n; // ���� ����
	Node* matrix[MAX];
} Graph;


/* ADT ��� */

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


/* ���� �Լ�*/

int main() {

	Graph* graph;

	init(&graph); // Graph �ʱ�ȭ

	int command;
	char vertex1, vertex2;
	int result1, result2;
	int answer;

	/* ����ڿ��� ADT ��� �ȳ� */

	printf("\n ===================== Undirected Graph ADT =====================\n\n");
	printf("   01. Insert Vertex   02. Delete Vertex    03. Add Edge \n");
	printf("   04. Delete Edge     05. Adjacent         06. Degree of Vertex \n");
	printf("   07. Num of Vertex   08. Num of Edge      09. Print \n");
	printf("   10. Is Connected    11. Path Exist       12. Clear \n");
	printf("   13. Is Empty        14. End Program\n\n");
	printf(" ----------------------------------------------------------------\n");
	printf("  Vertex is based on ASCII Code. You should write CAPITAL LETTER \n");
	printf(" ----------------------------------------------------------------\n");

	/* �ʱ� Graph ���� */

	insertVertex(&graph, 0);
	insertVertex(&graph, 1);
	insertVertex(&graph, 2);
	insertEdge(&graph, 0, 1);
	insertEdge(&graph, 0, 2);
	insertEdge(&graph, 1, 2);

	printf("\n\n �� Command: ");
	scanf(" %d", &command);

	while (command != 14) {
		int number;

		switch (command) {

		case 1:
			printf("\n �� New Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			insertVertex(&graph, result1);
			break;

		case 2:
			deleteVertex(&graph);
			// �ذ� �ؾ� �� �������
			break;

		case 3:
			printf("\n �� First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n �� Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			insertEdge(&graph, result1, result2);
			break;

		case 4:
			printf("\n �� First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n �� Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			deleteEdge(&graph, result1, result2);
			break;

		case 5:
			printf("\n �� Which Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			adjacent(&graph, result1);
			break;

		case 6:
			printf("\n �� Which Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			result2 = degreeofVertex(&graph, result1);
			printf("\n �� Degree of Vertex %c >> %d \n", vertex1, result2);
			break;

		case 7:
			result1 = numofVertex(&graph);
			printf("\n �� Num of Vertex >> %d \n", result1);
			break;

		case 8:
			result1 = numofEdge(&graph);
			printf("\n �� Num of Edge >> %d \n", result1);
			break;

		case 9:
			printGraph(&graph);
			break;

		case 10:
			result1 = isConnected(&graph);
			if (result1) printf("\n �� Graph is Connected. \n");
			else printf("\n �� Graph is Not Connected. \n");
			break;

		case 11:
			printf("\n �� First Vertex >> ");
			scanf(" %c", &vertex1);
			result1 = vertex1 - 65;
			printf("\n �� Second Vertex >> ");
			scanf(" %c", &vertex2);
			result2 = vertex2 - 65;
			answer = pathExist(&graph, result1, result2);
			if (answer == 1) printf("\n �� Path exist between %c and %c! \n", vertex1, vertex2);
			else if (answer == -1) printf("\n �� Vertex doesn't exist! \n");
			else printf("\n �� Path doesn't exist between %c and %c \n", vertex1, vertex2);
			break;

		case 12:
			init(&graph);
			break;

		case 13:
			result1 = isEmpty(&graph);
			if (result1)  printf("\n �� Graph is Empty. \n");
			else printf("\n �� Graph is Not Empty. \n");
			break;
		}

		printf("\n �� Command: ");
		scanf(" %d", &command);
	}

	return 0;
}

void init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX; i++) g->matrix[i] = NULL;
} // clear

void insertVertex(Graph* g, int a) {

	printf("\n �� Trying to Insert %c ... ", a + 65);

	if ((a < 0) || (a > 25)) {
		printf("Should input Capital Letter! \n");
		return;
	} // �빮�� �̿��� ���� �Է½� (ex. a, ...)
	else if ((g->n) >= MAX) {
		printf("Graph is Full! \n");
		return;
	} // ���� ������ �ִ� ������ ���
	else if ((g->n) != a) {
		printf("Wrong Command! \n");
		return;
	} // �̹� �ִ� ������ �Է��ϴ� ���� ���

	printf("Done! \n");
	g->n++;

}

void deleteVertex(Graph* g) {

	Node* ptr;
	int num = (g->n - 1);

	// ������ ���� ����
	g->matrix[num] = NULL;
	g->n--;

	// ���� ����
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
	printf("\n �� Deleted Latest Vertex. \n");
}

void insertEdge(Graph* g, int a, int b) {

	Node* node1, * node2;

	printf("\n �� Trying to edge %c and %c ... ", a + 65, b + 65);

	if (a >= g->n || b >= g->n) {
		printf("Vertex Doesn't Exist! \n");
		return;
	} // ���� �������� �ʴ� ���

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
	} // �� ���� ���̿� �̹� ������ �ִ� ���

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
	int result = 0; // ���� ������ 1 ������ 0

	node1 = g->matrix[a];
	node2 = g->matrix[b];

	printf("\n �� Trying to delete edge between %c and %c ... ", a + 65, b + 65);

	if (a >= g->n || b >= g->n) {
		printf("Vertex Doesn't Exist! \n");
		return;
	} // ���� �������� �ʴ� ���

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
	} // ���� �������� �ʴ� ���

	// ���� ���� ����
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

	printf("\n �� Graph >> ");
	for (int i = 0; i < g->n; i++) {
		printf(" (%c) ", i + 65); // ASCII code�� ���� ���
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

	printf("\n �� (%c) ", a + 65);
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
	int full; // ��� ����Ǿ� ���� �� ���� ����
	int edge;

	full = num * (num - 1) / 2;
	edge = numofEdge(g);

	if (edge == full) return 1;
	else return 0;
}

int pathExist(Graph* g, int a, int b) {

	Node* node1, * node2;
	int result = 0; // ���� �����ϸ� 1 ������ 0

	if (a >= g->n || b >= g->n) {
		printf(" �� Vertex Doesn't Exist! \n");
		return -1;
	} // ���� �������� �ʴ� ���

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