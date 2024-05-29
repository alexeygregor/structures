#include <vector>
#include <limits>
#include <numeric>
#include <iostream>
using namespace std;

struct my_vector
{
  double value = 0;
  int min = 0, max = 0;
  vector <double> vec1;
  vector <double> vec2;
};

void add(my_vector& math)
{
  cout << "Enter vector 1: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec1.push_back(math.value);
  }
  math.value = 0;
  cout << "Enter vector 2: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec2.push_back(math.value);
  }
  math.min = (math.vec1.size() <= math.vec2.size()) ? math.vec1.size() : math.vec2.size();
  math.max = (math.vec1.size() >= math.vec2.size()) ? math.vec1.size() : math.vec2.size();
  for (int i = 0; i < math.min; ++i)
  {
    if (math.vec1.size() >= math.vec2.size()) (math.vec1[i] += math.vec2[i]);
    else if (math.vec1.size() <= math.vec2.size()) (math.vec2[i] += math.vec1[i]);
  }
  cout << "Vector sum: ";
  for (int i = 0; i < math.max; ++i)
    math.max == math.vec1.size() ? cout << math.vec1[i] << " " : cout << math.vec2[i] << " ";
  cout << endl << endl;
}

void substract(my_vector& math)
{
  cout << "Enter vector 1: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec1.push_back(math.value);
  }
  math.value = 0;
  cout << "Enter vector 2: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec2.push_back(math.value);
  }
  math.min = (math.vec1.size() <= math.vec2.size()) ? math.vec1.size() : math.vec2.size();
  math.max = (math.vec1.size() >= math.vec2.size()) ? math.vec1.size() : math.vec2.size();
  if (math.min == math.vec1.size())
  {
    for (int i = math.min; i < math.max; ++i)
      math.vec1.push_back(0);
  }
  else
  {
    for (int i = math.min; i < math.max; ++i)
      math.vec2.push_back(0);
  }
  for (int i = 0; i < math.max; ++i)
    math.vec1[i] -= math.vec2[i];
  cout << "Vector substract: ";
  for (int i = 0; i < math.max; ++i)
    cout << math.vec1[i] << " ";
  cout << endl << endl;
}

void scale(my_vector& math)
{
  cout << "Enter vector: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec1.push_back(math.value);
  }
  cout << "Enter scale: "; cin >> math.value;
  cout << "Scalar product: ";
  for (int i = 0; i < math.vec1.size(); ++i)
  {
    math.vec1[i] *= math.value;
    cout << math.vec1[i] << " ";
  }
  cout << endl << endl;
}

void length(my_vector& math)
{
  cout << "Enter vector: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec1.push_back(math.value);
  }
  cout << "Vector length: " << math.vec1.size() << endl << endl;
}

void normalize(my_vector& math)
{
  cout << "Enter vector: " << endl;
  while (math.value != -1)
  {
    cin >> math.value;
    if (math.value != -1) math.vec1.push_back(math.value);
  }
  for(int i = 0; i < math.vec1.size(); i++)
    if (math.vec1[i] >= math.max) math.max = math.vec1[i];
  cout << "Normalize: ";
  for(int i = 0; i < math.vec1.size(); i++)
  {
    math.vec1[i] = math.vec1[i]/math.max;
    cout << math.vec1[i] << " ";
  }
  cout << endl << endl;
}

void insert(my_vector& math)
{
  string operation;
  while (operation != "q")
  {
    cout << "Enter operation: ";
    cin >> operation;
    try
    {
    if (operation == "a") add(math);
    if (operation == "s") substract(math);
    if (operation == "c") scale(math);
    if (operation == "l") length(math);
    if (operation == "n") normalize(math);
    }
    catch (const exception& e)
    {
      cerr << endl << "Input error: " << e.what();
      break;
    }
    math.vec1.clear();
    math.vec2.clear();
  }
}

int main()
{
  my_vector math;
  insert(math);
}
