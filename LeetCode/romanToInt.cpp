class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}           
        };
        int sum = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++){
            int a = roman[s[i]];
            if(a < roman[s[i + 1]]){
                sum -= a;// 累減
            }else{
                sum += a;// 累加
            }
        }
        return sum;
    }
};
