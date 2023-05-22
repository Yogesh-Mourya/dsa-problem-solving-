class Solution {
private:
    bool checkEqual(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        //count number of occurance of char in string s1
        int countS1[26]={0};
        for(int i=0;i<s1.length();i++){
            int n=s1[i]-'a';
            countS1[n]++;
        }
        //first window 
        int i=0;
        int countS2[26]={0};
        int windowSize = s1.length();
        while(i<windowSize && i<s2.length())
        {
            int n=s2[i]-'a';
            countS2[n]++;
            i++;
        }
        if(checkEqual(countS1,countS2))
            return 1;
        // shifting the window
        while(i<s2.length())
        {
            char newChar=s2[i];
            int index = newChar - 'a';
            countS2[index]++;
            
            char oldChar=s2[i-windowSize];
             index = oldChar - 'a';
            countS2[index]--;

            i++;
              if(checkEqual(countS1,countS2))
              return 1;
        }
        return 0;
    }
};
