#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

char					**ft_init(int size);
int						ft_solve(t_list **pieces, int size);
void					ft_check_width_height(t_list **current);
t_list					*parse_input(int fd, t_list **pieces);
/*typedef struct		s_fillit
{
	int						;
	char					;
	struct					*next;
}							t_fillit;
*/
#endif
