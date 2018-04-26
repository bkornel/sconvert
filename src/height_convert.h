//-*-c++-*-
// $Id: height_convert.h 4 2012-08-24 02:28:17Z mike $
// file:  height_convert.h
// author:  MJ Pfauth, 5 Dec 2009

// Copyright 2009 Michael J. Pfauth, mpfauth@hiwaay.net.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// If you don't need datum <--> geoid altitude conversion, then you don't need
// this file or the accompanying library archive.

#ifndef _HEIGHT_CONVERT_H_
#define _HEIGHT_CONVERT_H_

namespace SCoord
{
    extern const int SCOORD_NO_ERROR;
    extern const int SCOORD_UNKNOWN_ERROR;

// Init return values
    extern const int SCOORD_INIT_EGM96_NOT_F0UND;
    extern const int SCOORD_INIT_EGM96_READ_ERROR;

// Other return values
    extern const int SCOORD_LIB_NOT_INITIALIZED;
    extern const int SCOORD_LATITUDE_RANGE_ERROR;
    extern const int SCOORD_LONGITUDE_RANGE_ERROR;


// Initialize the height conversion library.  Needed in order to use the
// geodetic datum/ellipsoid <--> geoid/mean sea level altitude conversions.
// Returns SCOORD_NO_ERROR if initialization was successful.  Otherwise
// returns one of the other values.

    int
    Init ();

// Get the string version of an error code.

    const char* const
    GetHeightConversionError (
	const int error_code);

// WGS84 using EGM96 ellipsoid/datum <--> geoid/mean seal level altitude
// conversions.  Borrowed from GeoTrans, which is the main reason these
// functions are not templates.
// Latitude, longitude in radians.  Height in meters. 
// Return value geoid_height or datum_height undefined in case of error.

    int
    HeightDatumToGeoid (
	const double latitude,
	const double longitude,
	const double datum_height,
	double&      geoid_height);

    int
    HeightGeoidToDatum (
	const double latitude,
	const double longitude,
	const double geoid_height,
	double&      datum_height);

} // namespace SCoord

#endif
