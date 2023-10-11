/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:07 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/11 20:42:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, size_t x, size_t y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->btpx / 8));
	*(unsigned int*)dst = color;
}

void	ft_window(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width = 100;
	int		img_height = 100;
	t_data	wimg;

	map->size *= 25;
	map->len *= 25;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len, map->size, "The dungeons");
	wimg.wimg = mlx_new_image(mlx, map->len, map->size);
	wimg.addr = mlx_get_data_addr(wimg.wimg, &wimg.btpx, &wimg.len, &wimg.end);
	img = mlx_xpm_file_to_image(mlx, "../sprites/xpm/Walls/Wall_v3.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
