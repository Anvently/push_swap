/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:09:20 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 14:27:10 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Return penultimate node of the pile
/// @param pile
/// @return
static t_pile	*pile_before_last(t_pile *pile)
{
	t_pile	*current;

	if (!pile || !pile->prev || !pile->prev->prev)
		return (pile);
	current = pile;
	while (current->prev->prev)
		current = current->prev;
	return (current);
}

void	do_rotate(t_pile **pile)
{
	t_pile	*temp;

	temp = (*pile)->prev;
	pile_last(*pile)->prev = *pile;
	(*pile)->prev = NULL;
	*pile = temp;
}

void	do_rev_rotate(t_pile **pile)
{
	t_pile	*penultimate;

	penultimate = pile_before_last(*pile);
	if (!penultimate || !penultimate->prev)
		return ;
	penultimate->prev->prev = *pile;
	*pile = penultimate->prev;
	penultimate->prev = NULL;
}

void	do_rotate_rotate(t_pile **pile_a, t_pile **pile_b)
{
	do_rotate(pile_a);
	do_rotate(pile_b);
}

void	do_rev_rotate_rotate(t_pile **pile_a, t_pile **pile_b)
{
	do_rev_rotate(pile_a);
	do_rev_rotate(pile_b);
}
