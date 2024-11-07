#ifndef _INFO_HPP_
#define _INFO_HPP_

#include "move.hpp"



struct b_info{
    Move move;
    unsigned char piece;
    bool operator==(b_info const & info)const{
        return (move == info.move && piece == info.piece);
    };
};

template <> struct std::hash<b_info>{
    inline std::size_t operator()(const b_info & i)const{
        std::size_t move = std::hash<Move>()(i.move);
        std::size_t piece = std::hash<unsigned char>()(i.piece);
        return (move << 5) ^ piece;
    };
};


inline b_info make_b_info(Move move, unsigned char piece){
    b_info i;
    i.move = move;
    i.piece = piece;
    return i;
};
struct w_info{
    char position;
    char check;
    bool operator==(w_info const & info)const{
        return (position == info.position && check == info.check);
    };
};

template <> struct std::hash<w_info>{
    inline std::size_t operator()(const w_info & i)const{
        std::size_t piece = std::hash<char>()(i.position);
        std::size_t check = std::hash<char>()(i.check);
        return (piece << 2) ^ check;
    };
};


inline w_info make_w_info(char position, char check){
    w_info i;
    i.position = position;
    i.check = check;
    return i;
};
#endif