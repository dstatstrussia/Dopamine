#ifndef XNU_DEBUG_INJECT_H
#define XNU_DEBUG_INJECT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Verbose mode levels
#define XNU_DEBUG_VERBOSE_NONE     0
#define XNU_DEBUG_VERBOSE_BASIC    1
#define XNU_DEBUG_VERBOSE_FULL     2
#define XNU_DEBUG_VERBOSE_XNU_INJECT 3

// Enable extended debug verbose mode for exploit analysis
void xnu_debug_set_verbose_level(int level);
int xnu_debug_get_verbose_level(void);

// Log injection into XNU kernel memory / registers
// This performs the "full injection" with logging for debugging
int xnu_debug_inject_with_log(uint64_t target_addr, const void *payload, size_t payload_size, const char *exploit_name);

// Log kernel state for diagnostics
void xnu_debug_log_kernel_state(const char *context);

// Verbose logging macro
#define XNU_LOG_VERBOSE(fmt, ...) do { \
    if (xnu_debug_get_verbose_level() >= XNU_DEBUG_VERBOSE_FULL) { \
        printf("[XNU_DEBUG][VERBOSE] %s:%d " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
    } \
} while(0)

#define XNU_LOG_INJECT(fmt, ...) do { \
    if (xnu_debug_get_verbose_level() >= XNU_DEBUG_VERBOSE_XNU_INJECT) { \
        printf("[XNU_DEBUG][INJECT] %s:%d " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
    } \
} while(0)

#endif
