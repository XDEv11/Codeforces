CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow \
			            --debug -fsanitize=address,undefined -D_GLIBCXX_DEBUG

MAKE_FLAG := --no-print-directory

%: EXE = x$@.exe
%: 
	@make $(MAKE_FLAG) $(EXE)

x%.exe: %.cpp
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.exe
