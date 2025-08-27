#ifndef MYLIB_H
#define MYLIB_H

#ifdef _WIN32
  #ifdef MYLIB_EXPORTS
    #define MYLIB_API __declspec(dllexport)
  #else
    #define MYLIB_API __declspec(dllimport)
  #endif
#else
  #define MYLIB_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

MYLIB_API int add_numbers(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
