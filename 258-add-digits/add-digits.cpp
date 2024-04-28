class Solution {
public:
    int sum(int num){
        int ans = 0;
        while(num){
            int rem = num%10;
            ans+=rem;
            num/=10;
        }
        return ans;
    }
    int addDigits(int num) {
        while(num > 9){
            num = sum(num);
        }
        return num;
    }
};