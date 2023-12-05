/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:04:29 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 16:09:29 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	reverse_cost(int cost, int size)
{
	if (cost >= 0)
		return (cost - size);
	else
		return (cost + size);
}

/// @brief Calculate the true cost of a move taking the reverse rotate into
/// account. If rr are more efficient, the returned offset will be a negative
/// integer.
/// @param pile
/// @param offset
/// @return
int	get_true_cost(t_pile *pile, int offset)
{
	int	size;

	size = pile_size(pile);
	if (ft_abs(offset) > ft_abs(reverse_cost(offset, size)))
		return (reverse_cost(offset, size));
	return (offset);
}

/// @brief Return number of required rotate to do to place number in pile.
/// @param pile
/// @param n
/// @return Positive number for normal rotate.
/// Negative number for reverse rotate.
int	get_cost(t_pile *pile, int n)
{
	int	best;

	best = pile_closest_offset(pile, n);
	if (best < 0)
		best = pile_max_offset(pile);
	if (best < 0)
		best = 0;
	return (get_true_cost(pile, best));
}

/// @brief Calculate the actual number of rotation for a node
/// (including double rotation if cost have the same sign.)
/// @param rotate_from
/// @param rotate_to
/// @return
int	calc_final_cost(int rotate_from, int rotate_to)
{
	int	cost;

	if ((rotate_from < 0) == (rotate_to < 0))
		cost = ft_max(ft_abs(rotate_from), ft_abs(rotate_to));
	else
		cost = ft_abs(rotate_from) + ft_abs(rotate_to);
	return (cost);
}

/// @brief Check if cost can be optimize by using reversing rotate
/// on one of the base.
/// @param node
/// @param size_from
/// @param size_to
void	optimize_cost(t_pile *node, int size_from, int size_to)
{
	int	cost_rev_from;
	int	cost_rev_to;

	cost_rev_from = calc_final_cost(reverse_cost(node->rotate_from, size_from),
			node->rotate_to);
	cost_rev_to = calc_final_cost(node->rotate_from,
			reverse_cost(node->rotate_to, size_to));
	node->cost = calc_final_cost(node->rotate_from, node->rotate_to);
	if (cost_rev_from < node->cost)
	{
		node->rotate_from = reverse_cost(node->rotate_from, size_from);
		node->cost = cost_rev_from;
	}
	if (cost_rev_to < node->cost)
	{
		node->rotate_to = reverse_cost(node->rotate_to, size_to);
		node->cost = cost_rev_to;
	}
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
		pile_from->rotate_from = get_true_cost(head_from, i);
		pile_from->rotate_to = get_cost(head_to, pile_from->n);
		optimize_cost(pile_from, pile_size(head_from), pile_size(head_to));
		if (!pile_from->rotate_from && !pile_from->rotate_to)
			return ;
		pile_from = pile_from->prev;
		i++;
	}
}
