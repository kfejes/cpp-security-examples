#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string



using namespace std;

class LogEntry {
    private:
        string user;
        string logDate;

    std::string loggingDate()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }
        
    public:
        LogEntry(string name) {
            this->user = name;
            this->logDate = loggingDate();
        }
        ~LogEntry() = default;
        auto getEntry() {
            string entry = this->user + " logged at " + this->logDate;
            return entry;
        }
        bool operator==(string name) {
            if (this->user == name) {
                return true;
            } else {
                return false;
            }
        } 
};

class LoggingManager {
    private:
        vector<LogEntry> logs;
    public:
        LoggingManager() = default;
        ~LoggingManager() = default;
        void log(string user) {
            if (user != "") {
                this->logs.emplace_back(LogEntry(user));
            } else {
                throw "Invalid Parameter!";
            }
        }

        void printLogs() {
            int index = 1;
            for (auto i : this->logs) {
                cout << index << ". "<< i.getEntry() << endl;
                ++index;
            }
        }

        void RemoveUser(string user) {
            auto i = this->logs.begin();
            for (auto entry : this->logs) {
                if (entry == user) {
                    this->logs.erase(i);
                }
                ++i;
                cout << entry.getEntry() << endl;
            }
        }

        void RemoveUserSafely(string user) {
            auto count = this->logs.end();
            for (auto i = this->logs.begin(); i < count; ++i) {
                if ( *i == user) {
                    this->logs.erase(i);
                    count = this->logs.end();
                }
            cout << i->getEntry() << endl; 
            } 
        }
 };

int main() {

    LoggingManager lm;
    for (int i = 0; i < 10; ++i) {
        if (i % 4 == 0) {
            lm.log("user1");
        } 

        if (i % 5 == 0) {        
            lm.log("user2");
        } 

        if (i % 3 == 0) {
            lm.log("user3");
        } 

    } 

    lm.RemoveUser("user2");
    lm.RemoveUserSafely("user2");
    cout << " *** Print logs *** " << endl;
    lm.printLogs();

}

