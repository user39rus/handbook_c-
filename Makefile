all:
	clang++ 4_2_E*.cpp -Werror -Wextra -Wall -std=c++2a -O2 -fsanitize=address,undefined && ./a.out
