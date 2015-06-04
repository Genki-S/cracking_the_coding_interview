EXES = 2_4.out 2_5.out 2_5ex.out 2_6.out

test: $(EXES)

%.out: %.cpp
	g++ $< -o $@
	./$@
