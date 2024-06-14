#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// #include "test.h"
/*
 * The status of a line.
 */
enum {
    NO = 0, /* No line */
    RED = 1,
    BLUE = 2
};

/*
 * The board records the colors of the lines.
 * board[0] = color of 12
 * board[1] = color of 13
 * ...
 * board[14] = color of 56
 */

typedef char board_t[15];
typedef char player_t; /* A player should be RED or BLUE. */

player_t other_player(player_t player)
{
    switch (player) {
    case RED: return BLUE;
    case BLUE: return RED;
    default: assert(0);
    }
}

void print_board(board_t board)
{
    for (int i = 0; i < 15; ++i) {
        switch (board[i]) {
        case RED: printf("R  "); break;
        case BLUE: printf("B  "); break;
        case NO: printf(". "); break;
        }
    }printf("\n");
}
int has_won(board_t board, player_t player)
{
    int winningConditions[20][3] = {
    {0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {0, 4, 8},
    {1, 2, 9}, {1, 3, 10}, {1, 4, 11},
    {2, 3, 12}, {2, 4, 13},
    {3, 4, 14},
    {5, 6, 9}, {5, 7, 10}, {5, 8, 11},
    {6, 7, 12}, {6, 8, 13},
    {7, 8, 14},
    {9, 10, 12}, {9, 11, 13},
    {10, 11, 14},
    {12, 13, 14}};

    for (int i = 0; i < 20; i++)
    {
        if((board[winningConditions[i][0]] == other_player(player) && board[winningConditions[i][1]] == other_player(player) && board[winningConditions[i][2]] == other_player(player)))
        {
            return 1;
        }
    }return 0;
    

}

int is_full(board_t board)
{
    for(int i = 0; i < 15; i++){
        if(board[i] == NO){
            return 0;
        }
    }return 1;
}


typedef struct {
    int line; /* 0 for 12, 1 for 13, ..., 14 for 56. */
    int score; /* -1 for loss, 0 for draw, 1 for win. */
} move_t;

void init_board(board_t board)
{
    for(int i = 0; i < 15; i++){
        board[i] = NO;
    }
}

move_t best_move(board_t board, player_t player)
{
    move_t response;
    move_t candidate;
    int no_candidate = 1;
    
    for (int i = 0; i < 15; i++)
    {
        if(board[i] == NO){
            board[i] = player;
            if(has_won(board, player)){
                board[i] = NO;
                candidate = (move_t){
                    .line = i,
                    .score = 1
                };
                return candidate;
            }
            board[i] = NO;
        }
    }
    for (int i = 0; i < 15; i++){
        if (board[i] == NO){
            board[i] = player;
            response = best_move(board, other_player(player));
            board[i] = NO;
            response.score = -response.score;
            if (response.score == 1){
                candidate = (move_t){
                    .line = i,
                    .score = 1
                };
                return candidate;
            } else if (response.score == 0){
                candidate = (move_t){
                    .line = i,
                    .score = 0
                };
                no_candidate = 0;
            } else {
                if (no_candidate){
                    candidate = (move_t){
                        .line = i,
                        .score = -1
                    };
                    no_candidate = 0;
                } 
            }   
        } 
    }
    return candidate; 
}



int main() {
    /* Your game play logic. */
    /* The user should have the option to select red or blue player. */
    int move, line;
    player_t current = RED;
    board_t board;
    move_t response;
    response.score = 0;
    init_board(board);
    printf("You are RED. Enter first move.\n");
    
        while (1) {
            print_board(board);
            if (has_won(board, current)) {
                print_board(board);
                if(current == RED){
                    printf("You have won!\n");
                }else{
                    printf("Computer won!");
                }
                break;
            } else if (is_full(board)) {
                print_board(board);
                printf("Draw.\n");
                break;
            }
            if ((current == RED)) {
                printf("Your Move: ");
                scanf("%d", &move);
                line = move;
                if (board[line] != NO) {
                    printf("INVALID CHOICE!\n");
                    break;
                }
                board[line] = current;
                printf("You have played %d\n", current, line);
            } else {
                response = best_move(board, current);
                board[response.line] = current;
                printf("Computer has played %d\n", current, response.line);
            }
            current = other_player(current);

        }
    return 0;
}
