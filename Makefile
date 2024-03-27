GCCFLAGS = gcc -Wall -Werror -Wextra -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage -lcheck -lsubunit -lm -lrt -lpthread

all: clean s21_string.a s21_tests

gcov_report: s21_tests gcov_buld generate_gcda_files generate_info generate_html

generate_html:
	genhtml result.info --output-directory report

generate_gcda_files: run

gcov_buld:
	gcov check_unit_tests-tests

generate_info:
	lcov --capture --directory . -o result.info

clean:
	rm -rf *.gcno *.gcda *.gcov *.info ./report check_unit_tests *.o *.a

rebuild: clean all

s21_tests: tests/*.c s21_string.a main.c
	$(GCCFLAGS) s21_string.a main.c tests/*.c $(GCOVFLAGS) -o check_unit_tests -L. -ls21_string

s21_string.o:
	$(GCCFLAGS) -c functions/s21_*.c

s21_string.a: s21_string.o
	ar rcs libs21_string.a *.o
	rm -rf *.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a
	cp libs21_string.a ls21_string.a


run:
	./check_unit_tests