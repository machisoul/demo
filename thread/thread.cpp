#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

void myRunable()
{
    while(1)
    {
        cout << "hello george wong ! " << endl;
		unsigned int n = std::thread::hardware_concurrency();
		std::cout << n << " concurrent threads are supported.\n";
        sleep(1);
    }
}

int main(){
    std::thread t1(myRunable);
    t1.detach();
    sleep(10);
    //t1.detach();
}
