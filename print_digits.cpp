#include <iostream>
using namespace std;


// Normal printing
void print_digits(int num){
    if(num == 0){
        return ;
    }
    print_digits(num / 10);
    cout<<num % 10<<" ";
}

// Reverse printing
void rev_print_digits(int num){
    if(num == 0){
        return ;
    }
    cout<<num % 10<<" ";
    rev_print_digits(num / 10);
}

int main()
{
    int num = 6478;
    print_digits(num);
    cout<<endl;
    rev_print_digits(num);
    return 0;
}