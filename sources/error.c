/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:25:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 14:21:37 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	error_input(int error)
{
	ft_putstr_fd("Error when parsing the input : ", 2);
	if (error == 1)
		ft_putendl_fd("no arguments was given.", 2);
	else if (error == 2)
		ft_putendl_fd("incorrect number format.", 2);
	else if (error == 3)
		ft_putendl_fd("number already in pile.", 2);
	return (false);
}

bool	check_input_str(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (error_input(2));
	return (true);
}

bool	check_narg(int narg)
{
	if (narg <= 1)
		return (error_input(1));
	return (true);
}

bool	check_double(t_pile *pile, int n)
{
	while (pile)
	{
		if (pile->n == n)
			return (error_input(3));
		pile = pile->prev;
	}
	return (true);
}
