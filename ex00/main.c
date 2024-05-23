/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:12:22 by crasche       #+#    #+#                 */
/*   Updated: 2023/07/23 17:29:20 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid_col_top(int matrix[4][4], int col, int check);
int		valid_col_bottom(int matrix[4][4], int col, int check);
int		valid_row_left(int matrix[4][4], int row, int check);
int		valid_row_right(int matrix[4][4], int row, int check);
void	print_matrix(int matrix[4][4]);
int		build_empty_matrix(int *nbr);

static int	g_isresult = 0;

// calling validation for each row and column with giving input nubmer
void	valid_view_to_input(int matrix[4][4], int *nbr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((i / 4) == 0 && valid_col_top(matrix, (i % 4), nbr[i]))
			return ;
		if ((i / 4) == 1 && valid_col_bottom(matrix, (i % 4), nbr[i]))
			return ;
		if ((i / 4) == 2 && valid_row_left(matrix, (i % 4), nbr[i]))
			return ;
		if (i / 4 == 3 && valid_row_right(matrix, (i % 4), nbr[i]))
			return ;
		i++;
	}
	print_matrix(matrix);
	g_isresult = 1;
}

// print matrix
void	print_matrix(int matrix[4][4])
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + matrix[i][j];
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

// checking if the input is solvable 
void	is_solvable(int *nbr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (nbr[i] + nbr[i + 4] < 3 || nbr[i] + nbr[i + 4] > 5)
		{
			return ;
		}
		if (nbr[i + 8] + nbr[i + 12] < 3 || nbr[i + 8] + nbr[i + 12] > 5)
		{
			return ;
		}
		i++;
	}
	build_empty_matrix(nbr);
}

// Validating input string, tunring input str to int array
int	valid_str(char *str)
{
	int	nbr[16];
	int	i;

	i = 0;
	while (i < 32 && str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			nbr[i / 2] = str[i] - '0';
		}
		i++;
	}
	if (i != 31 || str[i] != '\0')
	{
		write (1, "Error\n", 6);
		return (1);
	}
	is_solvable(nbr);
	return (0);
}

int	main(int arg_count, char **arg_array)
{
	char	*str;

	str = arg_array[1];
	if (arg_count == 2)
	{
		if (valid_str(str) == 1)
			return (0);
	}
	if (g_isresult == 1)
		return (0);
	else if (g_isresult == 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
}
