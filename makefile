all:
	cd Sources  && $(MAKE)
	cd Meissel  && $(MAKE)

clean:
	rm -f libsieve.a
	cd Sources  && $(MAKE) clean
	cd Meissel  && $(MAKE) clean


