./quiz:main.o quiz_func.o 
	gcc -o quiz main.o quiz_func.o
main.o:main.c quiz.h 
	gcc -c main.c
quiz_func.o:quiz_func.c quiz.h
	gcc -c quiz_func.c

.PHONY: clean

clean:
	rm *.o;rm quiz;
