#ifndef _SCI_IO_H_
#define _SCI_IO_H_

//#############################################################################
//
//! \file   f2802x_common/include/sci_io.h
//!
//! \brief  Contains public interface to various functions related
//!         to the serial communications interface (SCI) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes

// drivers


// modules


//!
//! \defgroup SCI_IO

//!
//! \ingroup SCI_IO
//@{


#ifdef __cplusplus
extern "C" {
#endif

// the globals


// **************************************************************************
// the function prototypes


int SCI_open(const char * path, unsigned flags, int llv_fd);
int SCI_close(int dev_fd);
int SCI_read(int dev_fd, char * buf, unsigned count);
int SCI_write(int dev_fd, char * buf, unsigned count);
off_t SCI_lseek(int dev_fd, off_t offset, int origin);
int SCI_unlink(const char * path);
int SCI_rename(const char * old_name, const char * new_name);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _SCI_H_ definition

