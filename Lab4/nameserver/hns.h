#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <string>
#include <vector>

using std::pair;
using std::vector;

class HNS: public NameServerInterface {
public: 
  HNS(const int size);

  void insert(const HostName&, const IPAddress&) override;
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName&) override;
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
  IPAddress lookup(const HostName&) const override;

  int hash(const HostName& h) const;
  
private:
  vector<vector<pair<HostName, IPAddress>>> store;
  int size;
};

#endif  // HNS_H
