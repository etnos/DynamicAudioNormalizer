//////////////////////////////////////////////////////////////////////////////////
// Dynamic Audio Normalizer - Audio Processing Utility
// Copyright (c) 2015 LoRd_MuldeR <mulder2@gmx.de>. Some rights reserved.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// http://www.gnu.org/licenses/gpl-2.0.txt
//////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>
#include "Platform.h"

class AudioIO
{
public:
	AudioIO(void) {};
	virtual ~AudioIO(void) {}

	//Functions implemented in derived classes
	virtual bool openRd(const CHR *const fileName, const uint32_t channels, const uint32_t sampleRate, const uint32_t bitDepth) = 0;
	virtual bool openWr(const CHR *const fileName, const uint32_t channels, const uint32_t sampleRate, const uint32_t bitDepth) = 0;
	virtual int64_t read(double **buffer, const int64_t count) = 0;
	virtual int64_t write(double *const *buffer, const int64_t count) = 0;
	virtual bool close(void) = 0;
	virtual bool queryInfo(uint32_t &channels, uint32_t &sampleRate, int64_t &length, uint32_t &bitDepth) = 0;
	virtual void getFormatInfo(CHR *buffer, const uint32_t buffSize) = 0;
	
private:
	AudioIO &operator=(const AudioIO &) { throw 666; }
};
