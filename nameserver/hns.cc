#include "hns.h"

#include <string>
#include <algorithm>
#include <iostream>

HNS::HNS(unsigned int table_size){
	lookup_hashtable[table_size];

}

HNS::~HNS(){}

void HNS::insert(const HostName& host, const IPAddress& ip){

}

bool HNS::remove(const HostName& host){

	return false;
}

IPAddress HNS::lookup(const HostName& host) const{

	return NON_EXISTING_ADDRESS;
}
