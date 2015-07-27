EXES = 7.4.out 7.5.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
