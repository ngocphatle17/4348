#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <vector>
#include <cstdlib>  

using namespace std;

void write_to_pipe(int fd, const string &message) {
    string formatted_message = message + "\n";  // Ensure newline is sent
    write(fd, formatted_message.c_str(), formatted_message.size());
}

string read_from_pipe(int fd) {
    char buffer[1024]; // Hold new message
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        return string(buffer);
    }
    return ""; // empty if no data is read
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./driver <logfile>" << endl; // ensure the program uses the correct one.
        return 1;
    }

    string logfile = argv[1]; // store log file name
  
    // declare pipes
    int log_pipe[2], enc_pipe_in[2], enc_pipe_out[2];
    pipe(log_pipe);
    pipe(enc_pipe_in);
    pipe(enc_pipe_out);

    // Logger
    pid_t logger_pid = fork();
    if (logger_pid == 0) {
        dup2(log_pipe[0], STDIN_FILENO); // redirect standard input to read from pipe
        close(log_pipe[1]);
        execl("./logger", "logger", logfile.c_str(), NULL); // execute logger
        cerr << "Error: Failed to launch logger!" << endl;
        exit(1);
    }
    close(log_pipe[0]);
}