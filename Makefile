all:
	clang++ 3_5_C*.cpp -Werror -Wextra -Wall -std=c++2a -O2 -fsanitize=address,undefined && ./a.out
