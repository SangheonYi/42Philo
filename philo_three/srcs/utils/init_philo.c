/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:15:32 by hmin              #+#    #+#             */
/*   Updated: 2021/02/25 13:45:01 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	init_philo(t_philo *phi)
{
	phi->t_start = cur_time();
	phi->last_eat = phi->t_start;
}