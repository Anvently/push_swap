/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:17:28 by npirard           #+#    #+#             */
/*   Updated: 2023/12/07 10:01:49 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Return given rotate cost in the opposite action's cost.
/// @param cost
/// @param size
/// @return
int	reverse_cost(int cost, int size)
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

/// @brief Calculate the actual number of rotation for a node
/// (including double rotation if cost have the same sign.)
/// @param rotate_a
/// @param rotate_b
/// @return
int	calc_final_cost(int rotate_a, int rotate_b, int swap_a)
{
	int	cost;

	if ((rotate_a < 0) == (rotate_b < 0))
		cost = ft_max(ft_abs(rotate_a), ft_abs(rotate_b)) + swap_a;
	else
		cost = ft_abs(rotate_a) + ft_abs(rotate_b) + swap_a;
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

	cost_rev_from = calc_final_cost(reverse_cost(node->rotate_a, size_from),
			node->rotate_b, node->swap_a);
	cost_rev_to = calc_final_cost(node->rotate_a,
			reverse_cost(node->rotate_b, size_to), node->swap_a);
	node->cost = calc_final_cost(node->rotate_a, node->rotate_b, node->swap_a);
	if (cost_rev_from < node->cost)
	{
		node->rotate_a = reverse_cost(node->rotate_a, size_from);
		node->cost = cost_rev_from;
	}
	if (cost_rev_to < node->cost)
	{
		node->rotate_b = reverse_cost(node->rotate_b, size_to);
		node->cost = cost_rev_to;
	}
}
