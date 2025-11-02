#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
// Structure for a question 
struct Question { 
char question[200]; 
char options[4][100]; 
int correctOption; // 1-4 
}; 
int main() { 
// Question bank (15 questions) 
struct Question qBank[] = { 
{"What does CPU stand for?", 
{"Central Processing Unit", "Computer Processing Unit", "Control Processing Unit", "Central  
Printing Unit"}, 1}, 
{"Which of the following is an Operating System?", 
{"Python", "Linux", "HTML", "C++"}, 2}, 
{"Which data structure uses FIFO?", 
{"Stack", "Queue", "Array", "Tree"}, 2}, 
{"Which language is used for web apps?", 
{"HTML", "C", "Python", "Java"}, 1}, 
{"What does RAM stand for?", 
{"Random Access Memory", "Read Access Memory", "Run Access Memory", "Rapid Access  
Memory"}, 1}, 
{"Which symbol is used to end a statement in C?", 
{"#", ".", ";", ":"}, 3}, 
{"Which header file is needed for printf()?", 
{"stdlib.h", "stdio.h", "string.h", "conio.h"}, 2}, 
{"What is the output of 3 + 2 * 2?", 
{"10", "7", "8", "9"}, 2}, 
{"Which keyword is used to return a value in C?", 
{"get", "return", "output", "break"}, 2}, 
{"Which of these is not a loop?", 
{"for", "while", "if", "do-while"}, 3}, 
{"Who developed the C programming language?", 
{"Dennis Ritchie", "Charles Babbage", "Bjarne Stroustrup", "James Gosling"}, 1}, 
{"Which function is used to take input in C?", 
{"print()", "cin>>", "scanf()", "input()"}, 3}, 
{"Which of the following is a logical operator?", 
{"&&", "+", "*", "%"}, 1}, 
{"Which keyword is used to define a constant in C?", 
{"let", "const", "#define", "static"}, 3}, 
{"Which of the following is not a valid variable name?", 
{"total", "sum_1", "1stvalue", "_count"}, 3} 
}; 
int totalQuestions =15; 
int questionsPerPlay = 5; 
int playAgain; 
srand(time(0)); 
printf("=============================================\n"); 
printf("         WELCOME TO THE QUIZ GAME                                  
\n"); 
printf("=============================================\n"); 
printf("\nInstructions:\n"); 
printf("1. You will be asked %d random questions each round.\n", questionsPerPlay); 
printf("2. Each question has 4 options : choose your answer (1-4).\n"); 
printf("3. You’ll see if your answer is correct immediately.\n"); 
printf("4. At the end, your total score will be displayed.\n"); 
printf("5. You can play multiple times.\n"); 
printf("---------------------------------------------\n"); 
printf("Press Enter to start the game..."); 
getchar(); // wait for Enter 
do { 
int score = 0; 
int asked[20] = {0}; // track used questions (max 20) 
printf("\n=============================================\n"); 
printf("              QUIZ STARTED                                                             
\n"); 
printf("=============================================\n"); 
for (int i = 0; i < questionsPerPlay; i++) { 
int qIndex; 
do { 
qIndex = rand() % totalQuestions; 
} while (asked[qIndex] == 1); 
asked[qIndex] = 1; 
printf("\nQ%d: %s\n", i + 1, qBank[qIndex].question); 
for (int j = 0; j < 4; j++) { 
printf("   %d. %s\n", j + 1, qBank[qIndex].options[j]); 
} 
int answer; 
printf("Your answer (1-4): "); 
scanf("%d", &answer); 
if (answer == qBank[qIndex].correctOption) { 
printf(" Correct!\n"); 
score++; 
} else { 
printf("Wrong! Correct answer: %s\n", 
qBank[qIndex].options[qBank[qIndex].correctOption - 1]); 
}  
} 
printf("\n=============================================\n"); 
printf("                                    
QUIZ COMPLETED                                
\n"); 
printf("=============================================\n"); 
printf("Your total score: %d out of %d\n", score, questionsPerPlay); 
if (score == questionsPerPlay) 
printf(" Excellent! You nailed it!\n"); 
else if (score >= 3) 
printf(" Good! Keep it up!\n"); 
else 
printf(" Don’t worry, try again and improve!\n"); 
printf("\nDo you want to play again? (1 = Yes / 0 = No): "); 
scanf("%d", &playAgain); 
getchar(); // clear buffer 
} while (playAgain == 1); 
printf("\n=============================================\n"); 
printf("                            
Thank you for playing                                      
\n"); 
printf("=============================================\n"); 
return 0; 
}  
