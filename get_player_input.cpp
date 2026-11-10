#include<stdio.h>

struct player_input {
	int row;
	int col;
	int action;
};

struct player_input get_player_input() {
	struct player_input input;

	printf("선택할 칸의 행과 열을 입력하시오(0부터 시작): ");
	scanf_s("%d %d", &input.row, &input.col);

	printf("행동을 선택하시오(1. 칸 공개, 2. 깃발 설치/제거): ");
	scanf_s("%d", &input.action);

	return input;
}