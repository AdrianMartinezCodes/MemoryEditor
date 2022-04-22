add_library(MemoryFunctions ReadingMemory.cpp WritingMemory.cpp)
install(TARGETS MemoryFunctions DESTINATION lib)
install(FILES MemoryFunctions.hpp DESTINATION include)