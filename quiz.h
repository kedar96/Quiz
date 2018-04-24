typedef struct question
{
	char fullQues[500];
      //  char answers[4];
        char corrAns; //We don't need an int for that (0,1,2 or 3)
} questionType;


void quizType(int type);
