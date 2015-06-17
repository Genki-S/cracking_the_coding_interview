EXES = 3.1.out 3.2.out 3.3.out 3.4.out 3.5.out 3.6.out 3.7.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
