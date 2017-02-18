#include "umns.h"

#include <string>
#include <algorithm>
#include <iostream>

UMNS::UMNS(){}

UMNS::~UMNS(){}

void UMNS::insert(const HostName& host, const IPAddress& ip){
	lookup_map.insert(make_pair(host, ip));
}

bool UMNS::remove(const HostName& host){
	if (lookup_map.erase(host) > 0)
		return true;

	return false;
}

IPAddress UMNS::lookup(const HostName& host) const{
	auto it = lookup_map.find(host);
	if (it != lookup_map.end())
		return it->second;

	return NON_EXISTING_ADDRESS;
}
