#ifndef _PRINT_HPP_
#define _PRINT_HPP_

#include <string>
#include "move.hpp"
#include "piece.hpp"


std::string s_num = "0987654321";
std::string s_abc = "zabcdefghi";
std::string S_piece = "ePLNSBRGK";

inline char convert_num(int i){
    return s_num[i % 10];
};
inline char convert_abc(int i){
    return s_abc[i / 10];
};
inline char convert_piece(int i){
    return S_piece[i];
};

inline std::string convert_index(int i){
    std::string sfen_str = "**";
    sfen_str[0] = convert_num(i);
    sfen_str[1] = convert_abc(i);
    return sfen_str;
};

inline std::string move_to_sfen_grid(Move move){
    unsigned char from = GET_MOVE_FROM(move);
    unsigned char to = GET_MOVE_TO(move);
    unsigned char type = GET_MOVE_TYPE(move);
    std::string s_move = "****";
    s_move[2] = convert_num((int)to);
    s_move[3] = convert_abc((int)to);
    if(type != DROP){
        s_move[0] = convert_num((int)from);
        s_move[1] = convert_abc((int)from);
    }else{
        s_move[0] = convert_piece((int)from);
    };
    if(type == PROMOTE){
        s_move += "+";
    };
    return s_move;
};

int log_board(const char *board){
    for(int i = 1;i <= 9;i++){
        std::string raw = "|";
        for(int j = 1;j <= 9;j++){
            char p = board[j+i*10];
            if(p == EMPTY){
                raw += (std::string)"__|";
            }else if(p == B_PAWN){
                raw += (std::string)"^P_";
            }else if(p == B_LANCE){
                raw += (std::string)"^L_";
            }else if(p == B_KNIGHT){
                raw += (std::string)"^N_";
            }else if(p == B_SILVER){
                raw += (std::string)"^S_";
            }else if(p == B_GOLD){
                raw += (std::string)"^G_";
            }else if(p == B_BISHOP){
                raw += (std::string)"^B_";
            }else if(p == B_ROOK){
                raw += (std::string)"^R_";
            }else if(p == B_KING){
                raw += (std::string)"^K_";
            }else if(p == BP_PAWN){
                raw += (std::string)"^P+";
            }else if(p == BP_LANCE){
                raw += (std::string)"^L+";
            }else if(p == BP_KNIGHT){
                raw += (std::string)"^N+";
            }else if(p == BP_SILVER){
                raw += (std::string)"^S+";
            }else if(p == BP_BISHOP){
                raw += (std::string)"^B+";
            }else if(p == BP_ROOK){
                raw += (std::string)"^R+";
            }else if(p == W_PAWN){
                raw += (std::string)"vP_";
            }else if(p == W_LANCE){
                raw += (std::string)"vL_";
            }else if(p == W_KNIGHT){
                raw += (std::string)"vN_";
            }else if(p == W_SILVER){
                raw += (std::string)"vS_";
            }else if(p == W_GOLD){
                raw += (std::string)"vG_";
            }else if(p == W_BISHOP){
                raw += (std::string)"vB_";
            }else if(p == W_ROOK){
                raw += (std::string)"vR_";
            }else if(p == W_KING){
                raw += (std::string)"vK_";
            }else if(p == WP_PAWN){
                raw += (std::string)"vP+";
            }else if(p == WP_LANCE){
                raw += (std::string)"vL+";
            }else if(p == WP_KNIGHT){
                raw += (std::string)"vN+";
            }else if(p == WP_SILVER){
                raw += (std::string)"vS+";
            }else if(p == WP_BISHOP){
                raw += (std::string)"vB+";
            }else if(p == WP_ROOK){
                raw += (std::string)"vR+";
            }else{
                raw += (std::string)"BAG";
            };
        };
        std::cout<<raw<<std::endl;
    };
    return 0;
};
int log_hand(unsigned char *hand){
    std::cout<<"Black:"<<std::endl;
    std::cout<<"Rook:"<<(int)hand[0]<<std::endl;
    std::cout<<"Bishop:"<<(int)hand[1]<<std::endl;
    std::cout<<"Gold:"<<(int)hand[2]<<std::endl;
    std::cout<<"Silver:"<<(int)hand[3]<<std::endl;
    std::cout<<"Knight:"<<(int)hand[4]<<std::endl;
    std::cout<<"Lance:"<<(int)hand[5]<<std::endl;
    std::cout<<"Pawn:"<<(int)hand[6]<<std::endl;
    std::cout<<"White:"<<std::endl;
    std::cout<<"Rook:"<<(int)hand[7]<<std::endl;
    std::cout<<"Bishop:"<<(int)hand[8]<<std::endl;
    std::cout<<"Gold:"<<(int)hand[9]<<std::endl;
    std::cout<<"Silver:"<<(int)hand[10]<<std::endl;
    std::cout<<"Knight:"<<(int)hand[11]<<std::endl;
    std::cout<<"Lance:"<<(int)hand[12]<<std::endl;
    std::cout<<"Pawn:"<<(int)hand[13]<<std::endl;
    return 0;
};

#endif