#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#include <exception>
#include <iostream>
#include <string>

class server {
public:
  server(short port) {
    memset(&addr_, 0, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = INADDR_ANY;

    fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd_ <= 0) {
      throw std::runtime_error("Illegal server socket fd");
    }
  }

  void bind() {
    int err =
        ::bind(fd_, reinterpret_cast<struct sockaddr *>(&addr_), sizeof(addr_));
    if (err != 0) {
      err = errno;
      throw std::runtime_error("Fail to bind, errno = " + std::to_string(err));
    }
  }

  void listen() {
    int err = ::listen(fd_, 10);
    if (err != 0) {
      err = errno;
      throw std::runtime_error("Fail to listen, errno = " +
                               std::to_string(err));
    }
  }

  // sorry for not using epoll
  void accept() {
    while (1) {
      int conn = ::accept(fd_, NULL, NULL);
      if (conn <= 0) {
        continue;
      }

      for (;;) {
        char c;
        int num = ::read(conn, &c, sizeof(c));
        std::cout << "server received " << num << " bytes" << std::endl;
        if (num <= 0) {
          ::close(conn);
          ::shutdown(conn, SHUT_RDWR);
          break;
        }

        int rnum = rand() % 3;
        char pick = pick_[rnum];

        std::cout << "Server received " << c << " , server picked " << pick
                  << std::endl;

        char res[2];
        res[0] = pick;

        // even
        bool is_even = c == pick;

        // win
        bool win1 = c == 'a' && pick == 'c';
        bool win2 = c == 'b' && pick == 'a';
        bool win3 = c == 'c' && pick == 'b';

        if (is_even) {
          res[1] = 1;
        } else if (win1 || win2 || win3) {
          res[1] = 2;
        } else {
          res[1] = 0;
        }

        // send res back
        ::write(conn, res, 2);
      }
    }
  }

private:
  struct sockaddr_in addr_;
  int fd_;
  // a for Paper, b for Scissors, c for Rock
  char pick_[3]{'a', 'b', 'c'};
};

int main() {
  try {
    srand(time(NULL));

    // default port is 8080
    server s{8080};
    s.bind();
    s.listen();
    s.accept();
  } catch (std::exception &ex) {
    std::cout << ex.what() << std::endl;
  }
}
