#include "simplelogger.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "utils.h"
using namespace std;
class MOZILLA
{
public:
  void Gecko()
  {
    P(this);
  }
};

int main() {

  SleepFor(2);
  PrintTID("Test");
  //Test bin2Hex
  unsigned char ubin[] = {0xFF, 0xEE, 0x00, 0x55, 0x66};
  std::vector<std::remove_pointer<std::decay<decltype(ubin)>::type>::type> ubinVec;
  std::copy(ubin, ubin + 5, std::back_inserter(ubinVec));

  char* signedBin = reinterpret_cast<char*>(&ubin[0]);

  std::vector<std::remove_pointer<std::decay<decltype(signedBin)>::type>::type> signedbinVec;
  std::copy(signedBin, signedBin + 5, std::back_inserter(signedbinVec));
  PG(bin2hex(signedBin, 5));
  PG(bin2hex(ubin, 5));
  PG(ToVector(signedBin, 5));
  PG(ToVector(ubin, 5));
  PG(ubinVec);
  PG(signedbinVec);

  auto q = std::make_shared<int>(1);
  PR(q);
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  std::vector<std::string> vecStr;
  vecStr.push_back("1");
  vecStr.push_back("2");
  vecStr.push_back("3");

  std::map<std::string, double> s2d;
  s2d["mozilla"] = 123.5566;
  s2d["gecko"] = 1234.0;

  std::unordered_map<std::string, std::string> s2s;
  s2s["mozilla"] = "mozilla";
  s2s["gecko"] = "gecko";
  float a = 55.66f;
  std::string b = "haha";
  double c = 42689.2;
  const char* d = "abc";
  bool e = true;
  MOZILLA f;
  f.Gecko();
  int32_t g = -123;
  int64_t h = -5566;
  uint32_t i = 123;
  uint64_t j = 1234;

  P(a, b, c, d, e, &f, g, h, i, j, vec, vecStr, s2d, s2s);

  EZ_TAG = "123";
  PR(a, b, c, d, e, &f, g, h, i, j);
  PG(a, b, c, d, e, &f, g, h, i, j);
  PB(a, b, c, d, e, &f, g, h, i, j);
  PX0(EZ_RED);
  PX0(EZ_LIGHT_RED);
  PX0(EZ_GREEN);
  PX0(EZ_LIGHT_GREEN);
  PX0(EZ_BLUE);
  PX0(EZ_LIGHT_BLUE);
  PX0(EZ_DARY_GRAY);
  PX0(EZ_CYAN);
  PX0(EZ_LIGHT_CYAN);
  PX(EZ_LIGHT_CYAN, a, b, c, d, e, &f, g, h, i, j);
  PX0(EZ_PURPLE);
  PX0(EZ_LIGHT_PURPLE);
  PX0(EZ_BROWN);
  PX0(EZ_YELLOW);
  PX0(EZ_LIGHT_GRAY);
  PR0(); //Empty
  PG0();
  PB0();

  return 0;
}
