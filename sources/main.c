/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:10:20 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 16:20:06 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int narg, char **vargs)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = parse_input(narg, vargs);
	pile_b = NULL;
	if (pile_a)
		sort_pile(&pile_a, &pile_b);
	pile_clear(pile_a);
	pile_clear(pile_b);
	return (0);
}
