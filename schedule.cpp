#include <iostream>
// #include <time.h>
#include<chrono>
#include<thread>
using namespace std;
class schedule{
    public:
    void time()
    {
        this_thread::sleep_for(chrono::milliseconds(60000));
    }
};
int main(){
    schedule SC;
    cout<<"This is a sleep_for demonstration\n";
    SC.time();
    cout<<"I slept for 60000 milliseconds\n";
    return 0;
}

