
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

#include "print.hpp"
#include "board.hpp"
#include "node.hpp"
#include "read.hpp"


class Help{
    private:
        char base_board[100];
        unsigned char base_hand[100];
        int ans_lim;
        int mate_ply;
        int ill;
        Board board;
    public:
        Help();
        int main();
        int set(char *base_board, unsigned char *base_hand, bool turn);
        int enum_check();
        int safe_main();
        int solve();
};

Help::Help():ans_lim(10){
    this->board = Board();
};

int Help::solve(){
    int i, j;
    std::stack<std::string> answers;
    std::cout<<"info string engine will solve problem as helpmate in "<<(this->mate_ply)<<" moves and "<<(this->ill)<<" limit_invalids."<<std::endl;
    //solve
    std::unordered_set<Board> init_boards;
    init_boards.insert(this->board);
    std::string history = "kifu: ";
    Node node(init_boards, this->ill, history);
    //node.search(this->mate_ply, &answers, this->ans_lim);
    node.search(this->mate_ply, &answers, this->ans_lim);
    int answer_num = answers.size();
    std::string mate_cmd = "checkmate nomate";
    for(i = 0;i < answer_num;i++){
        std::string answer = answers.top();
        answers.pop();
        std::cout<<"info string "<<answer<<std::endl;
    };
    std::cout<<mate_cmd<<std::endl;
    return 0;
};
int Help::main(){
    std::string cmd, sfen_board, sfen_turn, sfen_hand;
    int i, j, k;
    int n;
    while(1){
        std::cin>>cmd;
        if(cmd == "usi"){
            std::cout<<"id name blindhelp_beta"<<std::endl;
            std::cout<<"id author xzg17"<<std::endl;
            std::cout<<"option name MatePly type spin default 1 min 1 max 99"<<std::endl;
            std::cout<<"option name RetryLimit type spin default 99 min 0 max 99"<<std::endl;
            std::cout<<"option name AnswerLimit type spin default 10 min 1 max 99"<<std::endl;
            std::cout<<"usiok"<<std::endl;
        }else if(cmd == "isready"){
            std::cout<<"readyok"<<std::endl;
        }else if(cmd == "setoption"){
            std::cin>>cmd;
            if(cmd == "name"){
                std::cin>>cmd;
                if(cmd == "MatePly"){
                    std::cin>>cmd;
                    if(cmd == "value"){
                        std::cin>>i;
                        this->mate_ply = i;
                    };
                }else if(cmd == "RetryLimit"){
                    std::cin>>cmd;
                    if(cmd == "value"){
                        std::cin>>i;
                        this->ill = i;
                    };
                }else if(cmd == "AnswerLimit"){
                    std::cin>>cmd;
                    if(cmd == "value"){
                        std::cin>>i;
                        this->ans_lim = i;
                    };
                }
            };
        }else if(cmd == "position"){
            std::cin>>cmd;
            if(cmd == "sfen"){
                std::cin>>sfen_board>>sfen_turn>>sfen_hand;
                char board[100];
                read_board(sfen_board, board);
                unsigned char hand[14];
                read_hand(sfen_hand, hand);
                this->set(board, hand, (sfen_turn[0] == 'b'));
                //log_board(this->board.board);
                //log_hand(this->board.hand);
            };
        }else if(cmd == "go"){
            std::cin>>cmd;
            if(cmd == "mate"){
                std::cin>>cmd;
                if(cmd == "infinite"){
                    this->solve();
                }else{
                    this->mate_ply = std::stoi(cmd);
                    std::cout<<"checkmate notimplemented"<<std::endl;
                };
            }else{
                std::cout<<"bestmove resign"<<std::endl;
            };
        }else if(cmd == "usinewgame"){
            bool on_game = true;
        }else if(cmd == "quit"){
            break;
        };
    };
    return 0;
};

int Help::set(char *base_board, unsigned char *base_hand, bool turn){
    this->board.set(base_board, base_hand, turn);
    return 0;
};