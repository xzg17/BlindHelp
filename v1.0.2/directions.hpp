#ifndef _DIRECTIONS_HPP_
#define _DIRECTIONS_HPP_

#include "piece.hpp"
#include "limited_set.hpp"

//to_nums->insert(100]
inline int direction_N(char board_num, limited_set<char, 100> *to_nums){
    if(board_num > 20){
        to_nums->insert(board_num - 10);
    };
    return 0;
};
inline int direction_S(char board_num, limited_set<char, 100> *to_nums){
    if(board_num < 90){
        to_nums->insert(board_num + 10);
    };
    return 0;
};
inline int direction_EW(char board_num, limited_set<char, 100> *to_nums){
    if(board_num % 10 != 1){
        to_nums->insert(board_num - 1);
    };
    if(board_num % 10 != 9){
        to_nums->insert(board_num + 1);
    };
    return 0;
};
inline int direction_NEW(char board_num, limited_set<char, 100> *to_nums){
    if(board_num > 20 && board_num % 10 != 1){
        to_nums->insert(board_num - 11);
    };
    if(board_num > 20 && board_num % 10 != 9){
        to_nums->insert(board_num - 9);
    };
    return 0;
};
inline int direction_SEW(char board_num, limited_set<char, 100> *to_nums){
    if(board_num < 90 && board_num % 10 != 1){
        to_nums->insert(board_num + 9);
    };
    if(board_num < 90 && board_num % 10 != 9){
        to_nums->insert(board_num + 11);
    };
    return 0;
};
inline int direction_KN(char board_num, limited_set<char, 100> *to_nums){
    if(board_num > 30 && board_num % 10 != 1){
        to_nums->insert(board_num - 21);
    };
    if(board_num > 30 && board_num % 10 != 9){
        to_nums->insert(board_num - 19);
    };
    return 0;
};
inline int direction_KS(char board_num, limited_set<char, 100> *to_nums){
    if(board_num < 80 && board_num % 10 != 1){
        to_nums->insert(board_num + 19);
    };
    if(board_num < 80 && board_num % 10 != 9){
        to_nums->insert(board_num + 21);
    };
    return 0;
};
inline int direction_PN(char board_num, limited_set<char, 100> *to_nums, char *board){
    unsigned char num = board_num;
    while(num > 20){
        num -= 10;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PS(char board_num, limited_set<char, 100> *to_nums, char *board){
    unsigned char num = board_num;
    while(num < 90){
        num += 10;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PEW(char board_num, limited_set<char, 100> *to_nums, char *board){
    unsigned char num;
    num = board_num;
    while(num % 10 != 1){
        num -= 1;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num % 10 != 9){
        num += 1;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PB(char board_num, limited_set<char, 100> *to_nums, char *board){
    unsigned char num;
    num = board_num;
    while(num > 20 && num % 10 != 1){
        num -= 11;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num > 20 && num % 10 != 9){
        num -= 9;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num < 90 && num % 10 != 1){
        num += 9;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num < 90 && num % 10 != 9){
        num += 11;
        to_nums->insert(num);
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
#endif