CC := gcc 
CC_FLAGS := -Wall -Wextra -Werror -lstdc++ -std=c++17
CC_TEST_FLAGS =
LEAKS = 
OPEN_CMD = 

OS = $(shell uname)
ifeq ($(OS), Darwin)
	CC_TEST_FLAGS = -lgtest --coverage 
	LEAKS = CK_FORK=no leaks -atExit -q -- 
	OPEN_CMD = xdg-open 
else ifeq ($(OS), Linux)
	CC_TEST_FLAGS = -lgtest -lrt -lpthread -lm -lsubunit
	LEAKS = CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes  ./unit_test
	OPEN_CMD = open 
endif

all: rt

test: google_format s21_matrix_oop.a 
	@$(CC) $(CC_FLAGS) s21_matrix_oop_tests.cpp s21_matrix_oop.cpp -o s21_matrix_oop_test $(CC_TEST_FLAGS)
	./s21_matrix_oop_test

debug: clean google_format s21_matrix_oop.a
	@$(CC) $(CC_FLAGS) -g s21_matrix_oop_debug.cpp s21_matrix_oop.cpp -o s21_matrix_oop_debug
	./s21_matrix_oop_debug


gcov_report: test
	lcov -t "Tests" -o tests.info -c -d .
	lcov -e tests.info '*.cpp' -o tests.info
	genhtml -o report tests.info
	open ./report/index.html

s21_matrix_oop.a: clean
	@$(CC) $(CC_FLAGS) -c s21_matrix_oop.cpp -o s21_matrix_oop.a

clean: 
	-@rm -rf s21_matrix_oop s21_matrix_oop_debug s21_matrix_oop_test *.a *.o *.gcda *.gcno *.info report/ *.dSYM/

rt: clean test

leaks: test
	$(LEAKS) ./s21_matrix_oop_test 

google_format:
	-@clang-format -style=Google -i *.h *.cpp
