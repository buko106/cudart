#include<iostream>
#include<cmath>

// cpu utils
using std::sqrt;

// sign
template<typename T> inline T sgn( T x ){
  if( x == 0.0 )
    return 0.0;
  else if( x > 0.0 )
    return 1.0;
  else
    return -1.0;
}

// conditional negation
template<typename T> inline T fneg_cond( T cond, T x ){
  if( cond )
    return x;
  else
    return -x;
}

// (x+y) mod 5
template<typename T> inline T add_mod5( T x, T y ){
  T sum = x + y;
  if( sum >= 5 )
    return sum-5;
  else
    return sum;
}

// primitieves for vector operation
// assign
template<typename T> inline void vecset( T *v, T x, T y, T z){
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

// fill
template<typename T> inline void vecfill( T *v, T elem ){
  v[0] = elem;
  v[1] = elem;
  v[2] = elem;
}

// initialize with 0.0
template<typename T> inline void vecbzero( T *v ){
  vecfill(v,0.0);
}

// copy
template<typename T> inline void veccpy( T *dest, T *src ){
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
}

// square of distance
template<typename T> inline T vecdist2( T *p, T *q ){
  return
    + (p[0]-q[0]) * (p[0]-q[0])
    + (p[1]-q[1]) * (p[1]-q[1])
    + (p[2]-q[2]) * (p[2]-q[2]);
}

// normalization without checking zero division
template<typename T> inline void vecunit( T *v ){
  T il = 1.0 / sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
  v[0] *= il;
  v[1] *= il;
  v[2] *= il;
}

// signed normalization with checking zero division
template<typename T> inline void vecunit_sgn( T *v, bool inv ){
  T l  = sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
  T il = ( l == 0.0 ? 1.0 : ( inv ? -1.0/l : 1.0/l ) );
  v[0] *= il;
  v[1] *= il;
  v[2] *= il;
}

// inner product
template<typename T> inline T veciprod( T *v, T *w ){
  return
    + v[0] * w[0]
    + v[1] * w[1]
    + v[2] * w[2];
}

// different form of inner prod
template<typename T> inline T veciprod( T *v, T w0, T w1, T w2 ){
  return
    + v[0] * w0
    + v[1] * w1
    + v[2] * w2;
}

// dest += scale * v
template<typename T> inline void vecaccum( T *dest, T scale, T *v){
  dest[0] += scale * v[0];
  dest[1] += scale * v[1];
  dest[2] += scale * v[2];  
}

// add
template<typename T> inline void vecadd( T *dest, T *v){
  dest[0] += v[0];
  dest[1] += v[1];
  dest[2] += v[2];
}

// mult
template<typename T> inline void vecmul( T *dest, T *v){
  dest[0] *= v[0];
  dest[1] *= v[1];
  dest[2] *= v[2];
}

// scaling
template<typename T> inline void vecscale( T *dest, T scale ){
  dest[0] *= scale;
  dest[1] *= scale;
  dest[2] *= scale;
}

// dest += v*w
template<typename T> inline void vecaccumv( T *dest, T *v, T *w ){
  dest[0] += v[0] * w[0];
  dest[1] += v[1] * w[1];
  dest[2] += v[2] * w[2];
}

template<typename T> struct pixel_t{
  T rgb[3];
  T intersection_points[5][3];
  T surface_ids[5];
  bool calc_diffuse[5];
  T energy[5][3];
  T received_ray_20percent[5][3];
  int group_id;
  T nvectors[5][3];
};

template<typename T> struct object_t{
  int texturetype;
  int form;
  int reflectiontype;
  int isrot;
  T abc[3];
  T xyz[3];
  bool isinvert;
  T surfparams[2];
  T color[3];
  T rotation[3];
  T ctbl[4];
};

int main( int argc, char **argv){
  
  return 0;
}
