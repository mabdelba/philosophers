/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:53:44 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/24 14:14:17 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	time_actuel(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

unsigned long	get_time(t_data *data)
{
	return (time_actuel() - data->start_time);
}

t_data	collect_data(int ac, char **av)
{
	t_data	data;

	data.number_of_philosophers = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data.number_must_eat = ft_atoi(av[5]);
	else
		data.number_must_eat = 0;
	data.start_time = time_actuel();
	data.drp = 0;
	pthread_mutex_init(&(data.print), NULL);
	return (data);
}

void	init_fork_ph(t_data *data, t_philo **ph, pthread_mutex_t **fork)
{
	int	i;

	*ph = malloc((data->number_of_philosophers) * sizeof(t_philo));
	*fork = malloc((data->number_of_philosophers) * sizeof(pthread_mutex_t));
	if (!*fork)
		return ;
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&(*fork)[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		(*ph)[i].id = i + 1;
		(*ph)[i].right_fork = &(*fork)[i];
		(*ph)[i].left_fork = &(*fork)[(i + 1) % data->number_of_philosophers];
		(*ph)[i].nbr_of_meals = 0;
		(*ph)[i].last_meal = 0;
		(*ph)[i].data = data;
		i++;
	}
}
