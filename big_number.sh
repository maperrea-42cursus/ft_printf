if [ "$1" = "sanitize" ] ;  then
	gcc -fsanitize=address -Wall -Wextra -Werror -Ilibft -Ibig_number big_number/*.c bn_main.c -Llibft -lft && ./a.out
elif [ "$1" = "no_flags" ] ; then
	gcc -Ilibft -Ibig_number big_number/*.c bn_main.c -Llibft -lft && ./a.out
else
	gcc -Wall -Wextra -Werror -Ilibft -Ibig_number big_number/*.c bn_main.c -Llibft -lft && ./a.out
fi
