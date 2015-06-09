EXES = 3.1.out 3.2.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
