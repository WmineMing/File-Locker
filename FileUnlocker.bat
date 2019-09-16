set password=1234
for %%i in ("./File Locked/*") do "./Locker/locker.exe" -u "./File Locked/%%i" %password% "./File/%%i"