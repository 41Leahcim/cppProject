#include <iostream>
#include <vector>

class Duration{
public:
    Duration(uint64_t hours, uint8_t minutes, uint8_t seconds)
    : totalTime((hours * 60 + minutes) * 60 + seconds){}
    
    uint64_t getHours() const{
        return totalTime / 3600 % 24;
    }

    uint64_t getMinutes() const{
        return totalTime / 60 % 60;
    }

    uint64_t getSeconds() const{
        return totalTime % 60;
    }

    uint64_t getTotalTime() const{
        return totalTime;
    }
private:
    uint64_t totalTime;
};

void help(){
    std::cout << "Welcome to the total duration calculator.\n"
                 "You can use the following codes to perform actions:\n"
                 " 0) stop\n 1) add a time\n 2) remove a time\n"
                 " 3) display total duration\n 4) display this help menu\n";
}

void addDuration(std::vector<Duration>& durations){
    uint64_t hours, minutes, seconds;
    std::cout << "Enter the amount of hours: ";
    std::cin >> hours;
    std::cout << "Enter the amount of minutes: ";
    std::cin >> minutes;
    std::cout << "Enter the amount of seconds: ";
    std::cin >> seconds;
    if(minutes >= 60 || seconds >= 60){
        throw "ERROR: Invalid duration!\n";
    }
    durations.emplace_back(hours, minutes, seconds);
}

void displayDurations(const std::vector<Duration>& durations){
    uint64_t hours, minutes, seconds;
    std::cout << "\n\n\nCurrent durations:\n";
    for(size_t i = 0;i < durations.size();i++){
        hours = durations[i].getHours();
        minutes = durations[i].getMinutes();
        seconds = durations[i].getSeconds();
        std::cout << i << ") " << hours << ':' << minutes << ':' << seconds << "\n";
    }
}

void removeDuration(std::vector<Duration>& durations){
    size_t index;
    std::cout << "Enter the id of the duration to remove: ";
    std::cin >> index;
    if(index >= durations.size()){
        throw "ERROR: Index out of bounds!\n";
    }else{
        durations.erase(std::begin(durations) + index);
    }
}

void displayTotalDuration(const std::vector<Duration>& durations){
    uint64_t hours, minutes, seconds;
    seconds = 0;
    for(const Duration& dur : durations){
        seconds += dur.getTotalTime();
    }
    hours = seconds / 3600;
    minutes = seconds / 60 % 60;
    seconds %= 60;
    std::cout << hours << ':' << minutes << ':' << seconds << "\n";
}

int main(){
    std::vector<Duration> durations;
    uint32_t action;
    help();
    while(true){
        std::cout << "Enter the action code: ";
        std::cin >> action;
        std::cin.clear();
        try{
        switch(action){
            case 0:
                std::cout << "Press enter to exit the program...\n";
                std::cin.get();
                return EXIT_SUCCESS;
            case 1:
                    addDuration(durations);
                break;
            case 2:
                displayDurations(durations);
                removeDuration(durations);
                break;
            case 3:
                displayTotalDuration(durations);
                break;
            case 4:
                help();
                break;
            default:
                std::cerr << "ERROR: Invalid action code!\n";
        }
        }catch(const char *error){
            std::cerr << error << "\n";
        }
    }
}
