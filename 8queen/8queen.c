#include <stdio.>
#include <stdbool.h>

void print_arr(char arr[8][8]);
bool is_valid_pos(int i, int j, char arr[8][8]);
bool has_collide(int check_row, int check_col, int queen_row, int queen_col);

int main() {
	char chess[8][8];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			chess[i][j]='-';
		}
	}

	int backward_flag;
	int j = 0;
	int last_queen_col_index = -1;
	int last_queen_row_index = -1;
	for(int i=0; i<8; i++) {
		backward_flag = true;
		for(j = last_queen_col_index + 1; j<8; j++) {
			if(is_valid_pos(i, j, chess)) {
				printf("row: %d, col: %d are valid.", i, j);
				chess[i][j] = '+';
				backward_flag = false;
				break;
			}
		}

		if(backward_flag) {
			last_queen_row_index = i - 1;
			for(int col = 0; col < 8; col++){
				if(chess[last_queen_row_index][col] == '+') {
					chess[last_queen_row_index][col] = '-';
					last_queen_col_index = col;
					break;
				}
			}

			//we need search the row before this one
			i -= 2;
		} else {
			last_queen_col_index = -1;
		}

		print_arr(chess);
		printf("\n");
	}

	print_arr(chess);
}

bool is_valid_pos(int i, int j, char arr[8][8]) {
	printf("checking for %d, %d\n", i, j);
	int queen_row = i - 1;
	bool valid_pos = true;
	while(queen_row >= 0) {
		for(int queen_col = 0; queen_col < 8; queen_col++) {
			if(arr[queen_row][queen_col] == '+') {
				if(has_collide(i, j, queen_row, queen_col) ){
					valid_pos = false;
					break;	
				}
				break;
			}
		}

		if(!valid_pos) {
			break;
		}	

		queen_row--;
	}

	return valid_pos;
}

bool has_collide(int check_row, int check_col, int queen_row, int queen_col) {
	bool has_collide = false;	

	//row
	//no need to check for row collide


	//col
	if(check_col == queen_col) {
		return true;
	}

	//italic
	//no need to check aria 1 and 2 of circle

	// +row, -col
	for(int i = queen_row + 1, j = queen_col - 1; i < 8 && j > -1; i++, j--) {
		if(i == check_row && j == check_col) {
			return true;
		}
	}

	// +row, +col
	for(int i = queen_row + 1, j = queen_col + 1; i < 8 && j < 8; i++, j++) {
		if(i == check_row && j == check_col) {
			return true;
		}
	}


	return has_collide;
}

void print_arr(char arr[8][8]){
	printf("\n\t");

	for(int i=0; i<8; i++) {
		printf("%d\t", i);	
	}

	printf("\t");

	for(int i=0; i<8; i++) {
		printf("\n%d\t", i);
		for(int j=0; j<8; j++){
			printf("%c\t", arr[i][j]);
		}
	}

	printf("\n");

}
