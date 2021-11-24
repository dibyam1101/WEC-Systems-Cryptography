#include<bits/stdc++.h>
using namespace std;

//Hardcoding Base64 Alphabet and the Encoded_Message for simplicity
string ENCODED_MESSAGE = "R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==";
string BASE_64_CHAR_SET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" ;

int main(){
    string intermediate = "", decoded_message = ""; 
    //Converting each character to corresponding 6Bit Base64 value and then appending the binary
    //to the intermediate string taking care of = and == in the end
    for(char c : ENCODED_MESSAGE){
        if(c=='='){
            intermediate.pop_back();
            intermediate.pop_back();
            continue;
            }

        int base64Index = BASE_64_CHAR_SET.find(c);
        string binary = "";
        for(int i = 5; i>=0 ;i--) binary += ((base64Index) & (1<<i)) ? "1" : "0";
        intermediate += binary;        
    }   
       
    //Making groups of 8 bits and converting every group to its corresponding ASCII character
    // and appending to the decoded message
    int n = intermediate.length();
    for(int i = 0; i<n; i+=8){
        string s = intermediate.substr(i,8);        
        long long ascii = 0;
        for(int j = 0; j<8; j++){
            ascii += (s[j]-'0')*pow(2,7-j);
        }
        decoded_message += (char)(ascii);         
    }    

    cout<<decoded_message;

    return 0;
}