#ifndef _MOVE_HPP_
#define _MOVE_HPP_

#include <unordered_set>

#define GET_MOVE_FROM(move) move.from
#define GET_MOVE_TO(move) move.to
#define GET_MOVE_TYPE(move) move.type
#define SET_MOVE_FROM(move, num) move.from = num
#define SET_MOVE_TO(move, num) move.to = num
#define SET_MOVE_TYPE(move, num) move.type = num

#define NONPROMOTE 0
#define PROMOTE 1
#define DROP 2

#define LEGAL 0
#define ILLEGAL 4
#define UNDEFINED 8


struct Move{
    unsigned char from;//11~99 and drop piece(7)
    unsigned char to;//11~99
    unsigned char type;//type:nonpromote, promote, drop, NULL
    bool operator==(Move const & move)const{
        return (from == move.from && to == move.to && (type) == (move.type));
    };
};

template <> struct std::hash<Move>{
    inline std::size_t operator()(const Move & move)const{
        std::size_t from = std::hash<int>()(move.from);
        std::size_t to = std::hash<int>()(move.to);
        std::size_t type = std::hash<int>()(move.type);
        return (!from) ^ to ^ type;
    };
};

inline Move make_move(int from, int to, int type, int legal){
    Move move;
    SET_MOVE_FROM(move, from);
    SET_MOVE_TO(move, to);
    move.type = type;
    return move;
};


#endif