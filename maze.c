/*迷宫搜索程序
 * 用数组来表示迷宫，1为墙，0为可走的路。在寻找出口时，用2来标记走过的路
 * 为了避免边界检查，所以在迷宫外加了一圈1（也就是墙），默认入口为maze[1][1]，出口为maze[EXIT_ROW][EXIT_COL]
 * 有8个移动方向，做成了数组，方便调用
 *20120117
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 6	//迷宫的规模，如果修改此处，也要相应修改迷宫数组
#define P 8
#define EXIT_ROW 4	//出口位置
#define EXIT_COL 6
#define MAX_STACK_SIZE 200 //栈的最大长度

typedef struct {
	short int vert;
	short int horiz;
}offsets;
typedef struct {
	short int row;
	short int col;
}element;


//移动方向的数组
offsets move[8] = {
	-1, 0,
	-1, 1,
	0, 1,
	1, 1,
	1, 0,
	1, -1,
	0, -1,
	-1, -1
};
//用于储存的栈
element stack[MAX_STACK_SIZE];
int top;

//对于stack的delete,add操作
element delete (int *top)
{
	(*top)--;
	element new = stack[*top];
	return new;
}

void add (int *top, element position)
{
	stack[*top] = position;
	(*top)++;
}	


//表示迷宫的数组，1代表墙
static int maze[M][P] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
};

//打印迷宫
void printmaze (void)
{
	int i, j;
	printf ("*********************************\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
			printf ("%4d",maze[i][j]);
		printf ("\n");
	}
	printf ("*********************************\n");
}

//迷宫寻路函数
void path (void)
{
	int i, row, col, next_row, next_col, dir, found = false;
	element position;
	top = 1; //top总是为下一个栈的下标
	stack[0].row = 1;
	stack[0].col = 1;
	while (top > -1 && !found)
	{
		position = delete (&top); //弹出一个元素
		row = position.row;
		col = position.col;
		dir = 0;
		maze[row][col] = 2;	//标记为走过
		while (dir < 8 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == EXIT_ROW && next_col == EXIT_COL) //如果找到了出口,标记走过并压栈
			{
				maze[next_row][next_col] = 2;
				position.row = next_row;
				position.col = next_col;
				add (&top,position);
				found = true;
			}
			else if (maze[next_row][next_col] == 0 ) //如果下一步不是墙而且没走过,压栈
			{
				position.row = next_row; 
				position.col = next_col;
				dir++;
				add (&top,position); 
				//printf ("top = %d\n",top);
			}
			else 	//否则尝试下一个方向
				++dir;
		}
		printmaze();//打印迷宫
	}

	if (found)	//如果找到输出找到提示
	{
		printf ("The maze has a path\n");
//		for (i = 0; i < top; i++)
//		{
//			printf ("(%d,%d)\n", stack[i].row, stack[i].col); 
//		}
	}
	else	//否则输出未找到
		printf ("The maze does not have a path\n");
}

//主函数中调用path
int main (void )
{
	path();
	return 0;
}

