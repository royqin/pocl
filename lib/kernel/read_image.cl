/* OpenCL built-in library: read_image()

   Copyright (c) 2013 Ville Korhonen 
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include "templates.h"
#include "image.h"
#include "pocl_image_rw_utils.h"

/* checks if integer coord is out of bounds. If out of bounds: Sets coord in 
   bounds and returns false OR populates color with border colour and returns 
   true. If in bounds, returns false */
int __pocl_is_out_of_bounds (void* image, int4 coord, 
                             void* sampler, void *color_)
{
  dev_image_t* dev_image = *((dev_image_t**)image);
  dev_sampler_t* dev_sampler = (dev_sampler_t*)sampler;
  uint4 *color = (uint4*)color_;
  if(*dev_sampler & CLK_ADDRESS_CLAMP_TO_EDGE)
    {
      if (coord.x >= dev_image->width)
        coord.x = dev_image->width-1;
      if (dev_image->height != 0 && coord.y >= dev_image->height)
        coord.y = dev_image->height-1;
      if (dev_image->depth != 0 && coord.z >= dev_image->depth)
        coord.z = dev_image->depth-1;
      
      if (coord.x < 0)
        coord.x = 0;
      if (coord.y < 0) 
        coord.y = 0;
      if (coord.z < 0)
        coord.z = 0;
      
      return 0;
    }
  if (*dev_sampler & CLK_ADDRESS_CLAMP)
    {    
      if(coord.x >= dev_image->width || coord.x < 0 ||
         coord.y >= dev_image->height || coord.y < 0 ||
         (dev_image->depth != 0 && (coord.z >= dev_image->depth || coord.z <0)))
        {
          (*color)[0] = 0;
          (*color)[1] = 0;
          (*color)[2] = 0;
          
          if (dev_image->order == CL_A || dev_image->order == CL_INTENSITY || 
              dev_image->order == CL_RA || dev_image->order == CL_ARGB || 
              dev_image->order == CL_BGRA || dev_image->order == CL_RGBA)
            (*color)[3] = 0;
          else
            (*color)[3] = 1; 
          
          return 1;
        }
    }
  return 0;
}

/* Reads a four element pixel from image pointed by integer coords. */
void __pocl_read_pixel (void* color, void* image, int4 coord)
{

  dev_image_t* dev_image = *((dev_image_t**)image);
  uint4* color_ptr = (uint4*)color;
  int i, idx;
  int width = dev_image->width;
  int height = dev_image->height;
  int num_channels = dev_image->num_channels;
  int elem_size = dev_image->elem_size; 
  
  for (i = 0; i < num_channels; i++)
    { 
      idx = i + (coord.x + coord.y*width + coord.z*height*width) * num_channels;
      if (elem_size == 1)
        {
          (*color_ptr)[i] = ((uchar*)(dev_image->data))[idx];
        }
      if (elem_size == 2)
        {
          (*color_ptr)[i] = ((ushort*)(dev_image->data))[idx];
        }
      if (elem_size == 4)
        {
          (*color_ptr)[i] = ((uint*)(dev_image->data))[idx];
        }
    }
}


/* Implementation for read_image with any image data type and int coordinates 
   __IMGTYPE__ = image type (image2d_t, ...)
   __RETVAL__  = return value (int4 or uint4 float4)
   __POSTFIX__ = function name postfix (i, ui, f)
   __COORD__   = coordinate type (int, int2, int4)
*/
#define IMPLEMENT_READ_IMAGE_INT_COORD(__IMGTYPE__,__RETVAL__,__POSTFIX__,\
                                            __COORD__)                  \
  __RETVAL__ _CL_OVERLOADABLE read_image##__POSTFIX__ (__IMGTYPE__ image, \
                                                       sampler_t sampler, \
                                                       __COORD__ coord) \
  {                                                                     \
    __RETVAL__ color;                                                   \
    int4 coord4;                                                        \
    INITCOORD##__COORD__(coord4, coord);                                \
    if (__pocl_is_out_of_bounds (&image, coord4, &sampler, &color))          \
      {                                                                 \
        return color;                                                   \
      }                                                                 \
    __pocl_read_pixel (&color, &image, coord4);                           \
                                                                        \
    return color;                                                       \
  }                                                                     \
  

/* read_image function instantions */
IMPLEMENT_READ_IMAGE_INT_COORD(image2d_t, uint4, ui, int2)
IMPLEMENT_READ_IMAGE_INT_COORD(image2d_t, int4, i, int2)
IMPLEMENT_READ_IMAGE_INT_COORD(image3d_t, uint4, ui, int4)
IMPLEMENT_READ_IMAGE_INT_COORD(image2d_t, float4, f, int2)
