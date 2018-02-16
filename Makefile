clean :
	rm -rf *.out
	find . -type f -name "*.hell" -exec rm -f {} \;



errorhere:
	g++ solution.cpp
	./a.out<test_cases/input1>>test_cases/tmp/output1generated.hell
	./a.out<test_cases/input2>>test_cases/tmp/output2generated.hell
	./a.out<test_cases/input3>>test_cases/tmp/output3generated.hell
	
	cmp test_cases/output1 test_cases/tmp/output1generated.hell
	cmp test_cases/output2 test_cases/tmp/output2generated.hell
	cmp test_cases/output3 test_cases/tmp/output3generated.hell
	
