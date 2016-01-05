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

#include <SLFS.h>

SLFS SerFlash;

SLFS::SLFS(void)
{
    filehandle = 0;
    filesize = 0;
    offset = 0;
    retval = SL_FS_OK;
    is_write = false;
    _readBytesInstance = NULL;
}

void SLFS::begin(void)
{
    WiFi.init();
}

void SLFS::end(void)
{
}

int32_t SLFS::open(const uint8_t *filename, int32_t mode)
{
    SlFsFileInfo_t finfo;

    if (filehandle) {
        retval = SLFS_LIB_ERR_FILE_ALREADY_OPEN;
        return retval;
    }

    retval = sl_FsOpen((unsigned char*)filename, mode, NULL, &filehandle);
    if (retval != SL_FS_OK)
        return retval;

    offset = 0;
    filesize = 0;
    if (mode == FS_MODE_OPEN_READ) {
        is_write = false;

        // Discover actual filesize
        retval = sl_FsGetInfo((unsigned char*)filename, 0, &finfo);
        if (retval != SL_FS_OK) {
            sl_FsClose(filehandle, NULL, NULL, 0);
            filehandle = 0;
            return retval;
        }
        filesize = finfo.FileLen;
    } else {
        is_write = true;

        // Discover maximum file size, store in 'filesize' so we know when to reject writes.
        retval = sl_FsGetInfo((unsigned char*)filename, 0, &finfo);
        if (retval != SL_FS_OK) {
            sl_FsClose(filehandle, NULL, NULL, 0);
            filehandle = 0;
            return retval;
        }
        filesize = finfo.AllocatedLen;
    }

    return retval;
}

int32_t SLFS::open(const char *filename, int32_t mode)
{
    return open((const uint8_t *)filename, mode);
}

int32_t SLFS::open(String filename, int32_t mode)
{
    const char *cfn = filename.c_str();
    return open((const uint8_t *)cfn, mode);
}

int32_t SLFS::close(void)
{
    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return retval;
    }
    
    offset = 0;
    filesize = 0;
    retval = sl_FsClose(filehandle, NULL, NULL, 0);
    filehandle = 0;
    is_write = false;

    return retval;
}

int32_t SLFS::seek(int32_t pos)
{
    retval = SL_FS_OK;

    if (pos >= 0 && pos <= filesize) {
        offset = pos;
        return SL_FS_OK;
    }
    retval = SLFS_LIB_ERR_OFFSET_OUT_OF_BOUNDS;
    return retval;
}

size_t SLFS::size(void)
{
    return (size_t)filesize;
}

int32_t SLFS::lastError(void)
{
    return retval;
}

const char * SLFS::lastErrorString(void)
{
    return getErrorString(retval);
}

int SLFS::available(void)
{
    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return false;
    }
    if (is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE;
        return false;  // Makes no sense when open in "write" mode
    }
    if (offset < filesize)
        return true;
    return false;
}

int SLFS::peek(void)
{
    uint8_t buf[4];

    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return (int)retval;
    }
    if (is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE;
        return (int)retval;
    }
    
    if (offset == filesize)
        return -1;
    
    retval = sl_FsRead(filehandle, offset, buf, 1);
    if (retval != 1) {
        return -1;
    }
    return (int)buf[0];
}

int SLFS::read(void)
{
    uint8_t buf[4];

    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return (int)retval;
    }
    if (is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE;
        return (int)retval;
    }
    
    if (offset == filesize)
        return -1;
    
    retval = sl_FsRead(filehandle, offset, buf, 1);
    if (retval != 1) {
        return -1;
    }
    offset++;
    return (int)buf[0];
}

size_t SLFS::readBytes(void *buffer, size_t len)
{
    unsigned char *cbuf = (unsigned char *)buffer;

    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return 0;
    }
    if (is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE;
        return 0;
    }
    
    if (offset == filesize)
        return 0;
    
    retval = sl_FsRead(filehandle, offset, cbuf, len);
    if (retval < 0)
        return 0;
    offset += retval;
    return retval;
}

String SLFS::readBytes(size_t maxlen)
{
    char *sh = NULL;
    size_t len;

    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return String("");
    }
    if (is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE;
        return String("");
    }
    
    if (offset == filesize)
        return String("");

    len = filesize-offset;
    if (len > maxlen)
        len = maxlen;

    // Free up some memory before allocating our next buffer
    if (_readBytesInstance != NULL) {
        delete _readBytesInstance;  // Execute String's destructor, freeing the buffer in the process
        _readBytesInstance = NULL;
    }

    // Allocate suitable buffer space to hold the file contents
    sh = (char *) malloc(len+1);
    sh[len] = '\0';
    
    retval = sl_FsRead(filehandle, offset, (uint8_t *)sh, len);
    if (retval < 0) {
        free(sh);
        return String("");
    }
    offset += retval;

    // Allocate a new String instance to hold the contents (which is strcpy'd by String's constructor)
    _readBytesInstance = new String(sh);
    free(sh);  // Creating a new String performs a strcpy, so 'sh' is no longer needed.
    return *_readBytesInstance;  // Caller will usually assign this to another String object, triggering yet another strcpy.
}

void SLFS::freeString(void)
{
    if (_readBytesInstance != NULL)
        delete _readBytesInstance;  // Execute String's destructor, freeing the buffer in the process
    _readBytesInstance = NULL;
}

void SLFS::flush(void)
{
    return;
}

size_t SLFS::write(uint8_t c)
{
    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return 0;
    }
    if (!is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_READ;
        return 0;
    }
    
    if (offset > filesize)
        return 0;

    retval = sl_FsWrite(filehandle, offset, &c, 1);
    if (retval < 1) {
        return 0;
    }
    offset++;
    return 1;
}

size_t SLFS::write(const uint8_t *buffer, size_t len)
{
    if (!filehandle) {
        retval = SLFS_LIB_ERR_FILE_NOT_OPEN;
        return 0;
    }
    if (!is_write) {
        retval = SLFS_LIB_ERR_FILE_OPEN_FOR_READ;
        return 0;
    }
    
    if (offset > filesize)
        return 0;

    retval = sl_FsWrite(filehandle, offset, (unsigned char *)buffer, len);
    if (retval < 0) {
        return 0;
    }
    offset += retval;
    return retval;
}

size_t SLFS::write(const void *a, size_t b)
{
    return write((const uint8_t *)a, b);
}

size_t SLFS::write(String s)
{
    return write((const uint8_t *)s.c_str(), s.length());
}

SLFS::operator bool()
{
    if (filehandle)
        return true;
    return false;
}

int32_t SLFS::del(const uint8_t *filename)
{
    if (filehandle) {
        retval = SLFS_LIB_ERR_FILE_ALREADY_OPEN;
        return retval;  // In case the file we have open is the one the user is trying to delete...
    }
    
    retval = sl_FsDel((unsigned char*)filename, 0);
    if (retval != SL_FS_OK)
        return retval;
    return retval;
}

int32_t SLFS::del(const char *filename)
{
    return del((const uint8_t *)filename);
}

int32_t SLFS::del(String filename)
{
    const char *cfn = filename.c_str();
    return del((const uint8_t *)cfn);
}

/* SimpleLink API error codes with string representations */

typedef struct {
    const char *name;
    const int32_t id;
} SLerrorCode;

const SLerrorCode simplelink_errorcode_fs[] = {
    {"SL_FS_OK", 0},
    {"SL_FS_ERR_EMPTY_SFLASH", -67},
    {"SL_FS_ERR_FILE_IS_NOT_SECURE_AND_SIGN", -66},
    {"SL_FS_ERASING_FLASH", -65},
    {"SL_FS_FILE_HAS_NOT_BEEN_CLOSE_CORRECTLY", -64},
    {"SL_FS_WRONG_SIGNATURE", -63},
    {"SL_FS_WRONG_SIGNATURE_OR_CERTIFIC_NAME_LENGTH", -62},
    {"SL_FS_NOT_16_ALIGNED", -61},
    {"SL_FS_CERT_CHAIN_ERROR", -60},
    {"SL_FS_FILE_NAME_EXIST", -59},
    {"SL_FS_SECURITY_BUF_ALREADY_ALLOC", -58},
    {"SL_FS_SECURE_FILE_MUST_BE_COMMIT", -57},
    {"SL_FS_ERR_INCORRECT_OFFSET_ALIGNMENT", -56},
    {"SL_FS_ERR_FAILED_READ_NVMEM_HEADER", -55},
    {"SL_FS_WRONG_FILE_NAME", -54},
    {"SL_FS_FILE_SYSTEM_IS_LOCKED", -53},
    {"SL_FS_SECURITY_ALLERT", -52},
    {"SL_FS_FILE_UNVALID_FILE_SIZE", -51},
    {"SL_FS_ERR_TOKEN_IS_NOT_VALID", -50},
    {"SL_FS_NO_DEVICE_IS_LOADED", -49},
    {"SL_FS_DATA_ADDRESS_SHOUD_BE_IN_DATA_RAM", -48},
    {"SL_FS_DATA_IS_NOT_ALIGNED", -47},
    {"SL_FS_ERR_OVERLAP_DETECTION_THRESHHOLD", -46},
    {"SL_FS_FILE_HAS_RESERVED_NV_INDEX", -45},
    {"SL_FS_ERR_MAX_FS_FILES_IS_LARGER", -44},
    {"SL_FS_ERR_MAX_FS_FILES_IS_SMALLER", -43},
    {"SL_FS_FILE_MAX_SIZE_EXCEEDED", -42},
    {"SL_FS_INVALID_BUFFER_FOR_READ", -41},
    {"SL_FS_INVALID_BUFFER_FOR_WRITE", -40},
    {"SL_FS_ERR_FILE_IMAGE_IS_CORRUPTED", -39},
    {"SL_FS_ERR_SIZE_OF_FILE_EXT_EXCEEDED", -38},
    {"SL_FS_WARNING_FILE_NAME_NOT_KEPT", -37},
    {"SL_FS_ERR_DEVICE_IS_NOT_FORMATTED", -36},
    {"SL_FS_ERR_FAILED_WRITE_NVMEM_HEADER", -35},
    {"SL_FS_ERR_NO_AVAILABLE_NV_INDEX", -34},
    {"SL_FS_ERR_FAILED_TO_ALLOCATE_MEM", -33},
    {"SL_FS_ERR_FAILED_TO_READ_INTEGRITY_HEADER_2", -32},
    {"SL_FS_ERR_FAILED_TO_READ_INTEGRITY_HEADER_1", -31},
    {"SL_FS_ERR_NO_AVAILABLE_BLOCKS", -30},
    {"SL_FS_ERR_FILE_MAX_SIZE_BIGGER_THAN_EXISTING_FILE", -29},
    {"SL_FS_ERR_FILE_EXISTS_ON_DIFFERENT_DEVICE_ID", -28},
    {"SL_FS_ERR_INVALID_ACCESS_TYPE", -27},
    {"SL_FS_ERR_FILE_ALREADY_EXISTS", -26},
    {"SL_FS_ERR_PROGRAM", -25},
    {"SL_FS_ERR_NO_ENTRIES_AVAILABLE", -24},
    {"SL_FS_ERR_FILE_ACCESS_IS_DIFFERENT", -23},
    {"SL_FS_ERR_BAD_FILE_MODE", -22},
    {"SL_FS_ERR_FAILED_READ_NVFILE", -21},
    {"SL_FS_ERR_FAILED_INIT_STORAGE", -20},
    {"SL_FS_ERR_CONTINUE_WRITE_MUST_BE_MOD_4", -19},
    {"SL_FS_ERR_FAILED_LOAD_FILE", -18},
    {"SL_FS_ERR_INVALID_HANDLE", -17},
    {"SL_FS_ERR_FAILED_TO_WRITE", -16},
    {"SL_FS_ERR_OFFSET_OUT_OF_RANGE", -15},
    {"SL_FS_ERR_ALLOC", -14},
    {"SL_FS_ERR_READ_DATA_LENGTH", -13},
    {"SL_FS_ERR_INVALID_FILE_ID", -12},
    {"SL_FS_ERR_FILE_NOT_EXISTS", -11},
    {"SL_FS_ERR_EMPTY_ERROR", -10},
    {"SL_FS_ERR_INVALID_ARGS", -9},
    {"SL_FS_ERR_FAILED_TO_CREATE_FILE", -8},
    {"SL_FS_ERR_FS_ALREADY_LOADED", -7},
    {"SL_FS_ERR_UNKNOWN", -6},
    {"SL_FS_ERR_FAILED_TO_CREATE_LOCK_OBJ", -5},
    {"SL_FS_ERR_DEVICE_NOT_LOADED", -4},
    {"SL_FS_ERR_INVALID_MAGIC_NUM", -3},
    {"SL_FS_ERR_FAILED_TO_READ", -2},
    {"SL_FS_ERR_NOT_SUPPORTED", -1},
    {"SLFS_LIB_ERR_FILE_NOT_OPEN", SLFS_LIB_ERR_FILE_NOT_OPEN},
    {"SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE", SLFS_LIB_ERR_FILE_OPEN_FOR_WRITE},
    {"SLFS_LIB_ERR_FILE_OPEN_FOR_READ", SLFS_LIB_ERR_FILE_OPEN_FOR_READ},
    {"SLFS_LIB_ERR_FILE_ALREADY_OPEN", SLFS_LIB_ERR_FILE_ALREADY_OPEN},
    {NULL, 0}
};

const char * SLFS::getErrorString(const int32_t code)
{
    SLerrorCode *cptr = NULL;
    int i=0;

    cptr = (SLerrorCode *)&simplelink_errorcode_fs[i];
    while (cptr->name != NULL && cptr->id != code) {
        i++;
        cptr = (SLerrorCode *)&simplelink_errorcode_fs[i];
    }
    if (cptr->name == NULL)
        return "ERR_UNKNOWN";
    return cptr->name;
}
