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
			printf("1~3 중에서 입력해주세요.\n\n");
		}
		else {
			return diff;
		}
	} while (diff < 1 || diff > 3);
}

int main(void) {
	select_difficulty();

	return 0;
}