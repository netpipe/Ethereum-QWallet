#include <unistd.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <iostream>
#include <memory.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <iostream>
#define headlessGUI //define for console mode only

#include "md5sum.h"
//#include "address.h"

#include "api.hpp"
Wrapper *wr=new Wrapper();

Factory *test=new Factory(wr,"testo");

Keypair testkeypair;

//create 5 databas scale to 50 later divide the ammount of coins by databases and search for coin address
//fill with coin addresses and main wallet info

// sign txid with private key use public key(wallet address) to decode it and verify
//hash tx with coin addresses to produce a txid file

//txid file has value, coins (random generated addresses ? or just coin numbers) hash of file , publickey, timestamp , fee, send to walletid

//int system(const char *command); //md5 file

//using namespace irr;
//using namespace core;
//using namespace scene;
//using namespace video;
//using namespace io;
//using namespace gui;



int main()
{


   //test->CreateRawTransaction(  "nonce: '0x1e7'",
//   "gasPrice: '0x2e90edd000'", "gasLimit: '0x30d40'",
//   "to: '0xbd064928cdd4fd67fb99880e6560978d7ca1'",
//   "value: '0xde0b6b3a7640000'",
//    "data: '0x'");

            std::string snoonce = "nonce: '0x1e7'";
            std::string sgasPrice = "gasPrice: '0x2e90edd000'"; // check against limit
            std::string sgasLimit = "gasLimit: '0x30d40'";
            std::string sto = "to: '0xbd064928cdd4fd67fb99880e6560978d7ca1'" ;
            std::string svalue =  "value: '0xde0b6b3a7640000'";
            std::string sdata ="data: '0x'";
        printf(test->CreateRawTransaction(snoonce,sgasPrice,sgasLimit,sto,svalue,sdata).c_str());


    return 0;
}
