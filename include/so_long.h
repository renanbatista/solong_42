#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# include "../MLX42/include/MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
}					t_map;

typedef struct s_control
{
	mlx_t			*mlx;
	t_map			*map;
	int				moviment[4];
	mlx_image_t		*i_back;
	mlx_image_t		*i_pac;
	mlx_image_t		*i_exit;
	mlx_image_t		*i_coll;
	mlx_image_t		*i_wall;
	mlx_texture_t	*t_back;
	mlx_texture_t	*t_pac;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_coll;
	mlx_texture_t	*t_wall;
	int				lm_x;
	int				lm_y;
	int				size_x;
	int				size_y;
	int				player_x;
	int				player_y;
	int				window_w;
	int				window_h;
	int				move_t;
	int				coll_for_exit;
	int				fail_map_validate;
	int				n_moviments;
	int				v_exit;
	int				v_collect;
	int				v_player;
	int				v_retangle;
	int				v_wall;
}					t_control;

void				handle_keypress(mlx_key_data_t keydata, void *param);
void				handle_close(void *param);
void				load_images(t_control *obj);
int					handle_initial_windows(t_control *obj, int args_number,
						char **args);
void				*ft_calloc(size_t nmemb, size_t size);
void				add_new_node_to_last(t_control *obj, char *str);
void				validate_collectable(t_control *obj);
void				validate_exit(t_control *obj);
void				handle_keypress_esc(void *param);
void				make_free_images(t_control *obj);
char				*join_str(char *str, char *str2);
int					ft_atoi(const char *nptr);
void				validate_moviment_w(t_control *obj);
int					handle_validate_map(t_control *obj);
void				print_msg(int type, t_control *obj);
void				ft_bzero(void *s, size_t n);

#endif
