// +AMGD       -*-c++-*-
// $Id: scoord.h 4 2012-08-24 02:28:17Z mike $
// file:  scoord.h
// author:  MJ Pfauth, 27 Dec 2003

// Copyright 2003 to 2012 Michael J. Pfauth, mpfauth@hiwaay.net.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef S_COORD_H
#define S_COORD_H

#include <string>

namespace SCoord {

// ECI <--> ECR

    template <typename T>
    void
    makeEciToEcrMatrix (
	const T time,
	T Teci2ecr[3][3]);

    template <typename T>
    void
    makeEcrToEciMatrix (
	const T time,
	T Tecr2eci[3][3]);

    template <typename T>
    void
    posEcrToEci (
	const T Tecr2eci[3][3],
	const T Pecr[3],
	T Peci[3]);

    template <typename T>
    void
    velEciToEcr (
	const T Teci2ecr[3][3],
	const T Peci[3],
	const T Veci[3],
	T Vecr[3]);

    template <typename T>
    void
    velEcrToEci (
	const T Tecr2eci[3][3],
	const T Pecr[3],
	const T Vecr[3],
	T Veci[3]);

    template <typename T>
    void
    accEciToEcr (
	const T Teci2ecr[3][3],
	const T Peci[3],
	const T Veci[3],
	const T Aeci[3],
	T Aecr[3]);

    template <typename T>
    void
    accEcrToEci (
	const T Tecr2eci[3][3],
	const T Pecr[3],
	const T Vecr[3],
	const T Aecr[3],
	T Aeci[3]);


// For the geodetic and spherical conversions, latitude and longitude
// are in radians and altitude in meters.  The order of Plla is latitude,
// longitude, altitude.


// Geodetic LLA <--> ECR, WGS 84 ellipsoid The position transformation
// functions are implemented from equations found in "Geodesy: The
// Concepts", Vanicek and Krakiwsky; Chapter 14, section 4.

    template <typename T>
    void
    posGeodeticToEcr (
	const T Plla[3],
	T Pecr[3]);

    template <typename T>
    void
    posEcrToGeodetic (
	const T Pecr[3],
	T Plla[3]);

// Geodetic velocity is defined thus: 
// Imagine an ENU coordinate system at the given geodetic position.
// Vlla[0] is the bearing in radians from true north, Vlla[1] is the
// magnitude (speed) of the velocity vector in the XY plane and
// Vlla[2] is the magnitude of the velocity in the Z (vertical)
// direction.  Other definitions are possible but this one is common.
    template <typename T>
    void
    velGeodeticToEcr (
	const T Plla[3],
	const T Vlla[3],
	T Vecr[3]);

    template <typename T>
    void
    velEcrToGeodetic (
	const T Vecr[3],
	const T Plla[3],
	T Vlla[3]);

// Geodetic acceleration vector is defined similarly to velocity above.
    template <typename T>
    void
    accGeodeticToEcr (
	const T Plla[3],
	const T Alla[3],
	T Aecr[3]);

    template <typename T>
    void
    accEcrToGeodetic (
	const T Aecr[3],
	const T Plla[3],
	T Alla[3]);

// Spherical earth <--> ECR
// Radius of the earth is assumed to be WGS84::EQUATORIAL_RADIUS,
// altitude is wrt radius of the earth.

    template <typename T>
    void
    posSphereToEcr (
	const T Plla[3],
	T Pecr[3]);

    template <typename T>
    void
    posEcrToSphere (
	const T Pecr[3],
	T Plla[3]);


// Convert geodetic latitude to geocentric latitude.  Note that
// geodetic and geocentric longitude are the same.
    template <typename T>
    T
    getGeocentricLatFromLLA (
	const T Plla[3]);

    template <typename T>
    T
    getGeocentricLatFromEcr (
	const T Pecr[3]);

    template <typename T>
    T
    getGeocentricLongFromEcr (
	const T Pecr[3]);

// ECR <--> ENU
// The transformation matrix requires geodetic latitude and longitude
    template <typename T>
    void
    makeEcrToEnuMatrix (
	const T gd_lat,
	const T gd_long,
	T Tecr2enu[3][3]);

    template <typename T>
    void
    makeEnuToEcrMatrix (
	const T gd_lat,
	const T gd_long,
	T Tenu2ecr[3][3]);

    template <typename T>
    void
    makeEnuToEnuMatrix (
	const T from_gd_lat,
	const T from_gd_long,
	const T to_gd_lat,
	const T to_gd_long,
	T Tenu2enu[3][3]);

// Oenu is the origin of the ENU system in ECR coordinates; ie, the
// origin's ECR position vector.
    template <typename T>
    void
    posEcrToEnu (
	const T Tecr2enu[3][3],
	const T Oenu[3],
	const T Pecr[3],
	T Penu[3]);

    template <typename T>
    void
    posEnuToEcr (
	const T Tenu2ecr[3][3],
	const T Oenu[3],
	const T Penu[3],
	T Pecr[3]);

    template <typename T>
    void
    velEcrToEnu (
	const T Tenu2ecr[3][3],
	const T Vecr[3],
	T Venu[3]);

    template <typename T>
    void
    velEnuToEcr (
	const T Tecr2enu[3][3],
	const T Venu[3],
	T Vecr[3]);

    template <typename T>
    void
    accEcrToEnu (
	const T Tecr2enu[3][3],
	const T Aecr[3],
	T Aenu[3]);


    template <typename T>
    void
    accEnuToEcr (
	const T Tenu2ecr[3][3],
	const T Aenu[3],
	T Aecr[3]);


// ENU <--> REA

// REA position is range in meters, elevation in radians, azimuth in
// radians

// REA velocity is composed of the ENU velocity components in the
// radial, elevation and azimuth directions.  Note that azimuth is
// measured clockwise from North (ie the Y-axis in the ENU XY plane).

// position
    template <typename T>
    void
    posEnuToRea (
	const T Penu[3],
	T Prea[3]);

    template <typename T>
    void
    posReaToEnu (
	const T Prea[3],
	T Penu[3]);

    template <typename T>
    void
    velEnuToRea (
	const T Venu[3],
	const T Prea[3],
	T Vrea[3]);

    template <typename T>
    void
    velReaToEnu (
	const T Prea[3],
	const T Vrea[3],
	T Venu[3]);

    template <typename T>
    void
    accEnuToRea (
	const T Aenu[3],
	const T Prea[3],
	T Area[3]);

    template <typename T>
    void
    accReaToEnu (
	const T Prea[3],
	const T Area[3],
	T Aenu[3]);

} // namespace SCoord

#include "eci_ecr.hpp"
#include "geodetic_ecr.hpp"
#include "sphere_ecr.hpp"
#include "ecr_enu.hpp"
#include "enu_rae.hpp"

#endif
