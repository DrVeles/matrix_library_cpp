CC := gcc 
CC_FLAGS := -lstdc++ -std=c++17
CC_TEST_FLAGS =
LEAKS = 
OPEN_CMD = 

OS = $(shell uname)
ifeq ($(OS), Darwin)
	CC_TEST_FLAGS = -lgtest
	LEAKS+=CK_FORK=no leaks -atExit -q -- 
	OPEN_CMD = xdg-open 
else ifeq ($(OS), Linux)
	CC_TEST_FLAGS = -lgtest -lrt -lpthread -lm -lsubunit
	LEAKS = CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes  ./unit_test
	OPEN_CMD = open 
endif

all: rt

test: s21_matrix_oop.a google_format
	@$(CC) $(CC_FLAGS) ./s21_matrix_oop_tests.cpp s21_matrix_oop.a -o s21_matrix_oop 
	./s21_matrix_oop 

s21_matrix_oop.a: clean
	@$(CC) $(CC_FLAGS) -c ./s21_matrix_oop.cpp -o s21_matrix_oop.a

clean: 
	-@rm -rf s21_matrix_oop *.a *.o

rt: clean test

leaks: test
	$(LEAKS)./s21_matrix_oop 

google_format:
	-@clang-format -style=Google -i *.h *.cpp