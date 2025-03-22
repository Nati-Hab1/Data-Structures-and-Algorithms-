# include <iostream>
using namespace std;

int sub (int x, int y){
    return x - y;
}

int sub (double x, double y){
    return x - y;
}

struct university{
    int room_num = 100;
    string room_type = "Lab";
}aau, unity;

template <typename generic1>
generic1 sub1 (generic1 a, generic1 b){
    return b - a;
}

namespace name1
{
    int a = 45;
    int b = 5;
    int point() { return a + b; }
}

namespace name2
{
  double x = 4;
  double y = 7;
  double point() { return x*y; }
}

int main(){
    cout<< sub(4,2)<<endl;
    cout<< sub(8.5, 3.6)<<endl;

    aau.room_num = 30;
    unity.room_type = "Cafeteria";
    university jimma;
    jimma.room_num = 300;
    jimma.room_type = "Office";

    cout<<aau.room_num<<endl;
    cout<<unity.room_type<<endl;
    cout<<jimma.room_num<<endl;
    cout<<jimma.room_type<<endl;

    cout<<sub1(2, 18)<<endl;
    cout<<sub1(2.5, 80.3)<<endl;

    cout << name1::point() << '\n';
    cout << name2::point() << '\n';
    cout << name2::x << '\n';
}

//What is the difference between struct and class in c++?
//Explore more about struct.

