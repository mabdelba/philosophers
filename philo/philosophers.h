/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:03:31 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/24 15:28:33 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	unsigned long	start_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	int				drp;
	pthread_mutex_t	print;
}					t_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	unsigned long	last_meal;
	int				nbr_of_meals;
	t_data			*data;
}					t_philo;

int				ft_parsing(int ac, char **av);
int				ft_isdigit(int c);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
long long		ft_atoi_l(const char	*str);
int				ft_atoi(const char	*str);
t_data			collect_data(int ac, char **av);
void			init_fork_ph(t_data *data, t_philo **ph,
					pthread_mutex_t **fork);
unsigned long	time_actuel(void);
unsigned long	get_time(t_data *data);
#endif 
