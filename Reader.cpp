#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    char *myfifo = (char *)"/home/solmaz/Documents/intership c++ code/IPC-hex/myfifo";
    int hex_number;

    // Open the named pipe for reading
    int read_fd = open(myfifo, O_RDONLY);

    // Read the hexadecimal number from the named pipe
    read(read_fd, &hex_number, sizeof(hex_number));

    // Output the hexadecimal number
    cout << "Hexadecimal number: 0x" << hex << hex_number << endl;

    // convert hexadecimal num to string
    std::string str_num = std::to_string(hex_number);

    // convert hexadecimal string to decimal (max 7 char)
    int decimal = std::stoi(str_num, nullptr, 16);
    cout << "It's decimal equivalent is " << decimal << endl;

    // Close the named pipe for reading
    close(read_fd);

    return 0;
}