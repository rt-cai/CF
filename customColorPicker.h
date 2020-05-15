/**
 * @file customColorPicker.h
 * Definition of a diagonal color picker.
 *
 */
#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"

/**
 * customColorPicker: a functor that determines the color that should be used
 * given an x and a y coordinate using a diagonal pattern.
 *
 */
class customColorPicker : public colorPicker
{
  public:
    /**
     * Constructs a new customColorPicker.
     */
    customColorPicker(PNG & img, HSLAPixel fillColor, int stripeSpacing);

    /**
     * Picks the color for pixel (x, y).
     *
     * @param x The x coordinate to pick a color for.
     * @param y The y coordinat to pick a color for.
     * @return The color chosen for (x, y).
     */
    virtual HSLAPixel operator()(int x, int y);

  private:
    PNG im;
    HSLAPixel color; /**< Color used for the stripe. */
    int spacing;     /**< Space between diagonals. */
};

#endif
