/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:16:13 by aliens            #+#    #+#             */
/*   Updated: 2022/04/03 20:06:04 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	error_msg2(int error)
{
	if (error == 12)
		printf("Invalid resolution\n");
	else if (error == 13)
		printf("Invalid map infos declaration\n");
}

void	error_msg_bonus(int error)
{
	if (error == 1)
		return ;
	printf("Error\n");
	if (error == 2)
		printf("Invalid textures\n");
	else if (error == 3)
		printf("Invalid character in map\n");
	else if (error == 4)
		printf("Malloc Error\n");
	else if (error == 5)
		printf("Invalid argument\nUsage : ./cub3D_bonus <path_to_map.cub>\n");
	else if (error == 6)
		printf("Map does not exist\n");
	else if (error == 7)
		printf("Map is not closed\n");
	else if (error == 8)
		printf("No player on map\n");
	else if (error == 9)
		printf("Too much player on map\n");
	else if (error == 10)
		printf("Invalid color\nUsage : C or F <0~255>, <0~255>, <0~255>\n");
	else if (error == 11)
		printf("Multiple map infos declaration\n");
	error_msg2(error);
}
