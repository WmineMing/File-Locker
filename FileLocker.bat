set password=1234
for %%i in ("./File/*") do "./Locker/locker.exe" -l "./File/%%i" %password% "./File Locked/%%i"