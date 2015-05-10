/**
 * @file color.h
 * @brief Functions for color generation/conversion
 * @{
 */

#ifndef _COLOR_H_
#define _COLOR_H_

#ifdef __cplusplus
extern "C" {
#endif

void color_hsl_to_rgb(float h, float s, float l, float *r, float *g, float *b);

#ifdef __cplusplus
}
#endif

#endif /* _COLOR_H_ */

/** @} */
