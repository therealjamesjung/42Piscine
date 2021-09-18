#ifndef _DATA_H_
#define _DATA_H_

typedef struct s_data
{
	int *col_u;
	int *col_d;
	int *row_l;
	int *row_r;
	int n;
} t_data;

typedef struct s_point
{
	int x;
	int y;
	int value;
} t_point;

#endif