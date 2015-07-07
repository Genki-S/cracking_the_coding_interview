EXES = 5.1.out 5.2.out 5.3.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
