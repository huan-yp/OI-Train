@echo off
:loop
makedata
football
football_2
fc football.out football_2.out
if not errorlevel 1 goto loop
pause
goto loop