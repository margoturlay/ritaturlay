#include <iostream>
#include <list>
using namespace std;
char *dec_to_oct(char *s, int n) {
  char *i, c, *t = s;
  unsigned int x = (unsigned int)n;
  do {
    *s++ = (char)(x & 0x7) + '0';
  } while ((x >>= 3) != 0);
  *s = '\0';

  for (i = t, --s; i < s; ++i, --s) {
    c = *i;
    *i = *s;
    *s = c;
  }
  return t;
}

void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); ++it)
    cout << '\t' << *it;
  cout << '\n';
}

int main() {

  list<int> list1;
  bool b = true;
  int res = 0, i = 1;
  cout << "Enter number: ";

  while (true) {
    int i;
    cin >> i;
    if (!cin) {
      cout << "Okey\n";
      cin.clear();
      break;
    }
    list1.push_back(i);
  }
  cout << "\n Your list: ";
  showlist(list1);
  while (b) {
    if (list1.empty())
      b = false;
    else {
      res += i * list1.back();
      list1.pop_back();
      i *= 10;
    }
  }
  char s1[32];
  cout << "Result: " << dec_to_oct(s1, res) << endl;

  return 0;
}