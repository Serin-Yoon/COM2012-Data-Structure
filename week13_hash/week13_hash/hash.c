#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {

	int key[137] = {
	512, 1, 513, 515, 4, 6, 7, 522, 524, 13,
	525, 527, 535, 536, 541, 557, 560, 50, 56, 571,
	574, 577, 580, 68, 583, 72, 77, 79, 81, 601,
	89, 613, 614, 616, 110, 113, 628, 116, 121, 130,
	135, 654, 658, 163, 677, 681, 173, 686, 692, 182,
	705, 194, 716, 205, 722, 727, 217, 730, 734, 226,
	742, 743, 753, 755, 757, 245, 252, 265, 778, 268,
	274, 275, 795, 798, 301, 817, 818, 307, 829, 831,
	833, 321, 324, 332, 845, 339, 342, 854, 858, 348,
	353, 354, 360, 361, 362, 876, 365, 881, 376, 888,
	894, 895, 896, 897, 387, 389, 390, 395, 398, 911,
	913, 407, 920, 921, 412, 925, 418, 932, 936, 937,
	940, 434, 439, 442, 956, 446, 958, 449, 968, 970,
	461, 463, 977, 992, 491, 496, 503
	};
	int value[170];
	int hashtable[170][2];

	int length = sizeof(key) / sizeof(int);

	int temp1; // double hashing�� ���
	int temp2; // double hashing�� ���

	// value ���
	for (int i = 0; i < length; i++) {
		value[i] = key[i] % 170;
	}

	// hash table 2���� �迭 �ʱ�ȭ
	for (int i = 0; i < 170; i++) {
		hashtable[i][0] = -1;
		hashtable[i][1] = -1;
	}



	////////////////// ���α׷� ���� //////////////////

	printf(" Key ���� Value ���� Ȯ���մϴ�. \n");
	printf("\n - Value = Key mod 170 ");
	printf("\n - �ߺ� Value�� ���� �� �ֽ��ϴ�. \n\n");
	system("pause");
	system("cls");

	// key��, �ʱ� value�� (�ߺ��� double hashing �Ŀ� ����) ���

	for (int i = 0; i < length; i++) {
		printf(" - Key (%d) Value (%d) \n\n", key[i], value[i]);
	}
	printf("\n");
	system("pause");
	system("cls");

	// double hashing ����

	printf(" �ߺ� Value ���� ���� Double Hashing�� �����մϴ�. \n");
	printf("\n");
	system("pause");
	system("cls");

	for (int i = 0; i < length; i++) {
		printf("\n Value %d >> %d \n", i, value[i]);
		if ((hashtable[value[i]][0] < 0) && (hashtable[value[i]][1] < 0)) {
			hashtable[value[i]][0] = key[i];
			hashtable[value[i]][1] = value[i];
		}
		else if ((hashtable[value[i]][0] >= 0) || (hashtable[value[i]][1] >= 0)) {

			for (int j = 0; j < 182; j++) {
				temp1 = key[i] % 170;
				temp2 = 182 - (key[i] % 182);
				value[i] = (temp1 + temp2 * j) % 170;
				if ((hashtable[value[i]][0] < 0) && (hashtable[value[i]][1] < 0)) break;
				else continue;
			}
			hashtable[value[i]][0] = key[i];
			hashtable[value[i]][1] = value[i];
		}
	}
	printf("\n");
	system("pause");
	system("cls");

	// Hash Table Ȯ��

	printf(" Hash Table�� Ȯ���մϴ�. \n");
	printf("\n");
	system("pause");
	system("cls");

	printf(" < Hash Table> \n\n");
	for (int i = 0; i < 170; i++) {
		if (hashtable[i][0] == -1) {
			printf(" table %d | empty \n\n", i);
		}
		else {
			printf(" table %d | key %d \n\n", i, hashtable[i][0]);
		}
	}
	return 0;
}