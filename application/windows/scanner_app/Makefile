.PHONY: all clean

all:
	mkdir -p bin
	cp -f ./../../../hal/opencv_windows/lib/* bin/
	make -r -s -f ../../../library/boilermake/Makefile -j

clean:
	make -r -s -f ../../../library/boilermake/Makefile clean -j

run:all
	./bin/scanner_app.exe
