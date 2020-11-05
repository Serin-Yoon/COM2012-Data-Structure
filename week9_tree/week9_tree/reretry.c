#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nodeNum = 0;

typedef struct Node {
	char data;
	//root¸é if_root°¡ 1
	int if_root;
} Node;


int exists[100];
Node nodes[100];

int searchNode(char input) {
	int i = 0;

	while (i < 100) {
		i++;
		if (nodes[i].data == input)
			break;
	}
	return i;
}

/* ADT */

void create(char input) {
	exists[1] = 1;
	nodes[1].data = input;
	nodes[1].if_root = 1;
	nodeNum++;
}

void insert_node(char here, char input) {
	int here_pos = searchNode(here);

	if (!exists[here_pos * 2]) {
		exists[here_pos * 2] = 1;
		nodes[here_pos * 2].data = input;
		nodeNum++;
	}
	else if (!exists[(here_pos * 2) + 1]) {
		exists[(here_pos * 2) + 1] = 1;
		nodes[(here_pos * 2) + 1].data = input;
		nodeNum++;
	}
	else {
		printf("Already full \n");
	}
}

void delete_node(char here) {
	int here_pos = searchNode(here);

	if (!exists[here_pos * 2] && !exists[(here_pos * 2) + 1]) {
		exists[here_pos] = 0;
		nodeNum--;
	}
	else {
		printf("Not a leaf node, cannot delete this \n");
	}
}

void get_parent(char here) {
	int here_pos = searchNode(here);
	printf("%c \n", nodes[here_pos / 2].data);
}

void get_child(char here) {
	int here_pos = searchNode(here);

	if (exists[here_pos * 2]) {
		printf("%c ", nodes[here_pos * 2].data);
	}
	if (exists[(here_pos * 2) + 1]) {
		printf("%c ", nodes[(here_pos * 2) + 1].data);
	}
	printf("\n");
}

void get_sibling(char here) {
	int here_pos = searchNode(here);

	if (here_pos % 2 == 0 && exists[here_pos + 1]) {
		printf("%c \n", nodes[here_pos + 1].data);
	}
	else if (here_pos % 2 != 0 && exists[here_pos - 1]) {
		printf("%c \n", nodes[here_pos - 1].data);
	}
}

void insert_sibling(char here, char input) {
	int here_pos = searchNode(here);

	if (nodes[here_pos].if_root) {
		printf("This is a root node \n");
		return;
	}

	if (here_pos % 2 == 0 && !exists[here_pos + 1]) {
		exists[here_pos + 1] = 1;
		nodes[here_pos + 1].data = input;
		nodeNum++;
	}
	else if (here_pos % 2 != 0 && !exists[here_pos - 1]) {
		exists[here_pos - 1] = 1;
		nodes[here_pos - 1].data = input;
		nodeNum++;

	}
	else {
		printf("Already full \n");
	}
}

void get_ancestors(char here) {
	int now = searchNode(here);

	while (!nodes[now].if_root) {
		now /= 2;
		printf("%c ", nodes[now].data);
	}
	printf("\n");
}

void get_descendants(char here) {
	int here_pos = searchNode(here);

	if (exists[here_pos * 2]) {
		printf("%c ", nodes[here_pos * 2].data);
		get_descendants(nodes[here_pos * 2].data);
	}
	if (exists[(here_pos * 2) + 1]) {
		printf("%c ", nodes[(here_pos * 2) + 1].data);
		get_descendants(nodes[(here_pos * 2) + 1].data);
	}
}

void print_tree(char here)
{
	int here_pos = searchNode(here);

	printf("(");
	printf("%c ", nodes[here_pos].data);

	if (exists[here_pos * 2])
		print_tree(nodes[here_pos * 2].data);
	if (exists[(here_pos * 2) + 1])
		print_tree(nodes[(here_pos * 2) + 1].data);

	printf(")");
}

int level_of_tree(char here) {
	int here_pos = searchNode(here);

	int lev = 0, from_left = 0, from_right = 0;

	if (!exists[here_pos * 2] && !exists[(here_pos * 2) + 1]) {
		lev = 0;
	}
	else {
		lev++;

		if (exists[here_pos * 2]) {
			from_left = level_of_tree(nodes[here_pos * 2].data);
		}
		if (exists[(here_pos * 2) + 1]) {
			from_right = level_of_tree(nodes[(here_pos * 2) + 1].data);
		}
	}

	int bigger = from_left > from_right ? from_left : from_right;
	lev += bigger;

	return lev;
}

void level_of_node(char here) {
	int now = searchNode(here);

	int level = 0;

	while (!nodes[now].if_root) {
		now /= 2;
		level++;
	}
	printf("The level of this node : %d \n", level);
}

int degree_of_tree(char here) {
	int here_pos = searchNode(here);

	int deg = 0, from_left = 0, from_right = 0;

	if (!exists[here_pos * 2] && !exists[(here_pos * 2) + 1]) {
		deg = 0;
	}
	else {

		if (exists[here_pos * 2]) {
			deg++;
			from_left = degree_of_tree(nodes[here_pos * 2].data);
		}
		if (exists[(here_pos * 2) + 1]) {
			deg++;
			from_right = degree_of_tree(nodes[(here_pos * 2) + 1].data);
		}
	}
	int to_compare = from_left > from_right ? from_left : from_right;
	deg = deg > to_compare ? deg : to_compare;

	return deg;

}


void degree_of_node(char here) {
	int here_pos = searchNode(here);

	int degree = 0;

	if (exists[here_pos * 2])
		degree++;
	if (exists[(here_pos * 2) + 1])
		degree++;

	printf("The degree of this node : %d \n", degree);

}

void count_node() {
	printf("The number of nodes : %d \n", nodeNum);
}

void clear() {

	nodes[1].if_root = 0;
	for (int i = 0; i < 100; i++) {
		exists[i] = 0;
		nodes[i].data = 0;
	}

}

int main() {

	clear();
	char command[50];
	printf("Write 'End' to end program.\n");
	printf(" Command: ");
	scanf(" %s", command);
	int len = strlen(command);

	while (strcmp(command, "End") != 0) {
		char c = command[0];

		switch (c) {
		case '+': {
			if (command[1] == '^') {
				create(command[2]);
			}
			else {
				char here = command[1];
				insert_node(here, command[3]);

				if (command[4] == ',') {
					insert_node(here, command[5]);
				}
			}
			break;
		}
		case '-': {
			delete_node(command[1]);

			break;
		}
		case '=': {
			char here = command[2];
			insert_sibling(here, command[4]);
			break;
		}
		case '#': {
			count_node();
			break;
		}
		case 'P': {
			char this = command[2];
			get_parent(this);
			break;
		}
		case 'C': {
			char this = command[2];
			get_child(this);
			break;
		}
		case 'S': {
			char this = command[2];
			get_sibling(this);
			break;
		}
		case 'T': {
			print_tree(nodes[1].data);
			printf("\n");
			break;
		}
		case 'A': {
			char this = command[2];
			get_ancestors(this);
			break;
		}
		case 'D': {
			char this = command[2];
			get_descendants(this);
			printf("\n");
			break;
		}
		case 'G': {
			if (command[1] == '(') {
				char this = command[2];
				degree_of_node(this);
			}
			else {
				int result = degree_of_tree(nodes[1].data);
				printf("The degree of tree : %d \n", result);
			}
			break;
		}
		case 'L': {
			if (command[1] == '(') {
				char this = command[2];
				level_of_node(this);
			}
			else {
				int result = level_of_tree(nodes[1].data);
				printf("The level of tree : %d \n", result);
			}
			break;
		}
		case 'K': {
			clear();
			break;
		}
		}

		for (int i = 0; i < len; i++)
			command[i] = 0;

		printf(" Command: ");
		scanf(" %s", command);
		int len = strlen(command);

	}

	return 0;
}

