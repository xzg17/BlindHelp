#ifndef _ENUM_MOVES_HPP_
#define _ENUM_MOVES_HPP_

#include "move.hpp"
#include "directions.hpp"

inline int get_wk(char *board){
    int i, n;
    for(i = 11;i < 100;i++){
        if(board[i] == W_KING){
            n = i;
            break;
        };
    };
    if(i == 100){
        return -1;
    };
    return n;
};

std::unordered_set<Move> black_move(char *board){
    std::unordered_set<Move> s;
    int i, n;
    n = 11;
    while(n != 100){
        int p = board[n];
        if(p == B_PAWN){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i > 20){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_LANCE){
            limited_set<char, 100> to_nums;
            direction_PN(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i > 20){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_KNIGHT){
            limited_set<char, 100> to_nums;
            direction_KN(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i > 30){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_SILVER){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i < 40 || n < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_GOLD || p == BP_PAWN || p == BP_LANCE || p == BP_KNIGHT || p ==BP_SILVER){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            direction_NEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        if(p == B_KING){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i < 40 || n < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_BISHOP){
            limited_set<char, 100> to_nums;
            direction_PB(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i < 40 || n < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == BP_BISHOP){
            limited_set<char, 100> to_nums;
            direction_PB(n, &to_nums, board);
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        if(p == B_ROOK){
            limited_set<char, 100> to_nums;
            direction_PN(n, &to_nums, board);
            direction_PS(n, &to_nums, board);
            direction_PEW(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i < 40 || n < 40){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == BP_ROOK){
            limited_set<char, 100> to_nums;
            direction_PN(n, &to_nums, board);
            direction_PS(n, &to_nums, board);
            direction_PEW(n, &to_nums, board);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        n += 1;
    };
    return s;
};
std::unordered_set<Move> white_move(char* board){
    std::unordered_set<Move> s;
    int i, n;
    n = 11;
    while(n != 100){
        int p = board[n];
        if(p == W_PAWN){
            limited_set<char, 100> to_nums;
            direction_S(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i < 90){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_LANCE){
            limited_set<char, 100> to_nums;
            direction_PS(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i < 90){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_KNIGHT){
            limited_set<char, 100> to_nums;
            direction_KS(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                if(i < 80){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
                if(i > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_SILVER){
            limited_set<char, 100> to_nums;
            direction_S(n, &to_nums);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i > 70 || n > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_GOLD || p == WP_PAWN || p == WP_LANCE || p == WP_KNIGHT || p == WP_SILVER){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        if(p == W_KING){
            limited_set<char, 100> to_nums;
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        if(p == W_BISHOP){
            limited_set<char, 100> to_nums;
            direction_PB(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i > 70 || n > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == WP_BISHOP){
            limited_set<char, 100> to_nums;
            direction_PB(n, &to_nums, board);
            direction_N(n, &to_nums);
            direction_S(n, &to_nums);
            direction_EW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        if(p == W_ROOK){
            limited_set<char, 100> to_nums;
            direction_PN(n, &to_nums, board);
            direction_PS(n, &to_nums, board);
            direction_PEW(n, &to_nums, board);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                if(i > 70 || n > 70){
                    s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                };
            };
        };
        if(p == WP_ROOK){
            limited_set<char, 100> to_nums;
            direction_PN(n, &to_nums, board);
            direction_PS(n, &to_nums, board);
            direction_PEW(n, &to_nums, board);
            direction_NEW(n, &to_nums);
            direction_SEW(n, &to_nums);
            ITERATE_LIMITED_SET(i, to_nums){
                s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
            };
        };
        n += 1;
    };
    return s;
};
int is_check_bking(char *board){
    int i, n, a;
    for(i = 11;i < 100;i++){
        if(board[i] == B_KING){
            n = i;
            break;
        };
    };
    if(i == 100){
        return 0;
    };
    {
        limited_set<char, 100> to_nums;
        direction_N(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_WP(a) || a == W_PAWN || a == W_LANCE || a == W_SILVER || a == W_GOLD || a == W_ROOK || a == W_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_NEW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_WP(a) || a == W_SILVER || a == W_GOLD || a == W_BISHOP || a == W_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_S(n, &to_nums);
        direction_EW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_WP(a) || a == W_GOLD || a == W_ROOK || a == W_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_SEW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == W_SILVER || a == W_BISHOP || a == WP_BISHOP || a == WP_ROOK || a == W_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_KN(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == W_KNIGHT){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PN(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == W_LANCE || a == W_ROOK || a == WP_ROOK){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PS(n, &to_nums, board);
        direction_PEW(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == W_ROOK || a == WP_ROOK){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PB(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == W_BISHOP || a == WP_BISHOP){
                return 1;
            };
        };
    };
    return 0;
};
int is_check_wking(char *board, int wk_pos){
    if(wk_pos == -1){
        return 0;
    };
    int i, n, a;
    n = wk_pos;
    {
        limited_set<char, 100> to_nums;
        direction_S(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_BP(a) || a == B_PAWN || a == B_LANCE || a == B_SILVER || a == B_GOLD || a == B_ROOK || a == B_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_SEW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_BP(a) || a == B_SILVER || a == B_GOLD || a == B_BISHOP || a == B_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_N(n, &to_nums);
        direction_EW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(IS_BP(a) || a == B_GOLD || a == B_ROOK || a == B_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_NEW(n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == B_SILVER || a == B_BISHOP || a == BP_BISHOP || a == BP_ROOK || a == B_KING){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_KS((char)n, &to_nums);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == B_KNIGHT){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PS(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == B_LANCE || a == B_ROOK || a == BP_ROOK){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PN(n, &to_nums, board);
        direction_PEW(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == B_ROOK || a == BP_ROOK){
                return 1;
            };
        };
    };
    {
        limited_set<char, 100> to_nums;
        direction_PB(n, &to_nums, board);
        ITERATE_LIMITED_SET(i, to_nums){
            a = board[i];
            if(a == B_BISHOP || a == BP_BISHOP){
                return 1;
            };
        };
    };
    return 0;
};    

std::unordered_set<Move> legal_moves(bool turn, char *board, unsigned char *hand,const int wk_pos){
    std::unordered_set<Move> s;
    unsigned char piece;
    int i, j, n, a;
    if(turn){
        for(auto move:black_move(board)){
            if(!IS_B(board[GET_MOVE_TO(move)])){
                piece = board[GET_MOVE_TO(move)];
                board[GET_MOVE_TO(move)] = board[GET_MOVE_FROM(move)];
                board[GET_MOVE_FROM(move)] = EMPTY;
                if(is_check_bking(board)){
                    board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                    board[GET_MOVE_TO(move)] = piece;
                    continue;
                };
                board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                board[GET_MOVE_TO(move)] = piece;
                s.insert(move);
            };
        };
        limited_set<char, 100> p;
        for(i = 0;i < 100;i++){
            if(board[i] == EMPTY){
                p.insert(i);
            };
        };
        if(hand[0] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_ROOK, i, DROP, UNDEFINED));
            };
        };
        if(hand[1] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_BISHOP, i, DROP, UNDEFINED));
            };
        };
        if(hand[2] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_GOLD, i, DROP, UNDEFINED));
            };
        };
        if(hand[3] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_SILVER, i, DROP, UNDEFINED));
            };
        };
        if(hand[4] != 0){
            ITERATE_LIMITED_SET(i, p){
                if(i > 30){
                    board[i] = WALL;
                    if(is_check_bking(board)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_KNIGHT, i, DROP, UNDEFINED));
                };
            };
        };
        if(hand[5] != 0){
            ITERATE_LIMITED_SET(i, p){
                if(i > 20){
                    board[i] = WALL;
                    if(is_check_bking(board)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_LANCE, i, DROP, UNDEFINED));
                };
            };
        };
        if(hand[6] != 0){
            a = -1;
            for(i = 11;i < 100;i++){
                if(board[i] == B_PAWN){
                    n = i % 10;
                    for(j = 0;j < 10;j++){
                        n += 10;
                        p.erase(n);
                    };
                };
                if(board[i] == W_KING){
                    a = i;
                };
            };
            //打歩詰処理
            if(a != -1){
                a += 10;
                if(p.count(a)){
                    board[a] = B_PAWN;
                    std::unordered_set<Move> s2 = legal_moves(!turn, board, hand, wk_pos);
                    if(s2.size() == 0){
                        p.erase(a);
                    };
                    board[a] = EMPTY;
                }; 
            };
            ITERATE_LIMITED_SET(i, p){
                if(i > 20){
                    board[i] = WALL;
                    if(is_check_bking(board)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_PAWN, i, DROP, UNDEFINED));
                };
            };
        };
    }else{
        for(auto move:white_move(board)){
            if(!IS_W(board[GET_MOVE_TO(move)])){
                piece = board[GET_MOVE_TO(move)];
                board[GET_MOVE_TO(move)] = board[GET_MOVE_FROM(move)];
                board[GET_MOVE_FROM(move)] = EMPTY;
                if(board[GET_MOVE_TO(move)] == W_KING){
                    if(is_check_wking(board, GET_MOVE_TO(move))){
                        board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                        board[GET_MOVE_TO(move)] = piece;
                        continue;
                    };
                }else{
                    if(is_check_wking(board, wk_pos)){
                        board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                        board[GET_MOVE_TO(move)] = piece;
                        continue;
                    };
                };
                board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                board[GET_MOVE_TO(move)] = piece;
                s.insert(move);
            }
        };
        limited_set<char, 100> p;
        for(i = 0;i < 100;i++){
            if(board[i] == EMPTY){
                p.insert(i);
            };
        };
        if(hand[7] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_ROOK, i, DROP, UNDEFINED));
            };
        };
        if(hand[8] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_BISHOP, i, DROP, UNDEFINED));
            };
        };
        if(hand[9] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_GOLD, i, DROP, UNDEFINED));
            };
        };
        if(hand[10] != 0){
            ITERATE_LIMITED_SET(i, p){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_SILVER, i, DROP, UNDEFINED));
            };
        };
        if(hand[11] != 0){
            ITERATE_LIMITED_SET(i, p){
                if(i < 80){
                    board[i] = WALL;
                    if(is_check_wking(board, wk_pos)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_KNIGHT, i, DROP, UNDEFINED));
                };
            };
        };
        if(hand[12] != 0){
            ITERATE_LIMITED_SET(i, p){
                if(i < 90){
                    board[i] = WALL;
                    if(is_check_wking(board, wk_pos)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_LANCE, i, DROP, UNDEFINED));
                };
            };
        };
        if(hand[13] != 0){
            a = -1;
            for(i = 11;i < 100;i++){
                if(board[i] == W_PAWN){
                    n = i % 10;
                    for(j = 0;j < 10;j++){
                        n += 10;
                        p.erase(a);
                    };
                };
                if(board[i] == B_KING){
                    a = i;
                };
            };
            if(a != -1){
                a -= 10;
                if(p.count(a)){
                    board[a] = W_PAWN;
                    std::unordered_set<Move> s2 = legal_moves(!turn, board, hand, wk_pos);
                    if(s2.size() == 0){
                        p.erase(a);
                    };
                    board[a] = EMPTY;
                }; 
            };
            ITERATE_LIMITED_SET(i, p){
                if(i < 90){
                    board[i] = WALL;
                    if(is_check_wking(board, wk_pos)){
                        board[i] = EMPTY;
                        continue;
                    };
                    board[i] = EMPTY;
                    s.insert(make_move(B_PAWN, i, DROP, UNDEFINED));
                };
            };
        };
    };
    return s;
};

#endif
