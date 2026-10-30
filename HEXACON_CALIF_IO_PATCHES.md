# Hexacon / Calif.io iOS 27.2 Integration (iPhone 16e / A18)

## Источник
- Hexacon, Париж, октябрь 2026 (heise.de 16.10.2026)
- Команда Calif.io представила первый jailbreak для iOS 27 (до 27.0.1)
- Untethered (выживает перезагрузку)
- AI использован для поиска цепочки эксплойтов

## Применено в Dopamine
- Версионные диапазоны в Info.plist обновлены до 27.2.0
- DOEnvironmentManager.m добавляет поддержку A18 (iPhone 16e) для 26.2 - 27.2.0
- info.c содержит оффсеты для 27.0+ и 27.2+ с учётом A18 (CPUFAMILY_ARM_TUPAI)
- machine_info.h содержит A19 (TAHITI_PRO) для будущих моделей

## Статус
- Публичного бинарника от Calif.io на момент 30.10.2026 нет
- Данная интеграция — структурная подготовка для релиза

## Universal Experimental Exploit (UniversalHexacon)
- Directory: Application/Dopamine/Exploits/UniversalHexacon/
- Source: UniversalHexacon.m / UniversalHexacon.h
- Config: Info.plist (universal device/model/version ranges)
- Integration: Uses xnu_debug_inject.c for full XNU injection with verbose logs
- Real device profile embedded: V59AP / iPhone17,5 / 27.2 / 24B119 / ChipID 33088 / arm64e
