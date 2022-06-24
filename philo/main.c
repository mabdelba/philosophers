/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:42:06 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/24 14:23:49 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(t_data *data, t_philo *ph, char *str)
{
	pthread_mutex_lock(&(data->print));
	printf("%ld %d %s\n", get_time(data), ph->id, str);
	pthread_mutex_unlock(&(data->print));
}

void	*routine(void *ptr)
{
	t_philo	*ph;

	ph = (t_philo *)ptr;
	if (ph->id % 2 == 0)
		usleep(ph->data->time_to_eat * 1000 / 2);
	while (1)
	{
		pthread_mutex_lock(ph->right_fork);
		ft_print(ph->data, ph, "has taken a fork");
		pthread_mutex_lock(ph->left_fork);
		ft_print(ph->data, ph, "has taken a fork");
		ph->last_meal = get_time(ph->data);
		ft_print(ph->data, ph, "is eating");
		usleep(ph->data->time_to_eat * 1000);
		ph->nbr_of_meals++;
		pthread_mutex_unlock(ph->right_fork);
		pthread_mutex_unlock(ph->left_fork);
		if (ph->nbr_of_meals >= ph->data->number_must_eat
			&& ph->data->number_must_eat)
			return (ph->data->drp++, ptr);
		ft_print(ph->data, ph, "is sleeping");
		usleep(ph->data->time_to_sleep * 1000);
		ft_print(ph->data, ph, "is thinking");
	}
	return (ptr);
}

void	check_death(t_philo	*ph, t_data *data)
{
	int	i;

	while (1)
	{
		usleep(100);
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (data->drp >= data->number_of_philosophers)
				return ;
			else if ((get_time(data) - ph[i].last_meal) > data->time_to_die)
			{
				pthread_mutex_lock(&(data->print));
				printf("%ld %d died\n", get_time(data), ph[i].id);
				return ;
			}
			i++;
		}
	}
}

void	create_philo(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&(ph[i].philo), NULL, routine, ph + i);
		i++;
	}
	check_death(ph, data);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*fork;

	if (ft_parsing(ac, av))
		return (1);
	data = collect_data(ac, av);
	init_fork_ph(&data, &philo, &fork);
	create_philo(&data, philo);
	free(philo);
	free(fork);
	return (0);
}
