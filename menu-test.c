#include "ms.h"

int		close_pls(void *param)
{
	(void)param;
	exit(0);
}

void	draw_filled_box(t_mlx *mlx, t_drawing *d)
{
	int			i;
	int			k;

	k = -1;
	while (++k < d->h)
	{
		i = -1;
		while (++i < d->w)
			mlx_pixel_put(mlx->mlx, mlx->win, d->x + i, d->y + k, d->color);
	}
}

void draw_empty_box(t_mlx *m, t_drawing *d)
{
	int x;
	int y;
	int i;
	int k;

	x = d->x;
	y = d->y;
	k = 3;
	while (k--)
	{
		i = d->w;
		while (--i)
			mlx_pixel_put(m->mlx, m->win, x + i, y + k, d->color);
	}
	y = d->y;
	k = 3;
	while (k--)
	{
		i = d->h;
		while (--i)
			mlx_pixel_put(m->mlx, m->win, x + k, y + i, d->color);
	}
	x = d->x;
	y += d->h;
	k = 3;
	while (k--)
	{
		i = d->w;
		while (--i)
			mlx_pixel_put(m->mlx, m->win, x + i, y - k, d->color);
	}
	y = d->y;
	x = d->x + d->w;
	k = 3;
	while (k--)
	{
		i = d->h;
		while (--i)
			mlx_pixel_put(m->mlx, m->win, x - k, y + i, d->color);
	}
}

void draw_cross_box(t_mlx *m, t_drawing *d)
{
	int x;
	int y;

	draw_empty_box(m, d);
	x = d->x;
	y = d->y + d->h;
	while (y != d->y)
	{
		mlx_pixel_put(m->mlx, m->win, x++, y--, d->color);
	}
}

void draw_boxes_line_vert(t_mlx *m, t_drawing d, int size,
								void (*draw)(t_mlx *, t_drawing *))
{
	int	i;

	i = -1;
	while (++i < size)
	{
		draw(m, &d);
		d.y += d.h;
	}
}

void draw_boxes_line_hor(t_mlx *m, t_drawing d, int size,
						  void (*draw)(t_mlx *, t_drawing *))
{
	int	i;

	i = -1;
	while (++i < size)
	{
		draw(m, &d);
		d.x += d.w;
	}
}

void draw_stick_vertical(t_mlx *m, t_drawing d, int size,
							void (*draw)(t_mlx *, t_drawing *))
{
	if (draw == &draw_cross_box)
	{
		draw_boxes_line_vert(m, d, size, draw);
		return ;
	}
	d.h *= size;
	draw(m, &d);
}

void draw_stick_horizontal(t_mlx *m, t_drawing d, int size,
							void (*draw)(t_mlx *, t_drawing *))
{
	if (draw == &draw_cross_box)
	{
		draw_boxes_line_hor(m, d, size, draw);
		return ;
	}
	d.w *= size;
	draw(m, &d);
}

int		draw_a(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h * 2;
	d.x -= d.w;
	draw_stick_vertical(m, d, 4, draw);
	d.x += d.w * 3;
	draw_stick_vertical(m, d, 4, draw);
	return (5);
}

int		draw_b(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h;
	d.x += d.w * 2;
	draw(m, &d);
	d.y += d.h * 2;
	draw(m, &d);
	d.x -= d.w * 2;
	d.y += d.h;
	draw_stick_horizontal(m, d, 2, draw);
	return (5);
}

int		draw_c(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w;
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 2, draw);
	return (4);
}

int		draw_d(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x += d.w * 2;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x -= d.w * 2;
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 2, draw);
	return (5);
}

int		draw_e(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 2;
	draw(m, &d);
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 2, draw);
	return (4);
}

int		draw_f(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 2;
	draw(m, &d);
	return (4);
}

int		draw_g(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w;
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 2, draw);
	d.x += d.w;
	d.y -= d.h;
	draw(m, &d);
	return (4);
}

int		draw_h(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h * 2;
	draw_stick_vertical(m, d, 5, draw);
	return (4);
}

int		draw_i(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw(m, &d);
	d.x += d.w;
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw(m, &d);
	d.y += d.h * 4;
	draw(m, &d);
	d.x -= d.w * 2;
	draw(m, &d);
	return (4);
}

int		draw_j(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw(m, &d);
	d.x += d.w;
	draw_stick_vertical(m, d, 4, draw);
	d.x += d.w;
	draw(m, &d);
	d.y += d.h * 4;
	d.x -= d.w * 2;
	draw(m, &d);
	return (4);
}

int		draw_k(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h * 2;
	draw_stick_vertical(m, d, 2, draw);
	d.y += d.h * 3;
	draw_stick_vertical(m, d, 2, draw);
	return (4);
}

int		draw_l(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.y += d.h * 4;
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	return (4);
}

int		draw_m(t_mlx *m, t_drawing d,
				 void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h;
	draw_stick_vertical(m, d, 5, draw);
	return (6);
}

int		draw_n(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.y += d.h;
	d.x += d.w;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h * 3;
	draw_stick_vertical(m, d, 5, draw);
	return (5);
}

int		draw_o(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w * 3;
	draw_stick_vertical(m, d, 3, draw);
	d.x -= d.w * 2;
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 2, draw);
	return (5);
}

int		draw_p(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h;
	d.x += d.w * 2;
	draw(m, &d);
	return (5);
}

int		draw_q(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w * 3;
	draw_stick_vertical(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.y += d.h;
	d.x -= d.w;
	draw_stick_horizontal(m, d, 3, draw);
	return (5);
}

int		draw_r(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_p(m, d, draw);
	d.x += d.w * 2;
	d.y += d.h * 3;
	draw(m, &d);
	d.y += d.h;
	d.x += d.w;
	draw(m, &d);
	return (5);
}

int		draw_s(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 3, draw);
	d.x -= d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw_stick_horizontal(m, d, 2, draw);
	d.x += d.w * 2;
	d.y += d.h;
	draw(m, &d);
	d.x -= d.w * 3;
	d.y += d.h;
	draw_stick_horizontal(m, d, 3, draw);
	return (5);
}

int		draw_t(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	d.x += d.w;
	draw_stick_vertical(m, d, 4, draw);
	return (4);
}

int		draw_u(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 4, draw);
	d.x += d.w;
	d.y += d.h * 4;
	draw_stick_horizontal(m, d, 2, draw);
	d.x += d.w * 2;
	d.y -= d.h * 4;
	draw_stick_vertical(m, d, 4, draw);
	return (5);
}

int		draw_v(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 4, draw);
	d.x += d.w;
	d.y += d.h * 4;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h * 4;
	draw_stick_vertical(m, d, 4, draw);
	return (4);
}

int		draw_w(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 4, draw);
	d.y += d.h;
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 3, draw);
	d.y -= d.h;
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 4, draw);
	d.y += d.h * 4;
	d.x -= d.w;
	draw(m, &d);
	d.x -= d.w * 2;
	draw(m, &d);
	return (6);
}

int		draw_x(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 2, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 2, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 2, draw);
	return (4);
}

int		draw_y(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 2, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h * 2;
	draw_stick_vertical(m, d, 3, draw);
	return (4);
}

int		draw_z(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 4, draw);
	d.y += d.h * 4;
	draw_stick_horizontal(m, d, 4, draw);
	d.y -= d.h;
	draw(m, &d);
	d.y -= d.h;
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h;
	d.x += d.w * 2;
	draw(m, &d);
	return (5);
}

int		draw_zero(t_mlx *m, t_drawing d,
				  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w;
	draw(m, &d);
	d.x += d.w;
	draw_stick_vertical(m, d, 5, draw);
	d.y += d.h * 4;
	d.x -= d.w;
	draw(m, &d);
	return (4);
}

int		draw_one(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_vertical(m, d, 4, draw);
	d.y += d.h;
	d.x -= d.w;
	draw(m, &d);
	d.y += d.h * 3;
	draw_stick_horizontal(m, d, 3, draw);
	return (4);
}

int		draw_two(t_mlx *m, t_drawing d,
					void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 3, draw);
	d.x += d.w * 2;
	d.y += d.h;
	draw(m, &d);
	d.y += d.h;
	d.x -= d.w * 2;
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	draw(m, &d);
	d.y += d.h;
	draw_stick_horizontal(m, d, 3, draw);
	return (4);
}

int		draw_three(t_mlx *m, t_drawing d,
					void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 3, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 4, draw);
	d.x -= d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.y += d.h * 2;
	d.x -= d.w;
	draw_stick_horizontal(m, d, 3, draw);
	return (4);
}

int		draw_four(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w;
	d.y += d.h * 2;
	draw(m, &d);
	d.x += d.w;
	d.y -= d.h * 2;
	draw_stick_vertical(m, d, 5, draw);
	return (4);
}

int		draw_five(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	draw(m, &d);
	d.y += d.h;
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 3, draw);
	d.y -= d.h;
	d.x += d.w * 2;
	draw(m, &d);
	return (4);
}

int		draw_six(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.y += d.h * 2;
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h;
	d.x += d.w;
	draw(m, &d);
	return (4);
}

int		draw_seven(t_mlx *m, t_drawing d,
					void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	draw(m, &d);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 4, draw);
	return (4);
}

int		draw_eight(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 5, draw);
	d.x -= d.w;
	draw(m, &d);
	d.y += d.h * 2;
	draw(m, &d);
	d.y += d.h * 2;
	draw(m, &d);
	return (4);
}

int		draw_nine(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 5, draw);
	d.x -= d.w;
	draw(m, &d);
	d.y += d.h * 2;
	draw(m, &d);
	return (4);
}

int		draw_less(t_mlx *m, t_drawing d,
			   void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w * 2;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	return (4);
}

int draw_more(t_mlx *m, t_drawing d,
			   void (*draw)(t_mlx *, t_drawing *))
{
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw(m, &d);
	return (4);
}

int draw_space(t_mlx *m, t_drawing d,
			  void (*draw)(t_mlx *, t_drawing *))
{
	(void) m;
	(void) d;
	(void) draw;
	return (4);
}

int		draw_ex_mark(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 3, draw);
	d.y += d.h * 4;
	draw(m, &d);
	return (2);
}

int		draw_quotes(t_mlx *m, t_drawing d,
						void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 2, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 2, draw);
	return (4);
}

int		draw_hash(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_vertical(m, d, 5, draw);
	d.x += d.w * 2;
	draw_stick_vertical(m, d, 5, draw);
	d.x -= d.w * 3;
	d.y += d.h;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.x -= d.w * 4;
	d.y += d.h * 2;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	return (6);
}

int		draw_dollar(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_horizontal(m, d, 4, draw);
	d.y += d.h;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m ,&d);
	d.x -= d.w * 2;
	d.y += d.h;
	draw_stick_horizontal(m, d, 4, draw);
	d.y += d.h;
	d.x += d.w;
	draw(m ,&d);
	d.x += d.w * 2;
	draw(m ,&d);
	d.x -= d.w * 3;
	d.y += d.h;
	draw_stick_horizontal(m, d, 4, draw);
	d.y += d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y -= d.h * 6;
	d.x += d.w;
	draw(m ,&d);
	return (5);
}

int		draw_procent(t_mlx *m, t_drawing d,
					   void (*draw)(t_mlx *, t_drawing *))
{
	draw(m ,&d);
	d.y += d.h * 4;
	draw(m ,&d);
	d.y -= d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y -= d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y -= d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y -= d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y += d.h * 4;
	draw(m ,&d);
	return (6);
}

int		draw_and(t_mlx *m, t_drawing d,
						void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.x -= d.w;
	d.y += d.h;
	draw(m ,&d);
	d.y += d.h;
	d.x += d.w;
	draw(m ,&d);
	d.y += d.h;
	d.x -= d.w;
	draw(m ,&d);
	d.y += d.h;
	d.x += d.w;
	draw_stick_horizontal(m, d, 3, draw);
	d.y -= d.h;
	d.x += d.w;
	draw_stick_horizontal(m, d, 2, draw);
	d.y -= d.h;
	d.x += d.w;
	draw(m ,&d);
	return (5);
}

int		draw_quote(t_mlx *m, t_drawing d,
					   void (*draw)(t_mlx *, t_drawing *))
{
	draw_stick_vertical(m, d, 2, draw);
	return (2);
}

int		draw_open_round_s(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x += d.w;
	d.y += d.h * 3;
	draw(m, &d);
	return (3);
}

int		draw_close_round_s(t_mlx *m, t_drawing d,
							 void (*draw)(t_mlx *, t_drawing *))
{
	draw(m, &d);
	d.x += d.w;
	d.y += d.h;
	draw_stick_vertical(m, d, 3, draw);
	d.x -= d.w;
	d.y += d.h * 3;
	draw(m, &d);
	return (3);
}

int		draw_star(t_mlx *m, t_drawing d,
							  void (*draw)(t_mlx *, t_drawing *))
{
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.y += d.h;
	d.x -= d.w * 3;
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	d.x -= d.w;
	draw_stick_horizontal(m, d, 5, draw);
	d.y += d.h;
	d.x += d.w;
	draw_stick_horizontal(m, d, 3, draw);
	d.y += d.h;
	d.x -= d.w;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	d.x += d.w * 2;
	draw(m, &d);
	return (6);
}

int		draw_plus(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	d.x -= d.w;
	d.y += d.h;
	draw_stick_horizontal(m, d, 3, draw);
	d.x += d.w;
	d.y += d.h;
	draw(m, &d);
	return (4);
}

int		draw_comma(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	d.y += d.h * 4;
	draw_stick_vertical(m, d, 2, draw);
	return (2);
}

int		draw_minus(t_mlx *m, t_drawing d,
					 void (*draw)(t_mlx *, t_drawing *))
{
	d.y += d.h * 2;
	draw_stick_horizontal(m, d, 3, draw);
	return (4);
}

int		draw_dot(t_mlx *m, t_drawing d,
					  void (*draw)(t_mlx *, t_drawing *))
{
	d.y += d.h * 4;
	draw(m, &d);
	return (2);
}

int		draw_slash_right(t_mlx *m, t_drawing d,
					void (*draw)(t_mlx *, t_drawing *))
{
	d.x += d.w * 2;
	draw(m, &d);
	d.y += d.h;
	d.x -= d.w;
	draw_stick_vertical(m, d, 3, draw);
	d.x -= d.w;
	d.y += d.h * 3;
	draw(m, &d);
	return (2);
}

void cast_symbols1(t_func *func_list)
{
	func_list[1] = draw_ex_mark;
	func_list[2] = draw_quotes;
	func_list[3] = draw_hash;
	func_list[4] = draw_dollar;
	func_list[5] = draw_procent;
	func_list[6] = draw_and;
	func_list[7] = draw_quote;
	func_list[8] = draw_open_round_s;
	func_list[9] = draw_close_round_s;
	func_list[10] = draw_star;
	func_list[11] = draw_plus;
	func_list[12] = draw_comma;
	func_list[13] = draw_minus;
	func_list[14] = draw_dot;
	func_list[15] = draw_slash_right;
}

void cast_numbers(t_func *func_list)
{
	func_list[55] = draw_x;
	func_list[56] = draw_y;
	func_list[57] = draw_z;
	func_list[16] = draw_zero;
	func_list[17] = draw_one;
	func_list[18] = draw_two;
	func_list[19] = draw_three;
	func_list[20] = draw_four;
	func_list[21] = draw_five;
	func_list[22] = draw_six;
	func_list[23] = draw_seven;
	func_list[24] = draw_eight;
	func_list[25] = draw_nine;
	func_list[0] = draw_space;
	cast_symbols1(func_list);
}

void cast_letters(t_func *func_list)
{
	func_list[32] = draw_a;
	func_list[33] = draw_b;
	func_list[34] = draw_c;
	func_list[35] = draw_d;
	func_list[36] = draw_e;
	func_list[37] = draw_f;
	func_list[38] = draw_g;
	func_list[39] = draw_h;
	func_list[40] = draw_i;
	func_list[41] = draw_j;
	func_list[42] = draw_k;
	func_list[43] = draw_l;
	func_list[44] = draw_m;
	func_list[45] = draw_n;
	func_list[46] = draw_o;
	func_list[47] = draw_p;
	func_list[48] = draw_q;
	func_list[49] = draw_r;
	func_list[50] = draw_s;
	func_list[51] = draw_t;
	func_list[52] = draw_u;
	func_list[53] = draw_v;
	func_list[54] = draw_w;
	cast_numbers(func_list);
}

void draw_string_with_boxes(t_mlx *mlx, t_drawing d,
							void (*draw)(t_mlx *, t_drawing *), const char *str)
{
	t_func			func_list[100];
	int i;
	int ch;

	cast_letters(func_list);
	i = -1;
	while (str[++i])
	{
		ch = str[i];
		if ((ch -= 32) > 64 && ch <= 90)
			ch -= 33;
		else if (ch > 90)
			ch -= 27;
		d.x += d.w * func_list[ch](mlx, d, draw);
	}
}

void draw_ms_logo(t_mlx *m, int where, int size, int color)
{
	t_drawing	d;

	d.color = color;
	d.y = where / SCREEN_WIDTH;
	d.x = where % SCREEN_WIDTH;
	d.w = size;
	d.h = size;
	draw_string_with_boxes(m, d, &draw_cross_box, "mineswapper");
}

void draw_menu_par1(t_mlx *m, t_drawing d, int mode)
{
	if (mode == 1)
		d.color = RED_B_COLOR;
	d.x += d.w * draw_p(m, d, &draw_filled_box);
	d.x += d.w * draw_l(m, d, &draw_filled_box);
	d.x += d.w * draw_a(m, d, &draw_filled_box);
	draw_y(m, d, &draw_filled_box);
}

void draw_menu_par2(t_mlx *m, t_drawing d, int mode)
{
	if (mode == 2)
		d.color = RED_B_COLOR;
	d.x += d.w * draw_o(m, d, &draw_filled_box);
	d.x += d.w * draw_p(m, d, &draw_filled_box);
	d.x += d.w * draw_t(m, d, &draw_filled_box);
	d.x += d.w * draw_i(m, d, &draw_filled_box);
	d.x += d.w * draw_o(m, d, &draw_filled_box);
	d.x += d.w * draw_n(m, d, &draw_filled_box);
	draw_s(m, d, &draw_filled_box);
}

void draw_menu_par3(t_mlx *m, t_drawing d, int mode)
{
	if (mode == 3)
		d.color = RED_B_COLOR;
	d.x += d.w * draw_e(m, d, &draw_filled_box);
	d.x += d.w * draw_x(m, d, &draw_filled_box);
	d.x += d.w * draw_i(m, d, &draw_filled_box);
	draw_t(m, d, &draw_filled_box);
}

void draw_menu_selectors(t_mlx *m, t_drawing d, int mode)
{
	d.color = RED_B_COLOR;
	d.x = 550;
	d.y = 300 + mode * 200;
	draw_more(m, d, &draw_filled_box);
	d.x = 990;
	draw_less(m, d, &draw_filled_box);
}

void draw_menu(t_ms *ms, int where, int size, int color)
{
	t_drawing	d;
	t_mlx		m;

	m = ms->mlx;
	d.color = color;
	d.y = where / SCREEN_WIDTH;
	d.x = where % SCREEN_WIDTH;
	d.w = size;
	d.h = size;
	draw_menu_par1(&m, d, ms->selected_opt);
	d.x = 625;
	d.y = 700;
	draw_menu_par2(&m, d, ms->selected_opt);
	d.x = 700;
	d.y = 900;
	draw_menu_par3(&m, d, ms->selected_opt);
	draw_menu_selectors(&m, d, ms->selected_opt);

	d.x = 0;
	d.y = 1000;
	draw_string_with_boxes(&ms->mlx, d, &draw_filled_box, "0123456789 !\"#$%&'()*+-,./");
}

/*

void	draw_fdf(t_mlx *m, int x, int y, int color)
{
	draw_fdf_f(m, x, y, color);
	draw_fdf_d(m, x + 200, y, color);
	draw_fdf_f(m, x + 600, y, color);
}

void	draw_start(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 1)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_s(m, x, y, color);
	draw_t(m, x + 50, y, color);
	draw_a(m, x + 90, y, color);
	draw_r(m, x + 140, y, color);
	draw_t(m, x + 190, y, color);
}

void	draw_options(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 2)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_o(m, x, y, color);
	draw_p(m, x + 50, y, color);
	draw_t(m, x + 100, y, color);
	draw_i(m, x + 140, y, color);
	draw_o(m, x + 180, y, color);
	draw_n(m, x + 230, y, color);
	draw_s(m, x + 280, y, color);
}

void	draw_exit(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 3)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_e(m, x, y, color);
	draw_x(m, x + 40, y, color);
	draw_i(m, x + 80, y, color);
	draw_t(m, x + 120, y, color);
}

typedef struct s_code
{
	int c;
	int	opened_opt;
	int	options[5];
	t_mlx *mlx;
}				t_code;

void draw_menu(t_mlx *m, t_code *code)
{
	draw_fdf(m, 400, 100, 0x0000FF00);
	mlx_string_put(m->mlx, m->win, 700, 500, 0x0000FF00,
				   "by jjerde and ftothmur!");
	draw_start(m, 700, 600, code->c);
	draw_options(m, 650, 800, code->c);
	draw_exit(m, 750, 1000, code->c);
	draw_more(m, 600, 400 +code->c * 200, 0x00FF0000);
	draw_less(m, 990, 400 +code->c * 200, 0x00FF0000);
}

void	draw_opt_a(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 1)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_c(m, x, y, color);
	draw_o(m, x + 40, y, color);
	draw_n(m, x + 90, y, color);
	draw_t(m, x + 140, y, color);
	draw_r(m, x + 180, y, color);
	draw_o(m, x + 230, y, color);
	draw_l(m, x + 280, y, color);
	draw_s(m, x + 320, y, color);
}

void	draw_opt_b(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 2)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_c(m, x, y, color);
	draw_o(m, x + 40, y, color);
	draw_l(m, x + 90, y, color);
	draw_o(m, x + 130, y, color);
	draw_r(m, x + 180, y, color);
	draw_s(m, x + 230, y, color);
}

void	draw_opt_c(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 3)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_d(m, x, y, color);
	draw_e(m, x + 40, y, color);
	draw_b(m, x + 80, y, color);
	draw_u(m, x + 120, y, color);
	draw_g(m, x + 160, y, color);
	draw_i(m, x + 270, y, color);
	draw_n(m, x + 310, y, color);
	draw_f(m, x + 360, y, color);
	draw_o(m, x + 400, y, color);
}

void	draw_opt_d(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 4)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_i(m, x, y, color);
	draw_n(m, x + 40, y, color);
	draw_f(m, x + 90, y, color);
	draw_i(m, x + 130, y, color);
	draw_n(m, x + 170, y, color);
	draw_i(m, x + 220, y, color);
	draw_t(m, x + 260, y, color);
	draw_y(m, x + 300, y, color);
	draw_a(m, x + 400, y, color);
	draw_m(m, x + 450, y, color);
	draw_m(m, x + 510, y, color);
	draw_o(m, x + 570, y, color);
}

void	draw_opt_e(t_mlx *m, int x, int y, int code)
{
	int color;

	if (code == 5)
		color = 0x00FF0000;
	else
		color = WHITE_COLOR;
	draw_b(m, x, y, color);
	draw_a(m, x + 40, y, color);
	draw_c(m, x + 90, y, color);
	draw_k(m, x + 130, y, color);
}

void	draw_checkboxes(t_code *code)
{
	t_drawing d;
	int	i;

	d.x = 150;
	d.w = 50;
	d.h = 50;
	i = 0;
	while (++i < 5)
	{
		d.y = i * 150 + 200;
		d.color = WHITE_COLOR;
		if (i == code->c)
			d.color = RED_COLOR;
		if (code->options[i - 1])
			draw_cross_box(code->mlx, &d);
		else
			draw_empty_box(code->mlx, &d);
	}
}

void	params(t_code *code)
{
	mlx_clear_window(code->mlx->mlx, code->mlx->win);
	draw_options(code->mlx, 650, 200, WHITE_COLOR);
	draw_checkboxes(code);
	draw_opt_a(code->mlx, 350, 350, code->c);
	draw_opt_b(code->mlx, 350, 500, code->c);
	draw_opt_c(code->mlx, 350, 650, code->c);
	draw_opt_d(code->mlx, 350, 800, code->c);
	draw_opt_e(code->mlx, 350, 950, code->c);
}

int up_down(int key, void *vcode)
{
	t_code *code;
	int		mode;

	code = (t_code *)vcode;
	mlx_clear_window(code->mlx->mlx, code->mlx->win);
	mode = 0;
	if (code->opened_opt)
		mode = 1;
	if (key == 126)
	{
		if (code->c != 1)
			code->c -= 1;
	} else if (key == 125)
	{
		if ((!mode && code->c != 3) || (mode && code->c != 5))
			code->c += 1;
	} else if (key == 53)
		close_pls(NULL);
	else if (key == 36)
	{
		if (!mode && code->c == 3)
			close_pls(NULL);
		else if (!mode && code->c == 2)
		{
			code->opened_opt = 1;
			code->c = 1;
		}
		else if (mode && code->c == 5)
		{
			code->c = 2;
			code->opened_opt = 0;
		}
		else if (mode)
		{
			if (code->options[code->c - 1])
				code->options[code->c - 1] = 0;
			else
				code->options[code->c - 1] = 1;
		}
	}
	if (code->opened_opt)
		params(code);
	else
		draw_menu(code->mlx, code);
	return (1);
}
*/

void	ms_init(t_ms *ms)
{
	ft_bzero(ms, sizeof(t_ms));
	ms->selected_opt = 1;
	ms->config[0] = 1;
}

int main(void)
{
	t_mlx	mlx;
	t_ms	ms_data;

	ms_init(&ms_data);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	ms_data.mlx = mlx;
	draw_ms_logo(&mlx, 100 * SCREEN_WIDTH + 100, 25, ORANGE_COLOR);
	draw_menu(&ms_data, 500 * SCREEN_WIDTH + 700, 10, WHITE_COLOR);

	//mlx_hook(mlx.win, 2, 1UL << 0UL, up_down, &code);
	mlx_hook(mlx.win, 17, 0, close_pls, NULL);
	mlx_loop(mlx.mlx);
	return (0);
}