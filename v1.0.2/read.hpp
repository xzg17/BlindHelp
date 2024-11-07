#ifndef _READ_HPP_
#define _READ_HPP_
#include <string>
#include "piece.hpp"
#include <iostream>
inline int read_board(std::string sfen_board, char *board){
    int i, j;
    j = 0;
    int n = (int)sfen_board.size();
    for(i = 0;i < 100;i++){
        board[i] = 0;
    };
    for(i = 0;i < 11;i++){
        board[i] = WALL;
    };
    for(j = 0;j < n;j++){
        if(sfen_board[j] == 'P'){
            board[i] += B_PAWN;
            i++;
        }else if(sfen_board[j] == 'L'){
            board[i] += B_LANCE;
            i++;
        }else if(sfen_board[j] == 'N'){
            board[i] += B_KNIGHT;
            i++;
        }else if(sfen_board[j] == 'S'){
            board[i] += B_SILVER;
            i++;
        }else if(sfen_board[j] == 'B'){
            board[i] += B_BISHOP;
            i++;
        }else if(sfen_board[j] == 'R'){
            board[i] += B_ROOK;
            i++;
        }else if(sfen_board[j] == 'G'){
            board[i] += B_GOLD;
            i++;
        }else if(sfen_board[j] == 'K'){
            board[i] += B_KING;
            i++;
        }else if(sfen_board[j] == 'p'){
            board[i] += W_PAWN;
            i++;
        }else if(sfen_board[j] == 'l'){
            board[i] += W_LANCE;
            i++;
        }else if(sfen_board[j] == 'n'){
            board[i] += W_KNIGHT;
            i++;
        }else if(sfen_board[j] == 's'){
            board[i] += W_SILVER;
            i++;
        }else if(sfen_board[j] == 'b'){
            board[i] += W_BISHOP;
            i++;
        }else if(sfen_board[j] == 'r'){
            board[i] += W_ROOK;
            i++;
        }else if(sfen_board[j] == 'g'){
            board[i] += W_GOLD;
            i++;
        }else if(sfen_board[j] == 'k'){
            board[i] += W_KING;
            i++;
        }else if(sfen_board[j] == '+'){
            board[i] += 8;
        }else if(sfen_board[j] == '/'){
            board[i] = WALL;
            i++;
        }else if('1' <= sfen_board[j] && sfen_board[j] <= '9'){
            for(char x = '1';x <= sfen_board[j];x++){
                board[i] = EMPTY;
                i++;
            };
        };
    };
    if(i != 100){
        std::cout<<"error while reading board"<<std::endl;
        return -1;
    };
    return 0;
};
inline int read_hand(std::string sfen_hand, unsigned char *hand){
    int i, j;
    for(i = 0;i < 14;i++){
        hand[i] = 0;
    };
    if(sfen_hand != "-"){
        unsigned char num = 0;
        for(j = 0;j < sfen_hand.size();j++){
            if(sfen_hand[j] == 'P'){
                if(num){
                    hand[6] = num;
                }else{
                    hand[6] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'L'){
                if(num){
                    hand[5] = num;
                }else{
                    hand[5] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'N'){
                if(num){
                    hand[4] = num;
                }else{
                    hand[4] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'S'){
                if(num){
                    hand[3] = num;
                }else{
                    hand[3] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'G'){
                if(num){
                    hand[2] = num;
                }else{
                    hand[2] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'B'){
                if(num){
                    hand[1] = num;
                }else{
                    hand[1] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'R'){
                if(num){
                    hand[0] = num;
                }else{
                    hand[0] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'p'){
                if(num){
                    hand[13] = num;
                }else{
                    hand[13] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'l'){
                if(num){
                    hand[12] = num;
                }else{
                    hand[12] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'n'){
                if(num){
                    hand[11] = num;
                }else{
                    hand[11] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 's'){
                if(num){
                    hand[10] = num;
                }else{
                    hand[10] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'g'){
                if(num){
                    hand[9] = num;
                }else{
                    hand[9] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'b'){
                if(num){
                    hand[8] = num;
                }else{
                    hand[8] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == 'r'){
                if(num){
                    hand[7] = num;
                }else{
                    hand[7] = 1;
                };
                num = 0;
            }else if(sfen_hand[j] == '0'){
                num *= 10;
            }else if(sfen_hand[j] == '1'){
                num *= 10;
                num += 1;
            }else if(sfen_hand[j] == '2'){
                num *= 10;
                num += 2;
            }else if(sfen_hand[j] == '3'){
                num *= 10;
                num += 3;
            }else if(sfen_hand[j] == '4'){
                num *= 10;
                num += 4;
            }else if(sfen_hand[j] == '5'){
                num *= 10;
                num += 5;
            }else if(sfen_hand[j] == '6'){
                num *= 10;
                num += 6;
            }else if(sfen_hand[j] == '7'){
                num *= 10;
                num += 7;
            }else if(sfen_hand[j] == '8'){
                num *= 10;
                num += 8;
            }else if(sfen_hand[j] == '9'){
                num *= 10;
                num += 9;
            };
        };
    };
    return 0;
};
#endif