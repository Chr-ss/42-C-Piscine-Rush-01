/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_pos.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 17:24:52 by crasche       #+#    #+#                 */
/*   Updated: 2023/07/23 17:24:53 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	valid_view_to_input(int matrix[4][4], int *nbr);
void	generate_matrix(int matrix[4][4], int row, int col, int *nbr);
void	print_matrix(int matrix[4][4]);

// check if current number is a valid match in row
int	is_row_valid(int matrix[4][4], int row, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[row][i] == num)
			return (0);
		i++;
	}
	return (1);
}

// check if current number is a valid match in col
int	is_col_valid(int matrix[4][4], int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

// if a cell with a fixed number is found this cell is skipped
void	go_to_next_cell(int matrix[4][4], int row, int col, int *nbr)
{
	int	next_row;
	int	next_col;

	if (row == 4) 
	{
		valid_view_to_input(matrix, nbr);
		return ;
	}
	next_row = row;
	next_col = col + 1;
	if (next_col == 4)
	{
		next_row++;
		next_col = 0;
	}
	generate_matrix(matrix, next_row, next_col, nbr);
}

// filling matrix with numbers recursively with backtracking 
void	generate_matrix(int matrix[4][4], int row, int col, int *nbr)
{
	int	num;

	if (row == 4) 
	{
		valid_view_to_input(matrix, nbr);
		return ;
	}
	if (matrix[row][col] != 0)
	{
		go_to_next_cell(matrix, row, col, nbr);
		return ;
	}
	num = 1;
	while (num <= 4) 
	{
		if (is_row_valid(matrix, row, num) && is_col_valid(matrix, col, num))
		{
			matrix[row][col] = num;
			go_to_next_cell(matrix, row, col, nbr);
			matrix[row][col] = 0;
		}
		num++;
	}
}
