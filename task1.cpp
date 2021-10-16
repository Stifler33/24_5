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
int main() {
    task strTask;
    std::vector<task> baseTask;
    std::string userInput;
    while (userInput != "exit"){
        std::cout << "Enter command\n";
        std::cin >> userInput;
        CHECK_EXIT
        if (userInput == "begin"){
            int sizeBase = baseTask.size();
            std::cout << "Enter name task\n";
            std::cin >> userInput;
            baseTask.push_back(strTask);
            baseTask.back().name = userInput;
            baseTask.back().TimeS = std::time(nullptr);
            baseTask.back().startTime = std::localtime(&baseTask.back().TimeS);
            std::cout << "Added task " << "'" + baseTask.back().name + "'"<< std::endl;
            std::cout << "Start time " << asctime(baseTask.back().startTime);
        }
    }
    return 0;
}
