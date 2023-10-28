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
	//��������
	char board[Row][Col] = { 0 };
	//��ʼ������
	Initboard(board, Row, Col);
	//��ӡ����
	Displayboard(board, Row, Col);
	while (1)
	{
		//�������
		PlayerMove(board, Row, Col);
		ret = Is_Win(board, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);


	return 0;
}