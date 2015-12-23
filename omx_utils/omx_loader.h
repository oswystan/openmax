/*
 **************************************************************************************
 *       Filename:  omx_loader.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 00:17:04
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_LOADER_H_INCLUDED
#define OMX_LOADER_H_INCLUDED

#define OMX_LIBNAME_MAX 128

class OmxLoader
{
public:
    OmxLoader();
    ~OmxLoader();

    int loadIt(const char* name);
    int unloadIt();

    const char* getName()
    {
        return libName;
    }

    void* queryInterface(unsigned int interfaceID);

private:
    void* handle;
    char  libName[OMX_LIBNAME_MAX];
};

#endif /*OMX_LOADER_H_INCLUDED*/

/********************************* END ***********************************************/

