#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

struct account
{
  string name, surname, payment, date;
};

void show(account& person)
{
  ifstream note;
  note.open("note.bin");
  cout << endl;
  while (note >> person.name >> person.surname >> person.payment >> person.date)
    cout << person.name << " " << person.surname << "  "
         << person.payment << "R.  " << person.date << endl;
  note.close();
}

string day(account& person)
{
  string key; int bfr = 0; char val[10];
  bfr = stoi(person.date.substr(0,2));
  sprintf (val, "%.i", bfr);
  if (bfr < 10) key += "0";
  key += val; key += ".";
  bfr = stoi(person.date.substr(3,6));
  sprintf (val, "%.i", bfr);
  if (bfr < 10) key += "0";
  key += val; key += ".";
  bfr = stoi(person.date.substr(6,10));
  sprintf (val, "%.i", bfr);
  key += val;
  return key;
}

string valid(account& person, string str)
{
  int bfr = 0;
  char pay[6];
  string buf;
  bfr = stoi(person.payment);
  sprintf (pay, "%.i", bfr);
  person.date = day(person);
  buf = person.name + " " + person.surname + "  " + pay + "  ";
  str += buf;
  buf = person.date;
  str += buf + "\n";
  return str;
}

void list(account& person)
{
  string str, buf;
  ifstream note;
  note.open("note.bin");
  while (note >> person.name >> person.surname >> person.payment >> person.date)
    str = valid(person, str);
  note.close();
  ofstream blank ("note.bin");
  blank << str;
  blank.close();
}

void add(account& person)
{
  string txt, input;
  vector <string> str;
  for (int i = 0; i < 4; ++i)
  { cin >> input; str.push_back(input); }
  person.name = str[0]; person.surname = str[1];
  person.payment = str[2]; person.date = str[3];
  txt = valid(person, txt);
  ofstream file ("note.bin", ios::app);
  file << txt;
  file.close();
}

int main()
{
  account person;
  string command;
  while (true)
  {
    bool ch = true;
    cout << "Input command: "; cin >> command;
    try
    {
      if (command == "q") break;
      else if (command == "list") list(person);
      else if (command == "add") add(person);
      else cerr << "Error: command" << endl;
    }
    catch (const exception& e)
    {
      cerr << "Error: " << e.what() << endl;
      ch = false;
    }
    if (ch) show(person);
    cout << endl;
  }
}
