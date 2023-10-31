/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:51 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/31 13:20:07 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_text	ft_init_tx(t_data data, t_text text)
{
	char	*path;

	path = "./sprites/xpm/Text/Text.xpm";
	text.tx = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	text.img_x = 6;
	text.img_y = 8;
	path = "./sprites/xpm/Text/Null.xpm";
	text.nl = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/0.xpm";
	text.ze = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/1.xpm";
	text.on = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/2.xpm";
	text.tw = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/3.xpm";
	text.tr = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/4.xpm";
	text.fo = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/5.xpm";
	text.fi = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/6.xpm";
	text.si = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/7.xpm";
	text.se = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	return (text);
}

static void	ft_paint_num(t_player *p, char num, size_t x, size_t y)
{
	if (num == '0')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.ze, x, y);
	if (num == '1')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.on, x, y);
	if (num == '2')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.tw, x, y);
	if (num == '3')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.tr, x, y);
	if (num == '4')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.fo, x, y);
	if (num == '5')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.fi, x, y);
	if (num == '6')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.si, x, y);
	if (num == '7')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.se, x, y);
	if (num == '8')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.ei, x, y);
	if (num == '9')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.ni, x, y);
	if (num == '\0')
		mlx_put_image_to_window(p->data.mlx, p->data.mlx_win, p->text.nl, x, y);
}

static void	ft_print_num(t_player *player, size_t num, size_t x, size_t y)
{
	size_t	cnt;
	char	*itoa;

	cnt = 0;
	itoa = ft_unsig_tobase(num, 'd');
	if (itoa)
	{
		while (itoa[cnt])
		{
			ft_paint_num(player, itoa[cnt], x, y);
			x += 7;
			cnt++;
		}
		if (cnt == 1)
		{
			while (cnt < 6)
			{
				ft_paint_num(player, '\0', x, y);
				x += 7;
				cnt++;
			}
		}
		free(itoa);
		itoa = NULL;
	}
}

void	ft_act_stat(t_player *player)
{
	ft_print_num(player, player->steps, 119, 30);
	ft_print_num(player, player->rem, 119, 41);
}

t_text	ft_init_text(t_player *player)
{
	char	*path;
	t_data	data;
	t_text	text;

	data = player->data;
	text.img_x = 90;
	text.img_y = 30;
	text = ft_init_tx(data, text);
	text.img_x = 6;
	text.img_y = 8;
	path = "./sprites/xpm/Text/8.xpm";
	text.ei = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	path = "./sprites/xpm/Text/9.xpm";
	text.ni = mlx_xpm_file_to_image(data.mlx, path, &text.img_x, &text.img_y);
	mlx_put_image_to_window(data.mlx, data.mlx_win, text.tx, 75, 25);
	player->text = text;
	ft_act_stat(player);
	return (text);
}
