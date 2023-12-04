/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:24:57 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 16:23:37 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	free_and_exit(t_pile *pile, char **strs)
{
	if (strs)
		ft_free_strings(strs);
	pile_clear(pile);
	exit(1);
}

/// @brief Return a list containing all given numbers if valid. Numbers can be
/// given as a succesion of strings or contained within in a stirng and
/// separated with spaces. Both presentation format can occur at the same time.
/// @param narg Number of string given as input
/// @param vargs List of strings
/// @return t_pile or ```NULL``` if format error or allocation error.
t_pile	*parse_input(int narg, char **vargs)
{
	t_pile	*pile_a;
	int		i;

	pile_a = NULL;
	if (!check_narg(narg))
		return (NULL);
	i = 1;
	while (i < narg)
		pile_a = parse_arg(pile_a, vargs[i++]);
	if (!pile_a)
	{
		error_input(1);
		exit(0);
	}
	return (pile_a);
}

/// @brief Add given numbers to the list.
/// @param str string containing 1 or more numbers separated with spaces.
/// @return List or ```NULL``` if format or allocation error.
t_pile	*parse_arg(t_pile *pile_a, char *str)
{
	int		n;
	int		i;
	char	**strs;

	strs = ft_split(str, ' ');
	if (!strs)
	{
		alloc_error();
		free_and_exit(pile_a, strs);
	}
	i = 0;
	while (strs[i])
	{
		n = ft_atoi(strs[i]);
		if (!check_input_str(strs[i]) || !check_double(pile_a, n))
			free_and_exit(pile_a, strs);
		pile_a = pile_add_back(pile_a, pile_new(n));
		if (!pile_a)
			free_and_exit(pile_a, strs);
		i++;
	}
	ft_free_strings(strs);
	return (pile_a);
}
