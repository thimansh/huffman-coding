/*
 * decoderhuff.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Himanshu Taneja
 */

#include <iostream>
#include <string>
#include <fstream>
#include "decoder.h"

using namespace std;

int main(int argc, char const *argv[]) {

   if ( argc != 3 ){
	cout<<"Usage: "<<argv[0]<<" encoded.bin code_table.txt"<<endl;
	return 0;
    }

    std::ifstream f (argv[1],ios::binary | ios::in);
    if ( !f.is_open() ){
	  std::cout<<"Could not open file\n";
	  return 0;
    }

    ifstream ct(argv[2], ios::in);
    if ( !ct.is_open() ){
	  std::cout<<"Could not open file\n";
	  return 0;
    }

    Decode D = Decode();
    int a;
    string b;
   // cout << "Decode Tree" << endl;
    while (ct >> a >> b) {
        D.addLeafAt(a, b);
    }



    cout << "Decoding Binary File: encoded.bin to decoded.txt" << endl;
    ofstream onfile ("decoded.txt",std::ios::out);

    char c;
    string result;
    while (f.get(c)) {
        for (int i = 7; i >= 0; i--) {
            int d = (c >> i) & 1;
            result.append(to_string(d));
            if (D.getAt(result) != -1) {

                onfile << D.getAt(result) << endl;
                result = "";
            }
        }

    }

    onfile.close();
    f.close();
    ct.close();
    return 0;
}




