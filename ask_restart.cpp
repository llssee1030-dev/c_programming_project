#include<stdio.h>

struct cell {
	int mine;
	int mine_count;
	int opened;
	int flagged;
};

int select_difficulty() {
	int diff;

	do {
		printf("난이도를 입력하시오(1. Easy, 2. Normal, 3. Hard): ");
		scanf_s("%d", &diff);
		if (diff < 1 || diff > 3) {
			printf("1~3 중에서 입력하시오.\n\n");
		}
		else {
			return diff;
		}
	} while (diff < 1 || diff > 3);
}

int ask_restart() {   //1: 재시작, 2: 종료 반환
	int re;

	do {
		printf("게임을 다시 진행하시겠습니까?(1. Yes, 2. No): ");
		scanf_s("%d", &re);

		if (re != 1 && re != 2) {
			printf("1 혹은 2를 입력하시오.\n\n");
		}
		else {
			return re;
		}
	} while (re != 1 && re != 2);
}

int main(void) {
	ask_restart();
	return 0;
}