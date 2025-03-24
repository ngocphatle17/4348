#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>

using namespace std;

// generate timsestamp in the format
string get_timestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", ltm);
    return string(buffer);
}

int main(int argc, char* argv[]) {
    // ensure correct number of arguments are provided
    if (argc != 2) {
        cerr << "Usage: ./logger <logfile>" << endl;
        return 1;
    }

    string logfile = argv[1]; // store
    ofstream log_file(logfile.c_str(), ios::app);
    
    // terminates if file is failed to open
    if (!log_file) {
        cerr << "Error opening log file!" << endl;
        return 1;
    }