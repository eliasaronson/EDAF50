#include "hns.h"
#include <algorithm>

using std::string;
using std::vector;

HNS::HNS(const int size){
  vector<vector<pair<HostName, IPAddress>>> temp(size, vector<pair<HostName, IPAddress>>());
  HNS::size = size;
  HNS::store = temp;
}

void HNS::insert(const HostName& h, const IPAddress& ip){
  pair<string, unsigned int> temp(h, ip);
  HNS::store[hash(h)].push_back(temp);
}

/*
 * Remove the pair with the specified host name. Returns true
 * if the host name existed and the pair was removed, false
 * otherwise.
 */
bool HNS::remove(const HostName& h){
  int hach = hash(h);
  auto it = std::find_if(store[hach].begin(), store[hach].end(), [h](pair<HostName, unsigned int> a) -> bool{ return a.first == h;}); 
  if (it == store[hach].end()) {
   return false;
 }
 else{
  store[hach].erase(it);
  return true;
 }
}

/*
 * Find the IP address for the specified host name. Returns
 * NON_EXISTING_ADDRESS if the host name wasn't in the name
 * server.
 */
IPAddress HNS::lookup(const HostName& h) const{
 int hach = hash(h);
 auto it = std::find_if(store[hach].begin(), store[hach].end(), [h](pair<HostName, unsigned int> a) -> bool{ return a.first == h;}); 
 if (it == store[hach].end()) {
   return NON_EXISTING_ADDRESS;
 }
 else{
 return it->second;
 }
}

int HNS::hash(const HostName& h) const{
  std::hash<string> ret; 
  return ret(h) % size;   
}
