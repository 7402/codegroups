CFLAGS=-Wall -std=c99
BINDIR=/usr/local/bin
MANDIR=/usr/local/share/man/man1

codegroups : main.c
	gcc $(CFLAGS) -o codegroups main.c

install : codegroups
	cp codegroups $(BINDIR)/
	codegroups --man-page > codegroups.1
	mkdir -p $(MANDIR)
	cp codegroups.1 $(MANDIR)/

clean :
	rm -f codegroups *.o

distclean :
	rm -f codegroups *.o $(BINDIR)/codegroups $(MANDIR)/codegroups.1
