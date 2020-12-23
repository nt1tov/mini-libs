#include <iostream>
#include <sstream>

// data structures
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>

// extra algos and data structures
#include <algorithm>
#include <utility>

//asserts
#include <cassert>

using namespace std;

// add to stream set 
template <class T>
ostream& operator <<(ostream& os, const set<T> s){
    os << "{";
    bool first = true;
    for(const auto& item:s){
        if(first == false){
            os << ", ";
        }
        first = false;
        os << item;
    }
    return os << "}";
}

//add to strea map
template <class K, class V>
ostream& operator <<(ostream& os, const map<K, V> m){
    os << "{";
    bool first = true;
    for(const auto& item : m){
        if(first == false){
            os << ", ";
        }
        first = false;
        os << item.first << ": " << item.second;
    }
    return os << "}";
}

template <class T, class U>
void AsssertEqual(const class T& t, const U &u, const string &hint) {
    if(t != u){
        ostringstream os;
        os << "Assertion Failed: " << t << "!=" <<u << "Hint: " << hint;
        throw runtime_error(os);
    }
}

class TestRunner{
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name){
        try{
            func();
            cerr << test_name << " OK" << endl;
        }
        catch(runtime_error& e){
            cerr << test_name << "fail: " << e.what() << endl;
        }
    }
    ~TestRunner(){
        if(fail_count > 0){
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }
private:
    int fail_count = 0;
}

// void testFuncExample1() {
//     AsssertEqual(..., ...);
// }

void TestAll() {
    TestRunner runner;
    // runner.RunTest(testExample, "run test 1");
    // runner.RunTest(test2Func, "run test 2");
}

// int main(){
//     TestAll();
// }



