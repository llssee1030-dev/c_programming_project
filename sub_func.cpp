#include<stdio.h>

struct cell {
	int mine;
	int mine_count;
	int opened;
	int flagged;
};

struct player_input {
	int row;
	int col;
	int action;
};

int select_difficulty() {   //1: Easy, 2: Normal, 3: Hard 반환
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

void print_board(int size, struct cell board[][17]) {   //10/16/17 size 전달받아 출력, 실제 배열은 17x17 사용
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (board[i][j].flagged == 1) {       //깃발이 있는 칸(깃발 없음=0, 깃발 있음=1)
				printf("F  ");
			}
			else if (board[i][j].opened == 0) {   //미공개 칸(미공개 칸=0, 공개 칸=1)
				printf("#  ");
			}
			else {                                //깃발이 없고 공개된 칸
				printf("%d  ", board[i][j].mine_count);
			}
		}
		printf("\n");
	}
}

int validate_input(struct player_input input, int size) {

	if (input.row < 0 || input.row >= size || input.col < 0 || input.col >= size) {   //행과 열 좌표 검사
		return 0;
	}
	else
		return 1;
}

struct player_input get_player_input(int size) {   //int size <- start_game()에서 난이도에 따라 정한 맵 크기를 전달받음
	struct player_input input;
	int val_result;

	do {
		printf("선택할 칸의 행과 열을 입력하시오(0부터 시작): ");
		scanf_s("%d %d", &input.row, &input.col);

		val_result = validate_input(input, size);

		if (val_result == 0) {
			printf("좌표를 다시 입력해주세요.\n\n");
		}
	} while (val_result == 0);

	do {
		printf("행동을 선택하시오(1. 칸 공개, 2. 깃발 설치/제거): ");
		scanf_s("%d", &input.action);

		if (input.action != 1 && input.action != 2) {   //행동 검사
			printf("1 혹은 2를 입력해주세요.\n\n");
		}
	} while (input.action != 1 && input.action != 2);

	return input;
}

void toggle_flag(struct cell board[][17], int row, int col) {
	if (board[row][col].opened == 1) {
		return;
	}
	else if (board[row][col].flagged == 0) {
		board[row][col].flagged = 1;
	}
	else
		board[row][col].flagged = 0;
}

int main(void) {
	struct player_input input;
	input = get_player_input(10);   //테스트용
	return 0;
}