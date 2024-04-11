#ifndef _DIRECTIONS_HPP_
#define _DIRECTIONS_HPP_

#include "piece.hpp"

//to_nums[100]
inline int direction_N(unsigned char board_num, bool *to_nums){
    if(board_num > 20){
        to_nums[board_num - 10] = true;
    };
    return 0;
};
inline int direction_S(unsigned char board_num, bool *to_nums){
    if(board_num < 90){
        to_nums[board_num + 10] = true;
    };
    return 0;
};
inline int direction_EW(unsigned char board_num, bool *to_nums){
    if(board_num % 10 != 1){
        to_nums[board_num - 1] = true;
    };
    if(board_num % 10 != 9){
        to_nums[board_num + 1] = true;
    };
    return 0;
};
inline int direction_NEW(unsigned char board_num, bool *to_nums){
    if(board_num > 20 && board_num % 10 != 1){
        to_nums[board_num - 11] = true;
    };
    if(board_num > 20 && board_num % 10 != 9){
        to_nums[board_num - 9] = true;
    };
    return 0;
};
inline int direction_SEW(unsigned char board_num, bool *to_nums){
    if(board_num < 90 && board_num % 10 != 1){
        to_nums[board_num + 9] = true;
    };
    if(board_num < 90 && board_num % 10 != 9){
        to_nums[board_num + 11] = true;
    };
    return 0;
};
inline int direction_KN(unsigned char board_num, bool *to_nums){
    if(board_num > 30 && board_num % 10 != 1){
        to_nums[board_num - 21] = true;
    };
    if(board_num > 30 && board_num % 10 != 9){
        to_nums[board_num - 19] = true;
    };
    return 0;
};
inline int direction_KS(unsigned char board_num, bool *to_nums){
    if(board_num < 80 && board_num % 10 != 1){
        to_nums[board_num + 19] = true;
    };
    if(board_num < 80 && board_num % 10 != 9){
        to_nums[board_num + 21] = true;
    };
    return 0;
};
inline int direction_PN(unsigned char board_num, bool *to_nums, unsigned char *board){
    unsigned char num = board_num;
    while(num > 20){
        num -= 10;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PS(unsigned char board_num, bool *to_nums, unsigned char *board){
    unsigned char num = board_num;
    while(num < 90){
        num += 10;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PEW(unsigned char board_num, bool *to_nums, unsigned char *board){
    unsigned char num;
    num = board_num;
    while(num % 10 != 1){
        num -= 1;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num % 10 != 9){
        num += 1;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
inline int direction_PB(unsigned char board_num, bool *to_nums, unsigned char *board){
    unsigned char num;
    num = board_num;
    while(num > 20 && num % 10 != 1){
        num -= 11;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num > 20 && num % 10 != 9){
        num -= 9;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num < 90 && num % 10 != 1){
        num += 9;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    num = board_num;
    while(num < 90 && num % 10 != 9){
        num += 11;
        to_nums[num] = true;
        if(board[num] != EMPTY){
            break;
        };
    };
    return 0;
};
#endif