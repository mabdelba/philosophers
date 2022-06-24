/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:57 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/24 15:23:56 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_leng(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	pars_size(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: Nombre des args n'est pas valide !\n");
		return (1);
	}
	return (0);
}

int	pars_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '+')
				j++;
			else if (!ft_isdigit(av[i][j]))
			{
				printf("Error: Un arg (ou plus) n'est pas valide !\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	pars_interval(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi_l(av[i]) < 1 || ft_atoi_l(av[i]) > 2147483647)
		{
			printf("Error: Au moins un arg n'est pas valide !\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parsing(int ac, char **av)
{
	if (pars_size(ac) || pars_digit(av) || pars_interval(av))
		return (1);
	return (0);
}
