
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void sort_by_first(int arr[][2], int n){
  auto ptr = (pair<int,int>*) arr;
  std::sort(ptr, ptr+n);
  }

int max_session(int times[][2], int n){
   int index = 0;
   int num = 1;
   int currentTime = times[0][0];
   while(index<n){
     int j = index;
     while(times[j][1]<currentTime && j<n){
       j++;
       }
     if(j >= n){
       break;
       }
     else{
     index = j;
     currentTime = times[index][0];
     num += 1;
     }
    }
    return num;
   }
int main(){
  int a[100][2];
  int n = 0;
  string session; int start; int dur;
  ifstream theFile("Schedule.txt");
  while(theFile>>session>>start>>dur){
    a[n][1] = start;
    a[n][0] = start + dur;
    n++;

    /*cout<<session<<" "<<start<<" "<<dur<<endl;*/
    }


  sort_by_first(a,n);

  int max_no = max_session(a,n);
  cout<<max_no;

  }
