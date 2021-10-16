#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
struct task{
    std::string name;
    std::time_t TimeS;
    std::tm* startTime;
    std::time_t TimeE;
    std::tm* endTime;
    bool progress = false;
};
#define CHECK_EXIT if (userInput == "exit") return 0;
#define BASE_PROGRESS baseTask.back().progress
#define BASE_NAME baseTask.back().name
#define BASE_TIME_S baseTask.back().TimeS
#define BASE_START_TIME baseTask.back().startTime
#define BASE_TIME_E  baseTask.back().TimeE
#define BASE_END_TIME baseTask.back().endTime
int main() {
    task strTask;
    std::vector<task> baseTask;
    std::string userInput;
    while (userInput != "exit"){
        std::cout << "Enter command\n";
        std::cin >> userInput;
        CHECK_EXIT
        if (userInput == "begin"){
            if(!baseTask.empty()){
                if (BASE_PROGRESS){
                    BASE_TIME_E = std::time(nullptr);
                    BASE_END_TIME = std::localtime(&BASE_TIME_E);
                    BASE_PROGRESS = false;
                }
            }
            std::cout << "Enter name task\n";
            std::cin >> userInput;
            baseTask.push_back(strTask);
            BASE_PROGRESS = true;
            BASE_NAME = userInput;
            BASE_TIME_S = std::time(nullptr);
            BASE_START_TIME = std::localtime(&BASE_TIME_S);
            std::cout << "Added task " << "'" + BASE_NAME + "'"<< std::endl;
            std::cout << "Start time " << asctime(BASE_START_TIME);
        }else if (userInput == "status"){
            for (int i = 0; i < baseTask.size(); i++){
                std::cout <<"'" + baseTask[i].name + "'"<< std::endl;
                std::cout << "Start time " << asctime(baseTask[i].startTime) << std::endl;
                if (!baseTask[i].progress) {
                    std::cout << "End time " << asctime(baseTask[i].endTime) << std::endl;
                }
            }
        }
    }
    return 0;
}
