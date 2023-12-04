/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:08:14 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 16:15:45 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Swap 2 first element at the top of the pile
/// @param pile Can be ```NULL``` or can contain only one node.
/// @return Top of the pile after the swap.
void	do_swap(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*top;

	if (!*pile || !(*pile)->prev)
		return ;
	temp = (*pile)->prev->prev;
	top = (*pile)->prev;
	top->prev = *pile;
	(*pile)->prev = temp;
	*pile = top;
}

/// @brief
/// @param pile_a
/// @param pile_b
void	do_swap_swap(t_pile **pile_a, t_pile **pile_b)
{
	do_swap(pile_a);
	do_swap(pile_b);
}
