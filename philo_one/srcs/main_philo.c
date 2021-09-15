/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:19:25 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:23:05 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pre_init(t_philo **phi, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*phi)[i].info = info;
		(*phi)[i].name = i + 1;
		(*phi)[i].t_start = -1;
		(*phi)[i].curent_time = 0;
		(*phi)[i].last_eat = 0;
		(*phi)[i].waf[LEFT] = (*phi)[i].name - 1;
		(*phi)[i].waf[RIGHT] = (*phi)[i].name - 2;
		if ((*phi)[i].waf[RIGHT] < 0)
			(*phi)[i].waf[RIGHT] = info->rules[SUM_PH] - 1;
		(*phi)[i].must_eat = (*phi)[i].info->rules[T_MST_E];
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;
	int				status;

	if (argc < 5 || argc > 6)
		return (ERR_WRONG_ARGC);
	philo = NULL;
	status = philo_pars(argv, &info);
	if (!status)
		if (!(philo = malloc((info.rules[SUM_PH]) * sizeof(t_philo))))
			status = ERR_MALLOC_PHILO;
	if (!status)
	{
		pre_init(&philo, &info);
		status = thread_start(&philo, &info);
	}
	clear_space(&info, &philo);
	return (status);
}
