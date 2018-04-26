// +AMGD   -*- c++ -*-
// $Id: enu_rae.hpp 4 2012-08-24 02:28:17Z mike $
// file:  enu_rae.cpp
// author:  MJ Pfauth, 27 Dec 2003

// Copyright 2003 to 2009  Michael J. Pfauth, mpfauth@hiwaay.net.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cmath>

namespace SCoord {

#ifndef sq
#define sq(a) ((a) * (a))
#endif

  template <typename T>
  void
  posEnuToRea (
	       const T Penu[3],
	       T Prae[3])
  {
    Prae[2] = atan2 (Penu[0], Penu[1]);

    T XYsquare = sq(Penu[0]) + sq(Penu[1]);
    Prae[1] = atan2 (Penu[2], sqrt (XYsquare));

    Prae[0] = sqrt (XYsquare + sq(Penu[2]));

  } // posEnuToRea

  template <typename T>
  void
  posReaToEnu (
	       const T Prae[3],
	       T Penu[3])
  {
    T cosAz = cos (Prae[2]);
    T sinAz = sin (Prae[2]);
    T cosEl = cos (Prae[1]);
    T sinEl = sin (Prae[1]);

    Penu[0] = Prae[0] * cosEl * sinAz;
    Penu[1] = Prae[0] * cosEl * cosAz;
    Penu[2] = Prae[0] * sinEl;

  } // posReaToEnu


  template <typename T>
  void
  velEnuToRea (
	       const T Venu[3],
	       const T Prea[3],
	       T Vrea[3])
  {
    T cos_el = cos (Prea[1]);
    T sin_el = sin (Prea[1]);
    T cos_az = cos (Prea[2]);
    T sin_az = sin (Prea[2]);

    Vrea[0] = cos_el * sin_az * Venu[0] + cos_el * cos_az * Venu[1] +
      sin_el * Venu[2];
    Vrea[1] = -sin_el * sin_az * Venu[0] - sin_el * cos_az * Venu[1] +
      cos_el * Venu[2];
    Vrea[2] = cos_az * Venu[0] - sin_az * Venu[1];

  } // velEnuToRea


  template <typename T>
  void
  accEnuToRea (
	       const T Aenu[3],
	       const T Prea[3],
	       T Area[3])
  {
    T cos_el = cos (Prea[1]);
    T sin_el = sin (Prea[1]);
    T cos_az = cos (Prea[2]);
    T sin_az = sin (Prea[2]);

    Area[0] = cos_el * sin_az * Aenu[0] + cos_el * cos_az * Aenu[1] +
      sin_el * Aenu[2];
    Area[1] = -sin_el * sin_az * Aenu[0] - sin_el * cos_az * Aenu[1] +
      cos_el * Aenu[2];
    Area[2] = cos_az * Aenu[0] - sin_az * Aenu[1];

  } // accEnuToRea


  template <typename T>
  void
  velReaToEnu (
	       const T Prea[3],
	       const T Vrea[3],
	       T Venu[3])
  {
    T cos_el = cos (Prea[1]);
    T sin_el = sin (Prea[1]);
    T cos_az = cos (Prea[2]);
    T sin_az = sin (Prea[2]);

    Venu[0] = cos_el * sin_az * Vrea[0] - sin_el * sin_az * Vrea[1] + cos_az * Vrea[2];
    Venu[1] = cos_el * cos_az * Vrea[0] - sin_el * cos_az * Vrea[1] - sin_az * Vrea[2];
    Venu[2] = sin_el * Vrea[0] + cos_el * Vrea[1];

  } // velReaToEnu


  template <typename T>
  void
  accReaToEnu (
	       const T Prea[3],
	       const T Area[3],
	       T Aenu[3])
  {
    T cos_el = cos (Prea[1]);
    T sin_el = sin (Prea[1]);
    T cos_az = cos (Prea[2]);
    T sin_az = sin (Prea[2]);

    Aenu[0] = cos_el * sin_az * Area[0] - sin_el * sin_az * Area[1] + cos_az * Area[2];
    Aenu[1] = cos_el * cos_az * Area[0] - sin_el * cos_az * Area[1] - sin_az * Area[2];
    Aenu[2] = sin_el * Area[0] + cos_el * Area[1];

  } // accReaToEnu

} // namespace SCoord
