/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:24:57 by npirard           #+#    #+#             */
/*   Updated: 2023/12/07 09:57:06 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

/// @brief Check if given str have a valid number format.
/// @param str
/// @return
bool	check_input_str(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (false);
	return (true);
}

/// @brief Check if given number is already contained in the pile.
/// @param pile
/// @param n
/// @return
bool	check_double(t_pile *pile, int n)
{
	while (pile)
	{
		if (pile->n == n)
			return (false);
		pile = pile->prev;
	}
	return (true);
}

/// @brief Return a pile containing all given numbers if valid. Numbers can be
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
	if (narg <= 1)
	{
		error_input(1);
		exit(0);
	}
	i = 1;
	while (i < narg)
		pile_a = parse_arg(pile_a, vargs[i++]);
	return (pile_a);
}

/// @brief Add given numbers to the pile.
/// @param str string containing 1 or more numbers separated with spaces.
/// @return Pile. Allocation or input error are handled. No need to check for
/// ```NULL```.
t_pile	*parse_arg(t_pile *pile_a, char *str)
{
	int		n;
	int		i;
	char	**strs;

	strs = ft_split(str, ' ');
	if (!strs)
		free_and_exit(pile_a, strs, -1);
	i = 0;
	while (strs[i])
	{
		if (!check_input_str(strs[i]))
			free_and_exit(pile_a, strs, 2);
		if (ft_strtoi(strs[i], &n))
			free_and_exit(pile_a, strs, 4);
		if (!check_double(pile_a, n))
			free_and_exit(pile_a, strs, 3);
		pile_a = pile_add_back(pile_a, pile_new(n));
		if (!pile_a)
			free_and_exit(pile_a, strs, -1);
		i++;
	}
	ft_free_strings(strs);
	return (pile_a);
}
