#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> read_file(std::string filename){
    std::vector<int> message;
    std::ifstream input_file(filename);
    if(input_file.is_open()){
        std::string line;
        while(getline(input_file, line, ',')) message.push_back(std::stoi(line));
    }
    input_file.close();
    return message;
}

std::vector<int> decrypt(std::vector<int> message, std::vector<int> key) {
    std::vector<int> decrypted_message(message.size());
    for (int i = 0; i < message.size(); i++) decrypted_message[i] = message[i] ^ key[i % key.size()];
    return decrypted_message;
}

bool is_english(std::string message){
    int num_chars = 0;
    for(char c : message)
        if(isalpha(c) || isspace(c) || ispunct(c)) num_chars++;
    double ratio = static_cast<double>(num_chars) / static_cast<double>(message.length());
    return ratio >= 0.9;
}

int main(){
    std::vector<int> message = read_file("p059_cipher.txt"); // This code produces wrong output, because "p059_cipher.txt" has been changed
    std::vector<int> key = {0, 0, 0};
    int max_ascii_sum = 0;

    for(int a = 'a'; a <= 'z'; a++){
        for(int b = 'a'; b <= 'z'; b++){
            for(int c = 'a'; c <= 'z'; c++){
                key = {a, b, c};
                std::vector<int> decrypted_message = decrypt(message, key);
                std::stringstream ss;
                for(int ascii_code : decrypted_message) ss << static_cast<char>(ascii_code);
                
                std::string message_str = ss.str();
                if(is_english(message_str)){
                    int ascii_sum = 0;
                    for (int ascii_code : decrypted_message) ascii_sum += ascii_code;
                    if (ascii_sum > max_ascii_sum) max_ascii_sum = ascii_sum; 
                }
            }
        }
    }

    std::cout << max_ascii_sum << '\n';
    return 0;
}
