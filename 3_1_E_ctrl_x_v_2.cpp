#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  list<string> text;

  while (true) {
    string line;
    getline(cin, line);

    if (line.empty())
      break;

    text.push_back(line);
  }

  auto cursor = text.begin();

  list<string> buffer;

  bool shiftPressed = false;
  int shiftOffset = 0;
  auto shift = text.begin();

  string command;
  while (cin >> command) {
    if (command == "Up") {
      if (cursor == text.begin()) {
        continue;
      }

      --cursor;
      if (!shiftPressed) {
        shift = cursor;
      } else {
        --shiftOffset;
      }
    } else if (command == "Down") {
      if (cursor == text.end()) {
        continue;
      }

      ++cursor;
      if (!shiftPressed) {
        shift = cursor;
      } else {
        ++shiftOffset;
      }
    } else if (command == "Ctrl+X") {
      if (shift == cursor && cursor == text.end()) {
        continue;
      }

      buffer.clear();

      if (shift == cursor) {
        auto toSplice = cursor;
        cursor = std::next(cursor);
        buffer.splice(buffer.begin(), text, toSplice);
      } else if (shiftOffset < 0) {
        buffer.splice(buffer.begin(), text, cursor, shift);
        cursor = shift;
      } else {
        buffer.splice(buffer.begin(), text, shift, cursor);
      }

      shiftPressed = false;
      shift = cursor;
      shiftOffset = 0;
    } else if (command == "Ctrl+V") {
      if (buffer.empty()) {
        continue;
      }

      if (shiftOffset < 0) {
        cursor = text.erase(cursor, shift);
      } else if (shiftOffset > 0) {
        cursor = text.erase(shift, cursor);
      }

      text.insert(cursor, buffer.begin(), buffer.end());

      shiftPressed = false;
      shift = cursor;
      shiftOffset = 0;
    } else if (command == "Shift") {
      shiftPressed = true;
    }
  }

  for (const auto &x : text) {
    cout << x << "\n";
  }
}