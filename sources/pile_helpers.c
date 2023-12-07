/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:27:54 by npirard           #+#    #+#             */
/*   Updated: 2023/12/07 09:54:44 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Return pile size
/// @param pile
/// @return
int	pile_size(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->prev;
		i++;
	}
	return (i);
}

/// @brief Check if a pile is sorted in ascending order.
/// @param pile
/// @return ```true``` if pile is sorted, else ```false```.
bool	pile_is_sort(t_pile *pile)
{
	while (pile)
	{
		if (pile->prev && pile->prev-> n < pile->n)
			return (false);
		pile = pile->prev;
	}
	return (true);
}

/// @brief Return index of maximum node in the list
/// @param pile
/// @param n
/// @return ```-1``` if pile is empty.
int	pile_max_offset(t_pile *pile)
{
	int	i_max;
	int	max;
	int	i;

	i_max = -1;
	i = 0;
	while (pile)
	{
		if (i_max < 0 || pile->n > max)
		{
			max = pile->n;
			i_max = i;
		}
		i++;
		pile = pile->prev;
	}
	return (i_max);
}

/// @brief Return the index of minimum node in the list
/// @param pile
/// @param n
/// @return ```-1``` if pile is empty.
int	pile_min_offset(t_pile *pile)
{
	int	i_min;
	int	min;
	int	i;

	i_min = -1;
	i = 0;
	while (pile)
	{
		if (i_min < 0 || pile->n < min)
		{
			min = pile->n;
			i_min = i;
		}
		i++;
		pile = pile->prev;
	}
	return (i_min);
}
