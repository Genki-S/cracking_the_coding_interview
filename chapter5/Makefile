EXES = 5.1.out 5.2.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
