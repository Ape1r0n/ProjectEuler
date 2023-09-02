#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define print(x) std::cout << x << '\n'

using std::getline, std::stringstream, std::string, std::vector;

int main(int argc, char** argv) {
	string temp, ans = "", boldedText = "affine plane radically integral local field open oriented line section jacobian orthogonal kernel embedding";
	stringstream ss(boldedText);
	vector<string> v;
	while (getline(ss, temp, ' ')) v.push_back(temp);
	for (int i = 0; i < v.size(); i++) ans += v[i][0];
	print(ans);
    return 0;
}
