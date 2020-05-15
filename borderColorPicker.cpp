#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
  color = fillColor;
  im = img;
  tol = tolerance;
  ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
  for(int i = 0; i < 4; i++){
    for(int j = 3-i; j >= 0; j--){
      if(i==2){
        if((x-2)<0 || (y-2)<0 || (x+2)>=im.width() || (y+2)>=im.height())
          return color;
        if(im.getPixel(x-2,y-2)->dist(ctr)>tol)
          return color;
        if(im.getPixel(x-2,y+2)->dist(ctr)>tol)
          return color;
        if(im.getPixel(x+2,y-2)->dist(ctr)>tol)
          return color;
        if(im.getPixel(x+2,y+2)->dist(ctr)>tol)
          return color;
      }
      if((x-i)<0 || (y-j)<0 || (x+i)>=im.width() || (y+j)>=im.height())
        return color;
      if(im.getPixel(x-i,y-j)->dist(ctr)>tol)
        return color;
      if(im.getPixel(x-i,y+j)->dist(ctr)>tol)
        return color;
      if(im.getPixel(x+i,y-j)->dist(ctr)>tol)
        return color;
      if(im.getPixel(x+i,y+j)->dist(ctr)>tol)
        return color;
    }
  }
  return *im.getPixel(x,y);
}
