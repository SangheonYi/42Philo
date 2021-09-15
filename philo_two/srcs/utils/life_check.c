/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:31:02 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 13:38:44 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		life_check(t_philo **phi)
{
	int		i;
	ssize_t	starved_time;

	i = 0;
	while (is_absent(*phi))
		usleep(10);
	while (1)
	{
		sem_wait((*phi)->info->last_eat);
		starved_time = cur_time() - (*phi)[i].last_eat;
		sem_post((*phi)->info->last_eat);
		if (starved_time >= (*phi)[i].info->rules[T_DIE] && (*phi)[i].must_eat)
			sem_wrap_chng(&(*phi)[i], (*phi)[i].info->l_check, &dead_status);
		if ((*phi)[i].info->dead_phi || !(*phi)[i].must_eat)
			break ;
		i++;
		if (i == (*phi)->info->rules[SUM_PH])
			i = 0;
		usleep(500);
	}
}
