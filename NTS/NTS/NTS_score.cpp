#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#define MAX_NUM 100000
using namespace std;

/* git url : https://github.com/FuckML/NTS.git */

void err_handling(char *msg){ // 에러 핸들링
  fputs(msg, stderr);
  fputc('\n', stderr);
  exit(1);
}
class Employee {
private:
  int number;
  bool *check;
public:
  Employee(int _number) { // 출력할 사원 수 초기화, 랜덤 seed추가, 중복 체크를 위해 최대 사원 수 만큼 0으로 할당
    number = _number;
    srand((unsigned)time(NULL));
    check = new bool[MAX_NUM];
    memset(check, 0, MAX_NUM);
  }
  void Print_info() {
    string id_st; // 출력 할 사원 ID
    int id_score; // 사원 점수
    int id_num; // 난수 받을 정수형 변수
    char buf[15]; // 난수를 char* 로 변환 할때의 buffer
    for (int i = 0; i < number; i++) { // 사원 수 만큼 반복
      id_st = "NT";
      while (1) {
        id_num = rand() % 99999; // 난수 저장
        if (!check[id_num]) { // 이미 출력한 사원이 아니라면
          check[id_num] = true; // 출력된 사원으로 체크
          break; // 루프 종료
        }
      }
      
      id_score = rand() % 100;
      sprintf(buf, "%05d", id_num);
      id_st += buf;
      cout << id_st << " " << id_score << endl; // 사원 ID와 점수 출력
    }
  }
  ~Employee() { // 메모리 해제
    delete[] check;
  }
};
int main(int argc, char **argv) {
  if (argc == 1 || argc >= 3) { // 인자가 0개, 2개이상 일 경우 Argument Error 출력
    err_handling("argument err");
  }
  int count;
  count = atoi(argv[1]); // 입력받은 인자를 int형으로 변환
  if (count > 99999) { // 인자가 최대 사원 수를 넘을 경우 초과 에러 출력
    err_handling("argument exceed");
  }
  Employee p(count);
  p.Print_info();

}