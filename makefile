./quiz:main.o quiz_func.o valid.o
	gcc -o quiz main.o quiz_func.o valid.o
main.o:main.c quiz.h 
	gcc -c main.c
quiz_func.o:quiz_func.c quiz.h
	gcc -c quiz_func.c
valid.o:valid.c quiz.h
	gcc -c valid.c
.PHONY: clean

clean:
	rm *.o;rm quiz;
