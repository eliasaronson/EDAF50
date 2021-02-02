#ifndef UMNS_h
#define UMNS_h

#include "nameserverinterface.h"
#include <string>
#include <unordered_map>

using std::pair;
using std::unordered_map;

class UMNS: public NameServerInterface {
public: 

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
  
private:
  unordered_map<HostName, IPAddress> store;
};

#endif  // UMNS_h
