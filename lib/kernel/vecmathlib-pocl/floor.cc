// Note: This file has been automatically generated. Do not modify.

#include "pocl-compat.h"

// floor: ['VF'] -> VF

// floor: VF=float
#if defined VECMATHLIB_HAVE_VEC_FLOAT_1 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float _cl_floor(float x0)
{
  vecmathlib::realvec<float,1> y0 = bitcast<float,vecmathlib::realvec<float,1> >(x0);
  vecmathlib::realvec<float,1> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,1>,float>((r));
}
#elif ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling libm
float _cl_floor(float x0)
{
  vecmathlib::realpseudovec<float,1> y0 = x0;
  vecmathlib::realpseudovec<float,1> r = floor(y0);
  return (r)[0];
}
#else
// Implement floor by calling builtin
float _cl_floor(float x0)
{
  vecmathlib::realbuiltinvec<float,1> y0 = x0;
  vecmathlib::realbuiltinvec<float,1> r = floor(y0);
  return (r)[0];
}
#endif

// floor: VF=float2
#if defined VECMATHLIB_HAVE_VEC_FLOAT_2 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float2 _cl_floor(float2 x0)
{
  vecmathlib::realvec<float,2> y0 = bitcast<float2,vecmathlib::realvec<float,2> >(x0);
  vecmathlib::realvec<float,2> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,2>,float2>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_FLOAT_4 || defined VECMATHLIB_HAVE_VEC_FLOAT_8 || defined VECMATHLIB_HAVE_VEC_FLOAT_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
float4 _cl_floor(float4);
float2 _cl_floor(float2 x0)
{
  float4 y0 = bitcast<float2,float4>(x0);
  float4 r = _cl_floor(y0);
  return bitcast<float4,float2>(r);
}
#else
// Implement floor by splitting into a smaller vector size
float _cl_floor(float);
float2 _cl_floor(float2 x0)
{
  pair_float y0 = bitcast<float2,pair_float>(x0);
  pair_float r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_float) == sizeof(float2));
  return bitcast<pair_float,float2>(r);
}
#endif

// floor: VF=float3
#if defined VECMATHLIB_HAVE_VEC_FLOAT_3 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float3 _cl_floor(float3 x0)
{
  vecmathlib::realvec<float,3> y0 = bitcast<float3,vecmathlib::realvec<float,3> >(x0);
  vecmathlib::realvec<float,3> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,3>,float3>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_FLOAT_4 || defined VECMATHLIB_HAVE_VEC_FLOAT_8 || defined VECMATHLIB_HAVE_VEC_FLOAT_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
float4 _cl_floor(float4);
float3 _cl_floor(float3 x0)
{
  float4 y0 = bitcast<float3,float4>(x0);
  float4 r = _cl_floor(y0);
  return bitcast<float4,float3>(r);
}
#else
// Implement floor by splitting into a smaller vector size
float2 _cl_floor(float2);
float3 _cl_floor(float3 x0)
{
  pair_float2 y0 = bitcast<float3,pair_float2>(x0);
  pair_float2 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_float2) == sizeof(float3));
  return bitcast<pair_float2,float3>(r);
}
#endif

// floor: VF=float4
#if defined VECMATHLIB_HAVE_VEC_FLOAT_4 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float4 _cl_floor(float4 x0)
{
  vecmathlib::realvec<float,4> y0 = bitcast<float4,vecmathlib::realvec<float,4> >(x0);
  vecmathlib::realvec<float,4> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,4>,float4>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_FLOAT_8 || defined VECMATHLIB_HAVE_VEC_FLOAT_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
float8 _cl_floor(float8);
float4 _cl_floor(float4 x0)
{
  float8 y0 = bitcast<float4,float8>(x0);
  float8 r = _cl_floor(y0);
  return bitcast<float8,float4>(r);
}
#else
// Implement floor by splitting into a smaller vector size
float2 _cl_floor(float2);
float4 _cl_floor(float4 x0)
{
  pair_float2 y0 = bitcast<float4,pair_float2>(x0);
  pair_float2 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_float2) == sizeof(float4));
  return bitcast<pair_float2,float4>(r);
}
#endif

// floor: VF=float8
#if defined VECMATHLIB_HAVE_VEC_FLOAT_8 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float8 _cl_floor(float8 x0)
{
  vecmathlib::realvec<float,8> y0 = bitcast<float8,vecmathlib::realvec<float,8> >(x0);
  vecmathlib::realvec<float,8> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,8>,float8>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_FLOAT_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
float16 _cl_floor(float16);
float8 _cl_floor(float8 x0)
{
  float16 y0 = bitcast<float8,float16>(x0);
  float16 r = _cl_floor(y0);
  return bitcast<float16,float8>(r);
}
#else
// Implement floor by splitting into a smaller vector size
float4 _cl_floor(float4);
float8 _cl_floor(float8 x0)
{
  pair_float4 y0 = bitcast<float8,pair_float4>(x0);
  pair_float4 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_float4) == sizeof(float8));
  return bitcast<pair_float4,float8>(r);
}
#endif

// floor: VF=float16
#if defined VECMATHLIB_HAVE_VEC_FLOAT_16 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
float16 _cl_floor(float16 x0)
{
  vecmathlib::realvec<float,16> y0 = bitcast<float16,vecmathlib::realvec<float,16> >(x0);
  vecmathlib::realvec<float,16> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<float,16>,float16>((r));
}
#else
// Implement floor by splitting into a smaller vector size
float8 _cl_floor(float8);
float16 _cl_floor(float16 x0)
{
  pair_float8 y0 = bitcast<float16,pair_float8>(x0);
  pair_float8 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_float8) == sizeof(float16));
  return bitcast<pair_float8,float16>(r);
}
#endif

#ifdef cl_khr_fp64

// floor: VF=double
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_1 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double _cl_floor(double x0)
{
  vecmathlib::realvec<double,1> y0 = bitcast<double,vecmathlib::realvec<double,1> >(x0);
  vecmathlib::realvec<double,1> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,1>,double>((r));
}
#elif ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling libm
double _cl_floor(double x0)
{
  vecmathlib::realpseudovec<double,1> y0 = x0;
  vecmathlib::realpseudovec<double,1> r = floor(y0);
  return (r)[0];
}
#else
// Implement floor by calling builtin
double _cl_floor(double x0)
{
  vecmathlib::realbuiltinvec<double,1> y0 = x0;
  vecmathlib::realbuiltinvec<double,1> r = floor(y0);
  return (r)[0];
}
#endif

// floor: VF=double2
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_2 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double2 _cl_floor(double2 x0)
{
  vecmathlib::realvec<double,2> y0 = bitcast<double2,vecmathlib::realvec<double,2> >(x0);
  vecmathlib::realvec<double,2> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,2>,double2>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_DOUBLE_4 || defined VECMATHLIB_HAVE_VEC_DOUBLE_8 || defined VECMATHLIB_HAVE_VEC_DOUBLE_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
double4 _cl_floor(double4);
double2 _cl_floor(double2 x0)
{
  double4 y0 = bitcast<double2,double4>(x0);
  double4 r = _cl_floor(y0);
  return bitcast<double4,double2>(r);
}
#else
// Implement floor by splitting into a smaller vector size
double _cl_floor(double);
double2 _cl_floor(double2 x0)
{
  pair_double y0 = bitcast<double2,pair_double>(x0);
  pair_double r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_double) == sizeof(double2));
  return bitcast<pair_double,double2>(r);
}
#endif

// floor: VF=double3
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_3 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double3 _cl_floor(double3 x0)
{
  vecmathlib::realvec<double,3> y0 = bitcast<double3,vecmathlib::realvec<double,3> >(x0);
  vecmathlib::realvec<double,3> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,3>,double3>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_DOUBLE_4 || defined VECMATHLIB_HAVE_VEC_DOUBLE_8 || defined VECMATHLIB_HAVE_VEC_DOUBLE_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
double4 _cl_floor(double4);
double3 _cl_floor(double3 x0)
{
  double4 y0 = bitcast<double3,double4>(x0);
  double4 r = _cl_floor(y0);
  return bitcast<double4,double3>(r);
}
#else
// Implement floor by splitting into a smaller vector size
double2 _cl_floor(double2);
double3 _cl_floor(double3 x0)
{
  pair_double2 y0 = bitcast<double3,pair_double2>(x0);
  pair_double2 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_double2) == sizeof(double3));
  return bitcast<pair_double2,double3>(r);
}
#endif

// floor: VF=double4
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_4 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double4 _cl_floor(double4 x0)
{
  vecmathlib::realvec<double,4> y0 = bitcast<double4,vecmathlib::realvec<double,4> >(x0);
  vecmathlib::realvec<double,4> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,4>,double4>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_DOUBLE_8 || defined VECMATHLIB_HAVE_VEC_DOUBLE_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
double8 _cl_floor(double8);
double4 _cl_floor(double4 x0)
{
  double8 y0 = bitcast<double4,double8>(x0);
  double8 r = _cl_floor(y0);
  return bitcast<double8,double4>(r);
}
#else
// Implement floor by splitting into a smaller vector size
double2 _cl_floor(double2);
double4 _cl_floor(double4 x0)
{
  pair_double2 y0 = bitcast<double4,pair_double2>(x0);
  pair_double2 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_double2) == sizeof(double4));
  return bitcast<pair_double2,double4>(r);
}
#endif

// floor: VF=double8
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_8 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double8 _cl_floor(double8 x0)
{
  vecmathlib::realvec<double,8> y0 = bitcast<double8,vecmathlib::realvec<double,8> >(x0);
  vecmathlib::realvec<double,8> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,8>,double8>((r));
}
#elif (defined VECMATHLIB_HAVE_VEC_DOUBLE_16) && ! defined POCL_VECMATHLIB_BUILTIN 
// Implement floor by using a larger vector size
double16 _cl_floor(double16);
double8 _cl_floor(double8 x0)
{
  double16 y0 = bitcast<double8,double16>(x0);
  double16 r = _cl_floor(y0);
  return bitcast<double16,double8>(r);
}
#else
// Implement floor by splitting into a smaller vector size
double4 _cl_floor(double4);
double8 _cl_floor(double8 x0)
{
  pair_double4 y0 = bitcast<double8,pair_double4>(x0);
  pair_double4 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_double4) == sizeof(double8));
  return bitcast<pair_double4,double8>(r);
}
#endif

// floor: VF=double16
#if defined VECMATHLIB_HAVE_VEC_DOUBLE_16 && ! defined POCL_VECMATHLIB_BUILTIN
// Implement floor by calling vecmathlib
double16 _cl_floor(double16 x0)
{
  vecmathlib::realvec<double,16> y0 = bitcast<double16,vecmathlib::realvec<double,16> >(x0);
  vecmathlib::realvec<double,16> r = vecmathlib::floor(y0);
  return bitcast<vecmathlib::realvec<double,16>,double16>((r));
}
#else
// Implement floor by splitting into a smaller vector size
double8 _cl_floor(double8);
double16 _cl_floor(double16 x0)
{
  pair_double8 y0 = bitcast<double16,pair_double8>(x0);
  pair_double8 r;
  r.lo = _cl_floor(y0.lo);
  r.hi = _cl_floor(y0.hi);
  pocl_static_assert(sizeof(pair_double8) == sizeof(double16));
  return bitcast<pair_double8,double16>(r);
}
#endif

#endif // #ifdef cl_khr_fp64
