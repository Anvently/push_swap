/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:04:29 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 16:19:25 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Return number of required rotate to do to place number in pile.
/// @param pile
/// @param n
/// @return Positive number for normal rotate.
/// Negative number for reverse rotate.
int	get_cost(t_pile *pile, int n)
{
	int	best;

	best = pile_closest_inf(pile, n);
	if (best < 0)
		best = pile_max_offset(pile);
	if (best < 0)
		best = 0;
	return (get_true_cost(pile, best));
}

/// @brief For every node of pile_from, calculate the cost of moving
/// them at the proper location in pile_to.
/// @param pile_from
/// @param pile_to
void	calc_costs(t_pile *pile_from, t_pile *pile_to)
{
	int		i;
	t_pile	*head_from;
	t_pile	*head_to;

	i = 0;
	head_from = pile_from;
	head_to = pile_to;
	while (pile_from)
	{
		pile_from->rotate_a = get_true_cost(head_from, i);
		pile_from->rotate_b = get_cost(head_to, pile_from->n);
		optimize_cost(pile_from, pile_size(head_from), pile_size(head_to));
		if (!pile_from->rotate_a && !pile_from->rotate_b)
			return ;
		pile_from = pile_from->prev;
		i++;
	}
}

t_pile	*find_cheapest(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*cheapest;
	t_pile	*current;

	calc_costs(*pile_from, *pile_to);
	current = *pile_from;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->prev;
	}
	return (cheapest);
}

/// @brief Return offset of closest smaller number of n in pile.
/// @param pile
/// @param n
/// @return ```-1``` if pile is empty or no index found.
int	pile_closest_inf(t_pile *pile, int n)
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

/// @brief Return offset of closest smaller number of n in pile.
/// @param pile
/// @param n
/// @return ```-1``` if pile is empty or no index found.
int	pile_closest_sup(t_pile *pile, int n)
{
	int	i;
	int	i_closest;
	int	diff;

	i = 0;
	i_closest = -1;
	diff = 0;
	while (pile)
	{
		if (pile->n > n && (i_closest < 0 || pile->n - n < diff))
		{
			i_closest = i;
			diff = pile->n - n;
		}
		i++;
		pile = pile->prev;
	}
	return (i_closest);
}
