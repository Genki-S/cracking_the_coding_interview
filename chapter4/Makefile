EXES = 4.1.out 4.2.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
