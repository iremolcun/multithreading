/*
 multithreading: the ability of multiple parts of one program
 to be executed at the same time. There are 2 ways to achieve this:
 multitasking: switching between first task and second task so fast. it seems like a parallel execution but
 this is not a real multithreading
 real multithreading: it can be executed at the same time.
 in pc each core takes each threads.

 for the multithreaded weather forecast app:
 the job of one thread will refresh the data(in every 2 secs).
 the job of other thread bringing data from the cache and showing data to the user.
 so there will be no delay.
*/


#include <iostream>
#include <thread>
#include <map>
#include <string>
#include<chrono>
using namespace std::chrono_literals;


void RefreshForecast(std::map<std::string, int> forecastMap) {

	while (true) {
		for (auto& item : forecastMap) { //foreach loop
			item.second++; //item variable's type becomes std::pair<const std::string,int> with auto
			std::cout << item.first << "-" << item.second << std::endl;
		}
		std::this_thread::sleep_for(2000ms);
	}

}

int main()
{
	std::map<std::string, int> forecastMap = {//string key, value ise int olacak boş bir map oldu.
		{"New York",15},
		{"Berlin",7}

	};

	forecastMap["İstanbul"] = 9;

	std::thread backGroundWorker(RefreshForecast, forecastMap);


	system("pause>nul");
}

