#include<stdio.h>

struct cell {
	int mine;
	int mine_count;
	int opened;
	int flagged;
};

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