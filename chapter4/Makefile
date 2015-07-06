EXES = 4.1.out 4.2.out 4.3.out 4.4.out 4.5.out 4.6.out 4.7.out 4.8.out 4.9.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
