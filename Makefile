all:
	clang++ 3_1_C_vans.cpp -Werror -Wextra -Wall -std=c++2a -O2 -fsanitize=address,undefined && ./a.out

