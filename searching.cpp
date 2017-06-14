#include<fstream>
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<ctype.h>
#include<cstring>

using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
    
    int len = 0;
 
    lps[0] = 0;
 
  
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
           
            if (len != 0)
            {
                len = lps[len-1];
 
                
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string pat, string txt, int pgno, int lno, int &flag, ofstream &file2)
{
    int M = pat.length();
    int N = txt.length();
 
   
    
    int lps[M];
 
   
    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j  = 0;  
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            
            j = lps[j-1];
            
            if(!(isalpha(txt[i])||isalpha(txt[i-M-1]))){
                               flag =1;
                               file2<<"Page "<<pgno<<", Line "<<lno<<"\n";
                               }
                               
            
        }
 
        
        else if (i < N && pat[j] != txt[i])
        {
           
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
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
                         
                         KMP(word,line,i,j,flag,file2);
                         
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
