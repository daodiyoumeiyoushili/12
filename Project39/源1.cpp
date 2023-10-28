#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("**1.play   0.exit  **\n");
	printf("*********************\n");
}
void game()
{
	char ret = 0;
	//创建棋盘
	char board[Row][Col] = { 0 };
	//初始化棋盘
	Initboard(board, Row, Col);
	//打印棋盘
	Displayboard(board, Row, Col);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, Row, Col);
		ret = Is_Win(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, Row, Col);
		Is_Win(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		Displayboard(board, Row, Col);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	Displayboard(board, Row, Col);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);


	return 0;
}