@echo off
del *.sdf
del /s *.aps
del /a:h *.suo
rmdir /s /q .vs
rmdir /s /q ipch
rmdir /s /q x64
rmdir /s /q Debug
rmdir /s /q Release
rmdir /s /q ping_vmm\x64
rmdir /s /q ping_vmm\Debug
rmdir /s /q ping_vmm\Release
pause
