/*
 * Copyright (C) 2015    Raphaël Beamonte <raphael.beamonte@polymtl.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation  and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of any
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * This file has been created for the purpose of the INF1010
 * course of École Polytechnique de Montréal.
 */

#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	Point();
	Point(const double& x = 0, const double& y = 0,const double& z = 0);

	/**
	 * @brief getX To get the value of x coordinate
	 * @return The value of x coordinate
	 */
	double getX() const;
	/**
	 * @brief getY To get the value of y coordinate
	 * @return The value of y coordinate
	 */
	double getY() const;
	/**
	 * @brief getZ To get the value of z coordinate
	 * @return The value of z coordinate
	 */
	double getZ() const;

	/**
	 * @brief move To move the Point
	 * @param dx Value to add to x coordinate
	 * @param dy Value to add to y coordinate
	 * @param dz Value to add to z coordinate
	 */
	void move(const double& dx,const  double& dy, const double& dz);

	/**
	 * @brief reset To reset the coordinates of the Point
	 */
	void reset();

	/**
	 * @brief print To print the coordinates of the Point on the standard output
	 */
	void print() const;

private:
	/**
	 * @brief x_ To store the value of the x coordinate
	 */
	double x_;
	/**
	 * @brief y_ To store the value of the y coordinate
	 */
	double y_;
	/**
	 * @brief z_ To store the value of the z coordinate
	 */
	double z_;

};
#endif // _POINT_H_