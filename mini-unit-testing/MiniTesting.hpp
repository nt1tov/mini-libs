#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <vector>

#define RUN_TEST(runner, test)          \
    runner.RunTest(test, #test)

#define ASSERT_EQUAL(a,b) {             \
    auto lhs = a;                       \
    auto rhs = b;                       \
    std::ostringstream os;              \
    os<< #a << " != " << #b      \
    << ", ";                            \
    os << __FILE__ << ": " << __LINE__; \
    AssertEqual(lhs, rhs, os.str());        \
}

#define ASSERT(a) {                     \
    auto lhs = a;                       \
    std::ostringstream os;              \
    os << #a << " != " << "true" \
    << ", ";                            \
    os << __FILE__ << ": " << __LINE__; \
    AssertEqual(lhs, true, os.str());   \
}

#define ADD_TEST(runner, func) {        \
    std::ostringstream os;              \
    os << __FILE__ << ": " << #func;    \
    runner.AddTest(func, os.str());     \
}


//TODO template opeator for pair
template<class T1, class T2>
std::ostream& operator<<(std::ostream &os, const std::pair<T1, T2>& p){
    os << "{";
    os << p.first << ": " << p.second;
    os << "}";
    return os;
}

//TODO template opeator for vector
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    os << "[";
    bool first = true;
    for(const auto& elem: v){
        if(!first){
            os << ", ";
        }
        first = false;
        os << elem;
    }
    os << "]";
    return os;
}

//TODO template opeator for set
template<class K>
std::ostream& operator<<(std::ostream& os, const std::set<K>& s){
    os << "{";
    bool first = true;
    for(const auto& node: s){
        if(!first) os << node <<", ";
        first = false;
        os << node;
    }
    os << "}";
    return os;
}

//template operator<< for map
template<class K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m){
    os << "{";
    bool first = true;
    for(const auto& node: m){
        if(!first) os << node <<", ";
        first = false;
        os << node;
    }
    os << "}";
    return os;
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string &hint = {}){
    if(t != u){
        std::stringstream os;
        os << t << " != " << u << "\n";
        if(!hint.empty()){
            os <<__FILE__<< ": [hint] " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string &hint = {}){
    AssertEqual(b, true, hint);
}


template <class TFunc>
class MiniTester{
public:
    MiniTester():
        runs_count(0),
        fails_count(0)
    {
    }
   // template<class TFunc>
    void RunTest(TFunc tfunc, const std::string &test_name){
        try{
            ++runs_count;
            tfunc();
            //std::cerr << setw <<
            std::cerr << __FILE__ << ": "
            << test_name << " [OK]" << std::endl;
        }
        catch(std::exception& ex){
            ++fails_count;
            std::cerr << __FILE__ << ": "
            << test_name <<" [FAILED]: " << ex.what() << std::endl;
        }
        catch(...){
            ++fails_count;
            std::cerr << __FILE__ << ": "
            << test_name <<" [FAILED]: "<<"unknown exception" << std::endl;
        }
    }
    void RunAll(){
        for(const auto& [test_func, test_name]: test_container){
            RunTest(test_func, test_name);
        }
    }

    void AddTest(TFunc tfunc, const std::string &test_name){
        test_container.push_back(std::pair<TFunc, std::string>{tfunc, test_name});
    }

    ~MiniTester(){
        std::cerr << __FILE__ << ": ["
        <<runs_count - fails_count
        << "/" << runs_count << "] tests completed." << std::endl;
        if(fails_count > 0){
            std::cerr << __FILE__ << ": ["<< fails_count
            << "] tests failed."<< std::endl;
            std::cerr << __FILE__ << ": " <<"[Exit status 1]"<< std::endl;
            exit(1);
        }
    }
private:
    int runs_count;
    int fails_count;
    std::vector<std::pair<TFunc, std::string>> test_container;
};

void test(void){
    return;
}
