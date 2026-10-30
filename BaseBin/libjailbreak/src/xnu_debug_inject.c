#include "xnu_debug_inject.h"
#include "info.h"
#include <mach/mach.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

static int g_verbose_level = XNU_DEBUG_VERBOSE_NONE;

void xnu_debug_set_verbose_level(int level) {
    g_verbose_level = level;
    if (level >= XNU_DEBUG_VERBOSE_FULL) {
        printf("[XNU_DEBUG][INIT] Extended verbose mode ENABLED (level=%d)\n", level);
        printf("[XNU_DEBUG][INIT] Full XNU injection logging active\n");
    }
}

int xnu_debug_get_verbose_level(void) {
    return g_verbose_level;
}

int xnu_debug_inject_with_log(uint64_t target_addr, const void *payload, size_t payload_size, const char *exploit_name) {
    XNU_LOG_INJECT("=== XNU INJECT START === exploit=%s addr=0x%llx size=%zu\n",
                    exploit_name ? exploit_name : "unknown", (unsigned long long)target_addr, payload_size);
    
    if (g_verbose_level >= XNU_DEBUG_VERBOSE_XNU_INJECT) {
        printf("[XNU_DEBUG][INJECT][DETAIL] Payload bytes (first 32): \n");
        const unsigned char *bytes = (const unsigned char *)payload;
        for (size_t i = 0; i < payload_size && i < 32; i++) {
            printf("[XNU_DEBUG][INJECT][DETAIL]  %02x", bytes[i]);
        }
        printf("\n");
        printf("[XNU_DEBUG][INJECT][DETAIL] Target kernel address mapped at 0x%llx\n",
               (unsigned long long)target_addr);
        printf("[XNU_DEBUG][INJECT][DETAIL] Kernel info struct initialized: %s\n",
               gSystemInfo.kernelConstant.base ? "yes" : "no");
    }
    
    // In a real jailbreak, this would perform the actual kernel write/injection
    // Here we log the full injection attempt for debugging
    printf("[XNU_DEBUG][INJECT][RESULT] Injection attempt completed (simulated/logged) for %s\n",
           exploit_name ? exploit_name : "unknown");
    
    XNU_LOG_INJECT("=== XNU INJECT END ===\n");
    return 0;
}

void xnu_debug_log_kernel_state(const char *context) {
    printf("[XNU_DEBUG][KERNEL_STATE] Context: %s\n", context ? context : "unknown");
    printf("[XNU_DEBUG][KERNEL_STATE] Kernel base: 0x%llx\n", (unsigned long long)gSystemInfo.kernelConstant.base);
    printf("[XNU_DEBUG][KERNEL_STATE] Phys base: 0x%llx\n", (unsigned long long)gSystemInfo.kernelConstant.physBase);
    printf("[XNU_DEBUG][KERNEL_STATE] Slide: 0x%llx\n", (unsigned long long)gSystemInfo.kernelConstant.slide);
    printf("[XNU_DEBUG][KERNEL_STATE] Verbose level: %d\n", g_verbose_level);
}
