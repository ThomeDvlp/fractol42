NAME		=	libft.a

SRC			=	ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_strlen.c			\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strcmp.c		\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_strdup.c			\
				ft_calloc.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_putstr_fd.c		\
				ft_putstr.c			\
				ft_putchar_fd.c		\
				ft_putchar.c		\
				ft_putnbr_fd.c		\
				ft_putnbr.c			\
				ft_putendl_fd.c		\
				ft_putunbr.c		\
				ft_puthex.c			\
				ft_printf.c			\
				ft_itoa.c			\
				ft_strtrim.c		\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_split.c			\
				ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c		

BONUS_SRC	=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			

OBJ			=	$(SRC:.c=.o) 

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)


CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
		
$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)

all:			$(NAME)

bonus:			$(BONUS_OBJ)
				ar rcs $(NAME) $(BONUS_OBJ)

clean:
				rm -f $(OBJ) $(BONUS_OBJ)

fclean:			clean
				rm -f $(NAME)	
	
so:
				$(CC) -fPIC $(FLAGS) $(SRC)
				gcc -shared -o libft.so $(OBJ)

re:				fclean all	

.PHONY:			all clean fclean re
