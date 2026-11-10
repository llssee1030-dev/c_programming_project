#include<stdio.h>

struct player_input {
	int row;
	int col;
	int action;
};

int validate_input(struct player_input input, int size) {
	int type;

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

int main(void) {
	struct player_input input;
	input = get_player_input(10);   //테스트용 Easy 버전
	return 0;
}