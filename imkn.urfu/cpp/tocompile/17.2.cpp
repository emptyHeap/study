#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Pair {
	public:
		double n;
		double m;
		Pair(double n, double m):
			n(n),
			m(m)
		{
		}
		Pair(istream& stream)
	       	{
			stream >> n;
			stream >> m;
		}
		bool equals(Pair anotherPair) const
		{
			return ((n == anotherPair.n) && (m == anotherPair.m));
		}
		bool operator == (const Pair &Ref) const
		{
			return equals(Ref);
		}
		bool operator != (const Pair &Ref) const
		{
			return !equals(Ref);
		}
};

int main() {
	vector<Pair> pairs;
	Pair *finishPair = new Pair(0, 0);
	Pair* inputPair = new Pair(cin);
	while (*inputPair != *finishPair){
		pairs.push_back(*inputPair);
		inputPair = new Pair(cin);
	}

	vector<Pair> result;
	copy_if(pairs.begin(), pairs.end(), back_inserter(result),
		[&](const Pair& lpair) {
			for (Pair rpair : pairs) {
				if (lpair.n == rpair.m) return false;
			}
			return true;
		});
	if (result.size() == 0) {
		cout << "no N values, satisfying task condition\n";
	} else {
		for (Pair pair : result) {
			cout << pair.n << " ";
		}
		cout << "/n";
	}
	return 0;
}
