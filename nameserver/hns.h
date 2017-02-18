#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>

class HNS : public NameServerInterface{

public:
	HNS(unsigned int hash_table_size);
	~HNS();
	void insert(const HostName& host, const IPAddress& ip);
	bool remove(const HostName& host);
	IPAddress lookup(const HostName& host) const;

private:
	std::vector<std::vector<std::pair<HostName, IPAddress>>> lookup_hashtable;
};

#endif