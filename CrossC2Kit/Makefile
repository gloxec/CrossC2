TARGET = cc2_portscan_demo cc2_keystrokes_demo

main: $(TARGET)

CFLAG = -fPIC -shared

%:
	clang $@.c -o $@.dylib $(CFLAG)

clean:
	-rm -rf ./*.dylib
