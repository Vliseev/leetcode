//
// Created by vlad on 12.08.19.
//

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=1,prev_count=0;
        int num=0;

        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                auto m = min(count,prev_count);
                num+=m;
                prev_count=count;
                count=1;
            }else{
                count++;
            }
        }
        return num+min(count,prev_count);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().countBinarySubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}