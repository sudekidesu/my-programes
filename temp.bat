@echo off  
:loop  
    exp4.exe > AC.out
    fc AC.out WA.out 
if not errorlevel 1 goto loop  
pause