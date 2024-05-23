/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 17:24:30 by crasche       #+#    #+#                 */
/*   Updated: 2023/07/23 17:24:34 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	generate_matrix(int matrix[4][4], int row, int col, int *nbr);

// setting fixed numbers for found 1
void	fill_fix_1(int matrix[4][4], int i)
{
	if (i / 4 == 0)
		matrix[0][i % 4] = 4;
	if (i / 4 == 1)
		matrix[3][i % 4] = 4;
	if (i / 4 == 2)
		matrix[i % 4][0] = 4;
	if (i / 4 == 3)
		matrix[i % 4][3] = 4;
}

//setting fixed nubmers for 4
void	fill_fix_4_top_bottom(int matrix[4][4], int i)
{
	if (i / 4 == 0)
	{
		matrix[0][i % 4] = 1;
		matrix[1][i % 4] = 2;
		matrix[2][i % 4] = 3;
		matrix[3][i % 4] = 4;
	}
	if (i / 4 == 1)
	{
		matrix[3][i % 4] = 1;
		matrix[2][i % 4] = 2;
		matrix[1][i % 4] = 3;
		matrix[0][i % 4] = 4;
	}
}

//setting fixed nubmers for 4
void	fill_fix_4_left_right(int matrix[4][4], int i)
{
	if (i / 4 == 2)
	{
		matrix[i % 4][0] = 1;
		matrix[i % 4][1] = 2;
		matrix[i % 4][2] = 3;
		matrix[i % 4][3] = 4;
	}
	if (i / 4 == 3)
	{
		matrix[i % 4][3] = 1;
		matrix[i % 4][2] = 2;
		matrix[i % 4][1] = 3;
		matrix[i % 4][0] = 4;
	}
}

// checking for 4 or 1 in input int array to set fixed numbers
int	fill_fixed(int matrix[4][4], int *nbr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (nbr[i] == 1)
			fill_fix_1(matrix, i);
		if (nbr[i] == 4 && i >= 0 && i <= 7)
			fill_fix_4_top_bottom(matrix, i);
		if (nbr[i] == 4 && i >= 8 && i <= 15)
			fill_fix_4_left_right(matrix, i);
		i++;
	}
	generate_matrix(matrix, 0, 0, nbr);
	return (0);
}

// building empty matrix.. filling it with 0
int	build_empty_matrix(int *nbr)
{
	int	matrix[4][4]; 
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
	fill_fixed(matrix, nbr);
	return (0);
}
