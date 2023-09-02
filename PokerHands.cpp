#include <bits/stdc++.h>

std::map<char, int> M = {{'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

typedef std::pair<int, char> Card;
    
std::vector<int> GetRank(std::vector<Card> &cards){
	std::sort(cards.begin(), cards.end(), [](Card a, Card b) { return a.first < b.first; }); 
	std::vector<int> nums;
	std::set<char> suits;
    bool consecutive = true;
	std::map<int, int> count;    
	std::vector<int> pair;
    int three = 0, four = 0;    
    
	for(auto &it : cards){
        if(!nums.empty() && it.first != nums.back() + 1){
            if(consecutive){
                if(nums.size() == 4 && it.first == 14 && nums[0] == 2){
                    nums.insert(nums.begin(), 1);
                    it.first = 1;                    
                } else consecutive = false;
            }
        }
        count[it.first]++;
        nums.push_back(it.first);
        suits.insert(it.second);        
    }
    for(auto it : count){
        int num = it.first, c = it.second;
        if(c == 2) pair.push_back(num);
        if(c == 3) three = num;
        if(c == 4) four = num;
    }
    
    if(consecutive){        
        if(suits.size() == 1){
            if(nums[0] == 10) return {1};
            else return {2};
        }
        return {6};        
    }
    if(four) return {3, four};    
    if(three){
        if(pair.size() == 1) return {4, three, pair[0]};
        else if(suits.size() > 1) return {7, three};
    }
    if(suits.size() == 1) return {5};
    if(pair.size() == 2) return {8, std::max(pair[0], pair[1]), std::min(pair[0], pair[1])};    
    if(pair.size() == 1) return {9, pair[0]};
    return {10, nums[4]};    
}


int main(){
    int t; std::cin >> t; 
    while(t--){
		std::vector<Card> P1, P2; 
        for(int i=0; i<10; i++){
            std::string card; std::cin >> card;
            if(i < 5) P1.push_back({(isdigit(card[0])) ? card[0]-'0' : M[card[0]], card[1]});
            else P2.push_back({(isdigit(card[0])) ? card[0]-'0' : M[card[0]], card[1]});
        }
        
		std::vector<int> hand1 = GetRank(P1);
		std::vector<int> hand2 = GetRank(P2);
        int rank1 = hand1[0];
        int rank2 = hand2[0];

        if(rank1 != rank2) 	std::cout << ((rank1 < rank2) ? "Player 1\n" : "Player 2\n");
        else{            
            for(int i=1; i<hand1.size(); i++){
                if(hand1[i] != hand2[i]){
					std::cout << ((hand1[i] > hand2[i]) ? "Player 1\n" : "Player 2\n");
                    goto next;
                }             
            }
            for(int i=4; i>=0; i--){
                if(P1[i].first != P2[i].first){
					std::cout << ((P1[i].first > P2[i].first) ? "Player 1\n" : "Player 2\n");
                    break;
                }
            }
            next:
            continue;
        }
    }
    return 0;
}
