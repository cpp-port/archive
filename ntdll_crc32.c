#include <windows.h>
#pragma comment(lib, "ntdll.lib")
// Function prototype matching the Windows Native API implementation
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllimport) ULONG NTAPI RtlComputeCrc32(ULONG InitialCrc, const BYTE *Buffer, INT Length);
#ifdef __cplusplus
}
#endif

// A simple wrapper to match standard crc32(crc, buf, len) signatures
unsigned long msvc_crc32(unsigned long crc, const unsigned char *buf, size_t len)
{
   return RtlComputeCrc32(crc, buf, (INT)len);
}


unsigned long __archive_crc32(unsigned long crc, const void * _p, size_t len)
{ 
   return msvc_crc32(crc, _p, len);
}