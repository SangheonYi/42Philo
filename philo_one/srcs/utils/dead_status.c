/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:44:53 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:11:40 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	dead_status(t_philo *phi)
{
	phi->info->dead_phi = phi->name;
	mutex_wrap_writing(phi, DEAD, 8, print_dead);
}
