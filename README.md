# WEC-Systems-Cryptography

## First Challenge

The QR code in the vaccination certificate was altered since  verify.cowin.gov.in gave a negative result. So, the QR was scanned and some encoded text was obtained. 

## Second Challenge

Upon further analysis, it was found that the code obtained from the QR code was indeed a BASE-64 code. 

* ### Base-64 ->    

    The **encoding** process works as follows. First, take the message and for every character, append the 8-bit binary representation of the ASCII value to some intermediate string.

    Afterwards, from the complete intermediate string, make groups of 6 starting from the left. If some bits cannot be made into groups of 6 in the end, append zeroes so the the grouping becomes possible. Also, for every 2 Zeroes appended, append one '='.

    Each of these 6 digit binary numbers represnt a number between 0-63 which act as indices for the BASE-64 CHARSET. (For example, if one grouping of 6 is 110001, the corresponding decimal value is 49 which corresponds to the 48th letter of the Base-64 Charset)

    The decoding process is also simple. For each character in the encoded message, find out its position in the base-64 char-set and append the corresponding 6 digit binary to some intermediate string. 

    Now , pop 2 or 4 zeroes from the end depending on the number of '='s in the end of the encoded message.

    Finally, make groups of 8 from left to right, convert each 8 bit binary to the correponding decimal value (which is the ASCII value of the final decoded character ). Convert this ASCII decimal value to a character and append it to the final decoded message. Keep going until there are no characters left in the intermediate string. 

Using a relatively simple C++ program the message in the QR code was decoded and a CIPHER text was obtained. 

## Third Challenge

Great job. Julius Caeser was born in the 100 BC:
PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F
OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY

The text gave away that Ceaser Cipher with an offset of 100 was used. 

* ### Caesar Cipher ->
    This is relatively simple cipher. Every character in the original message is shifted by some pre-decided offset. For example if the message is ON, and the offset is +3, then the final message becomes (O+3)(N+3) -> RQ. Note that the shifting wraps around the alphabet set. So, Z + 1 is essentially A. 

 Using a C++ program , the text was decoded the next clue was obtained. 


## Fourth Challenge
After decoding the previous message using caesar cipher, the following message was obtained. 

THE NEXT CIPHER KEYSQUARE IS THE ALPHABETS WITHOUT J
STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC

From the given message, it is clear that the cipher used uses a 'Cipher Keysquare' . Polybius and Playfair cipher were the two prime candidates. After some trial and error, it was found that Playfair Cipher was used with the KeySquare as  
ABCDE
FGHIK
LMNOP
QRSTU
VWXYZ

(Basially a row first filled 5X5 table without J)

* ### Playfair Cipher->

    The way this Cipher works is as follows

    A 5x5 keySquare is generated which acts as the key for encrypting the given message. Usually J is ommited from this keysquare(which was given). (For this task, both row major and column major grids had to be tried to finally get to the conclusion that a row major key square was used).

    The message to be encoded is split into pairs of 2. (tables -> ta bl es)

    Both the letters in the pair cannot be the same. So we break such pairs and add a bogus letter to the previous character and then continue with the process normally 
    (For example, ssa -> sx sa)

    In the end, if any character remains unpaired, then an extra bogus letter is added to complete the pairing. 
    (For example, press->pr es sx)

    Now to get the encrypted message, we check out each of these pairs one by one

    In a pair, if both the letters are in the same column, then replace each character with the character below them (with wrap around)

    If both the letters are in the same row, then replace each with the letter to the right of them (with wrap around). 

    If neither is true, then create the smallest enclosing rectangle these two letters are corners and replace each letter with the letters on the corresponding horizontal opposite corners

    The decoding process is very similar. For every 2 letters in the encoded message, if they're in the same row,move both letters to the left. If they're in the same column , move both one letter above. Otherwise, just replace each one with the corresponding horizontal opposite corners in the smallest enclosing rectangle

Finally, after applying this process we get another instruction, but this time in plain english. 

## Fifth Challenge

