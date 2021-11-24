#include<bits/stdc++.h>
using namespace std;

string ENCODED_MESSAGE = "TM, DTZ KTZSI RJ😔. HTSLWFYX. YMNX NX YMJ JSILTFQ. TW NX NY?🤨";
void caesar_cipher(string message, int key){
    key%=26;
    key = 26-key;
    string cipher_text = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            cipher_text += char((message[i] - 'A' + key) % 26 + 'A');
        }
        else cipher_text+=message[i];
    }
    cout<< cipher_text<<"\n";
}

void bruteForce(string message){
    for(int i = 0; i < 26; i++){
        caesar_cipher(message, i);
    }
}

int main(){
    bruteForce(ENCODED_MESSAGE);
}