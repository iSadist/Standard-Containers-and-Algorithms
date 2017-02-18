#include "mns.h"

#include <string>
#include <algorithm>
#include <iostream>

MNS::MNS(){}

MNS::~MNS(){}

void MNS::insert(const HostName& host, const IPAddress& ip){
	lookup_map.insert(make_pair(host, ip));
}

bool MNS::remove(const HostName& host){
	if (lookup_map.erase(host) > 0)
		return true;

	return false;
}

IPAddress MNS::lookup(const HostName& host) const{
	auto it = lookup_map.find(host);
	if (it != lookup_map.end())
		return it->second;

	return NON_EXISTING_ADDRESS;
}
