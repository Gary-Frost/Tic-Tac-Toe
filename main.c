//
//  main.c
//  Tic-Tac-Toe
//
//  Created by Gary Frost on 2020/4/13.
//  Copyright © 2020 Gary Frost. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
void print(int board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == 0){
                printf("   ");
            }
            else if (board[i][j] == 1){
                printf(" X ");
            }
            else if (board[i][j] == 2){
                printf(" O ");
            }
            if (j < 2){
            printf("|");
            }
        }
        if (i < 2){
        printf("\n—— + — + ——\n");
        }
    }
}
int *botF (int board[3][3]) {
    int chess = 0;
    int botx = 0;
    int boty = 0;
    int score[3][3] = {{1,0,1},{0,5000,0},{1,0,1}};
    
    if (board[1][1] == 1){
        score[0][0] += 20;
        score[2][0] += 20;
        score[0][2] += 20;
        score[2][2] += 20;
    }//                                             斜向DEcontinued
    
    if (board[1][1] == 1 && board[2][2] == 1){
        score[0][0] += 1000;
    }
    else if (board[1][1] == 1 && board[0][2] == 1){
        score[2][0] += 1000;
    }
    else if (board[1][1] == 1 && board[2][0] == 1){
        score[0][2] += 1000;
    }
    else if (board[1][1] == 1 && board[0][0] == 1){
        score[2][2] += 1000;
    }//                                             斜向block

    if (board[1][1] == 2 && board[2][2] == 2){
        score[0][0] += 10000;
    }
    else if (board[1][1] == 2 && board[0][2] == 2){
        score[2][0] += 10000;
    }
    else if (board[1][1] == 2 && board[2][0] == 2){
        score[0][2] += 10000;
    }
    else if (board[1][1] == 2 && board[0][0] == 2){
        score[2][2] += 10000;
    }//                                              斜向check
//                                                      以下开始循环
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] != 0){
                score[i][j] -= 100000;
            }//                                             占用⬆️

            if (j == 0){
                if (board[i][1] == 1 && board[i][2] == 1){
                    score[i][j] += 1000;
//                    printf("横向block1,%d %d\n",i,j);
                }
            }
            if (j == 1){
                if (board[i][0] == 1 && board[i][2] == 1){
                    score[i][j] += 1000;
//                    printf("横向block2,%d %d\n",i,j);
                }
            }
            if (j == 2){
                if (board[i][0] == 1 && board[i][1] == 1){
                    score[i][j] += 1000;
//                    printf("横向block3,%d %d\n",i,j);
                }
            }//                                            横向block ⬆️
            
            if (i == 0){
                if (board[1][j] == 1 && board[2][j] == 1){
                    score[i][j] += 1000;
//                    printf("纵向block4,%d %d\n",i,j);
                }
            }
            if (i == 1){
                if (board[0][j] == 1 && board[2][j] == 1){
                    score[i][j] += 1000;
//                    printf("纵向block %d %d\n",i,j);
                }
            }
            if (i == 2){
                if (board[1][j] == 1 && board[0][j] == 1){
                    score[i][j] += 1000;
//                    printf("纵向block %d %d\n",i,j);
                }
            }//                                                 纵向block⬆️
            
            if (j == 0){
                if (board[i][1] == 2){
                    score[i][j] += 20;
                }
            }
            if (j == 1){
                if (board[i][0] == 2 || board[i][2] == 2){
                    score[i][j] += 20;
                }
            }
            if (j == 2){
                if (board[i][1] == 2){
                    score[i][j] += 20;
                }
            }//                                           横向continued ⬆️
            
            if (j == 0){
                if (board[i][1] == 1 || board[i][2] == 1){
                    score[i][j] += 20;
                }
            }
            if (j == 1){
                if (board[i][0] == 1 || board[i][2] == 1){
                    score[i][j] += 20;
                }
            }
            if (j == 2){
                if (board[i][0] == 1 || board[i][1] == 1){
                    score[i][j] += 20;
                }
            }//                                           横向DEcontinued ⬆️
            
            if (i == 0){
                if (board[1][j] == 2 && board[2][j]!=1){
                    score[i][j] += 20;
                }
            }
            if (i == 1){
                if (board[0][j] == 2 || board[2][j] == 2){
                    score[i][j] += 20;
                }
            }
            if (i == 2){
                if (board[1][j] == 2){
                    score[i][j] += 20;
                }
            }//                                          纵向continued⬆️
            
            if (i == 0){
                if (board[1][j] == 1 || board[2][j] == 1){
                    score[i][j] += 20;
                }
            }
            if (i == 1){
                if (board[0][j] == 1 || board[2][j] == 1){
                    score[i][j] += 20;
                }
            }
            if (i == 2){
                if (board[1][j] == 1 || board[0][j] == 1){
                    score[i][j] += 20;
                }
            }//                                          纵向DEcontinued⬆️
            
            if (j == 0){
                if (board[i][1] == 2 && board[i][2] == 2){
                    score[i][j] += 10000;
                }
            }
            if (j == 1){
                if (board[i][0] == 2 && board[i][2] == 2){
                    score[i][j] += 10000;
                }
            }
            if (j == 2){
                if (board[i][0] == 2 && board[i][1] == 2){
                    score[i][j] += 10000;
                }
            }//                                           横向check ⬆️
            
            if (i == 0){
                if (board[1][j] == 2 && board[2][j] == 2){
                    score[i][j] += 10000;
                }
            }
            if (i == 1){
                if (board[0][j] == 2 && board[2][j] == 2){
                    score[i][j] += 10000;
                }
            }
            if (i == 2){
                if (board[1][j] == 2 && board[0][j] == 2){
                    score[i][j] += 10000;
                }
            }//                                             纵向check⬆️
            
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
//            printf("%d ",score[i][j]);
            if (score[i][j] > chess){
                chess = score[i][j];
                botx = i;
                boty = j;
            }
        }
        printf("\n");
    }
    int botMov[2] = {botx,boty};
    printf("\n");
    return botMov;
}
int checkWin(int board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][0] ==1 && board[i][1] == 1 && board[i][2] == 1){
                return 1;
                break;
            }
            else if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2){
                return 2;
                break;
            }//                                           横向⬆️
            if (board[1][j] == 2 && board[2][j] == 2 && board[0][j] == 2){
                return 2;
                break;
            }
            else if (board[1][j] == 1 && board[2][j] == 1 && board[0][j] == 1){
            return 1;
            break;
            }//                                           纵向⬆️
        }
    }
    if  (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    else if  (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        return 2;
    }
    if  (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        return 1;
    }
    else if  (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        return 2;
    }
    return 0;
}
int main() {
    printf("WELCOME TO THE TIC-TAC-TOE THAT NEVER LET YOU WIN!!!\n\n");
    int M[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int x,y;
    
    for (int i=0; i<4; i++){
        if  (checkWin(M) == 1 || checkWin(M) == 2) {
            break;
        }
        print(M);
        printf("\nPlease enter the coordinate of your chess piece\n");
        scanf("%d",&x);
        scanf("%d",&y);
        M[x-1][y-1] = 1;
        M[botF(M)[0]][botF(M)[1]] = 2;
    }
    
    if  (checkWin(M) == 1) {
        printf("\n\n卧槽不是吧，你居然真的赢了？？？\n将本局游戏过程截图发至Gary可获得5000元微信红包\n");//最终解释权归游戏开发者所有
    }
    else if (checkWin(M) == 2){
        printf("\n\n***** [YOU LOSE!!] *****\n");
    }
    else{
        printf("\n\n***** [DRAW?!] *****\n");
    }
    print(M);
    printf("\n\n");
}
