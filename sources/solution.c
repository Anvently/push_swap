/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 17:43:00 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

/// @brief Do a swap in a if required.
/// @param pile
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
