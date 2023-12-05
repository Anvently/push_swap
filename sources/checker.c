/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:42:43 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 10:26:43 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	listen_actions(t_pile **pile_a, t_pile **pile_b)
{
	char	*line;

	line = ft_gnl(0);
	while (line)
	{
		do_action(line, pile_a, pile_b);
		piles_print(*pile_a, *pile_b);
		get_cost(*pile_b, (*pile_a)->n);
		free(line);
		line = ft_gnl(0);
	}
	if (pile_is_sort(*pile_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int narg, char **vargs)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = parse_input(narg, vargs);
	pile_b = NULL;
	listen_actions(&pile_a, &pile_b);
	pile_clear(pile_a);
	pile_clear(pile_b);
	return (0);
}
