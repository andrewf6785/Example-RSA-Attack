CXX = g++
CXXFLAGS = -O2

DIR = RSA-Recreation-Cpp-Python/cppAlgos

SOURCES = ACCA.cpp $(addprefix $(DIR)/,bigInt/bigInt.cpp randomNumberGenerator/randomNumberGenerator.cpp decrypt.cpp eea.cpp encrypt.cpp keys.cpp miller_rabin.cpp modexp.cpp pickPrime.cpp commonPrimeCheck.cpp montgomeryConstant.cpp montgomeryModularExpo.cpp montgomeryReduction.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

attack.exe: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o attack.exe $(OBJECTS)

.PHONY: clean
clean:
	rm -f $(OBJECTS) attack.exe