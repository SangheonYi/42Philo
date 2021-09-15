/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:25:10 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				init_forks(t_info *info)
{
	int	i;
	int chk_sum;

	i = 0;
	chk_sum = 0;
	info->dead_phi = 0;
	info->monitor = NULL;
	info->forks = NULL;
	if (!(info->forks =
		malloc((info->rules[SUM_PH]) * sizeof(pthread_mutex_t))))
		return (ERR_MALLOC_FORK);
	while (i < info->rules[SUM_PH])
	{
		if ((chk_sum += pthread_mutex_init(&info->forks[i], NULL)))
			return (ERR_MUTEX_INIT);
		i++;
	}
	chk_sum += pthread_mutex_init(&info->write, NULL);
	chk_sum += pthread_mutex_init(&info->l_check, NULL);
	chk_sum += pthread_mutex_init(&info->last_eat, NULL);
	if (chk_sum)
		return (ERR_MUTEX_INIT);
	return (OK);
}

static int		set_rules(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 2)
		return (ERR_N_EN_PHILO);
	return (OK);
}

int				philo_pars(char **argv, t_info *info)
{
	int	i;
	int	status;

	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = set_rules(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if ((status = init_forks(info)))
		return (status);
	return (OK);
}
