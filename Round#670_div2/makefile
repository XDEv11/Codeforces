MAKE_FLAG := --no-print-directory

%: INPUT = $(shell echo $@ | tr A-Z a-z).in
%: EXE = x$@.exe
%: 
	@make $(MAKE_FLAG) $(EXE)
	@make $(MAKE_FLAG) $(INPUT)
	./$(EXE) < $(INPUT)

x%.exe: %.cpp
	g++ -Wall -std=c++17 -o $@ $<

%.in: 
	vim $@

clean:
	rm -f *.exe
