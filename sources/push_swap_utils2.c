/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:40:18 by wzielins          #+#    #+#             */
/*   Updated: 2024/11/28 17:40:32 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_word_count2(char const *str, char c)
{
	int	count;
	int	in_nbr;

	in_nbr = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && in_nbr == 0)
		{
			count++;
			in_nbr = 1;
		}
		else if (*str == c)
			in_nbr = 0;
		str++;
	}
	return (count);
}
/* c is separator, in_nbr is flag*/

long	ft_atol(char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

int	ft_check_int_range(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_number_in_str(char **parts_str, int *nbrs, int i)
{
	long	nbr;

	nbr = ft_atol(parts_str[i]);
	if (ft_check_int_range(nbr) == EXIT_FAILURE)
	{
		free_split(parts_str);
		free(nbrs);
		ft_error();
	}
	nbrs[i] = nbr;
}
