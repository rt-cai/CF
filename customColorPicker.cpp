#include "customColorPicker.h"

customColorPicker::customColorPicker(PNG & img, HSLAPixel fillColor, int stripeSpacing)
{
  im = img;
  color = fillColor;
  spacing = stripeSpacing;
}

HSLAPixel customColorPicker::operator()(int x, int y)
{
  for(int i = 0; i < 2*im.height(); i+=spacing){
    if(-y==x-i)
      return color;
  }
  return *im.getPixel(x,y);
}
