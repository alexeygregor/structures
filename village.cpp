#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

enum build_type
{
  garage = 1,
  barn = 2,
  bathhouse = 4
};

enum room_type
{
  bedroom = 1,
  kitchen = 2,
  bathroom = 4,
  children_room = 8,
  living_room = 16
};

struct administration
{
  int b_type = 0, r_type = 0;
  string room, build;
  vector <int> rooms, buildings;
};

int square;
int sector_square(int buildings)
{
  int sector_square = buildings * 200 + 600;
  square = sector_square;
  return square;
}

void constructions(administration& adm, int sector)
{
  string str, buf;
  int b_cnt = 0;
  cout << "How many buildings on sector: ";
  cin >> b_cnt;
  str = "_SECTOR#";
  buf = to_string(sector);
  str += buf + " [";
  buf = to_string(sector_square(b_cnt));
  str += buf + " m^2]\n";
  str += "Buildings:\n         ";
  cout << "What kind of buildings are this: " << endl;
  for (int i = 0; i < b_cnt; ++i)
  {
    cin >> adm.build;
    if (adm.build == "gar") adm.b_type = 1;
    else if (adm.build == "bar") adm.b_type = 2;
    else if (adm.build == "bat") adm.b_type = 4;
    else
      { cout << "Error. Try again" << endl; --i; continue; }
    adm.buildings.push_back(adm.b_type);
  }
  sort (adm.buildings.begin(), adm.buildings.end());
  for (int i = 0; i < b_cnt; ++i)
  {
    if (adm.buildings[i] & garage) str += "garage ";
    if (adm.buildings[i] & barn) str += "barn ";
    if (adm.buildings[i] & bathhouse) str += "bathhouse ";
  }
  str += "\n";
  adm.buildings.clear();
  ofstream list ("list.bin", ios::app);
  list << str;
  list.close();
}

void house(administration& adm)
{
  string str, buf;
  int f_cnt = 0, r_cnt = 1;
  str += "Rooms:\n";
  cout << "How many floors in the house: ";
  cin >> f_cnt;
  for (int i = 1; i <= f_cnt; ++i)
  {
    cout << "Floor " << i << endl;
    for (r_cnt = 1; r_cnt <= 5; ++r_cnt)
    {
      cout << "What " << r_cnt << " room: " << endl;
      cin >> adm.room;
      if (adm.room == "q") break;
      else if (adm.room == "bed") adm.r_type = 1;
      else if (adm.room == "kit") adm.r_type = 2;
      else if (adm.room == "bat") adm.r_type = 4;
      else if (adm.room == "cil") adm.r_type = 8;
      else if (adm.room == "liv") adm.r_type = 16;
      else { cout << "Error. Try again" << endl; --r_cnt; continue; }
      adm.rooms.push_back(adm.r_type);
    }
    buf = to_string(i);
    str += "Floor " + buf + ": ";
    sort (adm.rooms.begin(), adm.rooms.end());
    for (int i = 0; i < r_cnt - 1; ++i)
    {
      if (adm.rooms[i] == 1) str += "bedroom ";
      if (adm.rooms[i] == 2) str += "kitchen ";
      if (adm.rooms[i] == 4) str += "bathroom ";
      if (adm.rooms[i] == 8) str += "children_room ";
      if (adm.rooms[i] == 16) str += "living_room ";
    }
    str += "\n";
    adm.rooms.clear();
  }
  str += "\n";
  ofstream list ("list.bin", ios::app);
  list << str;
  list.close();
}

int main()
{
  administration adm;
  string str, buf;
  int sector = 0, village_square = 0, street = 0;
  cout << "Enter the number of sectors: ";
  cin >> sector;
  if (sector == -1)
    ofstream list ("list.bin");
  for (int i = 1; i <= sector; ++i)
  {
    cout << "\nSector " << i << endl;
    constructions(adm, i);
    house(adm);
    village_square += square;
  }
  if (village_square < 5000) street = 1;
  else street = village_square/5000;
  village_square += street*1000;
  buf = to_string(village_square);
  str = "_Village square: ";
  str += buf + " m^2";
  ofstream list ("list.bin", ios::app);
  list << str;
  list.close();
}
