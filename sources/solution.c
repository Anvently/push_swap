/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 18:16:30 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (*pile_a)
		push_to_b(pile_a, pile_b);
	while (pile_max_offset(*pile_b) != 0)
		do_action("rb\n", pile_a, pile_b);
	while (*pile_b)
		do_action("pa\n", pile_a, pile_b);
}
