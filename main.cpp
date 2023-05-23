#include <iostream>
#include <string>

using namespace std;

void makeTab(string pattern, int dlW, int* p);
void kmp(string text, string pattern, int dlw, int dlt, int* p); //Algorytm Knutha-Morrisa-Pratta

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

void makeTab(string pattern, int dlW, int* p)
{
    *p=0;
    *(p+1) = 0;
    int t = 0;
    for(int i=1;i<dlW;i++){
        while(t>0 && pattern[t]!=pattern[i])
            t=p[t];
        if(pattern[t]==pattern[i])
            t++;
        *(p+i+1)=t;
    }

}

void kmp(string text, string pattern, int dlw, int dlt, int* p)
{
    int i=0, j=0;
    while(i<dlt-dlw+1){
        cout<<"Poczatkek while"<<endl;
        while(pattern[j]==text[i+j] && j<dlw)
            j++;
        if(j==dlw)
            cout<<"Znaleziono wzorzec na pozycji "<<i<<endl;
        i=i+max(1,j-*(p+j));
        j=*(p+j);
    }
}
