#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "abacabacabacabab";
    string pattern = "abacabab";
    int dlT = text.length();
    int dlW = pattern.length();
    int p[dlW];

    //makeTab(pattern, dlW, p);
    //kmp(text, pattern, dlW, dlT, p);
    p[0]=0;
    p[1] = 0;
    int t = 0;
    for(int i=1;i<dlW;i++) {
        while (t > 0 && pattern[t] != pattern[i])
            t = p[t];
        if (pattern[t] == pattern[i])
            t++;
        p[i + 1] = t;
    }
    int i=0, j=0;
    while(i<dlT-dlW+1){
        cout<<"Poczatkek while"<<endl;
        while(pattern[j]==text[i+j] && j<dlW)
            j++;
        if(j==dlW)
            cout<<"Znaleziono wzorzec na pozycji "<<i<<endl;
        i=i+max(1,j-p[j]);
        j=p[j];
    }
    return 0;
}
