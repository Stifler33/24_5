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
    std::time_t curTime_t;
    curTime_t = std::mktime(&curDate);
    int curYear = curDate.tm_year;
    for (auto & ptr : date){
        std::tm curTM = ptr.day;
        curTM.tm_year = curYear;
        std::time_t newTime = std::mktime(&curTM);
        ptr.diff = std::difftime(newTime, curTime_t);
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
        std::string name;
        while(name != "end") {
            std::cout << "Enter name\n";
            std::cin >> name;
            if (name == "end") continue;
            baseDate.push_back(birthday);
            baseDate.back().name = name;
            std::cout << "Enter happy birthday\n";
            std::cin >> std::get_time(&baseDate.back().day, FORMAT_DATE);
        }
    }
    std::time_t currentDate = std::time(nullptr);
    std::tm curDatePtr = *std::localtime(&currentDate);
    minMon(baseDate, curDatePtr);
    std::time_t min;
    bool positive = false;
    for (auto a : baseDate){
        if (a.diff > 0 && !positive) {
            positive = true;
            min = a.diff;
        }
        if (a.diff < 0 && positive) continue;
        min = a.diff;
        for (auto b : baseDate){
            if (b.diff < 0 && positive) continue;
            if (min > b.diff) {
                min = b.diff;
            }
        }
    }
    bool foundToday = false;
    for (auto today : baseDate){
        if (today.diff == 0){
            std::cout << "Happy birthday " << today.name << std::endl;
            foundToday = true;
        }
    }
    if (foundToday) return 0;
    for (auto near : baseDate){
        if (near.diff == min) std::cout << "Near happy birthday " << std::put_time(&near.day, "%m/%d") << " " << near.name << std::endl;
    }
    return 0;
}