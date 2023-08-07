#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

void myRunable()
{
    while(1)
    {
        cout << "hello george wong ! " << endl;
        sleep(1);
    }
}

int main(){
    std::thread t1(myRunable);
    t1.join();
    // sleep(10);
}