#include <iostream>
#include <ctime>
#include <iomanip>
int main(){
    std::time_t null = 0;
    std::tm timePause = *std::localtime(&null);
    std::cin >> std::get_time(&timePause, "%M:%S");
    std::time_t timePause_t = std::mktime(&timePause);
    std::cout << std::put_time(&timePause, "%M:%S") << std::endl;
    std::time_t a = std::time(nullptr);
    while(timePause_t > 0){
        if (a != std::time(nullptr)){
            a = std::time(nullptr);
            timePause_t --;
            timePause = *std::localtime(&timePause_t);
            std::cout << std::put_time(&timePause, "%M:%S") << std::endl;
        }
    }
    std::cout << "DING! DING! DING!\n";
    return 0;
}
