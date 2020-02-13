/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:36:11 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/01/22 12:00:27 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_type
{
	int		hashtag;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		dot;
	int		precision;
	int		hh;
	int		h;
	int		ll;
	int		l;
	int		bigl;
	int		roundup;
}				t_type;

int				ft_printf(const char *str, ...);
void			clear_struct(t_type *info);
void			check_flags(const char *str, t_type *info);
int				is_flag(char a);
int				is_type(char a);
int				is_len(char a);
int				num_len(long long i);
void			print_struct(t_type *info);
const char		*check_numbers(const char *str, t_type *info);
int				print_block(char type, t_type *info, va_list ap);
int				print_c(va_list ap, t_type *info);
int				print_s(va_list ap, t_type *info);
int				print_p(va_list ap, t_type *info);
int				print_i_d(va_list ap, t_type *info);
int				print_o(va_list ap, t_type *info);
int				print_u(va_list ap, t_type *info);
int				print_f(va_list ap, t_type *info);
int				print_x(va_list ap, t_type *info, char type);
char			*ft_itoa_base_lower(long long num, int base);
char			*ft_itoa_base_upper(long long num, int base);
int				check_len_flags(const char *str, t_type *info);
int				check_len_flags_two(const char *str, t_type *info);
int				num_length(long long a);
char			*ft_itoa_base_lower2(long long num, int base, t_type *info);
void			putzero_count(int i, int *count);
void			putspaces_count(int i, int *count);
void			putzero(int i);
void			putspaces(int i);
char			*double_itoa(long double num, int len);
int				print_percent(t_type *info);
void			put_plus_space(t_type *info, int isneg);
const char		*gotrough1(const char *str, t_type *info,
				int *count, va_list ap);
const char		*gotrough2(const char *str, t_type *info);
const char		*count_numbers_width(const char *str, t_type *info);
const char		*count_numbers_precision(const char *str, t_type *info);
int				round_decimal(char *decimal, t_type *info);
char			*get_decimal(long double num, t_type *info);
void			put_sign(long double num, int *count, t_type *info);
char			*declare_null(void);
int				count_spaces_i(t_type *info, long long num, int isneg);
void			i_no_minus(t_type *info, int number_length,
				int isneg, int *ret);
void			i_yes_minus(t_type *info, int num_length,
				int *ret, long long num);
void			i_yes_minus2(t_type *info, int isneg);
void			o_no_minus2(t_type *info, long long num,
				char *octa, int octa_len);
void			print_x_0x(char type);
void			print_x_value(char type, long long num);
int				check_x_output_length(long long num, t_type *info);
int				count_f_length(long double num, t_type *info,
				char *dec, int *spaces);
void			check_f_helper(t_type *info, int spaces, int *ret_count);
int				ft_itoa_base_test_two(long long num);

#endif
