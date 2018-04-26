// +AMGD
// $Id: height_convert.cpp 4 2012-08-24 02:28:17Z mike $
// file:  height_convert.cpp
// author:  MJ Pfauth, 15 Nov 09

// Copyright 2009 Michael J. Pfauth, mpfauth@hiwaay.net.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include "height_convert.h"
#include "geoid.h"
#include "threads.h"


namespace
{
  static const char* ERROR_STRINGS[] = 
    {"No Error", "egm96.grd not found", "failed to read egm96.grd",
     "library not initialized", "latitude out of range", "longitude out of range", 
     "unknown error"};
}

namespace SCoord
{

  const int SCOORD_NO_ERROR = 0;
  const int SCOORD_INIT_EGM96_NOT_F0UND = 1;
  const int SCOORD_INIT_EGM96_READ_ERROR = 2;
  const int SCOORD_LIB_NOT_INITIALIZED = 3;
  const int SCOORD_LATITUDE_RANGE_ERROR = 4;
  const int SCOORD_LONGITUDE_RANGE_ERROR = 5;
  const int SCOORD_UNKNOWN_ERROR = 6;


  int
  Init ()
  {
    int returnVal;
    long initVal = Initialize_Geoid ();

    if (initVal == GEOID_NO_ERROR)
      returnVal = SCOORD_NO_ERROR;
    else if (initVal == GEOID_FILE_OPEN_ERROR)
      returnVal = SCOORD_INIT_EGM96_NOT_F0UND;
    else if (initVal == SCOORD_INIT_EGM96_READ_ERROR)
      returnVal = SCOORD_INIT_EGM96_READ_ERROR;
    else
      returnVal = SCOORD_UNKNOWN_ERROR;

    return returnVal;

  } // Init

  const char* const
  GetHeightConversionError (
			    const int error_code)
  {
    if (error_code < SCOORD_NO_ERROR || error_code > SCOORD_UNKNOWN_ERROR)
      return "unknown error code";
    else
      return ERROR_STRINGS[error_code];

  } // GetHeightConversionError


  int
  HeightDatumToGeoid (
		      const double latitude,
		      const double longitude,
		      const double datum_height,
		      double&      geoid_height)
  {
    long returnVal = 
      Convert_Ellipsoid_To_Geoid_Height (latitude, longitude, datum_height, 
					 &geoid_height);

    switch (returnVal)
      {
      case GEOID_NO_ERROR:
	return SCOORD_NO_ERROR;
      case GEOID_LAT_ERROR:
	return SCOORD_LATITUDE_RANGE_ERROR;
      case GEOID_LON_ERROR:
	return SCOORD_LONGITUDE_RANGE_ERROR;
      case GEOID_NOT_INITIALIZED_ERROR:
	return SCOORD_LIB_NOT_INITIALIZED;
      default:
	return SCOORD_UNKNOWN_ERROR;
      }

  } // HeightDatumToGeoid

  int
  HeightGeoidToDatum (
		      const double latitude,
		      const double longitude,
		      const double geoid_height,
		      double&      datum_height)
  {
    long returnVal = 
      Convert_Geoid_To_Ellipsoid_Height (latitude, longitude, geoid_height, 
					 &datum_height);

    switch (returnVal)
      {
      case GEOID_NO_ERROR:
	return SCOORD_NO_ERROR;
      case GEOID_LAT_ERROR:
	return SCOORD_LATITUDE_RANGE_ERROR;
      case GEOID_LON_ERROR:
	return SCOORD_LONGITUDE_RANGE_ERROR;
      case GEOID_NOT_INITIALIZED_ERROR:
	return SCOORD_LIB_NOT_INITIALIZED;
      default:
	return SCOORD_UNKNOWN_ERROR;
      }

  } // HeightGeoidToDatum

} // namespace SCoord
