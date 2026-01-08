bool compare(string a,string b){
            return a+b> b+a;
    }

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int m:nums){
            arr.push_back(to_string(m));

        }
        sort(arr.begin(),arr.end(),compare);
        
        if(arr[0]=="0"){
            return "0";
        }

        string s="";
        for(string m:arr){
            s+=m;
        }
        return s;


        
    }
};