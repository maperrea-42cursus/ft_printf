if [ "$1" = "sanitize" ] ;  then
	gcc -fsanitize=address -Wall -Wextra -Werror -Ilibft -Ibig_number libft/libft.a big_number/*.c bn_main.c && ./a.out
elif [ "$1" = "no_flags" ] ; then
	gcc -Ilibft -Ibig_number libft/libft.a big_number/*.c bn_main.c && ./a.out
else
	gcc -Wall -Wextra -Werror -Ilibft -Ibig_number libft/libft.a big_number/*.c bn_main.c && ./a.out
fi
