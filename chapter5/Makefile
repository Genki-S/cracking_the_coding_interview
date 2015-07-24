EXES = 5.1.out 5.2.out 5.3.out 5.5.out 5.6.out 5.8.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
