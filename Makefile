NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_print_character.c \
				ft_print_string.c \
				ft_print_unsigned_int_base.c \
				ft_print_int_base.c \
				ft_strlen.c \
				
OBJS		=	$(SRCS:.c=.o)

BONUS		=	ft_print_flags_bonus.c \
				ft_printf_bonus.c \
				ft_print_character_bonus.c \
				ft_print_string_bonus.c \
				ft_print_unsigned_int_base_bonus.c \
				ft_print_int_base_bonus.c \
				ft_strlen_bonus.c

BONUS_OBJS	= $(BONUS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

ifdef WITH_BONUS
	SRCS += $(BONUS)
    OBJS += $(BONUS_OBJS)
endif

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:		
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)        

bonus:			
				$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY:			all clean fclean re bonus