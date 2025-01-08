all:
	clang++ 4_3_H*.cpp -Werror -Wextra -Wall -std=c++2a -O2 -fsanitize=address,undefined && ./a.out
