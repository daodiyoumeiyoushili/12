#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Row 5
#define Col 5

void Initboard(char board[Row][Col], int row, int col);

void Displayboard(char board[Row][Col], int row, int col);

void PlayerMove(char board[Row][Col], int row, int col);

void ComputerMove(char board[Row][Col], int row, int col);

char Is_Win(char board[Row][Col], int row, int col);
