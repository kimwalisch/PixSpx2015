all:
	cd Sources  && $(MAKE)
	cd Meissel  && $(MAKE)
	cd Meissel6 && $(MAKE)

clean:
	rm -f libsieve.a
	cd Sources  && $(MAKE) clean
	cd Meissel  && $(MAKE) clean
	cd Meissel6 && $(MAKE) clean


