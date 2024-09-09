#include "encryption.h"
#include <fstream> //For file input-output reading
#include <cctype> 
using namespace std;

bool performCaesarCipher(string& content, bool encrypt){
    int shift = encrypt ? 3 : -3;

    for(char& ch : content){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base); //Caesar cipher

        }
    }
    return true;
}

bool encryptFile(const string& fileN, bool encrypt){
    
    //Open the input file
    ifstream inFile(fileN);

    if(!inFile) return false;

    //Read the content
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if(performCaesarCipher(content,encrypt)) {
        //Create an output file and writing the modified content
        ofstream outFile(encrypt ? "encrypted_" + fileN : "decrypted_" + fileN);
        if(!outFile) return false;

        outFile << content;

        outFile.close();

        return true;
    }
}