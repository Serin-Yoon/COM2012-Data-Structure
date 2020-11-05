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

	int temp1; // double hashing에 사용
	int temp2; // double hashing에 사용

	// value 계산
	for (int i = 0; i < length; i++) {
		value[i] = key[i] % 170;
	}

	// hash table 2차원 배열 초기화
	for (int i = 0; i < 170; i++) {
		hashtable[i][0] = -1;
		hashtable[i][1] = -1;
	}



	////////////////// 프로그램 시작 //////////////////

	printf(" Key 값과 Value 값을 확인합니다. \n");
	printf("\n - Value = Key mod 170 ");
	printf("\n - 중복 Value가 있을 수 있습니다. \n\n");
	system("pause");
	system("cls");

	// key값, 초기 value값 (중복시 double hashing 후에 적용) 출력

	for (int i = 0; i < length; i++) {
		printf(" - Key (%d) Value (%d) \n\n", key[i], value[i]);
	}
	printf("\n");
	system("pause");
	system("cls");

	// double hashing 적용

	printf(" 중복 Value 값에 한해 Double Hashing을 진행합니다. \n");
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

	// Hash Table 확인

	printf(" Hash Table을 확인합니다. \n");
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