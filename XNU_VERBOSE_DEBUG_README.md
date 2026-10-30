# Full Injection into XNU with Extended Verbose Logging

## Activation
Enable via code or configuration:
```
xnu_debug_set_verbose_level(XNU_DEBUG_VERBOSE_XNU_INJECT);
```

## Components
- `BaseBin/libjailbreak/src/xnu_debug_inject.h` / `.c` - Kernel-level debug injection with logging
- `Application/Dopamine/Exploits/xnu_verbose_debug.h` / `.m` - Exploit-level verbose wrapper
- `HEXACON_CALIF_IO_PATCHES.md` - Integration reference for iOS 27.2 / Hexacon

## Log Output Locations
- Console / stdout via `printf` for kernel-level messages
- `DODebugLogView.m` for UI-level verbose display
- `/var/mobile/Documents/Dopamine_verbose.log` (future: file logging extension)

## Why Exploit Fails Logging
When an exploit fails, the verbose mode logs:
1. Target kernel address (`target_addr`)
2. Payload bytes (first 32 bytes in hex)
3. Kernel base / phys base / slide from `gSystemInfo`
4. Context string describing the failure point
5. CPU family (`CPUFAMILY_ARM_TUPAI` for A18 / iPhone 16e)
6. Verbose level at time of failure

## Integration with Dopamine
- `DOExploitManager.m` calls `[DOExploitVerboseDebug enableFullVerboseMode]` during cleanup
- `DOEnvironmentManager.m` references `XNU_DEBUG_VERBOSE_XNU_INJECT`
- `info.c` includes 27.0+ and 27.2+ adjustments with A18 (`TUPAI`) handling
- `machine_info.h` includes A19 (`TAHITI_PRO`) for future models

## Status
- Structural integration complete
- Binary payload logging simulated (pending real kernel write mechanism from public Hexacon/Calif.io release)
