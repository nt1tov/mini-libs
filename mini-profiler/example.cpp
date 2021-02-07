#include "profiler.hpp"
#include <vector>

using namespace std;



void FastFunc(){
    vector<int> v;
    for(auto i = 0; i < 300000; ++i){
        v.push_back(i);
    }
}

void SlowFunc(){
    vector<int> v;
    for(auto i = 0; i < 300000; ++i){
        v.insert(begin(v), i);
    }
}

int main(){

    {
        PROFILE("FastFunc");
        FastFunc();

    }

    {
        PROFILE("SlowFunc");
        SlowFunc();

    }
    return 0;
}