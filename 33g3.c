#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define swh if(isxy == 'o'){isxy = 'x';}else if(isxy == 'x'){isxy = 'o';}

char board[3][5] = {{"..."},{"..."},{"..."}};

bool win(char isxo)
{
	//check x
	int xcount = 0;
	for(int y = 0;y < 3;y++)
	{
		for(int x = 0;x < 3;x++)
		{
			if(board[y][x] == isxo)
			{
				 xcount ++;
			}
		}
		if(xcount == 3)
		{
			return true;
		}
		xcount = 0;
	}
	//check y
	int xcount2 = 0;
	for(int x = 0;x < 3;x++)
	{
		for(int y = 0;y < 3;y++)
		{
			if(board[y][x] == isxo)
			{
				xcount2++;
			}
		}
		if(xcount2 == 3)
		{
			return true;
		}
		xcount2 = 0;
	}
	//check x,y
	if(board[0][0] == isxo && board[1][1] == isxo && board[2][2] == isxo)
	{
		return true;
	}
	else if(board[2][0] == isxo && board[1][1] == isxo && board[0][2] == isxo)
	{
		return true;
	}
	return false;
}

int main(void)
{
	bool end = false;
	char isxy = 'x';
	int nx = 0,ny = 0;
	printf(" 123\n");
	printf("1%s\n", board[0]);
	printf("2%s\n", board[1]);
	printf("3%s\n", board[2]);
	while(end == false)
	{
		swh;
		printf("\n");
		enter:printf("%c-x: ", isxy);
		scanf("%d", &nx);
		printf("\n");
		printf("%c-y: ", isxy);
		scanf("%d", &ny);
		printf("\n");
		if(board[ny - 1][nx - 1] == '.')
		{
			board[ny - 1][nx - 1] = isxy;
		}
		else
		{
			printf("Violation!\n");
			goto enter;
		}
		printf(" 123\n");
		printf("1%s\n", board[0]);
		printf("2%s\n", board[1]);
		printf("3%s\n", board[2]);
		end = win(isxy);
	}
	printf("winner: %c\n", isxy);
	return 0;
}
