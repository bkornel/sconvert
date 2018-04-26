// +AMGD    -*- c++ -*-
// $Id: sphere_ecr.hpp 4 2012-08-24 02:28:17Z mike $
// file:  sphere_ecr.cpp
// author:  MJ Pfauth, 3 Jan 2004

// Copyright 2003 to 2012 Michael J. Pfauth, mpfauth@hiwaay.net.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "wgs84.h"

#include <cmath>


namespace SCoord {

#ifndef sq
#define sq(a) ((a)*(a))
#endif

  template <typename T>
  void
  posSphereToEcr (
		  const T Plla[3],
		  T Pecr[3])
  {
    T Range = WGS84::EQUATORIAL_RADIUS + Plla[2];
    T cos_lat = cos (Plla[0]);

    Pecr[0] = Range * cos_lat * cos (Plla[1]);
    Pecr[1] = Range * cos_lat * sin (Plla[1]);
    Pecr[2] = Range * sin (Plla[0]);
  }

  template <typename T>
  void
  posEcrToSphere (
		  const T Pecr[3],
		  T Plla[3])
  {
    T X2_Y2 = sq (Pecr[0]) + sq (Pecr[1]);
    T Range_XY = sqrt (X2_Y2);
    T Range_XYZ = sqrt (X2_Y2 + sq (Pecr[2]));

    Plla[0] = asin (Pecr[2] / Range_XY);
    Plla[1] = atan2 (Pecr[1], Pecr[0]);
    Plla[2] = Range_XYZ - WGS84::EQUATORIAL_RADIUS;
  }


} // namespace SCoord

