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

auto f = [](){
	while(1)
	{
		cout << "hello lambda function !!!" << endl;
		sleep(1);
	}
};

class SayHello
{
public:
	SayHello(){
		std::cout<<"create the SayHello object!!"<<std::endl;
	}
    void operator()(int x) 
    {
		while(1){
			std::cout<<"hello:" << x <<std::endl;
			sleep(1);
		}
    }
};

int main(){
	SayHello sayh;
	std::thread t(sayh, 8);
   // t1.detach();
    sleep(10);
    //t1.detach();
}
