#include <bits/stdc++.h>
using namespace std;

void searchpat(string text,string pat){
    int m = text.size();
    int n = pat.size();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        int temp=n-1-i;
        if(temp==0){
            temp=n;
        }
        mp[pat[i]]=temp;
    }

    for(int s=0;s<m-n+1;){
        int j=n-1;
        int pos=s+j;
        while(j>=0 && pat[j]==text[pos]){
            j--;
            pos--;
        }
        if(j<0){
            cout<<"found at index "<<s<<endl;
            s++;
        }
        else{
            int temp=mp[text[pos]];
            s+=max(1,temp);
        }
    }

}

int main(){
    string text = "ABABABCD";
    string pat="ABC";
    searchpat(text,pat);
    return 0;
}
