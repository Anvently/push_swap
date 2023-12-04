/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:49:20 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 12:56:26 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Allocate a new pile node
/// @param n
/// @return ```NULL``` if allocation error.
t_pile	*pile_new(int n)
{
	t_pile	*node;

	node = malloc(sizeof(t_pile));
	if (!node)
		return (alloc_error());
	node->prev = NULL;
	node->n = n;
	return (node);
}

/// @brief Add given node to the top of the pile.
/// @param pile Chained list pile, can be empty
/// @param node If ```NULL``` pile is cleared.
/// @return ```node``` or ```NULL``` if pile was cleared.
t_pile	*pile_add_top(t_pile *pile, t_pile *node)
{
	if (!node)
		return (pile_clear(pile));
	if (!pile)
		return (node);
	node->prev = pile;
	return (node);
}

/// @brief Add given node at the end of the list
/// @param pile Chained list pile, can be empty
/// @param node If ```NULL``` pile is cleared.
/// @return ```node``` or ```NULL``` if pile was cleared.
t_pile	*pile_add_back(t_pile *pile, t_pile *node)
{
	if (!node)
		return (pile_clear(pile));
	if (!pile)
		return (node);
	pile_last(pile)->prev = node;
	return (pile);
}

/// @brief Return last node of the pile.
/// @param pile
/// @return
t_pile	*pile_last(t_pile *pile)
{
	while (pile->prev)
		pile = pile->prev;
	return (pile);
}

/// @brief Clear and free pile
/// @param pile
/// @return ```NULL```
void	*pile_clear(t_pile *pile)
{
	t_pile	*prev;

	while (pile)
	{
		prev = pile->prev;
		free(pile);
		pile = prev;
	}
	return (NULL);
}
