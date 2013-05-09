// The author(s) disclaim copyright to this source-code.
// Can be licensed under MIT (in case the public domain is not recognized).
// More information can be found in the LICENSE file.

#ifndef _FOUNDATION_ASSERT_H_
#define _FOUNDATION_ASSERT_H_

// Provides a more powerful assertion macro that provides contextual information
// like what code failed, on what line, in which file, and why.

#include <foundation/detect.h>
#include <foundation/compat.h>
#include <foundation/config.h>
#include <foundation/logger.h>

#if defined(_DEBUG)
  #define assertf( _Condition, _Format, ... ) \
    do { if (!(_Condition)) { foundation::log(_Format, ##__VA_ARGS__); raise(SIGABRT); } } while (0, 0)
#else
  #define assertf( _Condition, _Format, ... ) \
    do { (void)sizeof(_Condition); } while(0, 0)
#endif

#ifdef assert
  #undef assert
#endif

#define assert( _Condition ) \
  assertf(_Condition, \
    "An assertion failed:\n" \
    "\n" \
    "  `%s`\n" \
    "    in `%s` on line %u\n\n", \
    __foundation_stringify(_Condition), \
    __foundation_stringify(__FILE__), __LINE__ \
  )

#endif // _FOUNDATION_ASSERT_H_
