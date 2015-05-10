/**
 * @file color.c
 * @brief Functions for color generation/conversion
 * @{
 */

#include "color.h"
#include "math.h"

static float one_third = 1.0f/3.0f;

void color_hsl_to_rgb(float h, float s, float l, float* outR, float* outG, float* outB)
{
  float     temp1, temp2;
  float     temp[3];
  int       i;

  if(s == 0.0f) {
      *outR = l; *outG = l; *outB = l;
  }

  if(l < 0.5f)
    temp2 = l * (1.0f + s);
  else
    temp2 = l + s - l * s;
  temp1 = 2.0f * l - temp2;

  temp[0] = h + one_third;
  temp[1] = h;
  temp[2] = h - one_third;

  for(i = 0; i < 3; ++i) {

    if(temp[i] < 0.0f)
      temp[i] += 1.0f;
    if(temp[i] > 1.0f)
      temp[i] -= 1.0f;

    if(6.0f * temp[i] < 1.0f)
      temp[i] = temp1 + (temp2 - temp1) * 6.0f * temp[i];
    else {
      if(2.0f * temp[i] < 1.0f)
        temp[i] = temp2;
      else {
        if(3.0f * temp[i] < 2.0f)
          temp[i] = temp1 + (temp2 - temp1) * ((2.0f / 3.0f) - temp[i]) * 6.0f;
        else
          temp[i] = temp1;
      }
    }
  }

  *outR = temp[0]; *outG = temp[1]; *outB = temp[2];
}

/** @} */
