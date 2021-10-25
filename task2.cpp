#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
struct strBirthday{
    std::string name;
    std::tm day;
    std::time_t day_t;
    std::time_t diff;
};
#define INIT_DAY \
std::time_t init = std::time(nullptr);\
baseDate.back().day = *std::localtime(&init);
#define FORMAT_DATE "%Y.%m.%d"

void minMon(std::vector<strBirthday> &date, std::tm &curDate){
    int min = 0;
    std::time_t curTime_t;
    curTime_t = std::mktime(&curDate);
    int curYear = curDate.tm_year;
    for (auto & ptr : date){
        std::tm curTM = ptr.day;
        curTM.tm_year = curYear;
        std::time_t newTime = std::mktime(&curTM);
        ptr.diff = std::difftime(newTime, curTime_t);
        std::cout << ptr.diff << std::endl;
    }
}
int main() {
    strBirthday birthday;
    std::vector<strBirthday> baseDate;
    std::string typeEnterDate;
    std::cout << "what type of input ? file or manual\n";
    std::cin >> typeEnterDate;
    if (typeEnterDate == "file") {
        std::ifstream streamDay("day.txt");
        while(!streamDay.eof()){
            baseDate.push_back(birthday);
            streamDay >> baseDate.back().name;
            INIT_DAY
            streamDay >> std::get_time(&baseDate.back().day, FORMAT_DATE);
            baseDate.back().day_t = std::mktime(&baseDate.back().day);
        }
        if (false) {
            for (auto &i: baseDate) {
                std::cout << i.name << std::endl;
                std::cout << std::put_time(&i.day, FORMAT_DATE) << std::endl;
            }
        }
    }else if (typeEnterDate == "manual") {
    }
    std::time_t currentDate = std::time(nullptr);
    std::tm curDatePtr = *std::localtime(&currentDate);
    for (auto &baseDay : baseDate){
        if (baseDay.day.tm_mon == curDatePtr.tm_mon && baseDay.day.tm_mday == curDatePtr.tm_mday){
            std::cout << baseDay.name + " happy birthday\n";
        }
    }
    minMon(baseDate, curDatePtr);
    std::string name;
    std::time_t min;
    for (auto a : baseDate){
        min = a.diff;
        for (auto b : baseDate){
            if (min > b.diff) {
                min = b.diff;
                name = b.name;
            }
        }
    }
    std::cout << name;
    return 0;
}