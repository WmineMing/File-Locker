prefix=/usr/local

obj=locker.o demo.o

locker:$(obj)
	g++ -o locker $(obj)

locker.o:locker.h

.PHONY:clean install uninstall
clean:
	rm locker $(obj)
install:
	install -d $(prefix)/bin
	install -t $(prefix)/bin locker
uninstall:
	rm $(prefix)/bin/locker 
