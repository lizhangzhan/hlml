#pragma once

#include "common.hpp"
#include "bool2.hpp"

namespace hlml {
struct int2 {

  VI128 m = { 0 };

  HLML_INLINEF int2() {}
  HLML_INLINEF int2(i32 x, i32 y) : m(funcs::setXYZW(x, y, consts::snZero, consts::snZero)) {}
  HLML_INLINEF explicit int2(i32 x) : int2(x, x) {}
  HLML_INLINEF explicit int2(const i32 *p) : int2(p[0], p[1]) {}
  HLML_INLINEF explicit int2(VI128 v) : m(v) {}

  HLML_INLINEF void store(i32 *p) const { p[0] = x(); p[1] = y(); }

  HLML_INLINEF void setX(i32 x) { m = inserti(m, x, 0); }
  HLML_INLINEF void setY(i32 y) { m = inserti(m, y, 1); }

  HLML_INLINEF i32 x() const { return extracti(m, 0); }
  HLML_INLINEF i32 y() const { return extracti(m, 1); }

  HLML_INLINEF int2 xx() const { return shufflei2(*this, 0, 0); }
  HLML_INLINEF int2 xy() const { return *this; }
  HLML_INLINEF int2 yx() const { return shufflei2(*this, 1, 0); }
  HLML_INLINEF int2 yy() const { return shufflei2(*this, 1, 1); }

  HLML_INLINEF i32 r() const { return x(); }
  HLML_INLINEF i32 g() const { return y(); }

  HLML_INLINEF int2 rr() const { return xx(); }
  HLML_INLINEF int2 rg() const { return xy(); }
  HLML_INLINEF int2 gr() const { return yx(); }
  HLML_INLINEF int2 gg() const { return yy(); }
};

template<typename T> HLML_INLINEF T   operator+  (T a, i32 b) { return a + T(b); }
template<typename T> HLML_INLINEF T   operator+  (i32 b, T a) { return a + b; }
template<typename T> HLML_INLINEF T&  operator+= (T& a, i32 b) { return a += T(b); }
template<typename T> HLML_INLINEF T   operator-  (T a, i32 b) { return a - T(b); }
template<typename T> HLML_INLINEF T   operator-  (i32 a, T b) { return T(a) - b; }
template<typename T> HLML_INLINEF T&  operator-= (T& a, i32 b) { return a -= T(b); }
template<typename T> HLML_INLINEF T   operator*  (T a, i32 b) { return a * T(b); }
template<typename T> HLML_INLINEF T   operator*  (i32 b, T a) { return a * b; }
template<typename T> HLML_INLINEF T&  operator*= (T& a, i32 b) { return a *= T(b); }

HLML_INLINEF bool2   operator== (int2 a, int2 b) { return bool2(funcs::ftoi(cmpeq(a, b).m)); }
HLML_INLINEF bool2   operator!= (int2 a, int2 b) { return bool2(funcs::ftoi(cmpneq(a, b).m)); }
HLML_INLINEF bool2   operator<  (int2 a, int2 b) { return bool2(funcs::ftoi(cmplt(a, b).m)); }
HLML_INLINEF bool2   operator>  (int2 a, int2 b) { return bool2(funcs::ftoi(cmpgt(a, b).m)); }
HLML_INLINEF bool2   operator<= (int2 a, int2 b) { return bool2(funcs::ftoi(cmple(a, b).m)); }
HLML_INLINEF bool2   operator>= (int2 a, int2 b) { return bool2(funcs::ftoi(cmpge(a, b).m)); }

HLML_INLINEF int2 sumv(int2 v) { v.m = funcs::AhaddB(v.m, v.m);  return v; }
template<typename T> HLML_INLINEF i32 sum(T v) { return sumv(v).x(); }
HLML_INLINEF i32 hmin(int2 v) { return minv(v, shufflei2(v, 1, 0)).x(); }
HLML_INLINEF i32 hmax(int2 v) { return maxv(v, shufflei2(v, 1, 0)).x(); }
}
