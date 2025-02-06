MAKE_FLAG := --no-print-directory

%: EXE = x$@.exe
%: 
	@make $(MAKE_FLAG) $(EXE)
	./$(EXE) < sample.in

x%.exe: %.cpp
	g++ -Wall -std=c++17 -o $@ $<

clean:
	rm -f *.exe
