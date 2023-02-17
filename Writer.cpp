#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>
#include <cstring>

int main(int argc, char **argv)
{
    char *myfifo = (char *)"/home/solmaz/Documents/intership c++ code/IPC-hex/myfifo";
    int hex_number;

    int ret = mkfifo(myfifo, 0666);

    // Get hexadecimal number from user
    std::cout << "Enter a hexadecimal number: ";
    std::cin >> std::hex >> hex_number;

    // Open the named pipe for writing
    int write_fd = open(myfifo, O_WRONLY);

    // Write the hexadecimal number to the named pipe
    write(write_fd, &hex_number, sizeof(hex_number));

    // Close the named pipe for writing
    close(write_fd);

    return 0;
}