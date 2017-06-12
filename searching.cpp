#include<fstream>
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<ctype.h>
#include<cstring>

using namespace std;

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
                         vector<size_t> positions; 
    
                         
                        
                         size_t pos = line.find(word, 0);
                         while(pos != string::npos)
                         {
                                   if(!(isalpha(line[pos-1])||isalpha(line[pos+word.length()])))
                                   {    
                                   flag =1;
                                   file2<<"Page "<<i<<", Line "<<j<<"\n";
                                   positions.push_back(pos);
                                   }
                                   pos = line.find(word,pos+1);
                         }
                         
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
