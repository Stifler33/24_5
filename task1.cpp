#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
struct task{
    std::string name;
    std::time_t startTime;
    std::time_t endTime;
    double wastedTime;
    bool progress = false;
};
#define CHECK_EXIT if (userInput == "exit") return 0;
#define TASK_PROGRESS baseTask.back().progress
#define TASK_NAME baseTask.back().name
#define TASK_TIME_S baseTask.back().startTime
#define TASK_TIME_E  baseTask.back().endTime
#define TASK_WASTED_TIME baseTask.back().wastedTime
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
                if (TASK_PROGRESS){
                    TASK_TIME_E = std::time(nullptr);
                    TASK_WASTED_TIME = std::difftime(TASK_TIME_E, TASK_TIME_S);
                    TASK_PROGRESS = false;
                }
            }
            std::cout << "Enter name task\n";
            std::cin >> userInput;
            baseTask.push_back(strTask);
            TASK_PROGRESS = true;
            TASK_NAME = userInput;
            TASK_TIME_S = std::time(nullptr);
            std::cout << "Added task " << "'" + TASK_NAME + "'"<< std::endl;
            std::cout << "Start time " << asctime(std::localtime(&TASK_TIME_S));
        }else if (userInput == "status"){
            for (auto & i : baseTask){
                std::cout << std::endl;
                std::cout <<"'" + i.name + "'"<< std::endl;
                std::cout << "Start time\t" << asctime(std::localtime(&i.startTime));
                if (!i.progress) {
                    std::cout << "End time\t" << asctime(std::localtime(&i.endTime));
                    std::cout << "Wasted time\t" << i.wastedTime / 3600 << std::endl;
                }else std::cout << "task in progress\n";
            }
            std::cout << std::endl;
        }else if (userInput == "end"){
            for (auto & i : baseTask){
                if (i.progress){
                    i.endTime = std::time(nullptr);
                    i.wastedTime = std::difftime(i.endTime, i.startTime);
                    i.progress = false;
                }
            }
        }
    }
    return 0;
}
