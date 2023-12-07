/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/07 09:53:14 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Check if a swap in pile_a is required and perform it. Special case
///  where only 3 numbers remain.
/// @param pile
void	check_swap(t_pile **pile)
{
	int		min_offset;
	int		max_offset;

	if (pile_size(*pile) < 3)
		return ;
	min_offset = pile_min_offset(*pile);
	max_offset = pile_max_offset(*pile);
	if ((min_offset == 0 && max_offset == 1)
		|| (min_offset == 2 && max_offset == 0)
		|| (min_offset == 1 && max_offset == 2))
		do_action("sa\n", pile, NULL, true);
}

/// @brief Sort a in ascending order and b in descending order. Pile b has to be
/// already sorted, sort_piles only put max of pile_b on top of the pile.
/// @param pile_a
/// @param pile_b
void	sort_piles(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;

	cheapest = pile_new(0);
	if (!cheapest)
	{
		alloc_error();
		free_piles(pile_a, pile_b);
		exit(1);
	}
	check_swap(pile_a);
	while (!pile_is_sort(*pile_a) || pile_max_offset(*pile_b) > 0)
	{
		cheapest->rotate_a = get_true_cost(*pile_a, pile_min_offset(*pile_a));
		cheapest->rotate_b = get_true_cost(*pile_b, pile_max_offset(*pile_b));
		optimize_cost(cheapest, pile_size(*pile_a), pile_size(*pile_b));
		rotate_piles(pile_a, pile_b, cheapest);
	}
	pile_clear(cheapest);
}

/// @brief Put all the number of pile_b on top of pile_a, reverse rotating a
/// if necessary. Both pile have to be sorted first.
/// @param pile_a
/// @param pile_b
void	final_sort(t_pile **pile_a, t_pile **pile_b)
{
	while (*pile_b)
	{
		while (pile_last(*pile_a)->n > (*pile_b)->n
			&& (pile_min_offset(*pile_a) != 0
				|| (pile_closest_sup(*pile_a, (*pile_b)->n) != 0)))
			do_action("rra\n", pile_a, pile_b, true);
		do_action("pa\n", pile_a, pile_b, true);
	}
}

/// @brief Sort the piles. push every number of a (except 3) in b, sorting
/// them in descending order. Then push them back to a, and rotate a
/// if necessary.
/// @param pile_a
/// @param pile_b
void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;

	if (pile_is_sort(*pile_a))
		return ;
	while (pile_size(*pile_a) > 3)
	{
		cheapest = find_cheapest(pile_a, pile_b);
		rotate_piles(pile_a, pile_b, cheapest);
		do_action("pb\n", pile_a, pile_b, true);
	}
	sort_piles(pile_a, pile_b);
	final_sort(pile_a, pile_b);
	while (!pile_is_sort(*pile_a))
		do_action("rra\n", pile_a, pile_b, true);
}
