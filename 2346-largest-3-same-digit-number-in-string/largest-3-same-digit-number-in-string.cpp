class Solution {
public:
    string largestGoodInteger(string& num) {
        int count=0;
        char prev='X', maxd=' ';
        for(char c: num){
            if (c==prev) count++;
            else count=1;
            if (count==3)
                maxd=max(maxd, c);
            prev=c;
        }
        return (maxd==' ')?"":string(3, maxd);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();