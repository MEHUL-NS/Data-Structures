#include<iostream>

using namespace std;


bool checkPalindrome(string str , int i){
    if(i>=str.length()/2) return true;
    if(str[i]!=str[str.length()-i-1]) return false;
    return checkPalindrome(str,i+1);
}

int main(){
    string str;
    cout<<"Enter the string : ";
    cin>>str;

    checkPalindrome(str , 0) ? cout<<"Palindrome" : cout<<"Not Palindrome";

}