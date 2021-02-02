/**@file	/home/elias/Documents/C++/lab3/toString.cc
 * @author	elias
 * @version	800
 * @date
 * 	Created:	02nd Mar 2020
 * 	Last Update:	02nd Mar 2020
 */

#include <iostream>
#include <string>
#include "toString.h"

template <class T>

toString::toString(T a){
  T ret;
  try{
    ret = std::to_string(a);
  }catch(std::invalid_argument& e){
    try{
      ret << a;
    }catch(std::invalid_argument& e){
      std::cout << "No string representation found";
    }
  }
}
