#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#define MAX_NUM 100000
using namespace std;
void err_handling(char *msg) {
  fputs(msg, stderr);
  fputc('\n', stderr);
  exit(1);
}
class Employee {
private:
  int number;
  bool *check;
public:
  Employee(int _number) {
    number = _number;
    srand((unsigned)time(NULL));
    check = new bool[MAX_NUM];
    memset(check, 0, MAX_NUM);
  }
  void Print_info() {
    string id_st;
    int id_score;
    int id_num;
    char buf[15];
    for (int i = 0; i < number; i++) {
      id_st = "NT";
      while (1) {
        id_num = rand() % 99999;
        if (!check[id_num]) {
          check[id_num] = true;
          break;
        }
      }
      
      id_score = rand() % 100;
      sprintf(buf, "%05d", id_num);
      id_st += buf;
      cout << id_st << " " << id_score << endl;
    }
  }
  ~Employee() {
    delete[] check;
  }
};
int main(int argc, char **argv) {
  if (argc == 1 || argc >= 3) {
    err_handling("argument err");
  }
  int count;
  count = atoi(argv[1]);
  if (count > 99999) {
    err_handling("argument exceed");
  }
  Employee p(count);
  p.Print_info();

}