all:
	clang++ 3_2_B_common_letters.cpp -Werror -Wextra -Wall -std=c++2a -O2 -fsanitize=address,undefined && ./a.out
