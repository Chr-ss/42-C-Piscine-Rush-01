/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_valid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 17:24:39 by crasche       #+#    #+#                 */
/*   Updated: 2023/07/23 17:24:40 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int matrix[4][4]);

// validating each row from the top
int	valid_col_top(int matrix[4][4], int col, int check)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 1;
	while (j < 3 && (j + k) < 4)
	{
		if (matrix[j][col] > matrix[j + k][col])
			k++;
		else if (matrix[j][col] < matrix[j + k][col])
		{
			j = j + k;
			i++;
			k = 1;
		}
	}
	if (i == check)
		return (0);
	else 
		return (1);
}

// validating each row from the bottom
int	valid_col_bottom(int matrix[4][4], int col, int check)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 3;
	k = 1;
	while (j > 0 && (j - k) >= 0)
	{
		if (matrix[j][col] > matrix[j - k][col])
			k++;
		else if (matrix[j][col] < matrix[j - k][col])
		{
			j = j - k;
			i++;
			k = 1;
		}
	}
	if (i == check)
		return (0);
	else 
		return (1);
}

// validating each column from the left
int	valid_row_left(int matrix[4][4], int row, int check)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 1;
	while (j < 3 && (j + k) < 4)
	{
		if (matrix[row][j] > matrix[row][j + k])
			k++;
		else if (matrix[row][j] < matrix[row][j + k])
		{
			j = j + k;
			i++;
			k = 1;
		}
	}
	if (i == check)
		return (0);
	else 
		return (1);
}

// validating each column from the right 
int	valid_row_right(int matrix[4][4], int row, int check)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 3;
	k = 1;
	while (j >= 1 && (j - k) >= 0)
	{
		if (matrix[row][j] > matrix[row][j - k])
			k++;
		else if (matrix[row][j] < matrix[row][j - k])
		{
			j = j - k;
			i++;
			k = 1;
		}
	}
	if (i == check)
		return (0);
	else 
		return (1);
}
