#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������壬���������꣺");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//����Ϸ��ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã����������룺\n");
				break;
			}
		}
		else
		{
			printf("����Ƿ������������룺\n");
			break;
		}
	}
}
void ComputerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % 5;
		//���������0 1 2 3 4;
		y = rand() % 5;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//���ˣ�����1
//����������0
char Is_Full(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Is_Win(char board[Row][Col], int row, int col)
{
	//������
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
			board[i][2] == board[i][3] && board[i][3] == board[i][4] &&
			board[i][4] != ' ')
		{
			return board[i][2];
		}
	}
	//������
	for (j = 0; j < col; j++)
	{

		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] &&
			board[2][j] == board[3][j] && board[3][j] == board[4][j] &&
			board[4][j] != ' ')
			return board[1][j];
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[2][2] == board[2][2] &&
		board[2][2] == board[3][3] && board[3][3] == board[4][4] &&
		board[4][4] != ' ')

	{
		return board[1][1];
	}
	if (board[0][4] == board[1][3] && board[1][3] == board[2][2] &&
		board[2][2] == board[3][1] && board[3][1] == board[4][0] &&
		board[4][0] != ' ')
		return board[0][4];
	//û����Ӯ��ƽ��
	if (Is_Full(board, Row, Col))
	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}