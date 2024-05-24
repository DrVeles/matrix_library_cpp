CC = gcc 
CC_FLAGS := -Wall -Wextra -Werror -lstdc++ -std=c++17
CC_TEST_FLAGS = -lgtest --coverage 

all: s21_matrix_oop.a

test: google_format s21_matrix_oop.a 
	@$(CC) $(CC_FLAGS) s21_matrix_oop_tests.cpp s21_matrix_oop.cpp -o s21_matrix_oop_test $(CC_TEST_FLAGS)
	./s21_matrix_oop_test

gcov_report: test
	@lcov -t "Tests" -o tests.info -c -d . --ignore-errors inconsistent >/dev/null 2>&1
	@lcov -e tests.info '*.cpp' -o tests.info >/dev/null 2>&1
	@genhtml -o report tests.info >/dev/null 2>&1
	open ./report/index.html

s21_matrix_oop.a: clean
	@$(CC) $(CC_FLAGS) -c s21_matrix_oop.cpp -o s21_matrix_oop.a

clean: 
	-@rm -rf s21_matrix_oop s21_matrix_oop_debug s21_matrix_oop_test *.a *.o *.gcda *.gcno *.info report/ *.dSYM/

rt: clean test

leaks: test
	CK_FORK=no leaks -atExit -q --  ./s21_matrix_oop_test 

google_format:
	-@clang-format -style=Google -i *.h *.cpp
