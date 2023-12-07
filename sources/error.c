/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:25:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/07 09:37:36 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* bool	error_input(int error)
{
	ft_putstr_fd("Error when parsing the input : ", 2);
	if (error == 1)
		ft_putendl_fd("no arguments was given.", 2);
	else if (error == 2)
		ft_putendl_fd("incorrect number format.", 2);
	else if (error == 3)
		ft_putendl_fd("number already in pile.", 2);
	else if (error == 4)
		ft_putendl_fd("number cannot be contained within an int.", 2);
	else if (error == 5)
		ft_putendl_fd("unknown action.", 2);
	return (false);
} */

bool	error_input(int error)
{
	if (error != 1)
		ft_putendl_fd("Error.", 2);
	return (false);
}

void	free_and_exit(t_pile *pile, char **strs, int error)
{
	if (strs)
		ft_free_strings(strs);
	pile_clear(pile);
	if (error == -1)
		alloc_error();
	else if (error > 0)
		error_input(error);
	exit(error);
}

void	free_piles(t_pile **pile_a, t_pile **pile_b)
{
	pile_clear(*pile_a);
	pile_clear(*pile_b);
	*pile_a = NULL;
	*pile_b = NULL;
}
