/*********************************************************************************
*
* Copyright (C) 2014 by TH-Nürnberg
* Written by Christian Merkl <christian.merkl@th-nuernberg.de>
* All Rights Reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*********************************************************************************/
#ifndef ___POINT_CLOUD_H___
#define ___POINT_CLOUD_H___

#include <cstdlib>
#include <vector>
#include <Eigen/StdVector>

#include "obcore/base/Point.h"

namespace obvious {

template <typename PointT>
class PointCloud
{
public:
    PointCloud(const std::size_t size = 0);

    typedef std::vector<PointT, Eigen::aligned_allocator<PointT> > vector;
    typedef typename vector::iterator iterator;
    typedef typename vector::const_iterator const_iterator;

    inline iterator begin(void) { return _points.begin(); }
    inline const_iterator begin(void) const { return _points.begin(); }
    inline PointT& operator[](const unsigned int index) { return _points[index]; }
    inline const PointT& operator[](const unsigned int index) const { return _points[index]; }

private:
    vector _points;
};

template class PointCloud<Point>;

} // end namespace obvious

#endif
