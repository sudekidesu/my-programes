@echo off
:loop
    RAN.exe %random% > data.in
    WA.exe < data.in > WA.out
    AC.exe < WA.out > AC.out
    fc AC.out data.in 
if not errorlevel 1 goto loop
pause
goto loop
