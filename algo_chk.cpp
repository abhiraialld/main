// algo_chk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<mutex>
#include<list>
#include<map>
#include<set>
#include<functional>
#include<tuple>
#include<deque>



//class B
//{
//public: 
//    B() = default;
//    B(const B&) = delete;
//    B(B&&) = default;
//    B& operator=(const B&) = delete;
//};
//
//
//class A
//{
//public:
//    B obj;
//    inline static int i{ 0 };
//    int a{ 12 };
//     A(int o) : a(o)
//    {
//        a = o;
//    }
//    bool operator==(const A& obj) const
//    {
//        return a == obj.a;
//    }
//    constexpr int getA() const
//    {
//        return a;
//    }
//    /*A(A&& obj)
//    {
//
//    }*/
//    /*A(const A& obj)
//    {
//
//    }
//    A& operator=(int i)
//    {
//        A obj(*this);
//        obj.a += i;
//        return obj;
//    }*/
//    constexpr
//    void setA()
//    {
//        a = 34;
//    }
//    bool operator<(const A& obj) const
//    {
//        return a < obj.a;
//    }
//    A& operator+(const A& obj) 
//    {
//        this->a += obj.a;
//        return *this;
//    }
//    A operator++()
//    {
//        this->a++;
//        return *this;
//    }
//    operator int()
//    {
//        return a;
//    }
//    //std::mutex mut;
//};

//constexpr 
//int fun(const A &b)
//{
//    return b.getA() * 10;
//}

enum color {white,
black,
grey};

//auto white = false;


int x = 0;

decltype(auto) fun()
{
    return x;
}

decltype(auto) fun1()
{
    return (x); 
}

template
<typename T>
class ob
{
    
public:
    T& j;
    ob(int &i) : j(i)
    {}
    operator int&()
    {
        return j;
    }
    T& fun()
    {
        return j;
    }
    const T& fun() const
    {
        return j;
    }
    //~ob()
    //{
    //    std::cout << "\nDestructing ob\n";
    //}
};

template
<typename T>
void fun(T obj)
{
    obj.j++;
}

int co = 98;

auto lamb = [co = 53]
{
    co;
};

int main()
{


    int x = 12;
    ob<int> obj(x);
    obj.fun();




    /*int i;
    float f;
    std::string str;
    auto t1 = std::tie(str, i, f);
    std::get<0>(t1) = "rai";
    std::get<1>(t1) = 111;
    std::get<2>(t1) = 3.8;*/
    /*std::vector<int> v;
    std::list li{ 11, 65, 1, 23, 4,5 };
    std::list li2{ 33,44,55,66,77 };
    std::vector<ob> oi(5);
    li = std::move(li2);*/
    //li.sort();
    //li2.sort();
    //li.merge(li2);
    //std::map<int, std::string> mmap;
    //std::vector<int>::value_type a;
    //auto [first, second] = mmap.insert({ 12, "Abhinav" });
    //auto pai = mmap.insert({ 12, "Abhinav" });
    /*auto iter = std::find(li.begin(), li.end(), 23);
    auto siter = std::find(li2.begin(), li2.end(), 55);
    li.splice(iter, li2, siter, li2.end());*/
    //v.reserve(80);
    //v.push_back(12);
    //auto size = v.size();
    //auto cap = v.capacity();
    //std::vector<int> cv(v);
    //size = cv.size();
    //cap = cv.capacity();

    //constexpr int a = 10;
    //const int x = 21;
    //int j = 98;
    //A obj(12);
    //A b(54);
    //b = obj;
    ///*constexpr A obj(x);
    //int arr[fun(obj)];*/
    //std::vector v{ A{11},A{23},A{1},A{7},A{9},A{3},A{12},A{32},A{54},A{76},A{80} ,A{12} ,A{12} ,A{12} ,A{12} ,A{12} ,A{12} , A{0} };
    //auto iter = std::find(v.begin(), v.end(), A{ 23 });
    //v.insert(iter, A{ 24 });

    //{
    //    std::vector v{ A{11},A{23},A{1},A{7},A{9},A{3},A{12},A{32},A{54},A{76},A{80} ,A{12} ,A{12} ,A{12} ,A{12} ,A{12} ,A{12} , A{0} };
    //    //std::vector v{ 65, 23, 45, 13, 98, 70,13 };
    //    std::vector<A> b;
    //    std::nth_element(v.begin(), v.begin() + 4, v.end());
    //    std::transform(v.begin(), v.end(), v.begin(), [](auto& a)
    //        {
    //            a.a *= -1;
    //            return a;
    //        });
    //    std::iota(v.begin(), v.end(), A{ 0 });
    //    /*auto res = A{ 0 };
    //    res = std::accumulate(v.begin(), v.end(), res);*/
    //    /*auto ret = std::is_partitioned(v.begin(), v.end(), [](const auto a)
    //        {
    //            return a % 2 != 0;
    //        });
    //    auto iter = std::partition_point(v.begin(), v.end(), [](const auto a)
    //        {
    //            return a % 2 != 0;
    //        });*/
    //        /*std::copy_if(v.begin(), v.end(),std::back_inserter(b), [](auto a)
    //            {
    //                return a.a % 2 == 0;
    //            });*/
    //            /*auto iter = std::remove_if(v.begin(), v.end(), [](const auto& o)
    //                {
    //                    return o % 2 != 0;
    //                });*/
    //                /*std::unique_copy(v.begin(), v.end(), std::back_inserter(b));*/
    //                /*std::partial_sort(v.begin(), v.begin() + 4, v.end(), [](const auto& a, const auto& b)
    //                    {
    //                        return a.a > b.a;
    //                    });*/
    //                    /*std::nth_element(v.begin(), v.begin() + 3, v.end());*/
    //                    //auto [liter, hiter] = std::equal_range(v.begin(), v.end(), A{12});
    //    std::string sentence{ "Manners maketh man" };
    //    std::string temp{ sentence, sentence.find_first_of(" ") };
    //    auto index = sentence.find(temp, 1);
    //}
    return 9;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
