/* SimpleLink API - Filesystem
 * Supports the CC3100/CC3200 SimpleLink Serial Flash API
 * Tested on TI CC3200 LaunchPad
 *
 * Written by Eric Brundick for the Energia project
 * Copyright (C) 2014 Eric Brundick <spirilis at linux dot com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef SLFS_H
#define SLFS_H

#include <Energia.h>
#include <WiFi.h>

class SLFS : public Stream {
	private:
		int32_t filehandle;
		int32_t filesize, offset;
		int32_t retval;
		boolean is_write;

		const char * getSlErrorCode(int32_t);
		
	public:
		SLFS();
		void begin(void);
		void end(void);
		int open(const uint8_t *filename, int32_t mode);
		int open(const char *filename, int32_t mode) {return open((const uint8_t *)filename, mode); };
		int close(void);
		int del(const uint8_t *filename);
		int del(const char *filename) { return del((const uint8_t *)filename); };

		int32_t lastError(void);
		const char *lastErrorString(void);

		virtual int available(void);
		virtual int peek(void);
		virtual int read(void);
		size_t readBytes(char *, size_t);
		virtual void flush(void) { return; };
		virtual size_t write(uint8_t c);
		virtual size_t write(const uint8_t *, size_t);
		operator bool();
		using Print::write;
};

extern SLFS SerFlash;

#endif /* SLFS_H */
