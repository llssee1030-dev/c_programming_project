#include<stdio.h>

struct cell {
	int mine;
	int mine_count;
	int opened;
	int flagged;
};

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

int main(void) {

}