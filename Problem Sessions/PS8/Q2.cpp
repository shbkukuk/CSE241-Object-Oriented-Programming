#include<iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    Pair() {}
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    T1 getFirst() const { return first_; }
    T2 getSecond() const { return second_; }

    void setFirst(T1 first) { first_ = first; }
    void setSecond(T2 second) { second_ = second; }

private:
    T1 first_;
    T2 second_;
};


int main()
{
    Pair<char , char> p( 'A', 'B' );
    cout<<"” F i r s t  i s ”" << p .getFirst()<< endl;
    p.setFirst('Z') ;
    cout << "” F i r s t changed t o ”" << p.getFirst()<<endl;
    cout<< "”The p ai r i s : ”" << p.getFirst()<< "” , ”"
    << p.getSecond()
    <<endl ;
    Pair<int , string > p2 ( 34 ,  "B i l l") ;
    Pair<string , int> p3 ( " B i l l ", 34 ) ;
    cout << "”The p ai r i s : ”" << p2.getFirst() << "” , ”"
    << p2 .getSecond()
    << endl ;
    return 0 ;
}