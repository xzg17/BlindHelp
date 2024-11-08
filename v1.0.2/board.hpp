#ifndef _BOARD_HPP_
#define _BOARD_HPP_




#include <stack>
#include "enum_moves_ex.hpp"
#include "table.hpp"

class Board{
    private:
    public:
    int wk_pos;
    char board[100];
    unsigned char  hand[14];
    unsigned long long hash_value;
    //*****CBA
    //A:authentic
    //B:in probelem
    //C:hash
    char flag_char; 
    std::unordered_set<Move> authentic_legal_moves_set;
    std::unordered_set<Move> legal_moves_set_in_problem;
    bool turn;
    Board():flag_char(0){};
    int init(){
        this->wk_pos = 15;
        this->turn = 1;
        int i;
        for(i = 0;i < 100;i++){
            this->board[i] = init_board[i];
            if(i < 14){
                this->hand[i] = 0;
            };
        };
        this->flag_char = 0;
        return 0;
    };
    Board(const Board &board) = default;
    int is_check(){
        if(this->turn){
            return is_check_bking(this->board);
        }else{
            return is_check_wking(this->board, this->wk_pos);
        };
    };

    int set(char *input_board, unsigned char *input_hand, bool turn){
        this->turn = turn;
        int i;
        for(i = 0;i < 100;i++){
            this->board[i] = input_board[i];
            if(i < 14){
                this->hand[i] = input_hand[i];
            };
        };
        this->wk_pos = get_wk(input_board);
        return 0;
    };

    int push(Move move){
        this->flag_char &= 4;
        int move_to = GET_MOVE_TO(move);
        if((GET_MOVE_TYPE(move)) != DROP){
            int move_from = GET_MOVE_FROM(move);
            this->hash_value ^= zob_table[this->board[move_from]-1][move_from];
            if(move_from == this->wk_pos){
                this->wk_pos = move_to;
            };
            if(this->board[move_to] != EMPTY){
                if(this->board[move_to] == W_ROOK || this->board[move_to] == WP_ROOK){
                    this->hand[0] += 1;
                }else if(this->board[move_to] == W_BISHOP || this->board[move_to] == WP_BISHOP){
                    this->hand[1] += 1;
                }else if(this->board[move_to] == W_GOLD){
                    this->hand[2] += 1;
                }else if(this->board[move_to] == W_SILVER || this->board[move_to] == WP_SILVER){
                    this->hand[3] += 1;
                }else if(this->board[move_to] == W_KNIGHT || this->board[move_to] == WP_KNIGHT){
                    this->hand[4] += 1;
                }else if(this->board[move_to] == W_LANCE || this->board[move_to] == WP_LANCE){
                    this->hand[5] += 1;
                }else if(this->board[move_to] == W_PAWN || this->board[move_to] == WP_PAWN){
                    this->hand[6] += 1;
                }else if(this->board[move_to] == B_ROOK || this->board[move_to] == BP_ROOK){
                    this->hand[7] += 1;
                }else if(this->board[move_to] == B_BISHOP || this->board[move_to] == BP_BISHOP){
                    this->hand[8] += 1;
                }else if(this->board[move_to] == B_GOLD){
                    this->hand[9] += 1;
                }else if(this->board[move_to] == B_SILVER || this->board[move_to] == BP_SILVER){
                    this->hand[10] += 1;
                }else if(this->board[move_to] == B_KNIGHT || this->board[move_to] == BP_KNIGHT){
                    this->hand[11] += 1;
                }else if(this->board[move_to] == B_LANCE|| this->board[move_to] == BP_LANCE){
                    this->hand[12] += 1;
                }else if(this->board[move_to] == B_PAWN || this->board[move_to] == BP_PAWN){
                    this->hand[13] += 1;
                };
            };
            this->board[move_to] = this->board[move_from];
            if((GET_MOVE_TYPE(move)) == PROMOTE){
                this->board[move_to] += 8;
            }
            this->board[move_from] = EMPTY;
        }else{
            if(this->turn == 1){
                if(GET_MOVE_FROM(move) == B_ROOK){
                    this->hand[0] -= 1;
                }else if(GET_MOVE_FROM(move) == B_BISHOP){
                    this->hand[1] -= 1;
                }else if(GET_MOVE_FROM(move) == B_GOLD){
                    this->hand[2] -= 1;
                }else if(GET_MOVE_FROM(move) == B_SILVER){
                    this->hand[3] -= 1;
                }else if(GET_MOVE_FROM(move) == B_KNIGHT){
                    this->hand[4] -= 1;
                }else if(GET_MOVE_FROM(move) == B_LANCE){
                    this->hand[5] -= 1;
                }else if(GET_MOVE_FROM(move) == B_PAWN){
                    this->hand[6] -= 1;
                };
                this->board[move_to] = GET_MOVE_FROM(move);
            }else{
                if(GET_MOVE_FROM(move) == B_ROOK){
                    this->hand[7] -= 1;
                }else if(GET_MOVE_FROM(move) == B_BISHOP){
                    this->hand[8] -= 1;
                }else if(GET_MOVE_FROM(move) == B_GOLD){
                    this->hand[9] -= 1;
                }else if(GET_MOVE_FROM(move) == B_SILVER){
                    this->hand[10] -= 1;
                }else if(GET_MOVE_FROM(move) == B_KNIGHT){
                    this->hand[11] -= 1;
                }else if(GET_MOVE_FROM(move) == B_LANCE){
                    this->hand[12] -= 1;
                }else if(GET_MOVE_FROM(move) == B_PAWN){
                    this->hand[13] -= 1;
                };
                this->board[move_to] = GET_MOVE_FROM(move) + 16;
            };
        };
        this->turn = !(this->turn);
        this->hash_value ^= zob_table[this->board[move_to]-1][move_to];
        return 1;
    };
    std::unordered_set<Move> authentic_legal_moves(){
        if(!(this->flag_char & 1)){
            if(!(this->turn)){
                this->authentic_legal_moves_set = white_legal_evite(this->board, this->hand, this->wk_pos);
            }else{
                this->authentic_legal_moves_set = legal_moves(this->turn, this->board, this->hand, this->wk_pos);
            };
            this->flag_char |= 1;
        };
        return this->authentic_legal_moves_set;
    };
    std::unordered_set<Move> legal_moves_in_problem(){
        if(!(this->flag_char & 2)){
            if(this->turn){
                this->legal_moves_set_in_problem = black_check_moves(this->board, this->hand, this->wk_pos);
            }else{
                this->legal_moves_set_in_problem = white_legal_evite(this->board, this->hand, this->wk_pos);
            };
            this->flag_char |= 2;
        };
        return this->legal_moves_set_in_problem;
    };
    int is_legal(Move move){
        if(!(this->flag_char & 1)){
            if(!(this->turn)){
                this->authentic_legal_moves_set = white_legal_evite(this->board, this->hand, this->wk_pos);
            }else{
                this->authentic_legal_moves_set = legal_moves(this->turn, this->board, this->hand, this->wk_pos);
            };
            this->flag_char |= 1;
        };
        return (this->authentic_legal_moves_set.count(move));
    };
    int is_legal_in_problem(Move move){
        if(!(this->flag_char & 2)){
            if(this->turn){
                this->legal_moves_set_in_problem = black_check_moves(this->board, this->hand, this->wk_pos);
            }else{
                this->legal_moves_set_in_problem = white_legal_evite(this->board, this->hand, this->wk_pos);
            };
            this->flag_char |= 2;
        };
        return (this->legal_moves_set_in_problem.count(move));
    };
    std::size_t hash_(){
        if(!(this->flag_char & 4)){
            this->hash_value = (unsigned long long)zob_hash(this->board);
            this->flag_char |= 4;
        }
        return (std::size_t)this->hash_value;
    };
    std::size_t const_hash_()const{
        if(!(this->flag_char & 4)){
            return zob_hash(this->board);
        }
        return (std::size_t)this->hash_value;
    };
    bool operator==(Board const & another_board)const{
        for(int i =0;i<100;i++){
            if(board[i] != another_board.board[i]){
                return false;
            };
        };
        for(int i =0;i<14;i++){
            if(hand[i] != another_board.hand[i]){
                return false;
            };
        };
        return true;
    };
    bool operator<=(Board const & another_board)const{
        for(int i =0;i<100;i++){
            if(board[i] != another_board.board[i]){
                return false;
            };
        };
        for(int i =0;i<7;i++){
            if(hand[i] > another_board.hand[i]){
                return false;
            };
        };
        for(int i =7;i<14;i++){
            if(hand[i] < another_board.hand[i]){
                return false;
            };
        };
        return true;
    };
    bool operator>=(Board const & another_board)const{
        for(int i =0;i<100;i++){
            if(board[i] != another_board.board[i]){
                return false;
            };
        };
        for(int i =0;i<7;i++){
            if(hand[i] < another_board.hand[i]){
                return false;
            };
        };
        for(int i =7;i<14;i++){
            if(hand[i] > another_board.hand[i]){
                return false;
            };
        };
        return true;
    };
};
//*
template <> struct std::hash<Board>{
    inline std::size_t operator()(const Board & board)const{
        return board.const_hash_();
    };
};
//*/

#endif