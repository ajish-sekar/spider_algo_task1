#include<fstream>
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<ctype.h>
#include<cstring>

using namespace std;

int badchar[256];

int max (int a, int b) { return (a > b)? a: b; }

void badCharHeuristic( string str, int size)
{
    int i;
 
   
    for (i = 0; i < 256; i++)
         badchar[i] = -1;
 
    
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}

void BM( string txt, string pat, int pgno, int lno, int &flag, ofstream &file2)
{
    int m = pat.length();
    int n = txt.length();
 
  
 
    
    badCharHeuristic(pat, m);
 
    int s = 0;  
    while(s <= (n - m))
    {
        int j = m-1;
 
       
        while(j >= 0 && pat[j] == txt[s+j])
            j--;
 
       
        if (j < 0)
        {
            
            
            if(!(isalpha(txt[s-1])||isalpha(txt[s+m])))
                                   {    
                                   flag =1;
                                   file2<<"Page "<<pgno<<", Line "<<lno<<"\n";
                                   
                                   }
 
           
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
 
        }
 
        else
            
            s += max(1, j - badchar[txt[s+j]]);
    }
    
    
}

int main()
{
    char a[20] = "queries.txt";
    ifstream file(a);
    
    ofstream file2("output.txt");
    
    int i;
    
    
    
    string line;
    
    string word;
    
    while(!file.eof()){
                     int flag = 0;
                     getline(file,word);
                     file2<<"Word: "<<word;
                     file2<<"\nOcurrences :\n";
                     for(i=1;i<=25;i++){
                         int j=1;               
                         char c[20];
                         char file_name[20]= "page_";
                         itoa(i,c,10);
                         strcat(c,".txt");
                         strcat(file_name,c);
                         ifstream file3(file_name);
                         while(!file3.eof()){
                         
                         getline(file3,line);
                         
                         BM(line,word,i,j,flag,file2);
                         
                         j++;
                                 
                         }
                         file3.close();
                        
                         
                         }
                         if (flag==0)
                            file2<<"None\n";
                         file2<<"\n";
                       }
    file.close();
    file2.close();
        
    
    
    
    
}
