#ifndef _ENUM_MOVE_EX_HPP_
#define _ENUM_MOVE_EX_HPP_

   
#include "enum_moves.hpp"

inline int white_rider_king_from(unsigned char *board, bool *to_nums, int wk_pos){
    direction_PN(wk_pos, to_nums, board);
    direction_PS(wk_pos, to_nums, board);
    direction_PEW(wk_pos, to_nums, board);
    direction_PB(wk_pos, to_nums, board);
    return 0;
};


inline std::unordered_set<Move> white_nondrop_evite(unsigned char *board, bool *to_nums, int wk_pos){
    std::unordered_set<Move> s;
    int i, n, a;
    n = 11;
    while(n != 100){
        int p = board[n];
        if(p == W_PAWN){
            bool to_nums2[100] = BOOL_100;
            direction_S(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    if(i < 90){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == W_LANCE){
            bool to_nums2[100] = BOOL_100;
            direction_PS(n, to_nums2, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    if(i < 90){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == W_KNIGHT){
            bool to_nums2[100] = BOOL_100;
            direction_KS(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    if(i < 80){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == W_SILVER){
            bool to_nums2[100] = BOOL_100;
            direction_S(n, to_nums2);
            direction_NEW(n, to_nums2);
            direction_SEW(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i > 70 || n > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == W_GOLD || p == WP_PAWN || p == WP_LANCE || p == WP_KNIGHT || p == WP_SILVER){
            bool to_nums2[100] = BOOL_100;
            direction_N(n, to_nums2);
            direction_S(n, to_nums2);
            direction_EW(n, to_nums2);
            direction_SEW(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_KING){
            bool to_nums2[100] = BOOL_100;
            direction_N(n, to_nums2);
            direction_S(n, to_nums2);
            direction_EW(n, to_nums2);
            direction_NEW(n, to_nums2);
            direction_SEW(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_BISHOP){
            bool to_nums2[100] = BOOL_100;
            direction_PB(n, to_nums2, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i > 70 || n > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == WP_BISHOP){
            bool to_nums2[100] = BOOL_100;
            direction_PB(n, to_nums2, board);
            direction_N(n, to_nums2);
            direction_S(n, to_nums2);
            direction_EW(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        if(p == W_ROOK){
            bool to_nums2[100] = BOOL_100;
            direction_PN(n, to_nums2, board);
            direction_PS(n, to_nums2, board);
            direction_PEW(n, to_nums2, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i > 70 || n > 70){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == WP_ROOK){
            bool to_nums2[100] = BOOL_100;
            direction_PN(n, to_nums2, board);
            direction_PS(n, to_nums2, board);
            direction_PEW(n, to_nums2, board);
            direction_NEW(n, to_nums2);
            direction_SEW(n, to_nums2);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && to_nums2[i]){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        n += 1;
    };
    return s;
};
    
inline std::unordered_set<Move> white_legal_evite(unsigned char *board, unsigned char *hand, int wk_pos){
    std::unordered_set<Move> s;
    int i, j, n, a;
    unsigned char piece;
    bool to_nums[100] = BOOL_100;
    white_rider_king_from(board, to_nums, wk_pos);
    bool p[100] = BOOL_100;
    for(i = 0;i < 100;i++){
        if(to_nums[i] && board[i] == EMPTY){
            p[i] = true;
        };
    };
    if(hand[7] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                }else{
                    board[i] = EMPTY;
                    s.insert(make_move(B_ROOK, i, DROP, UNDEFINED));
                };
            };
        };
    };
    if(hand[8] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_BISHOP, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[9] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_GOLD, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[10] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_wking(board, wk_pos)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_SILVER, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[11] != 0){
        for(i = 0;i < 100;i++){
            if(p[i] && i < 80){
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
        for(i = 0;i < 100;i++){
            if(p[i] && i < 90){
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
                    p[n] = false;
                };
            };
            if(board[i] == B_KING){
                a = i;
            };
        };
        //打ち歩詰め処理
        if(a != -1){
            a -= 10;
            if(p[a]){
                board[a] = W_PAWN;
                std::unordered_set<Move> s2 = legal_moves(true, board, hand, wk_pos);
                if(s2.size() == 0){
                    p[a] = false;
                };
                board[a] = EMPTY;
            }; 
        };
        for(i = 0;i < 100;i++){
            if(p[i] && i < 90){
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
    //nondrop
    direction_KS(wk_pos, to_nums);
    for(auto move:white_nondrop_evite(board, to_nums, wk_pos)){
        if(!IS_W(board[GET_MOVE_TO(move)])){
            piece = board[GET_MOVE_TO(move)];
            board[GET_MOVE_TO(move)] = board[GET_MOVE_FROM(move)];
            board[GET_MOVE_FROM(move)] = EMPTY;
            if(is_check_wking(board, GET_MOVE_FROM(move) == wk_pos ? GET_MOVE_TO(move) : wk_pos)){
                board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
                board[GET_MOVE_TO(move)] = piece;
                continue;
            };
            board[GET_MOVE_FROM(move)] = board[GET_MOVE_TO(move)];
            board[GET_MOVE_TO(move)] = piece;
            s.insert(move);
        }
    };
    return s;
};

inline std::unordered_set<Move> preliminary_black_checks(unsigned char *board, bool *wk_nums){
    std::unordered_set<Move> s;
    int i, n;
    n = 11;
    while(n != 100){
        int p = board[n];
        if(p == B_PAWN){
            bool to_nums[100] = BOOL_100;
            direction_N(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    if(i > 20){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == B_LANCE){
            bool to_nums[100] = BOOL_100;
            direction_PN(n, to_nums, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    if(i > 20){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == B_KNIGHT){
            bool to_nums[100] = BOOL_100;
            direction_KN(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    if(i > 30){
                        s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    };
                    if(i < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == B_SILVER){
            bool to_nums[100] = BOOL_100;
            direction_N(n, to_nums);
            direction_NEW(n, to_nums);
            direction_SEW(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i < 40 || n < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == B_GOLD || p == BP_PAWN || p == BP_LANCE || p == BP_KNIGHT || p ==BP_SILVER){
            bool to_nums[100] = BOOL_100;
            direction_N(n, to_nums);
            direction_S(n, to_nums);
            direction_EW(n, to_nums);
            direction_NEW(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_KING){
            bool to_nums[100] = BOOL_100;
            direction_N(n, to_nums);
            direction_S(n, to_nums);
            direction_EW(n, to_nums);
            direction_NEW(n, to_nums);
            direction_SEW(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i < 40 || n < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == B_BISHOP){
            bool to_nums[100] = BOOL_100;
            direction_PB(n, to_nums, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i < 40 || n < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == BP_BISHOP){
            bool to_nums[100] = BOOL_100;
            direction_PB(n, to_nums, board);
            direction_N(n, to_nums);
            direction_S(n, to_nums);
            direction_EW(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        if(p == B_ROOK){
            bool to_nums[100] = BOOL_100;
            direction_PN(n, to_nums, board);
            direction_PS(n, to_nums, board);
            direction_PEW(n, to_nums, board);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                    if(i < 40 || n < 40){
                        s.insert(make_move(n, i, PROMOTE, UNDEFINED));
                    };
                };
            };
        };
        if(p == BP_ROOK){
            bool to_nums[100] = BOOL_100;
            direction_PN(n, to_nums, board);
            direction_PS(n, to_nums, board);
            direction_PEW(n, to_nums, board);
            direction_NEW(n, to_nums);
            direction_SEW(n, to_nums);
            for(i = 11;i < 100;i++){
                if(to_nums[i] && (wk_nums[i] || wk_nums[n])){
                    s.insert(make_move(n, i, NONPROMOTE, UNDEFINED));
                };
            };
        };
        n += 1;
    };
    return s;
};

inline std::unordered_set<Move> black_legal_prechecks(unsigned char *board, unsigned char *hand, int wk_pos){
    std::unordered_set<Move> s;
    unsigned char piece;
    int i, j, n, a;
    bool wk_nums[100] = BOOL_100;
    white_rider_king_from(board, wk_nums, wk_pos);
    direction_KS(get_wk(board), wk_nums);
    for(auto move:preliminary_black_checks(board, wk_nums)){
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
    bool p[100] = BOOL_100;
    for(i = 0;i < 100;i++){
        if(board[i] == EMPTY && wk_nums[i]){
            p[i] = true;
        };
    };
    if(hand[0] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_ROOK, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[1] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_BISHOP, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[2] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_GOLD, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[3] != 0){
        for(i = 0;i < 100;i++){
            if(p[i]){
                board[i] = WALL;
                if(is_check_bking(board)){
                    board[i] = EMPTY;
                    continue;
                };
                board[i] = EMPTY;
                s.insert(make_move(B_SILVER, i, DROP, UNDEFINED));
            };
        };
    };
    if(hand[4] != 0){
        for(i = 0;i < 100;i++){
            if(p[i] && i > 30){
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
        for(i = 0;i < 100;i++){
            if(p[i] && i > 20){
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
        a = wk_pos;
        for(i = 11;i < 100;i++){
            if(board[i] == B_PAWN){
                n = i % 10;
                for(j = 0;j < 10;j++){
                    n += 10;
                    p[n] = false;
                };
            };
        };
        //打歩詰処理
        if(a != -1){
            a += 10;
            if(p[a]){
                board[a] = B_PAWN;
                std::unordered_set<Move> s2 = legal_moves(false, board, hand, wk_pos);
                if(s2.size() == 0){
                    p[a] = false;
                };
                board[a] = EMPTY;
            }; 
        };
        for(i = 0;i < 100;i++){
            if(p[i] && i > 20){
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
    return s;
};

std::unordered_set<Move> black_check_moves(unsigned char *board, unsigned char *hand, int wk_pos){
    std::unordered_set<Move> checks;
    for(auto move:black_legal_prechecks(board, hand, wk_pos)){
        unsigned char move_to = GET_MOVE_TO(move);
        unsigned char move_from = GET_MOVE_FROM(move);
        if((GET_MOVE_TYPE(move)) == DROP){
            board[move_to] = move_from;
            if(is_check_wking(board, wk_pos)){
                checks.insert(move);
            };
            board[move_to] = EMPTY;
        }else{
            unsigned char p = board[move_to];
            board[move_to] = board[move_from];
            board[move_from] = EMPTY;
            if((GET_MOVE_TYPE(move)) == PROMOTE){
                board[move_to] += 8;
            };
            if(is_check_wking(board, wk_pos)){
                checks.insert(move);
            };
            if((GET_MOVE_TYPE(move)) == PROMOTE){
                board[move_to] -= 8;
            };
            board[move_from] =board[move_to];
            board[move_to] = p;
        };
    };
    return checks;
};


#endif