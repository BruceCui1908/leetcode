#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>

int main() {
  int server_fd = ::socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  // default server port is 8080
  server_addr.sin_port = htons(8080);
  // default server ip is 127.0.0.1
  ::inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  int res =
      ::connect(server_fd, reinterpret_cast<struct sockaddr *>(&server_addr),
                sizeof(server_addr));
  if (res != 0) {
    std::cout << "Not connected! Please start server first" << std::endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 10; i > 0; i--) {
    std::cout << "a for Paper, b for Scissors, c for Rock, any other things "
                 "will be lose. Times remain("
              << i << ") " << std::endl;
    std::string input;
    std::getline(std::cin, input);

    if (input != "a" && input != "b" && input != "c") {
      std::cout << "u lose" << std::endl;
    } else {
      ::write(server_fd, input.data(), input.size());
      char buf[2];
      int num{0};
      do {
        num = ::read(server_fd, buf, 2);
      } while (num != 2);

      switch (buf[0]) {
      case 'a':
        std::cout << "Computer is Paper";
        break;
      case 'b':
        std::cout << "Computer is Scissors";
        break;
      case 'c':
        std::cout << "Computer is Rock";
        break;
      default:
        std::cout << "Unknown";
      }

      std::cout << " ";

      if (buf[1] == 0) {
        std::cout << "u lose";
      } else if (buf[1] == 1) {
        std::cout << "u are even";
      } else {
        std::cout << "u win";
      }

      std::cout << std::endl;
    }
  }
}