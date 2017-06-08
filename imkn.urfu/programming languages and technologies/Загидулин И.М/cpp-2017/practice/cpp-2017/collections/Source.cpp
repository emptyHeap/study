#include "iostream"
#include "algorithm"
#include "string"
#include "map"
#include "vector"

using namespace std;


void main()
{
	map<string, int> myMap;

	myMap["cat"] = 100;
	myMap["dog"] = 20;
	myMap["elephant"] = -23;
	myMap["fox"] = 20;
	myMap["mouse"] = 10;
	
	cout << myMap["string5"] << endl;

	for (auto iter : myMap)
		cout << iter.first << ": " << iter.second << endl;

	vector<int> myArray;

	myArray.push_back(1);
	myArray.push_back(2);
	myArray.push_back(3);

	for (auto iter : myArray)
		cout << iter << endl;
}