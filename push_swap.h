# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/incs/libft.h"



///////////////////////////////
//   Nombres de mouvements   //
///////////////////////////////
typedef struct s_nb_move
{
	int	sa;
	int	ra;
	int	rra;
	int pa;
	int sb;
	int rb;
	int rrb;
	int pb;
	int ss;
	int	rr;
	int	rrr;
}				t_nb_move;



/////////////////////////
//   Norme fill_list   //
/////////////////////////
typedef struct s_fill_list
{
	int	temp;
	int	neg;
	int	i;
	int	j;
}				t_fill_list;



//////////////////////////////
//   Structure Principale   //
//////////////////////////////
typedef struct s_struct
{
	t_fill_list fl;
	t_nb_move move_nb;
	t_list  *list_a;
	t_list  *list_b;
	int	*sort_tab;
	int	nb_int;
	int nb_a;
	int nb_b;
	int	nb_move;
	int	min_i;
	int	check_tiny;
	int	visual;
	int	nb_ra;
	int	nb_rra;
	int max_rank;
}			   t_struct;

char	*sa(t_struct *data);
char	*sb(t_struct *data);
char	*ss(t_struct *data);

char	*ra(t_struct *data);
char	*rb(t_struct *data);
char	*rr(t_struct *data);

char	*rra(t_struct *data);
char	*rrb(t_struct *data);
char	*rrr(t_struct *data);

char	*pa(t_struct *data);
char	*pb(t_struct *data);



#endif 