
LFLAGS=-lcheck -lm
CFLAGS=-Wall -Werror -Wextra
SOURCES=my_math.c

all: my_math.a

style:
	clang-format -n -style=Google *.c *.h

style_force:
	clang-format -style=Google -dump-config > .clang-format
	clang-format -i *.c *.h

my_math.a: clean
	gcc  $(SYSFLAG) $(CFLAGS) -c $(SOURCES)
	ar rc my_math.a *.o
	ranlib my_math.a
	rm -f *.o
	
test: my_math.a
	gcc $(SYSFLAG) $(CFLAGS) test.c  my_math.a -L. $(LFLAGS) -o test
	-./test > test.log
	bash test_log.sh

rebuild: clean gcov_report

clean:
	rm -f test my_math.a *.gc* test.info log.xml test.log leak.log
	rm -f -rf report
