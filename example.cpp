#include "MiniTesting.hpp"
#include <algorithm>
#include <functional>
using namespace std;

void sorting(vector<int>& v ){
    for(int i = 1; i < v.size(); ++i){
        for(auto j = 0; j < v.size()-i; ++j){
            if(v[j+1] < v[j]) swap(v[j], v[j+1]);
        }
    }
}

void TestSort() {
    vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v1_res;
    copy(begin(v1), end(v1), back_inserter(v1_res));
    sort(begin(v1_res), end(v1_res));
    sorting(v1);
    ASSERT_EQUAL(v1_res, v1);
}

int main(){
    MiniTester<function<void(void)>> mt;
    function<void ()> TestSortFunc = TestSort;
    ADD_TEST(mt, TestSortFunc);
    mt.RunAll();
    return 0;
}