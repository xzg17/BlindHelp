#ifndef _LIMITED_SET_HPP_
#define _LIMITED_SET_HPP_

#define ITERATE_LIMITED_SET(valuename, setname) for(auto valuename=setname.begin; valuename != -1; valuename=setname.forward_linked_list[valuename])

//typename T should be signed char, signed short, signed int, signed long, signed long long

template <typename T, int N>
class limited_set{
    private:
    T backward_linked_list[N];
    bool count_array[N];
    int size;
    const T end;
    public:
    T begin;
    T forward_linked_list[N];
    limited_set():size(0), begin(-1), end(-1){
        for(int i=0;i<N;i++){
            count_array[i] = false;
        };
    };
    int count(const T value)const{
        if(0 <= value && value < N && this->count_array[value]){
            return 1;
        }else{
            return 0;
        };
    };
    int insert(T value){
        if(!this->count(value)){
            if(this->size){
                forward_linked_list[value] = this->begin;
                backward_linked_list[this->begin] = value;
            }else{
                forward_linked_list[value] = -1;
            };
            this->begin = value;
            this->count_array[value] = true;
            this->size += 1;
        };
        return 0;
    };
    int erase(T value){
        if(this->count(value)){
            if(value == this->begin){
                this->begin = forward_linked_list[this->begin];
            }else{
                const T pre_ = backward_linked_list[value];
                const T suc_ = forward_linked_list[value];
                forward_linked_list[pre_] = suc_;
                backward_linked_list[suc_] = pre_;
            };
            count_array[value] = false;
            this->size -= 1;
        };
        return 0;
    };
};

#endif