INCLUDE_DIR = /home/user/.usr/include

run : a.out
	./$^

a.out : main.cpp
	g++ -std=c++11 $^ -o $@ -I$(INCLUDE_DIR)