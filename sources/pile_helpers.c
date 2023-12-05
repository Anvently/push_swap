/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:27:54 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 14:34:56 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

/// @brief Assign the maximum number of the pile to ```max``` and return
/// it index.
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

/// @brief Return offset of closest smaller number of n in pile.
/// @param pile
/// @param n
/// @return ```-1``` if pile is empty or no index found.
int	pile_closest_offset(t_pile *pile, int n)
{
	int	i;
	int	i_closest;
	int	diff;

	i = 0;
	i_closest = -1;
	diff = 0;
	while (pile)
	{
		if (pile->n < n && (i_closest < 0 || n - pile->n < diff))
		{
			i_closest = i;
			diff = n - pile->n;
		}
		i++;
		pile = pile->prev;
	}
	return (i_closest);
}
