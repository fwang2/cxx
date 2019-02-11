/*
 * sdp.cc
 *
 *  Created on: Mar 25, 2013
 *      Author: f7b
 *
 * To make it work under macOS
 *
 * $ cd /usr/local/include
 * $ ln -s ../opt/openssl/include/openssl .
 *
 */


#include <string>
#include <openssl/sha.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;


void sha1(const string &fn, unsigned char* obuf) {
    unsigned char ibuf[fn.size()];
    fn.copy((char *) ibuf, fn.size());
    SHA1( ibuf , sizeof(ibuf), obuf);
    int i;
    printf("%s -> \n", ibuf);
    for (i = 0; i < sizeof(obuf); i++) {
        printf("%02x ", obuf[i]);
    }
    printf("\n");
}
int main() {
    string data {"/home/fwang2"};
    unsigned char obuf[SHA_DIGEST_LENGTH];
    sha1(data, obuf);

}
