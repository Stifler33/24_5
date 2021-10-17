#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
struct strBirthday{
    std::string name;
    std::tm day;
};
#define INIT_DAY \
std::time_t init = std::time(nullptr);\
baseDate.back().day = *std::localtime(&init);
#define FORMAT_DATE "%Y.%m.%d"

int minMon(std::vector<strBirthday> &date, std::tm &curDate){
    int min = 0;
    int curMon = curDate.tm_mon;
    for (auto &a : date){
        int minA = abs(curMon - a.day.tm_mon);
        for (auto &b : date){
            int minB = abs(curMon - b.day.tm_mon);
            if (minB < minA) min = b.day.tm_mon;
        }
    }
    return min;
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
    std::cout << minMon(baseDate, curDatePtr) + 1;
    return 0;
}