#ifndef GAME_H__
#define GAME_H__

#include <stdbool.h>
#include <stdio.h>

#define SIZE 4
extern uint8_t board[SIZE][SIZE];
extern uint32_t score;
extern uint8_t scheme;


/*--------------------------*/

void getColor(uint8_t value, char *color, size_t length);
void drawBoard(uint8_t board[SIZE][SIZE]);
uint8_t findTarget(uint8_t array[SIZE],uint8_t x,uint8_t stop);
bool slideArray(uint8_t array[SIZE]);
void rotateBoard(uint8_t board[SIZE][SIZE]);
bool moveUp(uint8_t board[SIZE][SIZE]);
bool moveLeft(uint8_t board[SIZE][SIZE]);
bool moveDown(uint8_t board[SIZE][SIZE]);
bool moveRight(uint8_t board[SIZE][SIZE]);
bool findPairDown(uint8_t board[SIZE][SIZE]);
uint8_t countEmpty(uint8_t board[SIZE][SIZE]);
bool gameEnded(uint8_t board[SIZE][SIZE]);
void addRandom(uint8_t board[SIZE][SIZE]);
void initBoard(uint8_t board[SIZE][SIZE]);
void setBufferedInput(bool enable);
int test();
void signal_callback_handler(int signum);

/*--------------------------*/

#endif
