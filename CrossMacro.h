//This header can help with transfering windows-msvc-project to linux-gcc.
//It has some msvc typedefs/functions and their equivalents in linux-gcc.
//But not all defined functions do same as their msvc equivalents.
//So you need to read their descriptions before using.
//But this header can save some time =)

#ifndef CROSSMACRO_H
#define CROSSMACRO_H

#ifdef __linux__ //LINUX with gcc

#define SLASH '/'
#define SLASHSTR "/"

#define sprintf_s snprintf
#define swprintf_s swprintf
#define stricmp strcasecmp
#define strnicmp strncasecmp
#define _stricmp strcasecmp
#define _strcmpi strcasecmp
#define _strnicmp strncasecmp
#define _wcsnicmp wcsncasecmp
#define StringCchPrintf snprintf
#define StringCchPrintfW swprintf
#define lstrcmpA strcmp
#define lstrcmpW wcscmp
#define lstrcmp strcmp
#define lstrlen strlen
#define lstrcmpiA stricmp
#define lstrcmpiW wcscasecmp
#define StrStrIA strstr
#define StrStrIW wcsstr
#define StringCchVPrintf vsnprintf
#define memcpy_s(dist,dist_c, src, src_c) memcpy(dist,src,src_c)
//#define localtime_s(tm, time) (*tm)=localtime(time)
#define strtok_s(str,delim,contex) strtok(str,delim)
#define localtime_s(tm, time) localtime_r(time, tm)
#define asctime_s(chr,sz,tm) asctime_r(tm,chr)
typedef  char* LPSTR;
typedef  const char* LPCSTR;
typedef  wchar_t* LPWSTR;
typedef const wchar_t* LPCWSTR;

#define _istdigit isdigit


#ifdef UNICODE
typedef LPWSTR LPTSTR;
typedef LPCWSTR LPCTSTR;

typedef wchar_t TCHAR;

#define _tcslen wcslen
#define _tcscmp wcsmp
#define _ttoi _wtoi
#else
typedef LPSTR LPTSTR;
typedef LPCSTR LPCTSTR;

typedef char TCHAR;
#define _tcslen strlen
#define _tcscmp strcmp
#define _ttoi atoi
#endif



#define SUCCEEDED(hr)   (((long)(hr)) >= 0)
#define FAILED(hr)      (((long)(hr)) < 0)

typedef unsigned long       DWORD;
typedef uint32_t* LPDWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef const void      *LPCVOID;
typedef void  *LPVOID;
typedef DWORD COLORREF;
typedef unsigned int UINT;

typedef __int8_t __int8;
typedef __int16_t __int16;
typedef __int32_t __int32;
typedef __int64_t __int64;
//custom
typedef __uint32_t uint32;
typedef __uint64_t uint64;
//

#define _atoi64(ch) strtoll(ch,nullptr,0)
#define _wtoi64(wch) wcstoll(wch,nullptr,0)
#define _wtoi(wch) wcstol(wch,nullptr,0)
#define _strtoui64(ch,ptr,base) strtoull(ch,ptr,base)
#define _wcstoui64(ch,ptr,base) wcstoull(ch,ptr,base)

#define InterlockedExchange(data,new_val) __sync_lock_test_and_set(data,new_val)
#define InterlockedCompareExchange(ptr,new_value,old_value) __sync_val_compare_and_swap(ptr, old_value, new_value)
#define InterlockedIncrement(ptr) __sync_add_and_fetch(ptr,1)

//#define __debugbreak()

#define IMPORT_TYPE
#define EXPORT_TYPE

#define MAX_PATH PATH_MAX
#define _MAX_PATH PATH_MAX

typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef wchar_t WCHAR;
typedef unsigned char byte;
typedef LONG *PLONG;
#define TRUE 1
#define FALSE 0

//#define RGB(r,g,b)  ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

typedef WCHAR OLECHAR;
typedef OLECHAR *LPOLESTR;

typedef __int64 LONG_PTR, *PLONG_PTR;
#define LRESULT     LONG_PTR

#define _ASSERTE(arg)
//#define CONFIRM(arg)

#define CopyMemory memcpy

#define _alloca alloca
#define _isnan __isnan
#define _finite finite


#define __declspec(arg)
#define __stdcall

#define ZeroMemory(p, sz) memset((p), 0, (sz))
#define FillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))

typedef struct { //from VS math.h
	double x,y; /* real and imaginary parts */
} _complex;

#define offsetof(s,m)   (size_t)&reinterpret_cast<const volatile char&>((((s *)0)->m))
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL

#ifdef _UNICODE
#define T(x) L##x
#else
#define _T(x) x
#endif


#ifdef  UNICODE
#define __TEXT(quote) L##quote
#else   /* UNICODE */
#define __TEXT(quote) quote
#endif /* UNICODE */
#define TEXT(quote) __TEXT(quote)

#define vsnprintf_s(buff,size,count, format,list) vsnprintf(buff,size,format,list)
#define _itoa_s(val,str,size,ten) sprintf(str,"%d",val) //for decimal only


#define INFINITE            0xFFFFFFFF

#define _NOEXCEPT _GLIBCXX_USE_NOEXCEPT

#define Sleep(ms) usleep(ms*1000)

typedef __int64_t LONGLONG;
typedef __uint64_t ULONGLONG;

typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG HighPart;
	};
	struct {
		DWORD LowPart;
		LONG HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER;

#define makedir(dir,Xflag) mkdir(dir,Xflag)

typedef void* HINSTANCE;

inline int _vscprintf (const char * format, va_list pargs)
{
   int retval;
   va_list argcopy;
   va_copy(argcopy, pargs);
   retval = vsnprintf(NULL, 0, format, argcopy);
   va_end(argcopy);
   return retval;
}

#elif _WIN32 //WINDOWS with msvc

#define SLASH '\\'
#define SLASHSTR "\\"
typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;

#define makedir(dir,Xflag) _mkdir(dir)

#endif //CROSSMACRO_H

