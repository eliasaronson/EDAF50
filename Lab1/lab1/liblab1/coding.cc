#include<coding.h>

unsigned char encode(unsigned char c){
    if (c+5 > 255) {
      c = c -255 + 5;
    }else{
      c = c + 5;
    }
    return c;
}
unsigned char decode(unsigned char c){
  if (c-5 < 0) {
    c = c + 255 - 5;
  }else{
    c = c - 5;
  }
      return c;
}
