#include <iostream>

using namespace std;

int main() {
  int num,
      bit,
      x;
  string command;
  cin >> num;

  for (int i = 0; i < num; i++) {
  
    cin >> command;

    if(command == "add"){
      cin >> x;
      bit |= (1 << x);
    } else if (command == "check"){
      cin >> x;
      if(bit & (1 << x)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (command == "remove"){
      cin >> x;
      bit &= !(1 << x);
    } else if (command == "toggle"){
      cin >> x;
      bit ^= (1 << x);
    } else if (command == "all"){
      cin >> x;
      bit = (1 << 21) -1;
    } else {
      bit = 0;
    }
  }


  return 0;
}

