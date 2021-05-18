#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

///////////////////////////////
//   Nombres de mouvements   //
///////////////////////////////
typedef struct s_nb_move
{
	int	sa;
	int	ra;
	int	rra;
	int	pa;
	int	sb;
	int	rb;
	int	rrb;
	int	pb;
	int	ss;
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
	t_fill_list	fl;
	t_nb_move	move_nb;
	t_list		*list_a;
	t_list		*list_b;
	int			*sort_tab;
	int			nb_int;
	int			nb_a;
	int			nb_b;
	int			nb_move;
	int			min_i;
	int			check_tiny;
	int			visual;
	int			nb_ra;
	int			nb_rra;
	int			max_rank;
}				t_struct;

////////////////////////
////  FILL_LIST.C  /////
////////////////////////
void	fill_list(t_struct *d, char **av);

//////////////////
///// MOVE.C /////
//////////////////
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

//////////////////
///// UTLIS.C ////
//////////////////
void	error(t_struct *data);
void	clean_data(t_struct *data);

//////////////////
///// CHECK.C ////
//////////////////
void	check_av(t_struct *data, char **av, int ac);
void	check_list(t_struct *data);
int		check_tri(t_list *list);
int		check_unsort(t_list *list);
int		check_sort(t_struct *data);
int		check_is_tiny(t_struct *data, int value);
int		check_tiny(t_list *list);
int		check_index_tiny(t_list *list);
int		check_ra_rra_rank_inf(t_list *list, t_struct *data, int div);

///////////////////////
////  RANK_LIST.C  ////
///////////////////////
int		*sort_tab(int *sort, int size);
void	rank_list(int *tab, t_list *list, t_struct *data);
int		*find_sort(t_list *list, t_struct *data);

///////////////////////
///// CHECK_RANK.C ////
///////////////////////
int		check_is_in_first_quarter_rank(int value, t_struct *data);
int		check_is_in_second_quarter_rank(int value, t_struct *data);
int		check_is_in_third_quarter_rank(int value, t_struct *data);
int		check_is_in_fourth_quarter_rank(int value, t_struct *data);
int		check_first_quarter_rank(t_list *list, t_struct *data);
int		check_second_quarter_rank(t_list *list, t_struct *data);
int		check_third_quarter_rank(t_list *list, t_struct *data);
int		check_fourth_quarter_rank(t_list *list, t_struct *data);
int		check_half_rank(t_list *list, t_struct *data);
int		check_second_half_rank(t_list *list, t_struct *data);

///////////////////////////
/////// SMOLSORT.C ////////
///////////////////////////
void	tinysort(t_struct *data);
void	smolsort(t_struct *data);
void	mediumsort(t_struct *data);
void	dumbsort(t_struct *data);

///////////////////////
/////  RANKSORT.C  ////
///////////////////////
void	ranksort(t_struct *data);
void	sort_second_half(t_struct *data);
void	sort_third_quarter(t_struct *data);
void	sort_fourth_quarter(t_struct *data);
void	move_n_sort_third_quarter(t_struct *data);
void	move_n_sort_fourth_quarter(t_struct *data);
void	sort_first_half(t_struct *data);
void	sort_first_quarter(t_struct *data);
void	second_while_of_first_quarter(t_struct *data);
void	sort_second_quarter(t_struct *data);
void	second_while_of_second_quarter(t_struct *data);
void	move_n_sort_first_half(t_struct *data);

/////////////////////
/////  RANDOM.C  ////
/////////////////////
void	rb_sb_rrb_sb_rb_sb_rrb(t_struct *data);
void	sb_rb_sb_rrb(t_struct *data);
void	rb_sb_rrb_sb(t_struct *data);

#endif 