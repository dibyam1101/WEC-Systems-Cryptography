#include<bits/stdc++.h>
using namespace std;

string ENCODED_MESSAGE = "STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC";

//Cipher Square without the letter 'J'
string cipher_square[5] = {"ABCDE", "FGHIK", "LMNOP", "QRSTU", "VWXYZ"};
map<char, pair<int, int>> mp;

signed main(){
    //Storing the position of each character in the cipher square for easy access
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            mp[cipher_square[i][j]] = make_pair(i, j);
        }
    
    }

    string decoded_message = "";

    for(int i = 0; i < ENCODED_MESSAGE.size(); i+=2){
        int row1 = mp[ENCODED_MESSAGE[i]].first;
        int col1 = mp[ENCODED_MESSAGE[i]].second;
        int row2 = mp[ENCODED_MESSAGE[i+1]].first;
        int col2 = mp[ENCODED_MESSAGE[i+1]].second;

        //Taking the letters above each of the two letters if they are in the same row (with a wrap around)
        if(row1 == row2){
            decoded_message += cipher_square[row1][((col1 - 1) + 5) % 5];
            decoded_message += cipher_square[row2][((col2 - 1) + 5) % 5];
        }


        //Taking the letters to the left of each letter if they are in the same column(with a wrap around)
        else if(col1 == col2){
            decoded_message += cipher_square[((row1 - 1) + 5 )% 5][col1];
            decoded_message += cipher_square[((row2 - 1) + 5 )% 5][col2];
        }

        //Else, finding the horizontal corners of the smallest enclosing rectangle
        else{
            decoded_message += cipher_square[row1][col2];
            decoded_message += cipher_square[row2][col1];
        }
    }

    cout<<decoded_message;
    
    
    return 0;
}