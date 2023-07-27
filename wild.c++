class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
         if(p.size()>s.size()) return "-1";
        int i=0;
        int j=0;
        int start=0;
        int minlen=INT_MAX;
        int count=0;
        vector<int>mp(26,0);
        for(int i=0;i<p.size();i++){
            if(mp[p[i]-'a']==0){
                count++;
            }
            mp[p[i]-'a']++;
            
        }
        
        while(j<s.size()){
                mp[s[j]-'a']--;
                if(mp[s[j]-'a']==0){
                    count--;
                }
            
            if(count==0){
                while( count==0){
                       mp[s[i]-'a']++;
                       if(mp[s[i]-'a']==1){
                           count++;
                       }
                       if(minlen>j-i+1){
                            minlen=j-i+1;
                            start=i;
                        }
                  
                    i++;
                }


            }
            j++;
        }
            if(minlen==INT_MAX) return "-1";
        return s.substr(start, minlen);
    }
};
