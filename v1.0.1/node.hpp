#ifndef _NODE_HPP_
#define _NODE_HPP_


#include "iostream"
#include "print.hpp"
#include "board.hpp"
#include "info.hpp"

#include <vector>
#include <unordered_map>

#define LIST(type) std::vector< type > 
class Node{
    private:
    int ill;
    std::unordered_set<Board> boards;
    LIST(Node) valid_child_nodes;
    LIST(Node) invalid_child_nodes;
    LIST(Move) invalid_or_check_moves;
    LIST(Board) invalids;
    std::string history;
    public:
    Node(std::unordered_set<Board> boards, int ill, std::string history){
        this->boards = boards;
        this->valid_child_nodes.clear();
        this->invalid_child_nodes.clear();
        this->invalid_or_check_moves.clear();
        this->ill = ill;
        this->history = history;
    };

    int is_mate(std::stack<std::string> *answers){
        for(auto board:this->boards){
            if(board.turn){
                return 0;
            }else{
                if(board.legal_moves_in_problem().size() == 0){
                    if(board.is_check()){
                        answers->push(this->history);
                        return 1;
                    };
                };
            };
        };
        return 0;
    };

    int expand(){
        std::unordered_set<Move> pseudo_legal_move_set;
        std::unordered_set<Move> pseudo_check_set;
        if(this->boards.begin()->turn){
            for(auto board:this->boards){
                for(auto move:board.legal_moves_in_problem()){
                    pseudo_check_set.insert(move);
                };
            };
            for(auto move:pseudo_check_set){
                bool legal_in_blind = true;
                for(auto board:this->boards){
                    if(board.is_legal(move)){
                        if(!(board.is_legal_in_problem(move))){
                            legal_in_blind = false;
                        };
                    }else{
                        if(this->ill <= 0){
                            legal_in_blind = false;
                        };
                    };
                    if(!legal_in_blind){
                        break;
                    };
                };
                if(legal_in_blind){
                    this->invalid_or_check_moves.push_back(move);
                };
            };
            for(const auto move:this->invalid_or_check_moves){
                std::unordered_set<Board> invalid_boards;
                std::unordered_map<b_info, std::unordered_set<Board>> valid_dict;
                for(auto board:this->boards){
                    if(board.is_legal(move)){
                        Board pushed_board(board);
                        unsigned char piece = (pushed_board.board[move.to]) & (unsigned char)7;
                        b_info info = make_b_info(move, piece);
                        pushed_board.push(move);
                        if(!(valid_dict.count(info))){
                            std::unordered_set<Board> l;
                            valid_dict[info] = l;
                        };
                        valid_dict[info].insert(pushed_board);
                    }else{
                        Board b(board);
                        invalid_boards.insert(b);
                    };
                };
                for(const auto board_list:valid_dict){
                    if(board_list.first.piece){
                        std::string get_piece = ";* ";
                        get_piece[1] = convert_piece(board_list.first.piece);
                        this->valid_child_nodes.push_back(Node(board_list.second, this->ill, (this->history)+move_to_sfen_grid(move)+get_piece));
                    }else{
                        this->valid_child_nodes.push_back(Node(board_list.second, this->ill, (this->history)+move_to_sfen_grid(move)+" "));
                    };
                };
                if(invalid_boards.size()){
                    this->invalid_child_nodes.push_back(Node(invalid_boards, this->ill-1, (this->history)+move_to_sfen_grid(move)+"x "));
                };
            };
        }else{
            for(auto board:this->boards){
                for(auto move:board.authentic_legal_moves()){
                    pseudo_legal_move_set.insert(move);
                };
            };
            LIST(Move)pseudo_legal_moves;
            for(auto move:pseudo_legal_move_set){
                pseudo_legal_moves.push_back(move);
            };
            this->invalid_or_check_moves = pseudo_legal_moves;
            std::unordered_map<w_info, std::unordered_set<Board>> info_dict;
            for(auto move:pseudo_legal_moves){
                for(auto board:this->boards){
                    char pos_info = 0;
                    bool check_info = false;
                    if(board.is_legal(move)){
                        Board b = board;
                        if(IS_B(b.board[move.to])){
                            pos_info = move.to;
                        };
                        b.push(move);
                        if(b.is_check()){
                            check_info = true;
                        }else{
                            check_info = false;
                        };
                        w_info i = make_w_info(pos_info, check_info);
                        if(!(info_dict.count(i))){
                            std::unordered_set<Board> l;
                            info_dict[i] = l;
                        };
                        info_dict[i].insert(b);
                    };
                };
            };
            for(const auto boards:info_dict){
                w_info info = boards.first;
                std::string info_str = "(";
                if(info.position != 0){
                    info_str += convert_index((int)info.position);
                };
                if(info.check){
                    info_str += "+";
                };
                if(info_str.size() == 1){
                    info_str += "-";
                };
                info_str += ") ";
                this->valid_child_nodes.push_back(Node(boards.second, this->ill, (this->history)+info_str));
            };
        };
        return 0;
    };
    int search(int depth, std::stack<std::string> *answers, int ans_lim){
        if(ans_lim <= answers->size()){
            return 0;
        };
        bool mate = this->is_mate(answers);
        if(depth){
            this->expand();
            int n;
            n = this->valid_child_nodes.size();
            for(int i = 0;i < n;i++){
                Node node = this->valid_child_nodes.back();
                node.search(depth - 1, answers, ans_lim);
                this->valid_child_nodes.pop_back();
            };
            n = this->invalid_child_nodes.size();
            for(int i = 0;i < n;i++){
                Node node = this->invalid_child_nodes.back();
                node.search(depth, answers, ans_lim);
                this->invalid_child_nodes.pop_back();
            };
        };
        return 0;
    };

};
#endif