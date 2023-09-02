#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long
#define print(x) std::cout << x << '\n'

using std::cin, std::cout, std::string, std::vector;

template<typename T>
void printVector(vector<T>& v) {
    if (v.size() == 1) cout << v[0];
    for (int i = 0; i < v.size()-1; i++) cout << v[i] << ", ";
    if (v.size() > 1) cout << v[v.size()-1];
    cout << '\n';
}

bool isTriangular(int n) {
	for (int i = 1; i < 1000; i++) {
		if (((i*(i + 1)) / 2) == n) 
			return true;
	}
	return false;
}

bool isSquare(int n) {
    for (int i = 1; i < 1000; i++) {
        if (i*i == n)
			return true;
	}
    return false;
}

bool isPentagonal(int n) {
    for (int i = 1; i < 1000; i++) {
        if ((i*(3*i - 1) / 2) == n) 
			return true;
    }
    return false;
}

bool isHexagonal(int n) {
    for (int i = 1; i < 1000; i++) {
        if ((i * (2 * i - 1)) == n) 
            return true;
	}
    return false;
}

bool isHeptagonal(int n) {
    for (int i = 1; i < 1000; i++) {
        if ((i * (5 * i - 3) / 2) == n) 
            return true;
	}
    return false;
}

bool isOctagonal(int n) {
    for (int i = 1; i < 1000; i++) {
        if ((3*i*i - 2*i) == n) 
            return true;
    }
    return false;
}

bool isCyclic(int a, int b) {
	return (a%100) == (b/100);
}

vector<int> generateTriangularNumbers() {
	vector<int> v;
	for (int i = 1000; i < 10000; i++) {
		if (isTriangular(i)) 
			v.push_back(i);
	}
	return v;
}

vector<int> generateSquareNumbers() {
    vector<int> v;
    for (int i = 1000; i < 10000; i++) {
        if (isSquare(i)) 
            v.push_back(i);
    }
    return v;
}

vector<int> generatePentagonalNumbers() {
    vector<int> v;
    for (int i = 1000; i < 10000; i++) {
        if (isPentagonal(i)) 
            v.push_back(i);
    }
    return v;
}

vector<int> generateHexagonalNumbers() {
    vector<int> v;
    for (int i = 1000; i < 10000; i++) {
        if (isHexagonal(i)) 
            v.push_back(i);
    }
    return v;
}

vector<int> generateHeptagonalNumbers() {
    vector<int> v;
    for (int i = 1000; i < 10000; i++) {
        if (isHeptagonal(i)) 
            v.push_back(i);
    }
    return v;
}

vector<int> generateOctagonalNumbers() {
    vector<int> v;
    for (int i = 1000; i < 10000; i++) {
        if (isOctagonal(i)) 
            v.push_back(i);
    }
    return v;
}


int main(int argc, char** argv) {
	vector<int> triangulars = generateTriangularNumbers(), squares = generateSquareNumbers(), pentagonals = generatePentagonalNumbers();
	vector<int> hexagonals = generateHexagonalNumbers(), heptagonals = generateHeptagonalNumbers(), octagonals = generateOctagonalNumbers();
	vector<int> indices = {0, 1, 2, 3, 4, 5};
	vector<vector<int>> figurateNumbers = { triangulars, squares, pentagonals, hexagonals, heptagonals, octagonals };

    do {
        vector<int> result_set(6, 0);
        for (int t = 0; t < figurateNumbers[indices[0]].size(); t++) {
            result_set[0] = figurateNumbers[indices[0]][t];
            for (int s = 0; s < figurateNumbers[indices[1]].size(); s++) {
                result_set[1] = figurateNumbers[indices[1]][s];
                if (!isCyclic(result_set[0], result_set[1])) continue;
                for (int p = 0; p < figurateNumbers[indices[2]].size(); p++) {
                    result_set[2] = figurateNumbers[indices[2]][p];
                    if (!isCyclic(result_set[1], result_set[2])) continue;
                    for (int h = 0; h < figurateNumbers[indices[3]].size(); h++) {
                        result_set[3] = figurateNumbers[indices[3]][h];
                        if (!isCyclic(result_set[2], result_set[3])) continue;
                        for (int he = 0; he < figurateNumbers[indices[4]].size(); he++) {
                            result_set[4] = figurateNumbers[indices[4]][he];
                            if (!isCyclic(result_set[3], result_set[4])) continue;
                            for (int o = 0; o < figurateNumbers[indices[5]].size(); o++) {
                                result_set[5] = figurateNumbers[indices[5]][o];
                                if (isCyclic(result_set[4], result_set[5]) && isCyclic(result_set[5], result_set[0])) {
                                    int ans = 0;
                                    for (int e : result_set) ans += e;
                                    cout << "Resulting set: "; printVector(result_set);
									cout << "Answer: " << ans << '\n';
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(indices.begin(), indices.end()));

	return 0;
}
